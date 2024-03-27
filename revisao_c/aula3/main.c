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
    Matriz *mat3 = inicializaMatriz(5, 5);

        for (int i = 0; i < recuperaNLinhas(mat1); i++)
        {
            for (int j = 0; j < recuperaNColunas(mat1); j++)
            {
                modificaElemento(mat1, i, j, i+j);
            }
        }

        for (int i = 0; i < recuperaNLinhas(mat2); i++)
        {
            for (int j = 0; j < recuperaNColunas(mat2); j++)
            {
                modificaElemento(mat2, i, j, i-j);
            }
        }

    Matriz *resultado = multiplicacao(mat1, mat2);    

    imprimeMatriz(mat1);
    imprimeMatriz(mat2);
    imprimeMatriz(resultado);

    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(resultado);
    
    return 0;
}
