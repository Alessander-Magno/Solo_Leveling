//Arrays: Leia 5 números e imprima-os na ordem inversa.

#include <stdio.h>

void imprima(int i, int array[])
{
    if (i >= 5)
    {
        printf("\nfim\n");

        return;
    }

    printf("%d ", array[i]);

    return imprima(i + 1, array);
}

void ler(int i, int array[])
{
    if (i <= 0)
    {
        printf("fim\n");
        
        return;
    }

    printf("%d°: ", 6 - i);
    scanf("%d", &array[i - 1]);

    return ler(i - 1, array);
}

int main()
{
    int array[5];

    ler(5, array);

    imprima(0, array);

    return 0;
}