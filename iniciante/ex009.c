// Soma de elementos de um vetor – Criar um vetor de 5 números, preenchê-lo e exibir a soma dos elementos.

#include <stdio.h>

void somaVetor(int vetor[], int soma[], int i)
{
    if (i >= 5)
    {
        return; 
    }

    soma[0] = soma[0] + vetor[i];

    somaVetor(vetor, soma, ++i);
}

void ler(int vetor[], int i)
{
    if (i >= 5)
    {
        return;
    }

    printf("%d° valor: ", i + 1);

    scanf("%d", &vetor[i]);

    ler(vetor, ++i);
}

int main()
{
    int vetor[5];
    int somaTotal[1] = {0};

    printf("Digite 5 valores\n");
    
    ler(vetor, 0);
    somaVetor(vetor, somaTotal, 0);

    printf("A soma total dos valores inseridos eh: %d\n", somaTotal[0]);

    return 0;
}