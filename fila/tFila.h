#ifndef fila_h
#define fila_h

typedef struct _tFila tFila;

tFila *criaFila();

void *insereFila(tFila *fila);

void retiraFila(tFila *fila);

void liberaFila(tFila *fila);

#endif