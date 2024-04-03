#include "../headers/produto.h"

typedef struct _tProduto
{
    char *nomeProduto;
    int valor;
    int codigo;
} tProduto;


tProduto *AdicionaProduto()
{
    tProduto *produto = malloc(sizeof(tProduto));

    printf("Digite o nome do produto: ");
    char temp[100];
    scanf("%99[^\n]", temp);
    scanf("%*c");
    produto->nomeProduto = strdup(temp);

    printf("Digite valor: ");
    scanf("%d", &produto->valor);
    scanf("%*c");
    return produto;
}

tProduto *AchaProduto(char *nome, tProduto **listaProduto, int tamanhoLista)
{
    for (int i = 0; i < tamanhoLista; i++)
    {
        if (!strcmp(nome, listaProduto[i]->nomeProduto))
        {
            return listaProduto[i];
        }
    }
    return NULL;
}

void DesalocaProduto(tProduto *produto)
{
    if (produto)
    {
        if (produto->nomeProduto)
        {
            free(produto->nomeProduto);
        }
        free(produto);
    }
}
