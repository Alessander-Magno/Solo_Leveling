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

int capturaSeta(int y, int ativar[]) 
{
    char chave1, chave2;
    int x = -1; //para caso um dos if's não sejam cumpridos ele retornará "erro"
    
    chave1 = getch(); // Captura o primeiro caractere (Escape)
    
    if (chave1 == 27) // Se for a sequência de Escape
    { 
        chave2 = getch(); // Captura o próximo caractere após o Escape

        if (chave2 == 91) // Confirma que é a sequência ANSI
        { 
            x = y; //passando a última posição do x na chamada passada
            chave2 = getch(); // Captura o caractere da seta

            switch (chave2) 
            {
                case 'C': // Seta para direita
                    //printf("Você pressionou a seta para direita!\n");
                    ++x;
                    break;
                case 'D': // Seta para esquerda
                    //printf("Você pressionou a seta para esquerda!\n");
                    --x;
                    break;
                default:
                    printf("Tecla desconhecida.\n");
                    return x;
            }

            if (x < 0)
            {
                x *= -1;
                x = x % 3;

                if (x == 1)
                {
                    x = 2;
                }
                else if (x == 2)
                {
                    x = 1;
                }
                else
                {
                    x = 0;
                }
            }
            else if (x > 2)
            {
                x = x % 3;
            }
        }
    }
    else if (chave1 == 10)
    {
        ativar[0] = 1;
        return y;
    }

    return x;
}

void imprimirMatriz (char matriz[][3])
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == 1)
            {
                printf("\033[4m%c\033[0m ", matriz[i][j]);
            }
            else
            {
                printf("%c ", matriz[i][j]);
            }
        }

        printf("\n");
    }

    return;
}

void mudarMatriz (char matriz[][3], int x, int ativar[])
{
    //alterando a posição do 'V'
    matriz[0][x] = 'V';

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == 1)
            {
                printf("\033[4m%c\033[0m ", matriz[i][j]);
            }
            else
            {
                printf("%c ", matriz[i][j]);
            }
        }
        
        printf("\n");
    }

    if (ativar[0] == 1)
    {
        printf("Vai colocar qual caractere nessa posição? ");
        scanf("%c", &matriz[1][x]);
        getchar();
    
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i == 1)
                {
                    printf("\033[4m%c\033[0m ", matriz[i][j]);
                }
                else
                {
                    printf("%c ", matriz[i][j]);
                }
            }
            
            printf("\n");
        }

        ativar[0] = 0;
    }
    
    //alterando a posição do 'V'
    matriz[0][x] = 32;

    return;
}

int main ()
{
    char matriz[2][3] = {{'V', 32, 32}, {32, 32, 32}};
    int ativar[1] = {0};

    printf("A matriz está desse jeito:\n");

    imprimirMatriz(matriz);

    matriz[0][0] = 32;
    
    int x = 0;
    int i = 0;

    while (1)
    {
        printf("Vai alterar que letra (aperte uma das setas para escolher)? ");
        x = capturaSeta(x, ativar); //o 'x' guardará a posição do selecionador 'V' para ele não precisar voltar sempre para a posição [0][0]
        
        if (x == -1)
        {
            printf("ERRO!\n");
            return 1;
        }

        printf("\n");
    
        /*getchar();
        printf("Qual seria a nova letra? ");
        char c;
        scanf("%c", &c);*/
    
        mudarMatriz(matriz, x, ativar);

        if (i >= 0)
        {
            printf("\033[A\033[2k\033[A\033[2k\033[A\033[2k");
        }

        ++i;
    }


    return 0;
}