// GRUPO:
// Jonathan yuri
// Welson Deivid
// Daniel Moreira

// Linguagem : C


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int verificarIgualdade(char p[100], int tamanho, int i, int contagem)
{
    if (i == tamanho)
    {
        return contagem;
    }
    if (p[i] == '(')
    {
        contagem++;
    }
    else if (p[i] == ')')
    {
        contagem--;
    }
    //printf("(%i %i)\n", i, contagem);
    return verificarIgualdade(p, tamanho, i + 1, contagem);
}

int verificarEquilibrio(char p[100], int tamanho)
{
    int v;
    if (p[0] == ')')    return 0; 
    // nao pode comecar com parenteses aberto
    else if (p[tamanho - 1] == '(') return 0;
    // nao pode terminar com parenteses fechado
    else
    {
        v = verificarIgualdade(p, tamanho, 0, 0);
        if (v == 0) return 1;
        else    return 0;
    }
}

int verificarContrario(char p[100], int i, int contagem)
{
    if (p[i] == ')')
    {
        contagem++;
    }
    else if (p[i] == '(')
    {
        contagem--;
    }
    //printf("%i %i\n", i, contagem);
    if (contagem < 0)
    {
        printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
        printf("posicao %i\n", i);
        printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
        return 1;
    }
    return verificarContrario(p, i - 1, contagem);
}

int posicaoDesbalanceada(char p[100], int tamanho, int contagem, int i)
{
    if (i == tamanho)
    {
        return 1;
    }
    if (p[0] == ')')
    {
        printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
        printf("posicao 0\n");
        printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
        return 0;
    }
    // nao pode comecar com parenteses aberto
    else if (p[tamanho - 1] == '(')
    {
        printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
        printf("posicao %i\n", tamanho - 1);
        printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
        return 0;
    }
    else
    {
        if (p[i] == '(')
        {
            contagem++;
        }
        else if (p[i] == ')')
        {
            contagem--;
        }
        if (contagem < 0)
        {
            printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
            printf("posicao %i\n", i);
            printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
            return 0;
        }
    }
    return posicaoDesbalanceada(p, tamanho, contagem, i + 1);
}

int menu()
{
    int num;

    printf("Digite:\n");
    printf("(1) - para ver se esta balanceado\n");
    printf("(2) - para ver onde esta desbalanceado\n");
    printf("(3) - para verificar outros parenteses\n");
    printf("(4) - para sair\n");

    scanf("%i", &num);

    return num;
}

int main()
{
    char parenteses[100];
    int tamanho, equilibrio, valor, v;

    valor = menu();

    
    printf("Digite os parenteses:\n");  // equilibrado
    scanf("%s", parenteses);
    tamanho = strlen(parenteses);

    while (valor != 4)
    {

        if (valor == 1)
        {
            equilibrio = verificarEquilibrio(parenteses, tamanho);

            if (equilibrio == 1)
            {
                printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
                printf("\t\tEsta balanceado\n");
                printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
            }
            else
            {
                printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
                printf("\tNao esta balanceado\n");
                printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
                // int pos = posicaoDesbalanceada(parenteses, tamanho, 0, 0);
                // printf("Parenteses desbalanceado na posicao: %d\n", pos);
                // printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
            
            }
        }

        else if (valor == 2)
        {
            equilibrio = verificarEquilibrio(parenteses, tamanho);
            //printf("%i\n", equilibrio);

            if (equilibrio == 0)
            {
                v = posicaoDesbalanceada(parenteses, tamanho, 0, 0);
                if (v == 1)
                {
                    verificarContrario(parenteses, tamanho - 1, 0);
                }
            }
            else
            {
                printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
                printf("Esta balanceado\n");
                printf("-==-=-=-=-=-=-=-=-=--==--==-=-=-=-=-=-=-=-=-=-\n");
            }
        }
        else if(valor == 3)
        {
            printf("Digite os parenteses:\n");  // equilibrado
            scanf("%s", parenteses);
            tamanho = strlen(parenteses);
        }
        else
        {
            printf("Valor Invalido\n");
        }
        valor = menu();
    }

    return 0;
}