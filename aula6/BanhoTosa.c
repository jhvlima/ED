#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLista.h"
#include "tGato.h"
#include "tCachorro.h"

typedef struct tBanhoTosa
{
    char *nome;
    tLista *agressivos;
    tLista *mansos;
} tBanhoTosa;

tBanhoTosa* inicaBanhoTosa(char* nome)
{
    tBanhoTosa *loja = malloc(sizeof(tBanhoTosa));
    loja->nome = strdup(nome);
    loja->agressivos = criaLista();
    loja->mansos = criaLista();
    return loja;
}

void cadastraCachorro(tBanhoTosa* loja, tCachorro* dog)
{
    if (!loja)
    {
        printf("LOJA NAO EXISTENTE\n");
        return;
    }
    if (!dog)
    {
        printf("CACHORRO NAO EXISTENTE\n");
        return;
    }
    
    if (verificaTemperamentoCachorro(dog) == MANSO)
    {
        InsereLista(loja->mansos, dog);
    }
    else
    {
        InsereLista(loja->agressivos, dog);
    }
}

void cadastraGato(tBanhoTosa* loja, tGato* cat)
{
    if (!loja)
    {
        printf("LOJA NAO EXISTENTE\n");
        return;
    }
    if (!cat)
    {
        printf("GATO NAO EXISTENTE\n");
        return;
    }
    
    if (verificaTemperamentoGato(cat) == MANSO)
    {
        InsereLista(loja->mansos, cat);
    }
    else
    {
        InsereLista(loja->agressivos, cat);
    }
}

void atualizaSituacaoGato(tBanhoTosa* loja, tGato* cat)
{
    if (!loja)
    {
        printf("LOJA NAO EXISTENTE\n");
        return;
    }
    if (!cat)
    {
        printf("GATO NAO EXISTENTE\n");
        return;
    }

    if (verificaTemperamentoGato(cat) == AGRESSIVO)
    {
        InsereLista(loja->agressivos, cat);
        RetiraLista(cat, loja->mansos);
    }
    else
    {
        InsereLista(loja->mansos, cat);
        RetiraLista(cat, loja->agressivos);
    }
}

void atualizaSituacaoCachorro(tBanhoTosa* loja, tCachorro* dog)
{
    if (!loja)
    {
        printf("LOJA NAO EXISTENTE\n");
        return;
    }
    if (!dog)
    {
        printf("CACHORRO NAO EXISTENTE\n");
        return;
    }

    if (verificaTemperamentoCachorro(dog) == AGRESSIVO)
    {
        InsereLista(loja->agressivos, dog);
        RetiraLista(dog, loja->mansos);
    }
    else
    {
        InsereLista(loja->mansos, dog);
        RetiraLista(dog, loja->agressivos);
    }
}

void imprimeBanhoTosa(tBanhoTosa* loja)
{
    if (!loja)
    {
        printf("LOJA NAO EXISTENTE\n");
        return;
    }
    printf("%s\n", loja->nome);
    ImprimeLista(loja->agressivos);
    ImprimeLista(loja->mansos);
}

/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor tGato: 30 reais, Valor tCachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(tBanhoTosa* loja)
{
    if (!loja)
    {
        printf("LOJA NAO EXISTENTE\n");
        return;
    }
     
    percorreLista(loja->agressivos) obtemTipoAnimal()
}

void liberaBanhoTosa(tBanhoTosa* loja)
{
    if (loja)
    {
        free(loja->nome);
        if (loja->agressivos)
        {
            DesalocaLista(loja->agressivos);
        }
        if (loja->mansos)
        {
            DesalocaLista(loja->mansos);
        }
        free(loja);
    }
}