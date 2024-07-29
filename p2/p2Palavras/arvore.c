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
    if (eIgual(a->palavra->string, palavra))
    {
        a->palavra->ocorencia++;
        return a;
    }

    buscaEIncrementaArvore(a->dir, palavra);
    buscaEIncrementaArvore(a->esq, palavra);
    return a;
}

tArv *insereArvore(tArv *a, tPalavra *palavra)
{
    if (taVazia(a))
    {
        tArv *novo = calloc(1, sizeof(tArv));
        novo->dir = novo->esq = NULL;
        memcpy(novo->palavra, palavra, sizeof(tPalavra));
        return novo;
    }
    if (a->palavra.ocorencia < palavra->ocorencia)
    {
        a->esq = insereArvore(a->esq, palavra);
    }
    else
    {
        a->dir = insereArvore(a->dir, palavra);
    }
    return a;    
}

void imprimeArvore(tArv *a);

int palavrasDistintas(tArv *a)
{
    int soma = 0;
    if (!taVazia(a->dir))
    {
        soma = +palavrasDistintas(a->dir);
    }
    if (!taVazia(a->esq))
    {
        soma = +palavrasDistintas(a->esq);
    }
    return soma +1;
}

int totalOcorrencias(tArv *a)
{
    int soma = 0;
    if (!taVazia(a->dir))
    {
        soma = +totalOcorrencias(a->dir);
    }
    if (!taVazia(a->esq))
    {
        soma = +totalOcorrencias(a->esq);
    }
    return soma + obtemOcorrencia(a);
}

int obtemOcorrencia(tArv *a)
{
    return a->palavra.ocorencia;
}

char *obtemPalavra(tArv *a)
{
    return a->palavra.string;
}

int maiorOcorrencia(tArv *a)
{
    int atual = 0, dir = 0, esq = 0;
    if (taVazia(a))
    {
        return 0;
    }

    atual = obtemOcorrencia(a);
    
    if (!taVazia(a->dir))
    {
        dir = maiorOcorrencia(a->dir);
    }
    if (!taVazia(a->esq))
    {
        esq = maiorOcorrencia(a->esq);
    }
    
    if (dir>esq)
    {
        if (dir > atual)
        {
            return dir;
        }
    }
    else
    {
        if (esq > atual)
        {
            return esq;
        }
    }
    return atual;
}

void liberaArvore(tArv *a)
{
    if (!taVazia(a))
    {
        liberaArvore(a->dir);
        liberaArvore(a->esq);
        free(a);
    }
}


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
