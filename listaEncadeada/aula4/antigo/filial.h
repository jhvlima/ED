#ifndef FILIAL_H
#define FILIAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/produto.h"
#include "../headers/lista.h"

typedef struct _tFilial tFilial;

void ImprimeFilial(tFilial *filial);

tFilial *AdicionaFilial(tProduto **listaProduto, int tamnhoLista);

void DesalocaFilial(tFilial *filial);

void CaculaEstoqueFilial(tFilial *filial);

#endif