#include "tGato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MANSO 1
#define AGRESSIVO 2

typedef struct _tGato
{
    char *nome;
    int vibe;
}tGato;

tGato *inicGato(char *nome, int vibe)
{
    tGato *g = malloc(sizeof(tGato));
    g->nome = strdup(nome);
    g->vibe = vibe;
}

void atribuiNivelAgressividadeGato(tGato *g, int vibeNova)
{
    g->vibe = vibeNova;
}

void imprimeGato(tGato *g)
{
    printf("%s\t", g->nome);
    if(g->vibe == MANSO)
    {
        printf("VIBE: manso\n");
    }
    else
    {
        printf("VIBE: agressivo\n");
    }
}

void liberaGato(tGato *g)
{
    if(g)
    {
        free(g->nome);
        free(g);
    }
}

int verificaTemperamentoGato(tGato* c)
{
    return c->vibe;
}