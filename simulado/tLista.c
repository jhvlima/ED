#include "pedido.h"
#include "produto.h"
#include "tLista.h"


typedef struct tcelula
{
    tCelula *proxima;
    TProduto *produto;
} tCelula;


struct tlista
{
    tCelula *primeira;
    tCelula *ultima;

};

tLista *inicializaLista()
{
    tLista *l = calloc(1, sizeof(tLista));
    return l;
}

void insereLista(tLista *lista, TProduto *prod)
{
    tCelula *cel = calloc(1, sizeof(tCelula));
    cel->produto = prod;
    cel->proxima = NULL;
    if (lista->ultima == NULL)
    {
        lista->primeira = lista->ultima = cel;
    }
    lista->ultima->proxima = cel;
}

void retiraLista(tLista *lista, char *prod)
{
    tCelula *cel, *ant;
    cel = lista->primeira;

    while (cel)
    {
    
        // uma celula
        if (RetornaNome(prod) == RetornaNome(lista->ultima->produto) && RetornaNome(prod) == RetornaNome(lista->primeira->produto))
        {
            /* code */
        }
        
        // primeira celula
        if (RetornaNome(prod) == RetornaNome(lista->primeira->produto))
        {
            /* code */
        }

        // ulitima celula
        if (RetornaNome(prod) == RetornaNome(lista->ultima->produto))
        {

        }
        
        // caso comum


        cel = cel->proxima;
    }
}

void imprimeLista(tLista *lista);


