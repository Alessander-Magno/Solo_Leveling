//Condicionais: Leia um número e diga se ele é par ou ímpar.

#include <stdio.h>

int main()
{
    int num;

    printf("Insira um valor: ");

    scanf("%d", &num);

    if (num % 2 == 0)
    {
        printf("Par\n");
    }
    else 
    {
        printf("Ímpar\n");
    }

    return 0;
}