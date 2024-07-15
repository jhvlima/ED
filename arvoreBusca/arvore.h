/*
Implemente um TAD árvore binária de busca (ABB) de alunos, com as funcionalidades básicas de: criação, busca, impressão, inserção, retirada e liberação.
Você escolhe o critério de ordenação para sua ABB.
Implemente um testador para sua implementação.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _tArv tArv;

int tarv_vazia(tArv *a);

tArv *criaArvore(int dado, tArv *e, tArv *d);

tArv *imprimeArvore(tArv *a);

int compara(int dado1, int dado2);

tArv *insereArvore(tArv *a, int dado);

tArv *retiraArvore(tArv *a, int dado);

tArv *liberaArvore(tArv *a);

void ordena(tArv *a);

tArv *buscaBinaria(tArv *a, int chaveBusca);
