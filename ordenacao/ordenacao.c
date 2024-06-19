/*
Implemente as funções de ordenação bolha (bubble sort), ordenação rápida (quick sort), busca linear (linear search) e busca binária (binary search).

Desenvolva um programa, com os seguintes passos:

1) Inicie um vetor grande (e.x., 100 mil elementos numéricos) desordenado (aleatório);
2) Teste ordenar o vetor usando as funções de ordenação bolha e ordenação rápida (quick sort); Nota-se diferença?
3) Teste os algoritmos de busca estudados. Nota-se diferença?

Referências quick-sort: Slides anexados e Seção 11.4 do livro texto (CELES, Waldemar. Introdução a Estruturas de Dados - Com Técnicas de Programação em C. E-book. ISBN 9788595156654. Disponível em: https://integrada.minhabiblioteca.com.br/#/books/9788595156654/. Acesso em: 19 jun. 2024.)
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int ehIgual(int valor1, int valor2)
{
    return valor1 == valor2;
}


void bubbleSort(int *vetor, int tamanho)
{
    int auxiliar = 0;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho -1; j++)
        {
            if (vetor[i] > vetor[j])
            {
                auxiliar = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = auxiliar;
            }
        }
    }
}

void quickSort(int *vetor, int inicio, int fim)
{
    int auxiliar;
}

int linearSearch(int *vetor, int tamanho, int alvo)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (ehIgual(vetor[i], alvo))
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int *vetor, int inicio, int fim, int alvo)
{
    int i = inicio;
    int f = fim;
    int m = (f-i)/2;

    // nao achou
    if (i > f)
    {
        return -1;
    }
    
    // metade da esquerda
    {
        return binarySearch(vetor, i, m-1, alvo);
    }

    // metade da direita
    if (alvo < vetor[m])
    {
        return binarySearch(vetor, m+1, f, alvo);
    }

    // achou
    return m;
}

int main()
{
    //int vet [100000] = rand(MAX);
    int vet [MAX] = {1, 2, 5, 5, 4, 6, 3, 4, 6, 9};


    // imprime como ta o vetor desordenado
    for (int i = 0; i < MAX; i++)
    {
        printf("[%d]", vet[i]);
    }
    printf("\n");

    // ordena
    bubbleSort(vet, MAX);
    
    // imprime como ta o vetor ordenado
    for (int i = 0; i < MAX; i++)
    {
        printf("[%d]", vet[i]);
    }
    printf("\n");

}