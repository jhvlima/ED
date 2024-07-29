#include "tabela.h"
#include <stdio.h>
#include <stdlib.h>
#define TAM 23

struct _tRede
{
    int next;
    int destination;
};

struct _tHash
{
    tRede *vetor[TAM];
};

int hash(int chave)
{
    return chave % TAM;
}

tHash *criaHash()
{
    tHash *tab = calloc(1, sizeof(tHash));
    return tab;
}

tHash *insereHash(tHash *tab, tRede *rede)
{
    int indice = hash(rede->destination);

    // aqui pode ser feito outro tratamento de colisao
    while (tab->vetor[indice] != NULL)
    {
        indice = (indice + 1) % TAM;
    }
    tab->vetor[indice] = rede;
    return tab;
}

tRede *buscaHash(tHash *tab, int destination)
{
    unsigned int indice = hash(destination);

    // aqui pode ser feito outro tratamento de colisao, que deve ser igual ao da funcao buscaHash 
    while (tab->vetor[indice] != NULL)
    {
        if (tab->vetor[indice]->destination == destination)
        {
            return tab->vetor[indice];
        }
        indice = (indice + 1) % TAM;
    }

    return NULL;
}

void liberaHash(tHash *tab)
{
    for (size_t i = 0; i < TAM; i++)
    {
        if (tab->vetor[i])
        {
            free(tab->vetor[i]);
        }
    }
    free(tab);
}

tRede *criaRede(int des, int next)
{
    tRede *nova = calloc(1, sizeof(tRede));
    nova->destination = des;
    nova->next = next;
    return nova;
}

int obtemNext(tRede *r)
{
    return r->next;
}

int obtemDestino(tRede *r)
{
    return r->destination;
}