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

typedef struct
{
    char *nomeProduto;
    int valor;
} tProduto;

tProduto *AdicionaProduto()
{
    tProduto *produto = malloc(sizeof(tProduto));

    printf("Digite o nome do produto: ");
    char temp[100];
    scanf("%99[^\n]", temp);
    scanf("%*c");
    produto->nomeProduto = strdup(temp);

    printf("Digite valor: ");
    scanf("%d", &produto->valor);
    scanf("%*c");
    return produto;
}

tProduto *AchaProduto(char *nome, tProduto **listaProduto, int tamanhoLista)
{
    for (int i = 0; i < tamanhoLista; i++)
    {
        if (!strcmp(nome, listaProduto[i]->nomeProduto))
        {
            return listaProduto[i];
        }
    }
    return NULL;
}

void DesalocaProduto(tProduto *produto)
{
    if (produto)
    {
        if (produto->nomeProduto)
        {
            free(produto->nomeProduto);
        }
        free(produto);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    tProduto *produto;
    int qnt;
} tItem;

void ImprimeItem(tItem *item)
{
    printf("\t\tItem: %s, valor unitário: %d, quantidade: %d\n", item->produto->nomeProduto, item->produto->valor, item->qnt);
}

tItem *AdicionaItem(tProduto **listaProduto, int tamanhoLista)
{
    tItem *item = malloc(sizeof(tItem));

    printf("Digite o nome do produto: ");
    char nome[100];
    scanf("%[^\n]", nome);
    scanf("%*c");

    item->produto = AchaProduto(nome, listaProduto, tamanhoLista);

    printf("Digite qnt: ");
    scanf("%d", &item->qnt);
    scanf("%*c");

    return item;
}

void DesalocaItem(tItem *item)
{
    if (item)
    {
        free(item);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    char *nomeFilial;
    tItem **item;
    int qntItems;
    int estoqueFilal;
} tFilial;

void ImprimeFilial(tFilial *filial)
{
    printf("\tFilial: %s\n", filial->nomeFilial);
    printf("\tEstoque: %d\n", filial->estoqueFilal);
    for (int i = 0; i < filial->qntItems; i++)
    {
        ImprimeItem(filial->item[i]);
    }
}

tFilial *AdicionaFilial(tProduto **listaProduto, int tamnhoLista)
{
    tFilial *filial = malloc(sizeof(tFilial));
    filial->item = malloc(10 * sizeof(tItem *));

    printf("Digite o nome da filial: ");
    char temp[100];
    scanf("%99[^\n]", temp);
    scanf("%*c");
    filial->nomeFilial = strdup(temp);
    filial->qntItems = 0;
    filial->estoqueFilal = 0;

    printf("Quantos itens deseja adicionar?: ");
    scanf("%d", &filial->qntItems);
    scanf("%*c");

    for (int i = 0; i < filial->qntItems; i++)
    {
        filial->item[i] = AdicionaItem(listaProduto, tamnhoLista);
    }
    return filial;
}

void DesalocaFilial(tFilial *filial)
{
    if (filial->nomeFilial)
    {
        free(filial->nomeFilial);
    }

    if (filial->item)
    {
        for (int i = 0; i < filial->qntItems; i++)
        {
            DesalocaItem(filial->item[i]);
        }
        free(filial->item);
    }

    if (filial)
    {
        free(filial);
    }
}

void CaculaEstoqueFilial(tFilial *filial)
{
    for (int i = 0; i < filial->qntItems; i++)
    {
        filial->estoqueFilal += filial->item[i]->produto->valor * filial->item[i]->qnt;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    char *nomeMercado;
    int estoque;
    tFilial **filial;
    int qntFilias;
} tMercado;

void ImprimeMercado(tMercado *mercado)
{
    printf("\nNome: %s, Estoque Total: %d\n", mercado->nomeMercado, mercado->estoque);
    for (int i = 0; i < mercado->qntFilias; i++)
    {
        ImprimeFilial(mercado->filial[i]);
    }
}

tMercado *AdicionaMercado(tProduto **listaProduto, int tamanhoLista)
{
    tMercado *mercado = malloc(sizeof(*mercado));
    mercado->filial = malloc(10 * sizeof(tFilial));

    printf("Digite o nome da mercado: ");
    char temp[100];
    scanf("%[^\n]", temp);
    scanf("%*c");
    mercado->nomeMercado = strdup(temp);
    mercado->qntFilias = 0;
    mercado->estoque = 0;

    printf("Quantas filiais deseja adilicionar?: ");
    scanf("%d", &mercado->qntFilias);
    scanf("%*c");

    for (int i = 0; i < mercado->qntFilias; i++)
    {
        mercado->filial[i] = AdicionaFilial(listaProduto, tamanhoLista);
    }
    return mercado;
}

void CaculaEstoqueMercado(tMercado *mercado)
{
    for (int i = 0; i < mercado->qntFilias; i++)
    {
        CaculaEstoqueFilial(mercado->filial[i]);
        mercado->estoque += mercado->filial[i]->estoqueFilal;
    }
}

void DesalocaMercado(tMercado *mercado)
{
    if (mercado->nomeMercado)
    {
        free(mercado->nomeMercado);
    }

    if (mercado->filial)
    {
        for (int i = 0; i < mercado->qntFilias; i++)
        {
            DesalocaFilial(mercado->filial[i]);
        }
        free(mercado->filial);
    }
    free(mercado);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

tProduto *AdicionaListaProdutos(tProduto **listaProduto, int *tamanhoLista)
{
    printf("Quantos produtos desaja cadastrar?: ");
    scanf("%d", tamanhoLista);
    scanf("%*c");

    for (int i = 0; i < *tamanhoLista; i++)
    {
        listaProduto[i] = AdicionaProduto();
    }
}

int main()
{
    int tamanhoLista = 0;
    tProduto **listaProduto = malloc(10 * sizeof(tProduto));

    AdicionaListaProdutos(listaProduto, &tamanhoLista);

    tMercado *mercado = AdicionaMercado(listaProduto, tamanhoLista);

    CaculaEstoqueMercado(mercado);

    ImprimeMercado(mercado);

    DesalocaMercado(mercado);

    for (int i = 0; i < tamanhoLista; i++)
    {
        DesalocaProduto(listaProduto[i]);
    }

    free(listaProduto);

    return 0;
}
