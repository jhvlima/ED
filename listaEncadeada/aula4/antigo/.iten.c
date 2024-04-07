
#include "../headers/produto.h"
#include "../headers/iten.h"

typedef struct
{
    tProduto *produto;
    int qnt;
} tItem;

void ImprimeItem(tItem *item)
{
    printf("\t\tItem: %s, valor unitário: %d, quantidade: %d\n", ObtemNomeProduto(item->produto), ObtemValorProduto(item->produto), item->qnt);
}

tItem *AdicionaItem(tProduto **listaProduto, int tamanhoLista)
{
    tItem *item = malloc(sizeof(tItem));

    printf("Digite o nome do produto: ");
    char nome[100];
    scanf("%[^\n]", nome);
    scanf("%*c");

    item->produto = AchaProduto(nome, listaProduto, tamanhoLista);

    printf("Digite qnt: ");
    scanf("%d", &item->qnt);
    scanf("%*c");

    return item;
}

void DesalocaItem(tItem *item)
{
    if (item)
    {
        free(item);
    }
}

