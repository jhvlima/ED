#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tProduto tProduto;

tProduto *AdicionaProduto();

tProduto *AchaProduto(char *nome, tProduto **listaProduto, int tamanhoLista);

void DesalocaProduto(tProduto *produto);

int ObtemValorProduto(tProduto *p);

int ObtemCodigpProduto(tProduto *p);

char *ObtemNomeProduto(tProduto *p);

void DesalocaListaProdutos(tProduto **lista, int tamanhoLista);

tProduto **CriaListaProdutos(int tamanhoLista);

#endif