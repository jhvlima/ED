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
};

int ehIgual(int dado1, int dado2)
{
    return dado1 == dado2;
}

int tarv_vazia(tArv *a)
{
    return a == NULL;
}

tArv *criaArvore(int dado, tArv *e, tArv *d)
{
    tArv *novo = calloc(1, sizeof(tArv));
    novo->dado = dado;
    novo->dir = d;
    novo->esq = e;
    return novo;
}

tArv *imprimeArvore(tArv *a)
{
    if (!tarv_vazia(a))
    {
        // rever essa impresao com <>
        printf(" |%d| ", a->dado);
        printf("<");
        imprimeArvore(a->esq);
        printf(">");
        imprimeArvore(a->dir);
    }
}

int compara(int dado1, int dado2)
{
    return dado1 > dado2;
}

tArv *insereArvore(tArv *a, int novoDado)
{
    // cria a subarvore(folha) que contem o dado
    if (tarv_vazia(a))
    {
        return criaArvore(novoDado, NULL, NULL);
    }
    // procura o lugar para inserir a subarvore(folha)
    if (compara(a->dado, novoDado))
    {
        a->dir = insereArvore(a->dir, novoDado);
    }
    else
    {
        a->esq = insereArvore(a->esq, novoDado);
    }
    
    // retorna a arvore completa
    return a;
}

tArv *retiraArvore(tArv *a, int dado)
{
    if (!tarv_vazia(a))
    {
        if (ehIgual(a->dado, dado))
        {
            return a;
        }

        // procura o lugar para inserir a subarvore(folha)
        if (compara(a->dado, dado))
        {
            return retiraArvore(a->dir, dado);
        }
        else
        {
            return retiraArvore(a->esq, dado);
        }
    }
    return NULL;
}

tArv *liberaArvore(tArv *a)
{
    if (!tarv_vazia(a))
    {
        liberaArvore(a->esq);
        liberaArvore(a->dir);
        free(a);
    }
    return NULL;
}

tArv *buscaBinaria(tArv *a, int chaveBusca)
{
    if (tarv_vazia(a) || (a->dado == chaveBusca))
    {
        return a;
    }
    if (compara(a->dado, chaveBusca))
    {
        return buscaBinaria(a->dir, chaveBusca);
    }
    return buscaBinaria(a->esq, chaveBusca);
}

int main()
{
    // cria arvores
    tArv *root = criaArvore(50, NULL, NULL);

    root = insereArvore(root, 10);
    root = insereArvore(root, 20);
    root = insereArvore(root, 30);
    root = insereArvore(root, 40);
    root = insereArvore(root, 25);

    tArv *foundNode = buscaBinaria(root, 40);
    if (foundNode != NULL)
    {
        printf("Node found with value: %d\n", foundNode->dado);
    }
    else
    {
        printf("Node not found\n");
    }

    // testa funcionalidades
    imprimeArvore(root);
    //printf("\nQnt de folhas: %d\n", folhas(root));
    //printf("Altura: %d\n", altura(root));
    //printf("Ocorrencias: %d\n", ocorrencias(root, "nome1"));

    // libera estruturas e dados
    liberaArvore(root);

    return 0;
}
