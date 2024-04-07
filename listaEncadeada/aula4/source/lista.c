#include "../headers/lista.h"
#include "../headers/produto.h"

typedef struct _tNode 
{
    tProduto* produto;
    tNode *proximoNode;
}tNode;

// sentinela
typedef struct _tLista 
{
    tNode* primeiroNode;
    tNode* ultimoNode;
}tLista;

tLista *CriaLista()
{
    tLista *lista = malloc(sizeof(tLista));
    lista->primeiroNode = lista->ultimoNode = NULL;
    return lista;
}

void *InsereLista(tLista *lista, tProduto *produto)
{
    if (produto == NULL)
    {
        printf("Produto inexistente\n");
    }
    if (lista == NULL)
    {
        printf("Lista inexistente\n");
    }
    tNode *novoNode = malloc(sizeof(tNode));

    // nao tem nenhum node
    if (!lista->ultimoNode)
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
    tNode *anterior = NULL;
    tNode *auxiliar = listaProduto->primeiroNode;
    while (auxiliar)
    {
        if (!strcmp(ObtemNomeProduto(auxiliar->produto), nome))
        {
            // lista de um node so
            if (auxiliar == listaProduto->primeiroNode && auxiliar == listaProduto->ultimoNode)
            {
                listaProduto->primeiroNode = listaProduto->ultimoNode = NULL;
                break;
            }

            // primeiro node
            if (auxiliar == listaProduto->primeiroNode)
            {
                listaProduto->primeiroNode = auxiliar->proximoNode;
                break;
            }
            
            // ultimo node
            if (auxiliar == listaProduto->ultimoNode)
            {
                listaProduto->ultimoNode = anterior;
                anterior->proximoNode = NULL;
                break;
            }

            // caso comum
            anterior->proximoNode = auxiliar->proximoNode;
            break;
            
        }
        anterior = auxiliar;
        auxiliar = auxiliar->proximoNode;
    }
    free(auxiliar);
}

void *RetiraListaCodigo(int codigo, tLista *listaProduto)
{
    tNode *anterior = NULL;
    tNode *auxiliar = listaProduto->primeiroNode;
    while (auxiliar)
    {
        if (ObtemCodigoProduto(auxiliar->produto) == codigo)
        {
            // lista de um node so
            if (auxiliar == listaProduto->primeiroNode && auxiliar == listaProduto->ultimoNode)
            {
                listaProduto->primeiroNode = listaProduto->ultimoNode = NULL;
                break;
            }

            // primeiro node
            if (auxiliar == listaProduto->primeiroNode)
            {
                listaProduto->primeiroNode = auxiliar->proximoNode;
                break;
            }
            
            // ultimo node
            if (auxiliar == listaProduto->ultimoNode)
            {
                listaProduto->ultimoNode = anterior;
                anterior->proximoNode = NULL;
                break;
            }

            // caso comum
            anterior->proximoNode = auxiliar->proximoNode;
            break;
            
        }
        anterior = auxiliar;
        auxiliar = auxiliar->proximoNode;
    }
    free(auxiliar);
}

void DesalocaLista(tLista *lista)
{
    tNode *atual = lista->primeiroNode;
    // o segundo node vira o inico da lista e libera o antigo primeiro
    while (atual)
    {
        lista->primeiroNode = atual->proximoNode;
        free(atual);
        atual = lista->primeiroNode;
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
