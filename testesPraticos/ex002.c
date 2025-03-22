#include <stdio.h>

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

void mudarMatriz (char matriz[][3], int x, char c)
{
    matriz[0][x] = 'V';
    matriz[1][x] = c;
    
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

int main ()
{
    char matriz[2][3] = {{32, 32, 32}, {'a', 'b', 'c'}};

    printf("A matriz está desse jeito:\n");

    imprimirMatriz(matriz);

    printf("Vai alterar que letra (digite sua posição de 1 a 3)? ");
    int x;
    scanf("%d", &x);
    x--;
    getchar();
    printf("Qual seria a nova letra? ");
    char c;
    scanf("%c", &c);

    mudarMatriz(matriz, x, c);

    return 0;
}