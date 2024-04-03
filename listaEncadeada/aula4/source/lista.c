#include "../headers/lista.h"
#include "../headers/produto.h"

typedef struct _tNode 
{
    tProduto* produto;
    tNode *proximoNode;
}tNode;

typedef struct _tLista 
{
    tNode* primeiroNode;
    tNode* ultimoNode;
    int tamanho;
}tLista;

tLista *CriaLista()
{
    tLista *lista = malloc(sizeof(tLista));
    lista->primeiroNode = lista->ultimoNode = NULL;
    lista->tamanho = 0;
    return lista;
}

void *InsereLista(tLista *lista, tProduto *produto)
{
    tNode *novoNode = malloc(sizeof(tNode));

    // nao tem nenhum node
    if (lista->ultimoNode)
    {
        lista->primeiroNode = lista->ultimoNode = novoNode;
    }
    
    else
    {
        lista->ultimoNode->proximoNode = novoNode;
        lista->ultimoNode = lista->ultimoNode->proximoNode;
    }

    lista->ultimoNode->produto = produto;
    lista->ultimoNode->proximoNode = NULL;   
}

void *RetiraListaNome(char *nome, tLista *listaProduto)
{

}

void DesalocaLista(tLista *lista)
{
    // o segundo node vira o inico da lista e libera o antigo primeiro
    while (lista->ultimoNode)
    {
        lista->primeiroNode = lista->primeiroNode->proximoNode;
        free(lista->primeiroNode);
    }
    free(lista);
}

void *ImprimeLista(tLista *lista)
{
    tNode *auxiliar = lista->primeiroNode;
    while (auxiliar)
    {
        ImprimeProduto(auxiliar->produto);
        auxiliar = auxiliar->proximoNode;
    }
}
