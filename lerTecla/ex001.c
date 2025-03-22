#include <stdio.h>
#include <string.h>

/*
    ESC [ A -> seta para cima.
    ESC [ B -> seta para baixo.
    ESC [ C -> seta para a direita.
    ESC [ D -> seta para a esquerda.
*/

int main ()
{
    char entrada[5];

    printf("Digite algo: ");

    fgets(entrada, 5, stdin);

    printf("String: %s", entrada);

    return 0;
}