//Gerador de números aleatórios – Gerar e exibir 5 números aleatórios entre 1 e 100.

#include <stdio.h> //biblioteca padrão
#include <stdlib.h> //biblioteca para usar uma função randômica
#include <time.h> //biblioteca para operadores de tempo

int main()
{
    srand(time(NULL)); //Inicializa a semente baseada no tempo atual

    printf("NÚMEROS ALEATÓRIOS ENTRE 0 E 100\n");

    for (int i = 0; i < 5; ++i)
    {
        printf("%d° = %d\n", i, (rand() % 101));
    }

    printf("NÚMEROS ALEATÓRIOS ENTRE DETERMINADO INTERVALO (50 a 150)\n");

    int minimo, maximo;
    minimo = 50;
    maximo = 150;

    for (int i = 0; i < 5; ++i)
    {
        printf("%d° = %d\n", i, (minimo + rand() % (maximo - minimo + 1)));
    }

    return 0;
}