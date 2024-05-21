#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pedido.h"
#include "produto.h"

typedef struct tcelula tCelula;
struct tcelula
{
    tCelula *proxima;
    TProduto *produto;
};

typedef struct tlista
{
    tCelula *primeira;
    tCelula *ultima;
} tLista;

/* Define o tipo TPedido (tipo opaco). Estrutura interna deste tipo eh definida na implementacao do TAD.
 * Trata-se da sentinela da lista e deve conter as seguintes informacoes:
 * Dono do pedido (char*) e os campos prim e ult da sentinela
 */
typedef struct pedido
{
    char *dono;
    tLista *listaProdutos;
} TPedido;

tLista *inicializaLista()
{
    tLista *l = calloc(1, sizeof(tLista));
    return l;
}

void insereLista(tLista *lista, TProduto *prod)
{
    tCelula *cel = calloc(1, sizeof(tCelula));
    cel->produto = prod;
    cel->proxima = NULL;
    if (lista->ultima == NULL)
    {
        lista->primeira = lista->ultima = cel;
    }
    else
    {
        lista->ultima->proxima = cel;
        lista->ultima = cel;
    }
}

void retiraLista(tLista *lista, char *prod)
{
    tCelula *cel, *ant = NULL;
    cel = lista->primeira;
    while (cel)
    {
        if (!strcmp(prod, RetornaNome(cel->produto)))
        {
            // uma celula
            if (cel == lista->primeira && cel == lista->ultima)
            {
                lista->primeira = lista->ultima = NULL;
                free(cel);
                return;
            }

            // primeira celula
            if (cel == lista->primeira)
            {
                lista->primeira = cel->proxima;
                free(cel);
                return;
            }

            // ulitima celula
            if (cel == lista->ultima)
            {
                ant->proxima = NULL;
                lista->ultima = ant;
                free(cel);
                return;
            }

            // caso comum
            ant->proxima = cel->proxima;
            free(cel);
            return;
        }
        ant = cel;
        cel = cel->proxima;
    }
}

void imprimeLista(tLista *lista)
{
    tCelula *cel = lista->primeira;
    while (cel)
    {
        ImprimeIngredientes(cel->produto);
        cel = cel->proxima;
    }
}

void liberaPedido(TPedido *p)
{
    tCelula *cel = p->listaProdutos->primeira;
    while (cel)
    {
        p->listaProdutos->primeira = cel->proxima;
        free(cel);
        cel = p->listaProdutos->primeira;
    }
    free(p->listaProdutos);
    free(p->dono);
    free(p);
}

/*----------------------------------------------------------------------
 * Inicializa o pedido de um cliente (ou seja, a sentinela!)
 * inputs: nome do dono do pedido
 * output: Pedido inicializado
 * pre-condicao: nome devidamente alocado
 * pos-condicao: Pedido inicializado contendo o nome como informado
 *---------------------------------------------------------------------- */
TPedido *InicPedido(char *dono)
{
    TPedido *p = calloc(1, sizeof(TPedido));
    p->dono = strdup(dono);
    p->listaProdutos = inicializaLista();
    return p;
}

/*----------------------------------------------------------------------
 * Inclui um produto no pedido de um cliente (ou seja, a sentinela!). Inserir ao FINAL!
 * Lembrando que um produto nao pode ser inserido mais de uma vez no pedido! Neste caso, exiba a mensagem "Produto já existe no pedido\n"
 * inputs: o pedido e o produto a ser inserido
 * output: nada
 * pre-condicao: pedido e produto foram devidamente inicializados
 * pos-condicao: produto inserido no pedido OU lista inalterada (caso o produto ja esteja na lista)
 *----------------------------------------------------------------------*/
void IncluiProdutoPedido(TPedido *pedido, TProduto *prod)
{
    if (pedido == NULL)
    {
        perror("pedido VAZIO\n");
        return;
    }
    if (prod == NULL)
    {
        perror("prod VAZIO\n");
        return;
    }
    insereLista(pedido->listaProdutos, prod);
}

/*----------------------------------------------------------------------
 * Imprime todos os dados de um pedido (o dono seguido de todos os produtos e ingredientes)
 * Caso o pedido seja novo e nao tenha ainda produtos, exibir a mensagem "Nao ha produtos neste pedido!\n"
 * inputs: o pedido
 * output: nada
 * pre-condicao: pedido devidamente inicializado
 * pos-condicao: funcao nao alterad os dados do pedido
 *----------------------------------------------------------------------*/
void ImprimePedido(TPedido *pedido)
{
    printf("DONO DO PEDIDO: %s\n", pedido->dono);
    imprimeLista(pedido->listaProdutos);
}

/*----------------------------------------------------------------------
 * Retira a unica ocorrência do produto (caso ele exista na lista).
 * Importante!!! Esta funcao nao libera o produto! Apenas o retira do pedido!
 * inputs: o pedido e, o produto a ser retirado
 * output: nada
 * pre-condicao: pedido e produto devidamente inicializados
 * pos-condicao: pedido nao contem o produto
 *----------------------------------------------------------------------*/
void RetiraProdutoPedido(TPedido *pedido, char *prod)
{
    retiraLista(pedido->listaProdutos, prod);
}

// A função envia pedido verifica se há restrição calórica ou restrição alimentar
// Se estiver tudo ok, retira o pedido da lista (libera o pedido, porém não libera o produto) e retorna 1
// Se não estiver ok, a lista permanece a mesma e a função retorna zero

/*----------------------------------------------------------------------
 * Primeiramente, verifica se há restrição calórica ou restrição alimentar, de acordo com os parametros
 **** Para a restricao calorica, deve-se somar as calorias de todos o produtos do pedido! Caso o numero de calorias do pedido ultrapasse a restricao, exiba a mensagem : "Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!"
 ****** Para a restricao alimentar, deve-se verificar se algum produto contem como ingrediente a restricao especificada. Caso algum produto contenha o ingrediente indicado, exiba a mensagem: Pedido não Enviado! Restricao alimentar no produto: %s\n
 * Se estiver tudo certo (ou seja respeitando-se as restricoes), destroi o pedido da pessoa, porém não libera os produtos) e retorna 1
 * inputs: o pedido e as restricoes calorica e alimentar
 * output: 0 (problema em algumas das restricoes). 1 (pedido enviado)
 * pre-condicao: pedido devidamente inicializado e strings validas
 * pos-condicao: se houver problema com as restricoes, o pedido deve ficar inalterado. se estiver tudo ok com as restricoes, deve destruir o pedido, porem os produtos nao devem ser liberados (pois podem estar em outros pedidos, de outras pessoas).
 *----------------------------------------------------------------------*/
int EnviaPedido(TPedido *pedido, int restricao_calorica, char *restricao_alimentar)
{
    int somaCalorias = 0;
    tCelula *cel = pedido->listaProdutos->primeira;
    while (cel)
    {
        somaCalorias += Calorias(cel->produto);

        if (VerificaIngrediente(cel->produto, restricao_alimentar))
        {
            printf("Pedido não Enviado! Restricao alimentar no produto: %s\n", RetornaNome(cel->produto));
            return 0;
        }
        cel = cel->proxima;
    }

    // deu certo
    if (restricao_calorica < somaCalorias)
    {
        printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }
    liberaPedido(pedido);
    return 1;
}