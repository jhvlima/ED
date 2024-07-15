#ifndef ARV
#define ARV

typedef struct _tPalavra tPalavra;

typedef struct _tArv tArv;

#define MAX 128

tArv *criaArvoreVazia();

tArv *buscaEIncrementaArvore(tArv *a, char* palavra);

void insereArvore(tArv *a, tArv *sub);

void imprimeArvore(tArv *a);

int palavrasDistintas(tArv *a);

int totalOcorrencias(tArv *a);

int obtemOcorrencia(tArv *a);

char *obtemPalavra(tArv *a);

int maiorOcorrencia(tArv *a);

void imprimeVetor(tPalavra *vetor, int tam);

#endif