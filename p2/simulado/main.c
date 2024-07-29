#include "tabela.h"
#include <stdio.h>

int main()
{
    // Create the hash table
    tHash *tab = criaHash();

    // Create some entries
    tRede *rede1 = criaRede(23, 26);
    tRede *rede2 = criaRede(13, 33);
    tRede *rede3 = criaRede(20, 13);
    tRede *rede4 = criaRede(23, 10);

    // Insert entries into the hash table
    tab = insereHash(tab, rede1);
    tab = insereHash(tab, rede2);
    tab = insereHash(tab, rede3);
    tab = insereHash(tab, rede4);

    // Search for entries
    tRede *found = buscaHash(tab, 33);
    if (found)
    {
        printf("Found destination: %d\n", obtemDestino(found));
    }
    else
    {
        printf("Destination 33 not found\n");
    }

    found = buscaHash(tab, 23);
    if (found)
    {
        printf("Found destination: %d\n",  obtemDestino(found));
    }
    else
    {
        printf("Destination 23 not found\n");
    }

    found = buscaHash(tab, 46);
    if (found)
    {
        printf("Found destination: %d\n",  obtemDestino(found));
    }
    else
    {
        printf("Destination 46 not found\n");
    }

    found = buscaHash(tab, 13);
    if (found)
    {
        printf("Found destination: %d\n",  obtemDestino(found));
    }
    else
    {
        printf("Destination 13 not found\n");
    }

    // Clean up the hash table
    liberaHash(tab);

    return 0;
}
