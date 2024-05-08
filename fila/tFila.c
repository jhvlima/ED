#include "tFila.h"
#include "amostra.h"

typedef struct _tCelula
{
    Amostra *amostra; 
}tCelula;

struct _tFila
{
    tCelula *primeiraCelula;
    tCelula *primeiraCelula;
};

tFila *criaFila();

void *insereFila(tFila *fila);

void retiraFila(tFila *fila);

void liberaFila(tFila *fila);
