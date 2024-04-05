#ifndef ITEN_H
#define ITEN_H

#include "../headers/produto.h"

typedef struct _tItem tItem;

void ImprimeItem(tItem *item);

tItem *AdicionaItem(tProduto **listaProduto, int tamanhoLista);

void DesalocaItem(tItem *item);

#endif