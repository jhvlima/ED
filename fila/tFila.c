#include <stdio.h>
#include <stdlib.h>
#include "tFila.h"
#include "amostra.h"

typedef struct _tCelula tCelula;
struct _tCelula
{
    Amostra *amostra;
    tCelula *proxima;
};

struct _tFila
{
    tCelula *primeira;
    tCelula *ultima;
};

tFila *criaFila()
{
    tFila *f = calloc(1, sizeof(tFila));
    return f;
}

void insereFila(tFila *fila, Amostra *amostra)
{
    tCelula *cel = calloc(1, sizeof(tCelula));
    cel->amostra = amostra;
    cel->proxima = NULL;

    if (fila->primeira == NULL)
    {
        fila->primeira = fila->ultima = cel;
        return;
    }

    // se tem prioridade insere no inicio
    if (retornaIdade(amostra) > 60)
    {
        if (fila->ultima == NULL)
        {
            fila->ultima = cel;
        }
        else
        {
            cel->proxima = fila->primeira;
        }
        fila->primeira = cel;        
    }
    
    // se nao tem prioridade inserno final
    else
    {
        fila->ultima->proxima = cel;
        fila->ultima = cel;        
    }
}

void retiraFila(tFila *fila)
{
    if (fila->primeira == NULL)
    {
        return;
    }
    // retira do inicio
    tCelula *cel = fila->primeira;
    fila->primeira = fila->primeira->proxima;
    if (fila->primeira == NULL)
    {
        fila->ultima = NULL;
    }
    free(cel);
}

void liberaFila(tFila *fila)
{
    tCelula *cel = fila->primeira;
    while (cel)
    {
        tCelula *temp = cel;
        cel = cel->proxima;
        liberaAmostra(temp->amostra);
        free(temp);
    }
    free(fila);
}

void imprimeFila(tFila *fila)
{
    tCelula *cel = fila->primeira;
    while (cel)
    {
        imprimeAmostra(cel->amostra);
        cel = cel->proxima;
    }    
}

Amostra *retornaPrimeiraAmostra(tFila *f)
{
    if (f->primeira == NULL)
    {
        return NULL;
    }
    return f->primeira->amostra;
}

Amostra *retornaProximaAmostra(tFila *fila, Amostra *a)
{
    if (fila == NULL || fila->primeira == NULL)
    {
        return NULL;
    }
    
    tCelula *cel = fila->primeira;
    while (cel)
    {
        if (cel->amostra == a)
        {
            if (cel->proxima == NULL)
            {
                return NULL; // 'a' is the last element
            }
            return cel->proxima->amostra;
        }
        cel = cel->proxima;
    }
    return NULL;
}