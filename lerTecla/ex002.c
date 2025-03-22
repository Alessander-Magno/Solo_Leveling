#include <stdio.h>
#include <unistd.h>
#include <termios.h>

char getch() {
    struct termios oldt, newt;
    char ch;
    
    // Obtém as configurações atuais do terminal
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    
    // Desabilita o buffer de linha (sem esperar por Enter)
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    ch = getchar();  // Lê a tecla pressionada
    
    // Restaura as configurações antigas do terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return ch;
}

int main() {
    printf("Pressione uma tecla: ");
    
    char tecla = getch();  // Captura a tecla pressionada sem precisar de Enter
    
    printf("\nVocê pressionou: %c\n", tecla);
    
    return 0;
}