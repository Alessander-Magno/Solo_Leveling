//Contador com atraso – Exibir uma contagem regressiva de 10 a 0, com um intervalo de 1 segundo entre cada número.

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
    clock_t inicio, fim;
    double tempo;

    inicio = clock();

    for (volatile int i = 10; i >= 0; --i)
    {
        printf("%d\n", i);
        sleep(1);
    }
 
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de programa: %lf\n", tempo);

    return 0;
}