#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

void calc_esfera(float r, float* area, float* volume)
{
    *area = 4*r*r*PI;
    *volume = (4*r*r*r*PI)/3;
}

int raizes(float a, float b, float c, float* x1, float* x2)
{
    if ((pow(b,2)-4*a*c) >= 0)
    {
        *x1 = (b + sqrt(pow(b,2)-4*a*c))/2*a;
        *x2 = (b - sqrt(pow(b,2)-4*a*c))/2*a;  
        return 0;
    }
    else
    {
        return -1;
    }
}

int pares (int n, int* vet)
{
    int qnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(vet[i]%2))
        {
            qnt++;
        }
    }
    return qnt;
}

void  inverte  (int  n,  int* vet)
{
    int auxiliar;
    for (int i = 0; i < n/2; i++)
    {
        auxiliar = vet[i];
        vet[i] = vet[n-i-1];
        vet[n-i-1] = auxiliar;
    }
}

double avalia (double* poli, int grau, double x)
{
    double valor = 0;
    for (int i = 0; i <= grau; i++)
    {
        valor += poli[i] * pow(x,i);
    }
    return valor;
}

int main() 
{
    int escolha;
    printf("Escolha uma funcao de 1 a 5:\n");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        float raio = 1, area = 2, volume = 3;
        float *ponteiro_2 = &area, *ponteiro_3 = &volume;

        calc_esfera(raio, ponteiro_2, ponteiro_3);

        printf("raio: %f area: %f volume: %f", raio, *ponteiro_2, *ponteiro_3);

    }
    
    else if (escolha == 2)
    {
        float a, b ,c;
        float *r1 = malloc(sizeof(float)); 
        float *r2 = malloc(sizeof(float)); 

        printf("Coeficientes a, b e c: ");
        scanf("%f %f %f", &a, &b, &c);

        if (raizes(a, b, c, r1, r2) == 0) 
        {
            printf("As raizes sao: x1 = %f, x2 = %f\n", *r1, *r2);
        } 
        else 
        {
            printf("Nao existem raizes reais para a equacao.\n");
        }
        free(r1);
        free(r2);
    }
    
    else if (escolha == 3)
    {
        printf("tamanho vet:");
        int n;
        scanf("%d", &n);
        printf("vet:");
        int *vet = malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++)
        {
            vet[i] = i*5;
            printf("|%d|", vet[i]);

        }
        printf("\nQtn de pares: %d", pares(n, vet));
        free(vet);
    }

    else if (escolha == 4)
    {
        printf("tamanho vet:");
        int n;
        scanf("%d", &n);
        printf("vet:");
        int *vet = malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++)
        {
            vet[i] = i*5;
            printf("|%d|", vet[i]);
        }

        inverte(n, vet);

        printf("\nInvertido");

        for (int i = 0; i < n; i++)
        {
            printf("|%d|", vet[i]);
        }

        free(vet);
    }

    else if (escolha == 5)
    {
        printf("grau:");
        int n;
        scanf("%d", &n);

        printf("vet:");
        double *vet = malloc(sizeof(double)*(n+1));
        for (int i = 0; i <= n; i++)
        {
            vet[i] = i*2 + 1;
            printf("|%lf|", vet[i]);
        }

        printf("\nvariavel:");
        double x;
        scanf("%lf", &x);

        printf("AVALIA: %lf\n", avalia(vet, n, x));
        free(vet);
    }

    else 
    {
        printf("escolha um numero valido\n");
    }
    
    return 0;
}