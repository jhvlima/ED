/*
*********************************
* Programa testador do TAD Arvore de Expressoes
*********************************
*/
#include <stdio.h>
#include "arvoreExp.h"

int main()
{
 
    // criando a arvore vazia
    Arv* arv = CriaVazia();

    //Imprime a arvore (neste momento ainda vazia)
    Imprime(arv);

     arv = CriaOperador('+',
               CriaOperador('*',
 		   CriaOperador ('-', 
                       CriaOperando (6), CriaOperando (3)),
                   CriaOperador ('+', 
                       CriaOperando (4), CriaOperando (1))),
               CriaOperando (5));
    
    printf ("\nA arvore eh: ");  
    //Imprime a arvore de expressoes
    Imprime(arv);

   printf ("\nO valor da expressao da arvore1 eh: %g \n", Avalia(arv));  

   printf ("\nO numero de folhas da arvore1 eh: %d \n", Folhas(arv));  

   printf ("\nA altura da arvore1 eh: %i \n", Altura(arv));  

    arv = Libera(arv);

    printf ("\nA arvore eh: ");      
    Imprime(arv);

    
  //segunda arvore

  Arv* arv2= CriaOperador('+',
               CriaOperador('+',
 		   CriaOperador ('*', 
                       CriaOperando (6), CriaOperando (5)),
                   CriaOperando(22)), 
                   CriaOperador ('+', 
                       CriaOperador('-',
                             CriaOperador ('*', 
                                 CriaOperando (5), CriaOperando (10)), 
                             CriaOperando (20)),
                       CriaOperando (30)));


     printf ("\nA arvore2 eh: ");  
    
     //Imprime a arvore de expressoes
     Imprime(arv2);

     printf ("\nO valor da expressao da arvore2 eh: %g \n", Avalia(arv2)); 
     printf ("\nO numero de folhas da arvore2 eh: %i \n", Folhas(arv2));   

     printf ("\nA altura da arvore2 eh: %i \n", Altura(arv2));  

     arv2 = Libera(arv2);

     printf ("\nA arvore eh: ");      
     Imprime(arv2);
     Libera(arv2);
}