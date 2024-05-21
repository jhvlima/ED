#include "posto.h"
#include "tFila.h"
#include "amostra.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct posto
{
    char *nome;
    tFila *naoProcessado;
    tFila *processadoNegativo;
    tFila *processadoPositivo;
};

Posto* inicPosto(char* nome)
{
    Posto *posto = calloc(1, sizeof(Posto));
    posto->naoProcessado = criaFila();
    posto->processadoNegativo = criaFila();
    posto->processadoPositivo = criaFila();
    posto->nome = strdup(nome);
    return posto;
}

void imprimePosto(Posto* posto)
{
    printf("Dados do Posto: %s\n", posto->nome);
    printf("Amostras não processadas\n");
    imprimeFila(posto->naoProcessado);
    printf("\n");
    printf("Amostras com resultados positivos\n");
    imprimeFila(posto->processadoPositivo);
    printf("\n");
    printf("Amostra com resultados negativos\n");
    imprimeFila(posto->processadoNegativo);
}

/* Simula a realização de uma coleta de material para teste
 * A função deve criar uma amostra e fazer as devidas atribuições à amostra
 * Deve-se inserir a amostra na fila de "não processados"
 * ATENÇÃO: se a pessoa for idosa (idade>=60), ela deve ir para o início da fila de não processados
* inputs: referência para o posto de saúde, o nome do dono da coleta e a idade da pessa
* output: nenhum
* pre-condicao: posto válido, nome da pessoa válido
* pos-condicao: Amostra alocada e inserida na fila de amostras não processadas
 */
void realizaColeta(Posto* posto, char* pessoa, int idade)
{
    Amostra *amostra = inicAmostra(pessoa, idade);
    insereFila(posto->naoProcessado, amostra);
}


/* Essa função simula o processamento (testagem) das amostras e atualiza os resultados nas amostras. Deve-se usar a constante LIMITE_CARGA_VIRAL para definir positivo e negativo.
* inputs: referência do posto de saúde.
* output: nenhum
* pre-condicao: posto válido
* pos-condicao: amostras foram devidamente processadas; fila de amostras não processadas deve ficar vazia; fila de amostras positivas deve conter as amostras que testaram positivo (idosos na frente); fila de amostras negativas deve conter as amostras que testaram negativo (idosos na frente).
 */
void processaLoteAmostras(Posto* posto)
{
    Amostra *amostra = retornaPrimeiraAmostra(posto->naoProcessado);
    while (amostra)
    {
        if (LIMITE_CARGA_VIRAL < retornaCargaViral(amostra))
        {
            insereFila(posto->processadoPositivo, amostra);
        }
        else
        {
            insereFila(posto->processadoNegativo, amostra);
        }
        retiraFila(posto->naoProcessado);
        amostra = retornaProximaAmostra(posto->naoProcessado, amostra);
    }
}

void liberaPosto(Posto* posto)
{
    if (posto)
    {
        liberaFila(posto->naoProcessado);
        liberaFila(posto->processadoPositivo);
        liberaFila(posto->processadoNegativo);
        free(posto->nome);
    }
    free(posto);
}