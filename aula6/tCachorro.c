#include "tCachorro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MANSO 1
#define AGRESSIVO 2

typedef struct _tCachorro
{
    char *nome;
    int vibe;
}tCachorro;

tCachorro *inicCachorro(char *nome, int vibe)
{
    tCachorro *g = malloc(sizeof(tCachorro*));
    g->nome = strdup(nome);
    g->vibe = vibe;
}

void atribuiNivelAgressividadeCachorro(tCachorro *g, int vibeNova)
{
    g->vibe = vibeNova;
}

void imprimeCachorro(tCachorro *g)
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

void liberaCachorro(tCachorro *g)
{
    if(g)
    {
        free(g->nome);
        free(g);
    }
}

int verificaTemperamentoCachorro(tCachorro* c)
{
    return c->vibe;
}