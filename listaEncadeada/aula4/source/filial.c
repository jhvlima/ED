#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/produto.h"
#include "../headers/lista.h"
#include "../headers/iten.h"


typedef struct
{
    char *nomeFilial;
    tItem **item;
    int qntItems;
    int estoqueFilal;
} tFilial;

void ImprimeFilial(tFilial *filial)
{
    printf("\tFilial: %s\n", filial->nomeFilial);
    printf("\tEstoque: %d\n", filial->estoqueFilal);
    for (int i = 0; i < filial->qntItems; i++)
    {
        ImprimeItem(filial->item[i]);
    }
}

tFilial *AdicionaFilial(tProduto **listaProduto, int tamnhoLista)
{
    tFilial *filial = malloc(sizeof(tFilial));
    filial->item = malloc(10 * sizeof(tItem *));

    printf("Digite o nome da filial: ");
    char temp[100];
    scanf("%99[^\n]", temp);
    scanf("%*c");
    filial->nomeFilial = strdup(temp);
    filial->qntItems = 0;
    filial->estoqueFilal = 0;

    printf("Quantos itens deseja adicionar?: ");
    scanf("%d", &filial->qntItems);
    scanf("%*c");

    for (int i = 0; i < filial->qntItems; i++)
    {
        filial->item[i] = AdicionaItem(listaProduto, tamnhoLista);
    }
    return filial;
}

void DesalocaFilial(tFilial *filial)
{
    if (filial->nomeFilial)
    {
        free(filial->nomeFilial);
    }

    if (filial->item)
    {
        for (int i = 0; i < filial->qntItems; i++)
        {
            DesalocaItem(filial->item[i]);
        }
        free(filial->item);
    }

    if (filial)
    {
        free(filial);
    }
}

void CaculaEstoqueFilial(tFilial *filial)
{
    for (int i = 0; i < filial->qntItems; i++)
    {
        filial->estoqueFilal += ObtemValorProduto(filial->item[i]->produto) * filial->item[i]->qnt;
    }
}