#ifndef HASH
#define HASH
typedef struct _tHash tHash;

typedef struct _tRede tRede;

tHash *criaHash();

tHash *insereHash(tHash *tab, tRede *r);

void imprimeHash(tHash *tab);

void liberaHash(tHash *tab);

tRede *buscaHash(tHash *tab, int destination);

tRede *criaRede(int des, int next);

int obtemNext(tRede *r);
int obtemDestino(tRede *r);
#endif