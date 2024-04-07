#include "../headers/produto.h"

typedef struct _tProduto
{
    char *nomeProduto;
    int valor;
    int codigo;
} tProduto;

tProduto **CriaListaProdutos(int tamanhoLista)
{
    tProduto **listaProdutos = malloc(sizeof(tProduto*) * tamanhoLista);
    for (int i = 0; i < tamanhoLista; i++)
    {
        listaProdutos[i] = AdicionaProduto(); 
    }
    return listaProdutos;
}

void DesalocaListaProdutos(tProduto **lista, int tamanhoLista)
{
    for (int i = 0; i < tamanhoLista; i++)
    {
        DesalocaProduto(lista[i]); 
    }
    free(lista);
}

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
    
    printf("Digite codigo: ");
    scanf("%d", &produto->codigo);
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

int ObtemValorProduto(tProduto *p)
{
    return p->valor;
}

int ObtemCodigoProduto(tProduto *p)
{
    return p->codigo;
}

char *ObtemNomeProduto(tProduto *p)
{
    return p->nomeProduto;
}

void ImprimeProduto(tProduto *p)
{
    printf("\tProduto: %s, valor unitário: %d, codigo: %d\n", ObtemNomeProduto(p), ObtemValorProduto(p), ObtemCodigoProduto(p));
}
