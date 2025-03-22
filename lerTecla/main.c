#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

char getch() //altera as configurações do terminal
{
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

void capturaSeta() 
{
    char chave1, chave2;
    
    chave1 = getch(); // Captura o primeiro caractere (Escape)
    
    if (chave1 == 27) // Se for a sequência de Escape
    { 
        chave2 = getch(); // Captura o próximo caractere após o Escape

        if (chave2 == 91) // Confirma que é a sequência ANSI
        { 
            chave2 = getch(); // Captura o caractere da seta

            switch (chave2) 
            {
                case 'A': // Seta para cima
                    printf("Você pressionou a seta para cima!\n");
                    break;
                case 'B': // Seta para baixo
                    printf("Você pressionou a seta para baixo!\n");
                    break;
                case 'C': // Seta para direita
                    printf("Você pressionou a seta para direita!\n");
                    break;
                case 'D': // Seta para esquerda
                    printf("Você pressionou a seta para esquerda!\n");
                    break;
                default:
                    printf("Tecla desconhecida.\n");
            }
        }
    }
}

int main() 
{
    printf("Pressione uma seta para continuar...\n");
    
    capturaSeta();
    
    return 0;
}