#include <stdio.h>
#include <ctype.h>

/*
faça um programa que receba um nome válido
para efeitos de teste, os nomes válidos são formados só por letra
não existe a possibilidade de um nome ter zero caracteres
o campo não deve permitir que a string inicie com uma letra minúscula nem com espaço
*/

void verificar_nome(char nome[], int cont)
{
    if (nome[cont] == '\0')
    {
        printf("Nome valido\n");
        return;
    }
    if (isalpha(nome[cont]) == 0)
    {
        printf("Nome invalido\n");
    }
    else
    {
        verificar_nome(nome, cont + 1);
    }
}

void printar(char nome[], int i)
{
    if (nome[i] != '\0')
    {
        printf("%c", nome[i]);
        printar(nome, i+1);
    }
}

int main()
{
    char nome[256];
    //scanf("[^\n]", nome);
    fgets(nome, 256, stdin);
    
    //printar(nome, 0);
    
    if (nome[0] == '\n')
    {
        printf("Nome invalido\n");
    }
    else
    {
        int min = islower(nome[0]);
        if (nome[0] == ' ' || min != 0)
        {
            printf("Nome invalido\n");
        }
        else
        {
            verificar_nome(nome, 0);
        }
    }
    
    return 0;
}
