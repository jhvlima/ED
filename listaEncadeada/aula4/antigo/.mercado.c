#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/produto.h"
#include "../headers/mercado.h"
#include "../headers/filial.h"
#include "../headers/lista.h"

typedef struct _tMercado
{
    char *nomeMercado;
    int estoque;
    tFilial **filial;
    int qntFilias;
} tMercado;

void ImprimeMercado(tMercado *mercado)
{
    printf("\nNome: %s, Estoque Total: %d\n", mercado->nomeMercado, mercado->estoque);
    for (int i = 0; i < mercado->qntFilias; i++)
    {
        ImprimeFilial(mercado->filial[i]);
    }
}

tMercado *AdicionaMercado(tProduto **listaProduto, int tamanhoLista)
{
    tMercado *mercado = malloc(sizeof(*mercado));
    mercado->filial = malloc(10 * sizeof(tFilial));

    printf("Digite o nome da mercado: ");
    char temp[100];
    scanf("%[^\n]", temp);
    scanf("%*c");
    mercado->nomeMercado = strdup(temp);
    mercado->qntFilias = 0;
    mercado->estoque = 0;

    printf("Quantas filiais deseja adilicionar?: ");
    scanf("%d", &mercado->qntFilias);
    scanf("%*c");

    for (int i = 0; i < mercado->qntFilias; i++)
    {
        mercado->filial[i] = AdicionaFilial(listaProduto, tamanhoLista);
    }
    return mercado;
}

void CaculaEstoqueMercado(tMercado *mercado)
{
    for (int i = 0; i < mercado->qntFilias; i++)
    {
        CaculaEstoqueFilial(mercado->filial[i]);
        mercado->estoque += mercado->filial[i]->estoqueFilal;
    }
}

void DesalocaMercado(tMercado *mercado)
{
    if (mercado->nomeMercado)
    {
        free(mercado->nomeMercado);
    }

    if (mercado->filial)
    {
        for (int i = 0; i < mercado->qntFilias; i++)
        {
            DesalocaFilial(mercado->filial[i]);
        }
        free(mercado->filial);
    }
    free(mercado);
}