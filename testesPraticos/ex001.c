#include <stdio.h>

int main ()
{
    char matriz[2][3] = {{127, 127, 127}, {'a', 'b', 'c'}};

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

    return 0;
}