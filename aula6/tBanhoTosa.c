#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tBanhoTosa.h"
#include "tLista.h"
#include "tGato.h"
#include "tCachorro.h"

#define MANSO 1
#define AGRESSIVO 2
#define CACHORRO 3
#define GATO 4

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

void cadastraCachorro(tBanhoTosa* loja, tCachorro* dog)
{
    if (!loja)
    {
        printf("LOJA NAO EXISTENTE\n");
        return;
    }
    if (!dog)
    {
        printf("CACHORRO NAO EXISTENTE\n");
        return;
    }
    
    if (verificaTemperamentoCachorro(dog) == MANSO)
    {
        insereLista(loja->mansos, dog, CACHORRO);
    }
    else
    {
        insereLista(loja->agressivos, dog, CACHORRO);
    }
}

void cadastraGato(tBanhoTosa* loja, tGato* cat)
{
    if (!loja)
    {
        printf("LOJA NAO EXISTENTE\n");
        return;
    }
    if (!cat)
    {
        printf("GATO NAO EXISTENTE\n");
        return;
    }
    
    if (verificaTemperamentoGato(cat) == MANSO)
    {
        insereLista(loja->mansos, cat, GATO);
    }
    else
    {
        insereLista(loja->agressivos, cat, GATO);
    }
}

void atualizaSituacaoGato(tBanhoTosa* loja, tGato* cat)
{
    if (!loja)
    {
        printf("LOJA NAO EXISTENTE\n");
        return;
    }
    if (!cat)
    {
        printf("GATO NAO EXISTENTE\n");
        return;
    }

    if (verificaTemperamentoGato(cat) == AGRESSIVO)
    {
        insereLista(loja->agressivos, cat, GATO);
        retiraLista(loja->mansos, cat);
    }
    else
    {
        insereLista(loja->mansos, cat, GATO);
        retiraLista(loja->agressivos, cat);
    }
}

void atualizaSituacaoCachorro(tBanhoTosa* loja, tCachorro* dog)
{
    if (!loja)
    {
        printf("LOJA NAO EXISTENTE\n");
        return;
    }
    if (!dog)
    {
        printf("CACHORRO NAO EXISTENTE\n");
        return;
    }

    if (verificaTemperamentoCachorro(dog) == AGRESSIVO)
    {
        insereLista(loja->agressivos, dog, CACHORRO);
        retiraLista(loja->mansos, dog);
    }
    else
    {
        insereLista(loja->mansos, dog, CACHORRO);
        retiraLista(loja->agressivos, dog);
    }
}

void imprimeBanhoTosa(tBanhoTosa* loja)
{
    if (!loja)
    {
        printf("LOJA NAO EXISTENTE\n");
        return;
    }
    printf("%s\n", loja->nome);
    imprimeLista(loja->agressivos);
    imprimeLista(loja->mansos);
}

float calculaReceita(tBanhoTosa* loja)
{
    if (!loja)
    {
        printf("LOJA NAO EXISTENTE\n");
        return 0;
    }
    return calculaReceitaListaAgressivo(loja->agressivos) + calculaReceitaLista(loja->mansos);
}

void liberaBanhoTosa(tBanhoTosa* loja)
{
    if (loja)
    {
        free(loja->nome);
        if (loja->agressivos)
        {
            desalocaLista(loja->agressivos);
        }
        if (loja->mansos)
        {
            desalocaLista(loja->mansos);
        }
        free(loja);
    }
}