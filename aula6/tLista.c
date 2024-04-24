#include "tLista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tCelula 
{
    void* animal;
    tCelula *proximaCelula;
    tCelula *anteriorCelula;
}tCelula;

// sentinela
typedef struct _tLista 
{
    tCelula* primeiraCelula;
    tCelula* ultimaCelula;
}tLista;

tLista *CriaLista()
{
    tLista *lista = malloc(sizeof(tLista));
    lista->primeiroNode = lista->ultimoNode = NULL;
    return lista;
}

// insere na ultima posicao da lista
void InsereLista(tLista *lista, void *animal)
{
    if (animal == NULL)
    {
        printf("Animal inexistente\n");
    }

    tCelula *novoNode = malloc(sizeof(tNode));

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

    lista->ultimoNode->produto = animal;
    lista->ultimoNode->proximoNode = NULL; 
}

void RetiraLista(tLista *lista, void* animal);

void DesalocaLista(tLista *lista);

void ImprimeLista(tLista *lista);