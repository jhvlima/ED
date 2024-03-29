#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

//Tipo matriz (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementaÁ„o do TAD
typedef struct matriz 
{
    int nLinhas, nColunas;
    int **elemento;   
}Matriz;

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas)
{
    if (!(nlinhas) && !(ncolunas))
    {
        return NULL;
    }
    
    Matriz *mat = malloc(sizeof(*mat));
    mat->elemento = malloc(nlinhas * sizeof(int*));
    for (int i = 0; i < nlinhas; i++)
    {
        mat->elemento[i] = malloc(ncolunas * sizeof(int));
    }
    
    mat->nColunas = ncolunas;
    mat->nLinhas = nlinhas;

    return mat;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna s„o v·lidos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
    if (mat)
    {
        mat->elemento[linha][coluna] = elem;
    }
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna s„o v·lidos na matriz
 * pos-condicao: mat n„o È modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna)
{
    if (mat)
    {
        return mat->elemento[linha][coluna];
    }
}

/*Retorna o n˙mero de colunas da matriz mat
 * inputs: a matriz
 * output: o n˙mero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada
 */
int recuperaNColunas (Matriz* mat)
{
    if (mat)
    {
        return mat->nColunas;
    }
}

/*Retorna o n˙mero de linhas da matriz mat
 * inputs: a matriz
 * output: o n˙mero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada
 */
int recuperaNLinhas (Matriz* mat)
{
    if (mat)
    {
        return mat->nLinhas;
    }
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat)
{
    if (mat)
    {
        Matriz *trans = inicializaMatriz(recuperaNColunas(mat), recuperaNLinhas(mat));
        for (int i = 0; i < recuperaNLinhas(mat); i++)
        {
            for (int j = 0; j < recuperaNColunas(mat); j++)
            {
                modificaElemento(trans, j, i, recuperaElemento(mat, i, j));
            }
        }
        return trans;
    }
}
/* code */
/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicaÁ„o
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1
 * correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 n„o s„o modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2)
{
    if (recuperaNLinhas(mat2) == recuperaNColunas(mat1))
    {
        Matriz *resultado = inicializaMatriz(recuperaNLinhas(mat1), recuperaNColunas(mat2));

        for (int i = 0; i < recuperaNLinhas(mat1); i++)
        {
            for (int j = 0; j < recuperaNColunas(mat2); j++)
            {
                int soma = 0;
                for (int k = 0; k < recuperaNColunas(mat1); k++)
                {
                    soma += mat1->elemento[i][k] * mat2->elemento[k][j];
                }
                resultado->elemento[i][j] = soma;
            }
        }
        return resultado;
    }
    return NULL;
}

/*Imprime a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat)
{
    if (mat)
    {
        for (int i = 0; i < recuperaNLinhas(mat); i++)
        {
            for (int j = 0; j < recuperaNColunas(mat); j++)
            {
                printf("|%d|", mat->elemento[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void imprimeLinhas (Matriz* mat, int indice)
{
    if (mat)
    {
        for (int i = 0; i < recuperaNColunas(mat); i++)
        {
            printf("|%d|", mat->elemento[indice][i]);
        }
    }
}

void destroiMatriz (Matriz* mat)
{
    if (mat)
    {
        for (int i = 0; i < recuperaNLinhas(mat); i++)
        {
            free(mat->elemento[i]);
        }
        free(mat->elemento);
        free(mat);
    }
    
}