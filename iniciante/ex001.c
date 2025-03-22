//Entrada e saída: Leia um número inteiro e imprima seu dobro.

#include <stdio.h>

int main()
{
    int num;

    printf("Insira um valor: ");
    
    scanf("%d", &num);

    printf("O número digitado eh: %d, cujo dobro eh: %d\n", num, num * 2);

    return 0;
}