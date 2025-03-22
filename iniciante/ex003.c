//Laços de repetição: Imprima todos os números de 1 a 100.

#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
    clock_t inicio, fim;
    double tempo;

    inicio = clock();
    
    for (volatile int i = 0; i <= 100; ++i)
    {
        printf("%d\n", i);
        sleep(1);
    }

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %lf segundos\n", tempo);

    return 0;
}