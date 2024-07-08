/* 
Implemente um TAD árvore binária de busca (ABB) de alunos, com as funcionalidades básicas de: criação, busca, impressão, inserção, retirada e liberação. 
Você escolhe o critério de ordenação para sua ABB.
Implemente um testador para sua implementação.
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct _tArv
{
    int dado;
    tArv *dir;
    tArv *esq;
} 

int tarv_vazia (tArv* a)
{
   return a == NULL;
}

tArv* criaArvore(int dado, tArv* e, tArv* d)
{
    tArv *novo = calloc(1, sizeof(tArv));
    novo->dado = aluno;
    novo->dir = d;
    novo->esq = e;
    return novo;
}

tArv *imprimeArvore(tArv *a)
{ 
    if (!tarv_vazia(a))
    {
        // rever essa impresao com <>
        printf("|%d|", a->dado);
        printf("< ");
        imprimeArvore(a->esq);
        printf(" >");
        imprimeArvore(a->dir);
    }
}

tArv *insereArvore(tArv *a, int dado)
{
    if (!tarv_vazia(a))
    {
        // compaara se o dado é maior que o outro
        if(compara(a->dir, dado))
        {
            
        }
        else
        {

        }
    }    
}

tArv *retiraArvore(tArv *a, int dado)
{
    if (!tarv_vazia(a))
    {
        if(ehIgual(a->dado, dado))
        {
            return a;
        }
    }
}

tArv *liberaArvore(tArv *a)
{
    if (!tarv_vazia(a))
    {
        tarv_libera(a->esq);
        tarv_libera(a->dir);
        liberaAluno(a->dado);
        free(a);
    }
    return NULL;
}

void ordena(tArv *a)
{

}