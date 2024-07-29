/*
> Refatore o exercício 15 de forma a utilizar uma Tabela Hash Genérica!

obs1.: na última aula eu falei um pouco sobre tabela hash genérica...
As funções de hash e comparação precisam ser definidas como callback.

obs2: caso seja utilizado tratamento de colisão por lista encadeada, a lista precisa ser genérica também.
No caso de tratamento de colisão na própria tabela, o tad Hash genérico já dá conta de implementar todas as funcionalidades.

####### possibilidade de definição de TAD #############
typedef struct hash Hash;

Hash* cria (int tam, size_t tam_item);
void* busca (Hash* hash, void* key, int (*fhash)(void*), int (*comp)(void*,void*));
void* hash_insere (Hash* thash, void* key, void* objeto, int (*hash)(void*), int(*comp)(void*,void*));
void libera(Hash* table);

*/