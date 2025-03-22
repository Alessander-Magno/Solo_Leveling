#include <stdio.h>

int main() {
    char entrada[100]; // Buffer para armazenar a entrada

    printf("Digite algo: ");
    fgets(entrada, sizeof(entrada), stdin);

    // Apaga a linha anterior do terminal
    printf("\033[A\33[2K"); // Move o cursor para cima e limpa a linha inteira

    printf("Entrada apagada!\n");

    return 0;
}