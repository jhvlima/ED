/*
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
    char *nomeItem;
    int valor;
    int qnt;
}tItem;

void ImprimeItem(tItem *item)
{
    printf("\t\t\tItem: %s, valor unitário: %d, quantidade: %d\n", item->nomeItem, item->valor, item->qnt);
}

tItem *AdicionaItem()
{
    tItem *item = malloc(sizeof(tItem));

    printf("Digite o nome do produto:");
    char temp[100];
    scanf("%[^\n]", temp);
    item->nomeItem = strdup(temp);
    
    printf("Digite o valor e a qnt:");
    scanf("%d %d", item->valor, item->qnt);
    return item;

}

void DesalocaItem(tItem *item)
{
    if (item->nomeItem)
    {
        free(item->nomeItem);
    }
    
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
}tFilial;

void ImprimeFilial(tFilial *filial)
{
    printf("\tFilial: %s\n", filial->nomeFilial);
    printf("\t\tEstoque: %d\n", filial->estoqueFilal);
    for (int i = 0; i < filial->qntItems; i++)
    {
        Imprimeitem(filial->item);
    }
}

tFilial *AdicionaFilial(tFilial *filial)
{
    tFilial *filial = malloc(sizeof(tFilial));
    filial->item = malloc(10 * sizeof(tItem*));

    printf("Digite o nome da filial:");
    char temp[100];
    scanf("%[^\n]", temp);
    filial->nomeFilial = strdup(temp);
    filial->qntItems = 0;

    int i = 0;
    while (1)
    {
        char car;
        printf("Deseja adicionar um item? (s/n):)");
        scanf("%c", &car); 
        if (car == 'n')
        {
            break;
        }
        
        filial->item[i] = AdicionaItem();
        filial->qntItems++;
    }
    return filial;
}

tFilial *DesalocaFilial(tFilial *filial)
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
    }

    if (filial)
    {
        free(filial);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct 
{
    char *nomeMercado;
    int estoque;
    tFilial *filial;
    int qntFilias;
}tMercado;

void ImprimeMercado(tMercado *mercado)
{
    printf("Nome: %s, Estoque Total: %d\n", mercado->nomeMercado);
    for (int i = 0; i < mercado->qntFilias; i++)
    {
        ImprimeFilial(mercado->filial);
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{




    return 0;
}
