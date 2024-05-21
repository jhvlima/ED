#ifndef fila_h
#define fila_h

#include "amostra.h"

typedef struct _tFila tFila;

tFila *criaFila();

void insereFila(tFila *fila, Amostra *a);

void retiraFila(tFila *fila);

void liberaFila(tFila *fila);

void imprimeFila(tFila *fila);

Amostra *retornaPrimeiraAmostra(tFila *f);

Amostra *retornaProximaAmostra(tFila *fila, Amostra *a);

#endif