#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tProduto tProduto;

tProduto *AdicionaProduto();

tProduto *AchaProduto(char *nome, tProduto **listaProduto, int tamanhoLista);

void DesalocaProduto(tProduto *produto);

