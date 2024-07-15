#ifndef HASH
#define HASH
typedef struct _tHash tHash;

typedef struct _tRede tRede;

tHash iniciaHash();

tHash insereHash(tHash *tab, tRede *r);

void imprimeHash(tHash *tab);

void liberaHash(tHash *tab);

#endif