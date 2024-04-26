#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tCelula tCelula;

typedef struct _tLista tLista;

// cria lista vazia
tLista *criaLista();

// insere na ultima posicao da lista
void insereLista(tLista *lista, void *animal);

void retiraLista(tLista *lista, void* animal);

void desalocaLista(tLista *lista);

void imprimeLista(tLista *lista);

float calculaReceitaLista(tLista *l);

float calculaReceitaListaAgressivo(tLista *l);


#endif