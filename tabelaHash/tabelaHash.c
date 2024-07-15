/*
Implemente um programa para contar o número de vezes que uma palavra aparece em um arquivo de entrada. 
Seu programa deve ler um arquivo texto e retornar, no terminal, as palavras seguidas do número de ocorrências dessas palavras no arquivo. 
Use uma TABELA HASH para manter as palavras e contar o número de ocorrências. Implemente: TadPalavra, TadHash e um cliente.
*/

#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

struct _tHash
{

}; 

tHash *criatHash();

tHash *imprimetHash(tHash *t);

tHash *liberatHash(tHash *t);
