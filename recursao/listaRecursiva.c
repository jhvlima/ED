/*

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _tLista tLista;

struct _tLista
{
    int dado;
    tLista *proximo;
};

tLista* criaLista()
{
    tLista *lista = calloc(1, sizeof(tLista));
    return lista;
}

void insereLista(tLista *lista, tLista *novo)
{
    // LISTA VAZIA
    if(!lista)
    {
        lista = novo;
    }

    // NORMAL
    if (!lista->proximo)
    {
        lista->proximo = novo;
    }

    insereLista(lista->proximo, novo);
}

tLista *retiraLista(tLista *lista, tLista *lixo)
{
    
}

void imprimeLista(tLista *lista)
{
    if(!lista)
    {
        return;
    }
    printf("%d", lista->dado);
    imprimeLista(lista->proximo);   
}

void destroiLista(tLista *lista)
{

}

int main()
{
    tLista *lista = criaLista();
    insereLista(lista);
    destroiLista(lista);
    return 0;
}