#ifndef ARV
#define ARV

typedef struct _tPalavra tPalavra;

typedef struct _tArv tArv;

#define MAX 128

tArv *criaArvoreVazia();

tArv *buscaEIncrementaArvore(tArv *a, char* palavra);

tArv *insereArvore(tArv *a, tPalavra* palavra);

void imprimeArvore(tArv *a);

// qnt de arvores
int palavrasDistintas(tArv *a);

// soma de todas ocorrencias
int totalOcorrencias(tArv *a);

int obtemOcorrencia(tArv *a);

char *obtemPalavra(tArv *a);

// 
int maiorOcorrencia(tArv *a);

void imprimeVetor(tPalavra *vetor, int tam);

#endif