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
    IndicePilha Pilha1, Pilha2;
} TipoPilhaDupla;

typedef struct
{
    TipoItem *Item[MaxTam];
    IndicePilha Pilha[N];
} TipoPilhaMultipla;

TipoPilhaDupla *iniciaPilha()
{
    TipoPilhaDupla *P = (TipoPilhaDupla *)malloc(sizeof(TipoPilhaDupla));
    P->Pilha1.Base = 0;
    P->Pilha1.Topo = -1; /* cresce para a direita */
    P->Pilha2.Base = MaxTam - 1;
    P->Pilha2.Topo = MaxTam; /* cresce para a esquerda */
}

void adicionaPilha(TipoPilhaDupla *pilha)
{

}

void retiraPilha(TipoPilhaDupla *pilha, TipoItem* iten)
{

}