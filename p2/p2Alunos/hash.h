#ifndef TABELA
#define TABELA

typedef struct _tAluno tAluno;
typedef struct _has tHash;


tHash *cria();
tHash *insere(tHash *tab, tAluno *aluno);
tHash *busca(tHash *tab, char *nome);
void libera(tHash *tab);

tAluno *criaAluno(char nome);
void diario(tAluno *a, int aula, char presenca);

#endif