#include "tGato.h"
#include "tCachorro.h"
#include "tLista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CACHORRO 3
#define GATO 4

typedef union tAnimal
{
    tCachorro *cachorro;
    tGato *gato;
}tAnimal;

typedef struct _tCelula 
{
    int tipoAnimal;
    tAnimal *animal;
    tCelula *proximaCelula;
    tCelula *anteriorCelula;
}tCelula;

// sentinela
typedef struct _tLista 
{
    tCelula* primeiraCelula;
    tCelula* ultimaCelula;
}tLista;

tLista *criaLista()
{
    tLista *lista = malloc(sizeof(tLista));
    lista->primeiraCelula = lista->ultimaCelula = NULL;
    return lista;
}

// insere na ultima posicao da lista
void insereLista(tLista *lista, void *animal)
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

    novoNode->animal = animal;
    novoNode->proximaCelula = NULL; 
}

void retiraLista(tLista *lista, void* animal)
{
    tCelula *auxiliar = lista->primeiraCelula;
    while (auxiliar)
    {
        if (auxiliar->animal == animal)
        {
            // lista de um node so
            if (auxiliar == lista->primeiraCelula && auxiliar == lista->ultimaCelula)
            {
                lista->primeiraCelula = lista->ultimaCelula = NULL;
                break;
            }

            // primeiro node
            if (auxiliar == lista->primeiraCelula)
            {
                lista->primeiraCelula = auxiliar->proximaCelula;
                break;
            }
            
            // ultimo node
            if (auxiliar == lista->ultimaCelula)
            {
                lista->ultimaCelula = auxiliar->anteriorCelula;
                lista->ultimaCelula->proximaCelula = NULL;
                break;
            }

            // caso comum
            auxiliar->anteriorCelula->proximaCelula = auxiliar->proximaCelula;
            auxiliar->proximaCelula->anteriorCelula = auxiliar->anteriorCelula;
            break;
        }
        auxiliar = auxiliar->proximaCelula;
    }
    free(auxiliar);
}

void desalocaLista(tLista *lista)
{
    if (lista)
    {
        tCelula *atual = lista->primeiraCelula;
        while (atual)
        {
            lista->primeiraCelula = atual->proximaCelula;
            free(atual);
            atual = lista->primeiraCelula;
        }
        free(lista);
    }
}

void imprimeLista(tLista *lista)
{
    tCelula *auxiliar = lista->primeiraCelula;
    while (auxiliar)
    {
        if (auxiliar->tipoAnimal == CACHORRO)
        {
            imprimeCachorro(auxiliar->animal);
        }
        else
        {
            imprimeGato(auxiliar->animal);
        }
        auxiliar = auxiliar->proximaCelula;
    }
}

float calculaReceitaLista(tLista *l)
{
    tCelula *auxiliar = l->primeiraCelula;
    float soma = 0;
    while (auxiliar)
    {
        if (auxiliar->tipoAnimal == CACHORRO)
        {
            soma = soma + 40;
        }
        else
        {
            soma = soma + 30;
        }
        auxiliar = auxiliar->proximaCelula;
    }
    return soma;
}

float calculaReceitaListaAgressivo(tLista *l)
{
    tCelula *auxiliar = l->primeiraCelula;
    float soma = 0;
    while (auxiliar)
    {
        if (auxiliar->tipoAnimal == CACHORRO)
        {
            soma = soma + 40;
        }
        else
        {
            soma = soma + 30;
        }
        soma = soma + 5;
        auxiliar = auxiliar->proximaCelula;
    }
    return soma;
}