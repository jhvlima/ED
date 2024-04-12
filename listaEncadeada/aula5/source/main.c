/* AULA 4
Nesta aula de laboratório, vamos implementar um TAD Lista Simplesmente Encadeada com Sentinela de produtos de um supermercado!
Tarefas:
1) Implementar produto.c e produto.h (o produto vai ter um código, um nome e um preço).
2) Implementar a lista.c e a lista.h, com as funcionalidades básicas de uma lista: criação, inserção, retirada (por código ou nome do produto), impressão e liberação da memória.
3) Implementar um testador (com a main) para testar a sua implementação.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/produto.h"
#include "../headers/lista.h"

int main()
{
    // lista de tProduto
    int tamanhoLista = 0;
    printf("Quantos produtos desaja cadastrar?: ");
    scanf("%d", &tamanhoLista);
    scanf("%*c");
    tProduto **listaProdutos = CriaListaProdutos(tamanhoLista);

    // tLista de produtos
    tLista *listaEncadeada = CriaLista();
    for (int i = 0; i < tamanhoLista; i++)
    {
        listaEncadeada = InsereLista(listaEncadeada, listaProdutos[i]);
    }

    // teste de funcionamento
    printf("Lista de produtos completa:\n");
    ImprimeLista(listaEncadeada);

    listaEncadeada = RetiraListaNome("agua mineral", listaEncadeada);
    listaEncadeada = RetiraListaCodigo(1234, listaEncadeada);
    listaEncadeada = RetiraListaCodigo(1010, listaEncadeada);

    printf("Lista de produtos alterada:\n");
    ImprimeLista(listaEncadeada);

    DesalocaLista(listaEncadeada);
    DesalocaListaProdutos(listaProdutos, tamanhoLista);

    return 0;
}
