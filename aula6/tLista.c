#include "tGato.h"
#include "tCachorro.h"
#include "tLista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union tAnimal
{
    tCachorro *cachorro;
    tGato *gato;
}tAnimal;

typedef struct _tCelula 
{
    union tAnimal;
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
    lista->primeiraCelula = lista->ultimaCelula = NULL;
    return lista;
}

// insere na ultima posicao da lista
void InsereLista(tLista *lista, void *animal)
{
    if (animal == NULL)
    {
        printf("Animal inexistente\n");
    }

    tCelula *novoNode = malloc(sizeof(tCelula));

    // nao tem nenhum node
    if (!lista->ultimaCelula)
    {
        lista->primeiraCelula = lista->ultimaCelula = novoNode;
        novoNode->anteriorCelula = NULL;
    }    
    else
    {
        novoNode->anteriorCelula = lista->ultimaCelula;
        lista->ultimaCelula->proximaCelula = novoNode;
        lista->ultimaCelula = novoNode;
    }

    novoNode->tAnimal = animal;
    novoNode->proximaCelula = NULL; 
}

void RetiraLista(tLista *lista, void* animal);

void DesalocaLista(tLista *lista);

void ImprimeLista(tLista *lista)
{

}