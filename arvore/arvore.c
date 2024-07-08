/*
    Implemente o TAD árvore da aula passada com a seguinte modificação:
        faça um TAD árvore de alunos (e não de char, como na aula). Use o nome do aluno como chave de busca na função pertence. Além disto, faça as funções:
            - int folhas (tArv* a); //retorna o número de folhas da árvore
            - int ocorrencias (tArv* a , char* nome); //retorna o número de vezes que o aluno aparece na árvore
            - int altura (tArv* a); retorna a altura da árvore

    Inclua todos os arquivos (.c e .h) que você utilizou para fazer este exercício, incluindo os testadores!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct _tAluno
{
    char *nome;
};

void liberaAluno(tAluno *aluno)
{
    if (aluno)
    {
        free(aluno->nome);
        free(aluno);
    }
}

void imprimeAluno(tAluno *aluno)
{
    if (aluno)
    {
        printf("|%s| ", aluno->nome);
    }
}

int ehIgual(tAluno *a1, char *a2)
{
    return !strcmp(a1->nome, a2);
}

////////////////////////////////////////////////////////////////////////

struct _tArv
{
    tAluno *dado;
    tArv *esq;
    tArv *dir;
};

//Cria uma árvore vazia
tArv* tarv_criavazia (void)
{
    return NULL;
}

//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
tArv* tarv_cria (tAluno *aluno, tArv* e, tArv* d)
{
    tArv *novo = calloc(1, sizeof(tArv));
    novo->dado = aluno;
    novo->dir = d;
    novo->esq = e;
    return novo;
}

//libera o espaço de memória ocupado pela árvore a
tArv* tarv_libera (tArv* a)
{
    if (!tarv_vazia(a))
    {
        tarv_libera(a->esq);
        tarv_libera(a->dir);
        liberaAluno(a->dado);
        free(a);
    }
    return NULL;
}

//retorna true se a árvore estiver vazia e false
//caso contrário
int tarv_vazia (tArv* a)
{
   return a == NULL;
}

//indica a ocorrência (1) ou não (0) do caracter c
int tarv_pertence (tArv* a, tAluno *chave)
{
    if (tarv_vazia(a))
    {
        return 0;
    }
    else
    {
        return ehIgual(a->dado, chave->nome) || tarv_pertence(a->esq, chave) || tarv_pertence(a->dir, chave);
    }
}

//imprime as informações dos nós da árvore
void tarv_imprime (tArv* a)
{
    if (!tarv_vazia(a))
    {
        // rever essa impresao com <>
        imprimeAluno(a->dado);
        printf("< ");
        tarv_imprime(a->esq);
        printf(" >");
        tarv_imprime(a->dir);
    }
}

int folhas (tArv* a) //retorna o número de folhas da árvore
{
    int soma = 0;
  
    if (!tarv_vazia(a->dir))
    {
        soma =+ folhas(a->dir);
    }

    if (!tarv_vazia(a->esq))
    {
        soma =+ folhas(a->esq);
    }

    return soma + 1;
}

int ocorrencias (tArv* a , char* nome) // retorna o número de vezes que o aluno aparece na árvore
{
    int soma = 0;
    if (!tarv_vazia(a))
    {
        // rever essa impresao com <>
        if (ehIgual(a->dado, nome))
        {
            return soma +1;
        }

        soma = ocorrencias(a->esq, nome) + ocorrencias(a->dir, nome);
    }
    return soma;
}

int altura (tArv* a) //retorna a altura da árvore
{
    if (tarv_vazia(a))
    {
        return -1;
    }

    int  maximoDir = 0, maximoEsq = 0;

    if (!tarv_vazia(a->dir))
    {
        maximoDir =+ 1 +altura(a->dir);
    }

    if (!tarv_vazia(a->esq))
    {
        maximoEsq =+ 1 + altura(a->esq);
    }

    if (maximoDir > maximoEsq)
    {
        return maximoDir;
    }
    return maximoEsq;
}

int main ()
{
    // cria alunos
    tAluno *a1 = calloc(1, sizeof(tAluno));
    a1->nome = strdup("nome1");

    tAluno *a2 = calloc(1, sizeof(tAluno));
    a2->nome = strdup("nome2");

    tAluno *a3 = calloc(1, sizeof(tAluno));
    a3->nome = strdup("nome3");

    tAluno *a4 = calloc(1, sizeof(tAluno));
    a4->nome = strdup("nome4");

    tAluno *a5 = calloc(1, sizeof(tAluno));
    a5->nome = strdup("nome5");

    // cria arvores
    tArv *folha1 = tarv_cria(a1, NULL, NULL);
    tArv *folha2 = tarv_cria(a2, NULL, NULL);

    tArv *galho3 = tarv_cria(a3, folha1, folha2);
    tArv *galho4 = tarv_cria(a4, NULL, NULL);

    tArv *root = tarv_cria(a5, galho3, galho4);

    // testa funcionalidades
    tarv_imprime(root);
    printf("\nQnt de folhas: %d\n", folhas(root));
    printf("Altura: %d\n", altura(root));
    printf("Ocorrencias: %d\n", ocorrencias(root, "nome1"));

    // libera estruturas e dados
    tarv_libera(root);

    return 0;
}
