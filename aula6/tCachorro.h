#ifndef _tCachorro_
#define  _tCachorro_

#include <stdio.h>

typedef func *imprimeCachorro;
typedef struct _tCachorro tCachorro;

tCachorro *inicCachorro(char *nome, int vibe);

void atribuiNivelAgressividadeCachorro(tCachorro *c, int vibeNova);

void imprimeCachorro(tCachorro *c);

void liberaCachorro(tCachorro *c);

#endif