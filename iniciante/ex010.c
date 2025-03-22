//Verificação de número primo – O usuário insere um número, e o programa verifica se ele é primo ou não.

#include <stdio.h>
#include <math.h>

int ehPrimo(int x, int div)
{
    if (x <= 1)
    {
        return 0;
    }

    if (div > sqrt(x))
    {
        return 1;
    }

    if (x % div == 0)
    {
        return 0;
    }

    ehPrimo(x, ++div);
}

int main()
{
    int x;

    printf("Teste de Primalidade\n");

    printf("Insira um valor: ");

    scanf("%d", &x);

    if (ehPrimo(x, 2))
    {
        printf("O valor %d eh um número primo\n", x);
    }
    else
    {
        printf("O valor %d não eh um número primo\n", x);
    }

    return 0;
}