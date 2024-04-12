#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/produto.h"

/*
    Lista duplamete encadeada sem sentinela
*/
typedef struct _tLista tLista;

// cria lista vazia
tLista *CriaLista();

// insere na primeira posicao da lista
tLista *InsereLista(tLista *lista, tProduto *produto);

tLista *RetiraListaNome(char *nome, tLista *listaProduto);

tLista *RetiraListaCodigo(int codigo, tLista *listaProduto);

void DesalocaLista(tLista *lista);

void ImprimeLista(tLista *lista);


#endif