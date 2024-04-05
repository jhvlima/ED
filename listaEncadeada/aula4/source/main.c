/* AULA 4
Nesta aula de laboratório, vamos implementar um TAD Lista Simplesmente Encadeada com Sentinela de produtos de um supermercado!
Tarefas:
1) Implementar produto.c e produto.h (o produto vai ter um código, um nome e um preço).
2) Implementar a lista.c e a lista.h, com as funcionalidades básicas de uma lista: criação, inserção, retirada (por código ou nome do produto), impressão e liberação da memória.
3) Implementar um testador (com a main) para testar a sua implementação.
*/

/* AULA 1
Hoje faremos um exercício com objetivo de treinar alocação dinâmica de: vetores, strings e structs.

Faremos uma simulação bem simplificada de uma rede de filiais de um supermercado e a presença de produtos em algumas filiais.

Dados de entrada podem ser definidos pelo usuário ou pela entrada padrão...

Informações sobre o domínio do problema:

- Um Supermercado tem um nome, um vetor de filiais e um valor total do estoque;
- Uma filial tem um nome e um estoque;
- Um estoque tem um valor e um vetor de items de estoque;
- Um item de estoque tem um quantidade e está relacionado ao um tipo de produto;
- Um tipo de produto tem um nome e um valor.


A dinâmica do programa se resume no seguinte:

- cadastrar tipos de produtos
- alocar um supermercado
- alocar filiais para este supermercado
- alocar items de estoque para cada filial (associar o produto pré cadastrado a uma quantidade)
- calcular o estoque da filial
- calcular o estoque do supermercado
- imprimir todas as informações relativas ao supermercado, por exemplo:


Nome: Carone, Estoque Total: 184500
             Filial: Jardim Camburi
             Estoque: 23000
                 Item: Leite Integral Selita, valor unitário: 10, quantidade: 200
                 Item: Presunto de Parma, valor unitário: 50, quantidade: 300
                 Item: Queijo, valor unitário: 30, quantidade: 200
             Filial: Jardim da Penha
             Estoque: 161500
                 Item: Biscoito, valor unitário: 5, quantidade: 2000
                 Item: Presunto de Parma, valor unitário: 50, quantidade: 3000
                 Item: Carne de Sol, valor unitário: 30, quantidade: 50
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/produto.h"
#include "../headers/mercado.h"
#include "../headers/filial.h"
#include "../headers/lista.h"

int main()
{
    // lista de produtos 
    int tamanhoLista = 0;
    printf("Quantos produtos desaja cadastrar?: ");
    scanf("%d", &tamanhoLista);
    scanf("%*c");
    tProduto **listaProdutos = CriaListaProdutos(tamanhoLista);

    tMercado *mercado = AdicionaMercado(listaProdutos, tamanhoLista);

    CaculaEstoqueMercado(mercado);

    ImprimeMercado(mercado);

    DesalocaMercado(mercado);

    DesalocaListaProdutos(listaProdutos, tamanhoLista);

    return 0;
}
