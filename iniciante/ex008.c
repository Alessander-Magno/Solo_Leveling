// Contador de vogais em uma string – O usuário digita uma palavra, e o programa conta quantas vogais há nela.

#include <stdio.h>
#include <ctype.h>

int contadorLetras(char palavras[], int i)
{
    if (palavras[i] == '\0' || palavras[i] == 10) //'\n' == 10 quebra linha
    {
        return i;
    }

    return contadorLetras(palavras, ++i);
}

int contadorVogais(char palavras[], int i, int qtd)
{
    if (palavras[i] == '\0' || palavras[i] == 10)
    {
        return qtd;
    }

    char c = tolower(palavras[i]); //Converte para minúscula

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        ++qtd;
    }

    return contadorVogais(palavras, ++i, qtd);
}

int contadorEspacos(char palavras[], int i, int qtd)
{
    if (palavras[i] == '\0' || palavras[i] == 10)
    {
        return qtd;
    }

    if (palavras[i] == 32)
    {
        ++qtd;
    }

    return contadorEspacos(palavras, ++i, qtd);
}

int main()
{
    char palavras[101];
    int strlen, strvogais, strconso;

    printf("Insira uma frase: ");

    fgets(palavras, 101, stdin);
    //palavras[strcspn(palavras, "\n")] = '\0';

    strlen = contadorLetras(palavras, 0);
    strvogais = contadorVogais(palavras, 0, 0);
    strconso = strlen - (strvogais + contadorEspacos(palavras, 0, 0));

    printf("A sua frase tem %d caractere(s), %d vogal(ais) e %d consoante(s)\n", strlen, strvogais, strconso);

    return 0;
}