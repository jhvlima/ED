#include <stdio.h>
//#include "aluno.h"

#ifndef tarvore
#define tarvore

typedef struct _tArv tArv;

typedef struct tAluno tAluno;

//Cria uma árvore vazia
tArv* tarv_criavazia (void);
//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
//tArv* tarv_cria (tAluno *aluno, tArv* e, tArv* d);
//libera o espaço de memória ocupado pela árvore a
tArv* tarv_libera (tArv* a);
//retorna true se a árvore estiver vazia e false
//caso contrário
int tarv_vazia (tArv* a);
//indica a ocorrência (1) ou não (0) do caracter c
int tarv_pertence (tArv* a, tAluno *aluno);
//imprime as informações dos nós da árvore
void tarv_imprime (tArv* a);

int folhas (tArv* a); //retorna o número de folhas da árvore
int ocorrencias (tArv* a , char* nome); //retorna o número de vezes que o aluno aparece na árvore
int altura (tArv* a); //retorna a altura da árvore

#endif