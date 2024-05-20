#include "pedido.h"
#include "produto.h"

#ifndef lista_h
#define lista_h

typedef struct tcelula tCelula;

typedef struct tlista tLista;

void insereLista(tLista *lista, TProduto *prod);

void retiraLista(tLista *lista, TProduto *prod);

void imprimeLista(tLista *lista);

tLista *inicializaLista();

#endif