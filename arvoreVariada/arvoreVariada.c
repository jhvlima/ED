/* Implementar uma árvore com número variável de filhos, como nos slides.
Além das funcionalidades básicas (criação, impressão, busca, liberação), implementar as seguintes funcionalidades:
calcular a altura da árvore; calcular o número de nós folha de uma árvore; e calcular o número de nós com apenas um filho. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct _tAluno
{
    char *nome;
};

void liberaAluno(void *a)
{
    tAluno *aluno = (tAluno*)a;
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
        printf(" |%s| ", aluno->nome);
    }
}

int ehIgual(tAluno *a1, char *a2)
{
    return !strcmp(a1->nome, a2);
}

/*--------------------------------------------| Estrutura de Arvore Variada |---------------------------------------------------*/

struct _tArv
{
    tAluno *dado;
    tArv *listaFilhos; // na verdade é o primeiro filho
    tArv *listaIrmaos; // na verdade é o primeiro irmao
};

//Cria uma árvore vazia
tArv* tarv_criavazia (void)
{
    return NULL;
}

//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
tArv* tarv_cria (tAluno *aluno)
{
    tArv *novo = calloc(1, sizeof(tArv));
    novo->dado = aluno;
    novo->listaFilhos = NULL;
    novo->listaIrmaos = NULL;
    return novo;
}

//insere uma nova sub-árvore como filha de um dado nó, sempre no início da lista, por simplicidade
void tarv_insere (tArv* a, tArv* filho)
{
    filho->listaIrmaos = a->listaFilhos;
    a->listaFilhos = filho;
}


//libera o espaço de memória ocupado pela árvore a
tArv* tarv_libera (tArv* a)
{
    tArv *primogenito = a->listaFilhos;
    while(primogenito != NULL)
    {        
        tArv *auxiliar = primogenito->listaIrmaos;
        tarv_libera(primogenito);
        primogenito = auxiliar;
    }
    liberaAluno(a->dado);
    free(a);
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
    tArv *primogenito;
    if (ehIgual(a->dado, chave->nome))
    {
        return 1;
    }
    else
    {
        for (primogenito = a->listaFilhos; primogenito != NULL; primogenito->listaIrmaos)
        {
            if(tarv_pertence(primogenito, chave))
            {
                return 1;
            }
        }
    }
    return 0;
}

//imprime as informações dos nós da árvore
void tarv_imprime (tArv* a)
{
    tArv *primogenito;
    if (!tarv_vazia(a))
    {        
        printf("<");
        imprimeAluno(a->dado);

        for (primogenito = a->listaFilhos; primogenito != NULL; primogenito = primogenito->listaIrmaos)
        {
            tarv_imprime(primogenito);
        }

        printf(">");
    }
}

int folhas (tArv* a) //retorna o número de folhas da árvore
{
    int soma = 0;

    if (!tarv_vazia(a->listaFilhos))
    {
        soma =+ folhas(a->listaFilhos);
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

        soma = ocorrencias(a->listaFilhos, nome);
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

    if (!tarv_vazia(a->listaFilhos))
    {
        maximoDir =+ 1 +altura(a->listaFilhos);
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

    printf("COMECANDO O PROGRAMA\n");

/*  cria arvores binarias
    tArv *folha1 = tarv_cria(a1);
    tarv_insere(folha1, tarv_criavazia());
    printf("INSERIDO 1 COM SUCESSO\n");

    tArv *folha2 = tarv_cria(a2);
    tarv_insere(folha2, tarv_criavazia());
    printf("INSERIDO 2 COM SUCESSO\n");

    tArv *galho3 = tarv_cria(a3);


    tArv *galho4 = tarv_cria(a4);
    tarv_insere(galho4, tarv_criavazia());

    tArv *root = tarv_cria(a5);
    tarv_insere(root, galho3);
    tarv_insere(root, galho4);
*/

    // cria arvores variadas 
    tArv *folha1 = tarv_cria(a1);
    tArv *folha2 = tarv_cria(a2);
    tArv *galho3 = tarv_cria(a3);
    tArv *folha4 = tarv_cria(a4);
    tArv *root = tarv_cria(a5);

    tarv_insere(galho3, folha1);
    tarv_insere(galho3, folha2);

    tarv_insere(root, galho3);
    tarv_insere(root, folha4);

    // testa funcionalidades (tem que consertar isso)
    tarv_imprime(root);
    //printf("\nQnt de folhas: %d\n", folhas(root));
    //printf("Altura: %d\n", altura(root));
    //printf("Ocorrencias: %d\n", ocorrencias(root, "nome1"));

    // libera estruturas e dados
    tarv_libera(root);

    return 0;
}
