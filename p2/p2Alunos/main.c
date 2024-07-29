#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"


int main()
{

    // primeirp arquivo
    FILE *ptr = fopen("entrada.txt", "r");
    if (ptr == NULL)
    {
        printf("no such file.");
        return 0;
    }
    int qntAulas = 0;
    char nome[100];

    tHash *tab = cria();

    fscanf(ptr, "%*c %d%*c", &qntAulas);
    while (fscanf(ptr, "%s %*c", nome) != EOF)
    {
        tAluno *aluno = criaAluno(nome);
        tab = insere(tab, aluno);
    }
    fclose(ptr);

    for (size_t i = 0; i < qntAulas; i++)
    {
        // pra cada arquivo de aula
        char nomeArquivo[100] = {"entrada"};
        sprintf(nomeArquivo, "%d.txt", i);
        FILE *ptr = fopen(nomeArquivo, "r");
        if (ptr == NULL)
        {
            printf("NAO ABRIU ARQUIVO: %s",nomeArquivo);
            return 0;
        }
        char nome[100];
        char presenca;
        while (fscanf(ptr, "%s %c", nome, &presenca) == 2)
        {
            tAluno *aluno = busca(tab, nome);
            diario(aluno, i, presenca);
        }
    }

    

    return 0;
}