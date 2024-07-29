#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"
#include "tLista.h"

struct _tAluno
{

};
struct _tLista
{
    tLista *prox;
    tALuno *dado;
};


tAluno *criaLista()
{
    tLista *novo = calloc(1, sizeof(tAluno));
    return novo;
}

tLista *insereLista(tLista *lista, tAluno *aluno)
{
    tLista *novo = criaLista();
    novo->dado = aluno;
    
    if (lista == NULL)
    {
        novo->prox = NULL;    
    }
    else
    {
        novo->prox = lista;  
    }
    return novo;
}

void liberaLista(tLista *lista)
{
    if (lista)
    {
        liberaLista(lista->prox);
        free(lista);
    }
}