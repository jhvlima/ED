#include "tabela.h"

#define TAM 23

struct _tRede
{
    int next;
    int destination;
};

struct _tHash
{
    tRede *vetor[TAM];
};

int hash(tRede *chave)
{
    return chave->destination % TAM;
}

tHash *criaHash(int tamTab, size_t tam)
{

}

tHash insereHash(tHash *tab, tRede *rede)
{

}

tRede *buscaHash(tHash *tab, tRede *redeDestino)
{
    int indice = hash(redeDestino->destination);
    while(tab[indice] != NULL)
    {
        if(tab[indice] == redeDestino->destination)
        {
            return tab[indice];
        }
        h = (h + 1) % TAM;
    }
    return NULL;
}

void liberaHash(tHash *tab)
{

}

