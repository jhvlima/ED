/* Implemente um TAD árvore binária de busca (ABB) de alunos, com as funcionalidades básicas de: criação, busca, impressão, inserção, retirada e liberação. 
Você escolhe o critério de ordenação para sua ABB.
Implemente um testador para sua implementação.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _tArv tArv; 

tArv *criaArvore();

tArv *imprimeArvore(tArv *a);

tArv *insereArvore(tArv *a, int dado);

tArv *retiraArvore(tArv *a, int dado);

tArv *liberaArvore(tArv *a);

void ordena(tArv *a);