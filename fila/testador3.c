//
//  testador3.c
//  PostoSaude
//
//  Created by Patricia Dockhorn Costa on 14/07/22.
//
//  Testador 3 (vale até 10,0): Testa criação, inserção, impressão, retirada e liberação de memória

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
    
    //processa as amostras do posto de jardim camburi
    //somente as amostras que ainda não foram processadas
    processaLoteAmostras(jcamburi);
    
    /*
    Dados do Posto: Posto de Jardim Camburi
    Amostras não processadas

    Amostras com resultados positivos
    Nome do dono da amostra: Patricia, carga viral: 807, idade: 44, resultado: POSITIVO

    Amostra com resultados negativos
    Nome do dono da amostra: Joao, carga viral: 249, idade: 64, resultado: NEGATIVO
    Nome do dono da amostra: Maria, carga viral: 73, idade: 20, resultado: NEGATIVO */
    imprimePosto(jcamburi);
    
    
    //A seguir, usa o Posto de jardim da penha como exemplo
    //O processo é similar ao anterior...
    
    Posto* jPenha = inicPosto("Posto de Jardim da Penha");
    
    realizaColeta(jPenha, "A", 23);
    realizaColeta(jPenha, "B", 61);
    realizaColeta(jPenha, "C", 65);

    imprimePosto(jPenha);
    
    processaLoteAmostras(jPenha);
    
    imprimePosto(jPenha);
    

    //libera toda a memória alocada
    liberaPosto(jcamburi);
    liberaPosto(jPenha);
    return 0;
}
