// overflow > topoP1 = topoP2-1
#include <stdio.h>

#define N 10
#define MaxTam 1000

typedef int TipoItem;

typedef struct
{
    int Topo, Base;
} IndicePilha;

typedef struct
{
    TipoItem *Item[MaxTam];
    IndicePilha Pilha[N];
} TipoPilhaMultipla;

