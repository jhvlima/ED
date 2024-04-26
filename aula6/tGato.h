#ifndef _tGato_
#define  _tGato_

#include <stdio.h>

typedef struct _tGato tGato;

tGato *inicGato(char *nome, int vibe);

void atribuiNivelAgressividadeGato(tGato *g, int vibeNova);

void imprimeGato(tGato *g);

void liberaGato(tGato *g);

#endif