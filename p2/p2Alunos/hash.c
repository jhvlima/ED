#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

#define TAM 151

struct _tAluno
{
    char nome[100];
    int presenca[100];
};

struct _has
{
    tAluno vetor[100];
};


tHash *cria()
{
    tHash *tab = calloc(1, sizeof(tHash));
}

int hash(int key)
{
    return key % TAM;
}

tHash *insere(tHash *tab, tAluno *aluno)
{
    int indice = hash((int)(aluno->nome) % TAM);
    while (tab->vetor[indice] != NULL)
    {
        indice = indice + hash(indice+1);
    }
    tab->vetor[indice] = aluno;
    return tab;
}

tAluno *busca(tHash *tab, char *nome)
{
    int indice = hash((int)(aluno->nome) % TAM);
    while (tab->vetor[indice] != NULL)
    {
        tab->vetor;
    }
    return tab->vetor[indice];
}

void libera(tHash *tab)
{
    free(tab);
}

tAluno *criaAluno(char nome)
{
    tAluno *a = calloc(1, sizeof(tAluno));
    a->nome = strdup(nome);
    return a;
}


#define F 0
#define P 1

void diario(tAluno *a, int aula, char presenca)
{
    if (presenca == 'F')
    {
        a->presenca[aula] = F;
    }
    else
    {
        a->presenca[aula] = T;
    }
}