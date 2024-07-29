#ifndef lista
#define lista

typedef struct _tAluno tAluno;
typedef struct _tLista tLista;


tAluno *criaLista();
tLista *insereLista(tLista *lista, tAluno *aluno);
void liberaLista(tLista *lista);

#endif