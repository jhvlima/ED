/*

• Abrir o arquivo de entrada e ler palavras; 
• Armazenar cada palavra na árvore binária de busca; 
• Incrementar a contagem de palavras já inseridas; 
• Contabilizar número de palavras distintas e o número total de palavras; 
• Descobrir a palavra com maior frequência.  

• Alocar um vetor que tenha como tamanho, o número de palavras distintas; 
• Ordenar o vetor, por ordem crescente de frequência das palavras (use a quicksort da biblioteca padrão); 
• Abrir o arquivo de saída e escrever as palavras ordenadas por frequência; 
• Liberar toda a memória alocada.

*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


int main(int argc, char *argv[])
{
    FILE *arquivo = fopen(argv[1], "r");
    
    tArv *raiz = criaArvoreVazia();

    char palavra[MAX];
    while (fscanf(arquivo, "%s", palavra) != EOF)
    {
        // incrementa na arvore
        tArv *subArvore = buscaEIncrementaArvore(raiz, palavra);

        if (subArvore == NULL)
        {            
            insereArvore(raiz, subArvore);
        }
    }
    int tamVetor = palavrasDistintas(raiz);
    tPalavra *vetor = calloc(tamVetor, sizeof(tPalavra));
    preencheVetor(a, vetor, tamVetor);
    qsort(vetor, tamVetor, sizeof(tPalavra), compara);
    imprimeVetor(vetor, tamVetor);
    
    printf("\n------------------------ \n");
    printf("%d palavras distintas encontradas \n", tamVetor);
    printf("%d palavras no total \n", totalOcorrencias(raiz));
    printf("%s é a palavra de maior frequência (%d)\n", obtemPalavra(maiorOcorrencia(raiz)), obtemOcorrencia(maiorOcorrencia(raiz)));

    free(vetor);        
    liberaArvore(raiz);

    return 0;
}