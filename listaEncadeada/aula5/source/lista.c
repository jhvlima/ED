/*
    Lista duplamete encadeada sem sentinela
*/

#include "../headers/lista.h"
#include "../headers/produto.h"

typedef struct _tLista 
{
    tProduto *produto;
    tLista* anteriorNode;
    tLista* proximoNode;
}tLista;

tLista *CriaLista()
{ 
    return NULL;
}

tLista *InsereLista(tLista *lista, tProduto *produto)
{
    if (produto == NULL)
    {
        printf("Produto inexistente\n");
        return lista;
    }
    if (lista == NULL)
    {
        printf("Lista inexistente\n");
    }
    
    tLista *novoNode = malloc(sizeof(tLista));
    if (novoNode == NULL)
    {
        printf("Erro na alocação de memória\n");
        return lista;
    }

    novoNode->anteriorNode = NULL;
    novoNode->produto = produto;
    novoNode->proximoNode = lista;

    if (lista)
    {
        // atualiza o anterior da lista
        lista->anteriorNode = novoNode;
    }

    return novoNode;
}

tLista *RetiraListaNome(char *nome, tLista *listaProduto)
{
    tLista *auxiliar = listaProduto;
    while (auxiliar)
    {
        if (!strcmp(ObtemNomeProduto(auxiliar->produto), nome))
        {
            // lista de um node so
            if (auxiliar == listaProduto && auxiliar->proximoNode == NULL)
            {
                listaProduto->anteriorNode = listaProduto->proximoNode = NULL;
                free(auxiliar);
                return listaProduto;
            }

            // primeiro node
            if (auxiliar == listaProduto)
            {
                listaProduto = auxiliar->proximoNode;
                free(auxiliar);
                return listaProduto;
            }
            
            // ultimo node
            if (auxiliar->proximoNode == NULL)
            {
                auxiliar->anteriorNode->proximoNode = NULL;
                free(auxiliar);
                return listaProduto;
            }

            // caso comum
            auxiliar->anteriorNode->proximoNode = auxiliar->proximoNode;
            auxiliar->proximoNode->anteriorNode = auxiliar->anteriorNode;
            free(auxiliar);
            return listaProduto;  
        }
        auxiliar = auxiliar->proximoNode;
    }
    return listaProduto;
}

tLista *RetiraListaCodigo(int codigo, tLista *listaProduto)
{
    tLista *auxiliar = listaProduto;
    while (auxiliar)
    {
        if (ObtemCodigoProduto(auxiliar->produto) == codigo)
        {
            // lista de um node so
            if (auxiliar == listaProduto && auxiliar->proximoNode == NULL)
            {
                listaProduto->anteriorNode = listaProduto->proximoNode = NULL;
                free(auxiliar);
                return listaProduto;
            }

            // primeiro node
            if (auxiliar == listaProduto)
            {
                listaProduto = auxiliar->proximoNode;
                free(auxiliar);
                return listaProduto;
            }
            
            // ultimo node
            if (auxiliar->proximoNode == NULL)
            {
                auxiliar->anteriorNode->proximoNode = NULL;
                free(auxiliar);
                return listaProduto;
            }

            // caso comum
            auxiliar->anteriorNode->proximoNode = auxiliar->proximoNode;
            auxiliar->proximoNode->anteriorNode = auxiliar->anteriorNode;
            free(auxiliar);
            return listaProduto;  
        }
        auxiliar = auxiliar->proximoNode;
    }
    return listaProduto;
}

void DesalocaLista(tLista *lista)
{
    tLista *atual = lista;
    // o segundo node vira o inico da lista e libera o antigo primeiro
    while (atual)
    {
        lista = atual->proximoNode;
        free(atual);
        atual = lista;
    }
}

void ImprimeLista(tLista *lista)
{
    tLista *auxiliar = lista;
    while (auxiliar)
    {
        ImprimeProduto(auxiliar->produto);
        auxiliar = auxiliar->proximoNode;
    }
}
