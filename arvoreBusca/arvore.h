/* Implemente um TAD árvore binária de busca (ABB) de alunos, com as funcionalidades básicas de: criação, busca, impressão, inserção, retirada e liberação. 
Você escolhe o critério de ordenação para sua ABB.
Implemente um testador para sua implementação.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _tArv tArv; 

tArv *criaArvore();

tArv *imprimeArvore(tArv * a);

tArv *insereArvore(tArv * a, );

tArv *retiraArvore(tArv *a, );

tArv *liberaArvore(tArv *);

void ordena(tArv *a);