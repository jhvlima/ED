// overflow > topoP1 = topoP2-1
#include <stdio.h>

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

TipoPilhaDupla *iniciaPilha()
{
    TipoPilhaDupla *P = (TipoPilhaDupla *)calloc(1, sizeof(TipoPilhaDupla));
    P->Pilha1.Base = 0;
    P->Pilha1.Topo = -1; /* cresce para a direita */
    P->Pilha2.Base = MaxTam - 1;
    P->Pilha2.Topo = MaxTam; /* cresce para a esquerda */
}

void adicionaPilha(TipoPilhaDupla *pilha)
{
    // pilha vazia
    if (pilha->Pilha1)
    {
        /* code */
    }
    
    // insere no inicio

}

void retiraPilha(TipoPilhaDupla *pilha)
{
    // retira no inicio

}