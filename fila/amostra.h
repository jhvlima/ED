//
//  amostra.h
//  PostoSaude
//
//  Created by Patricia Dockhorn Costa on 14/07/22.
//

#ifndef amostra_h
#define amostra_h

//Definem o significado do atributo numérico "resultado" da amostra
#define POSITIVO 1
#define NEGATIVO 0

#include <stdio.h>

//Tipo opaco que define a amostra para testagem
typedef struct amostra Amostra;

//Cria uma nova amostra, cujo dono tem um nome e uma idade
//Essa função gera um valor aleatório entre 0 e 1000 para simular a carga viral de uma pessoa
Amostra* inicAmostra(char* nome, int idade);

//Registra o valor do resultado do teste na amostra
void registraResultado(Amostra* amostra, int resultado);

//Imprime os dados da amostra no formato:
//Nome do dono da amostra: Patricia, carga viral: 807, idade: 44, resultado: POSITIVO
void imprimeAmostra(Amostra* amostra);

//Retorna o valor da carga viral de uma amostra
int retornaCargaViral(Amostra* amostra);

//Retorna a idade do dono da amostra
int retornaIdade(Amostra* amostra);

//libera todoas os dados alocados para a amostra
void liberaAmostra(Amostra* amostra);

#endif /* amostra_h */
