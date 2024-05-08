//
//  amostra.c
//  PostoSaude
//
//  Created by Patricia Dockhorn Costa on 14/07/22.
//

#include "amostra.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct amostra{
    char* nome;
    int idade;
    int resultado;
    int carga_viral;
};

Amostra* inicAmostra(char* nome, int idade){
    Amostra* amostra = malloc(sizeof(Amostra));
    amostra->idade = idade;
    amostra->nome = strdup(nome);
    amostra->resultado = -1; //ainda sem resultados
    
    //inventa uma carga viral, para testes...
    amostra->carga_viral = rand()%1000;

    return amostra;
}

int retornaIdade(Amostra* amostra){
    return amostra->idade;
}

int retornaCargaViral(Amostra* amostra){
    return amostra->carga_viral;
}

void registraResultado(Amostra* amostra, int resultado){
    amostra->resultado = resultado;
}

void imprimeAmostra(Amostra* amostra){
    
    if (amostra->resultado)
        printf ("Nome do dono da amostra: %s, carga viral: %d, idade: %d, resultado: POSITIVO\n", amostra->nome, amostra->carga_viral, amostra->idade);
    else
        printf ("Nome do dono da amostra: %s, carga viral: %d, idade: %d, resultado: NEGATIVO\n", amostra->nome, amostra->carga_viral, amostra->idade);
}

void liberaAmostra(Amostra* amostra){
    free(amostra->nome);
    free(amostra);
}
