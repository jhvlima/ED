#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/produto.h"

typedef struct _tLista tLista;

typedef struct _tNode tNode;

// cria lista vazia
tLista *CriaLista();

// insere na ultima posicao da lista
void *InsereLista(tLista *lista, tProduto *produto);

void *RetiraListaNome(char *nome, tLista *listaProduto);

void *RetiraListaCodigo(int codigo, tLista *listaProduto);

void DesalocaLista(tLista *lista);

void *ImprimeLista(tLista *lista);


#endif