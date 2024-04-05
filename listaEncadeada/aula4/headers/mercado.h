#ifndef MERCADO_H
#define MERCADO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/produto.h"
#include "../headers/filial.h"
#include "../headers/lista.h"

typedef struct _tMercado tMercado;

void ImprimeMercado(tMercado *mercado);

tMercado *AdicionaMercado(tProduto **listaProduto, int tamanhoLista);

void CaculaEstoqueMercado(tMercado *mercado);

void DesalocaMercado(tMercado *mercado);

#endif