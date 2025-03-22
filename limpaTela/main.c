#include <stdio.h>

int main() {
    char entrada[100]; // Buffer para entrada do usuário

    printf("Digite algo: ");
    fgets(entrada, sizeof(entrada), stdin);

    // Move o cursor para a esquerda até apagar a entrada do usuário
    printf("\033[2K\033[1G"); // Apaga a linha e volta ao início
    printf("Digite algo: ");   // Reimprime o prompt sem a entrada do usuário

    return 0;
}