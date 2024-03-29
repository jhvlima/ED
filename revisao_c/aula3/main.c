/*
1) Implemente o TAD Matriz que está especificado no arquivo matriz.h. Gere um arquivo matriz.c com sua implementação. 

2) Faça um testador (cliente.c) que teste todas as funcionalidades do TAD Matriz:
- Inicialize 2 ou mais matrizes;
- Insira dados;
- Imprima as matrizes;
- Verifique as funcionalidades de transposta e multiplicação;
- Libere toda a memória alocada.

Tente implementar o TAD de forma incremental, ao invés de fazer tudo de uma vez e testar somente no final. 
Use o Valgrind para verificar o uso correto da memória.  
*/
#include <stdio.h>
#include "matriz.h"

int main(int argc, char const *argv[])
{
    Matriz *mat1 = inicializaMatriz(3, 2);
    Matriz *mat2 = inicializaMatriz(2, 3);
    Matriz *mat3 = inicializaMatriz(4, 4);

// insere elementos da mat1
    for (int i = 0; i < recuperaNLinhas(mat1); i++)
    {
        for (int j = 0; j < recuperaNColunas(mat1); j++)
        {
            modificaElemento(mat1, i, j, i+j);
        }
    }
// insere elementos da mat2
    for (int i = 0; i < recuperaNLinhas(mat2); i++)
    {
        for (int j = 0; j < recuperaNColunas(mat2); j++)
        {
            modificaElemento(mat2, i, j, i-j);
        }
    }

// insere elementos da mat3
    for (int i = 0; i < recuperaNLinhas(mat3); i++)
    {
        for (int j = 0; j < recuperaNColunas(mat3); j++)
        {
            modificaElemento(mat3, i, j, i-j);
        }
    }

    Matriz *resultado = multiplicacao(mat1, mat2);    
    Matriz *trans = transposta(mat3);

    printf("matriz 1\n");
    imprimeMatriz(mat1);
    printf("matriz 2\n");
    imprimeMatriz(mat2);
    printf("matriz produto matriz 1 por matriz 2\n");
    imprimeMatriz(resultado);
    printf("matriz 3\n");
    imprimeMatriz(mat3);
    printf("matriz 3 trasnposta\n");
    imprimeMatriz(trans);

    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(mat3);
    destroiMatriz(resultado);
    destroiMatriz(trans);
    return 0;
}
