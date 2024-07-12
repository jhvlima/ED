/*

*/
#include <stdio.h>
#include <stdlib.h>

#ifndef
#define LISTARECURSIVA_H

typedef struct _tLista tLista;

tLista* criaLista();
void insereLista(tLista *lista, tLista *novo);
tLista *retiraLista(tLista *lista, tLista *lixo);
void imprimeLista(tLista *lista);
void destroiLista(tLista *lista);

#endif