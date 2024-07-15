#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore.h"

struct _tPalavra
{
    int ocorencia;
    char string[MAX];
};

struct _tArv
{
    tPalavra palavra;
    tArv *esq;
    tArv *dir;
};

tArv *criaArvoreVazia()
{
    return NULL;
}

static int taVazia(tArv *a)
{
    return a == NULL;
}

static int eIgual(char *p1, char *p2)
{
    return !strcmp(p1, p2);
}

tArv *buscaEIncrementaArvore(tArv *a, char* palavra)
{
    if (taVazia(a))
    {
        return a;
    }
    if (eIgual(a->palavra.string, palavra))
    {
        a->palavra.ocorencia++;
        return a;
    }

    buscaEIncrementaArvore(a->dir, palavra);
    buscaEIncrementaArvore(a->esq, palavra);
    return a;
}

void insereArvore(tArv *a, tArv *sub)
{

}

void imprimeArvore(tArv *a);

int palavrasDistintas(tArv *a)
{
    int soma = 0;
    if (!taVazia(a->dir))
    {
        soma = +folas(a->dir);
    }
    if (!taVazia(a->esq))
    {
        soma = +folas(a->esq);
    }
    return soma +1;
}

int totalOcorrencias(tArv *a);

int obtemOcorrencia(tArv *a);

char *obtemPalavra(tArv *a);

int maiorOcorrencia(tArv *a);

void liberaArvore(tArv *a);


void imprimeVetor(tPalavra *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%s %d\n", vetor[i]->string, vetor[i]->ocorencia);
    }
}

void preencheVetor(tArv *a, tPalavra *vetor, int tam)
{
    tArv *auxiliar = a;
    for (int i = 0; i < tam; i++)
    {
        vetor[i]->string = a->palavra.string;
        vetor[i]->ocorencia = a->palavra.ocorencia;
        
    }
}
