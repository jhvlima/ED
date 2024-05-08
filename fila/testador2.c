//
//  testador2.c
//  PostoSaude
//
//  Created by Patricia Dockhorn Costa on 14/07/22.
//
//  Testador 2 (vale até 8,0): Testa criação, inserção, impressão e liberação de memória

#include <stdio.h>
#include "posto.h"

int main(int argc, const char * argv[]) {

    //cria uma instância de um posto de saúde
    Posto* jcamburi = inicPosto("Posto de Jardim Camburi");
    
    //realiza as coletas de material para exame
    realizaColeta(jcamburi, "Patricia", 44);
    realizaColeta(jcamburi, "Joao", 64);
    realizaColeta(jcamburi, "Maria", 20);

    //imprime os dados do posto, não seguinte formato:
    /*Dados do Posto: Posto de Jardim Camburi
    Amostras não processadas
    Nome do dono da amostra: Joao, carga viral: 249, idade: 64, resultado: NEGATIVO
    Nome do dono da amostra: Patricia, carga viral: 807, idade: 44, resultado: NEGATIVO
    Nome do dono da amostra: Maria, carga viral: 73, idade: 20, resultado: NEGATIVO
     
     Amostras com resultados positivos

     Amostra com resultados negativos
     */
    imprimePosto(jcamburi);
    

    //libera toda a memória alocada
    liberaPosto(jcamburi);
    return 0;
}
