#include "tGato.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _tGato
{
    char *nome;
    int vibe;
}tGato;

tGato *inicGato(char *nome, int vibe)
{
    tGato *g = malloc(sizeof(tGato*));
    g->nome = strdup(nome);
    g->vibe = vibe;
}

void atribuiNivelAgressividadeGato(tGato *g, int vibeNova)
{
    g->vibe = vibeNova;
}

void imprimeGato(tGato *g)
{
    printf("%s", g->nome);
    if(g->vibe == MANSO)
    {
        printf("manso");
    }
    else
    {
        printf("agressivo");
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