#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tLista tLista;

// cria lista vazia
tLista *CriaLista();

// insere na ultima posicao da lista
void InsereLista(tLista *lista, void *animal);

void RetiraLista(tLista *lista, void* animal);

void DesalocaLista(tLista *lista);

void ImprimeLista(tLista *lista);


#endif