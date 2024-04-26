#ifndef _tCachorro_
#define  _tCachorro_

#include <stdio.h>

typedef struct _tCachorro tCachorro;

tCachorro *inicCachorro(char *nome, int vibe);

void atribuiNivelAgressividadeCachorro(tCachorro *c, int vibeNova);

void imprimeCachorro(tCachorro *c);

void liberaCachorro(tCachorro *c);

int verificaTemperamentoCachorro(tCachorro* c);

#endif