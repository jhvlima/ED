#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLista.h"
//#include "tGato.h"
//#include "tCachorro.h"

typedef struct tBanhoTosa
{
    char *nome;
    tLista *agressivos;
    tLista *mansos;
} tBanhoTosa;

tBanhoTosa* inicBanhoTosa(char* nome)
{
    tBanhoTosa *loja = malloc(sizeof(tBanhoTosa));
    loja->nome = strdup(nome);
    loja->agressivos = criaLista();
    loja->mansos = criaLista();
    return loja;
}

/* Insere o tCachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraCachorro(tBanhoTosa* loja, tCachorro* dog)
{    
}

/* Insere o tCachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraGato(tBanhoTosa* loja, tGato* cat);


/* Essa função atualiza a situação de um tGato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(tBanhoTosa* loja, tGato* cat)
{
    if (cat->vibe == MANSO)
    {
        RetiraListaGato(nome, loja->mansos);
    }
    else
    {
        RetiraListaGato(nome, loja->agressivos);
    }
    
    
}












/* Essa função atualiza a situação de um tCachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(tBanhoTosa* loja, tCachorro* dog);


/* Imprime os dados da Loja (nome, e conteúdo das listas)
* inputs: referencia para a loja
* output: nenhum
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
void imprimeBanhoTosa(tBanhoTosa* loja);


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor tGato: 30 reais, Valor tCachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(tBanhoTosa* loja);


/* Libera toda a memória alocada
* inputs: referencia para a loja
* output: não tem
* pre-condicao: loja alocada
* pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(tBanhoTosa* loja);
