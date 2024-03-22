#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int variavel_1 = 1, variavel_2 = 2, variavel_3 = 3, variavel_4 = 4;
    int *ponteiro_1 = &variavel_1, *ponteiro_2 = &variavel_2, *ponteiro_3 = &variavel_3, *ponteiro_4 = &variavel_4;

    printf("Variavel 1: %d\n", *ponteiro_1);
    *ponteiro_1 = 7;
    printf("Variavel 1 apos modificacao: %d\n", *ponteiro_1);

    printf("Variavel 2: %d\n", *ponteiro_2);
    *ponteiro_2 = 14;
    printf("Variavel 2 apos modificacao: %d\n", *ponteiro_2);

    printf("Variavel 3: %d\n", *ponteiro_3);
    *ponteiro_3 = 21;
    printf("Variavel 3 apos modificacao: %d\n", *ponteiro_3);

    printf("Variavel 4: %d\n", *ponteiro_4);
    *ponteiro_4 = 28;
    printf("Variavel 4 apos modificacao: %d\n", *ponteiro_4);

    return 0;
}