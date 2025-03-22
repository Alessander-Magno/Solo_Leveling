#include <stdio.h>
#include <unistd.h>
#include <termios.h>

void getch(char string[]) 
{
    struct termios oldt, newt;
    
    // Obtém as configurações atuais do terminal
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    
    // Desabilita o buffer de linha (sem esperar por Enter)
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    scanf("%s", string);  // Lê a tecla pressionada
    
    // Restaura as configurações antigas do terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return;
}

int main() 
{
    char string[100];

    printf("Digite algo: ");
    
    getch(string);  // Captura a tecla pressionada sem precisar de Enter
    
    printf("\nVocê pressionou: %s\n", string);
    
    return 0;
}
