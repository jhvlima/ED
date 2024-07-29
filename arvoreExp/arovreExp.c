/*
Implemente o TAD árvore binária de expressões aritméticas. Por exemplo, a expressão (6-
3)*(4+1)+5 é representada pela árvore binária ilustrada na figura abaixo. As folhas da árvore
armazenam operandos e os nós internos operadores. Se avaliada, a expressão desta árvore resulta
no valor 20.

Gere um arquivo arv_exp.c com sua implementação e envie pelo classroom.

Teste a sua implementação com o programa progarv_exp.c. Ambos os arquivos arv_exp.h e
progarv_exp.c estão disponíveis no classroom.
*/
#include "arvoreExp.h"
#include <stdio.h>
#include <stdlib.h>

/*Tipo que define a arvore(tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. */
struct arv
{
    Arv *esq;
    Arv *dir;
    int valor;
    char operador;
};

/*Cria uma arvore vazia, ou seja, retorna NULL
* inputs: nenhum
* output: NULL
*/
Arv* CriaVazia(void)
{
    Arv *novo = NULL;
    return novo;
}

/*cria um nó raiz de operador dados o operador e as duas sub-árvores, a da esquerda e a da direita
* inputs: o operador, as sub-arvores da esquerda e da direita
* output: o endereço do nó raiz criado
*/
Arv* CriaOperador(char c, Arv* e, Arv* d)
{
    Arv *novo = CriaVazia();
    novo = calloc(1, sizeof(Arv));
    novo->operador = c;
    novo->dir = d;
    novo->esq = e;
    novo->valor = 0;
    return novo;
}

/*cria um nó operando dado o valor do no (como o operando é um nó folha, as sub-arvores da esquerda e da direita são nulas
* inputs: o operando
* output: o endereço do nó raiz criado
*/
Arv* CriaOperando(int valor)
{
    Arv *novo = CriaVazia();
    novo = calloc(1, sizeof(Arv));
    novo->valor = valor;
    novo->operador = '\0';
    novo->dir = novo->esq = NULL;
    return novo;
}

/*Imprime a árvore em notação InOrder (esq, raiz, direita)
* inputs: o endereço da raiz da árvore
* output: nenhum
*/
void Imprime(Arv* arv)
{
    if (arv)
    {
        Imprime(arv->esq);
        if (arv->operador)
        {
            printf("%c", arv->operador);
        }
        if (arv->valor)
        {
            printf("%d", arv->valor);
        }
        Imprime(arv->dir);
    }
}

/* Libera memória alocada pela estrutura da árvore
as sub-árvores devem ser liberadas antes de se liberar o nó raiz
* inputs: o endereço da raiz da árvore
* output: uma árvore vazia, representada por NULL
*/
Arv* Libera (Arv* arv)
{
    if (arv)
    {
        Libera(arv->esq);
        Libera(arv->dir);
        free(arv);
    }
    return NULL;
}

float opera(char arvOp, float arvN1, float arvN2)
{
    if (arvOp == '+')
    {
        return arvN1 + arvN2;
    }
    if (arvOp == '-')
    {
        return arvN1 - arvN2;
    }
    if (arvOp == '*')
    {
        return arvN1 * arvN2;
    }
    if (arvOp == '/')
    {
        return arvN1 / arvN2;
    }
    else
    return 0;
}

/* Retorna o valor correspondente à avaliação da expressão representada na árvore
* inputs: o endereço da raiz da árvore
* output: o valor da expressão
*/
float Avalia(Arv* arv)
{
    if (!arv) return 0;

    if (!arv->esq && !arv->dir)
    {
        return arv->valor;
    }
    float valorEsq = Avalia(arv->esq);
    float valorDir = Avalia(arv->dir);
    return opera(arv->operador, valorEsq, valorDir);
}


/* Retorna o número de folhas da árvore
* inputs: o endereço da raiz da árvore
* output: o número de folhas
*/
int Folhas(Arv* arv)
{
    int soma = 0;
    if (arv->dir)
    {
        soma =+ Folhas(arv->dir);
    }
    if (arv->esq)
    {
        soma =+ Folhas(arv->esq);
    }
    return soma + 1;
}

/* Retorna a altura da árvore
* inputs: o endereço da raiz da árvore
* output: a altura da árvore
*/
int Altura(Arv* arv)
{
    if (!arv) 
    {
        return -1;
    }
    
    int alturaEsq = Altura(arv->esq);
    int alturaDir = Altura(arv->dir);

    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
}