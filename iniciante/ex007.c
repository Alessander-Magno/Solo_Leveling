//Cálculo do fatorial – O usuário insere um número e o programa calcula seu fatorial.

#include <stdio.h>

int fatorial(int num)
{
    if (num == 1)
    {
        return 1;
    }

    return num * fatorial(num - 1);
}

int main()
{
    int num;

    printf("Insira um número para eu calcular seu fatorial: ");

    scanf("%d", &num);

    printf("Esse é o fatorial de %d = %d\n", num, fatorial(num));

    return 0;
}