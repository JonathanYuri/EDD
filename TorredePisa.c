#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
}TorreDePisa;

void criar(TorreDePisa *l)
{
    l->inicio = NULL;
}

void imprimir(TorreDePisa t)
{
    No *aux = t.inicio;
    while (aux != NULL)
    {
        printf("%i ", aux->valor);
        aux = aux->proximo;
    }
}

int vazia(TorreDePisa t)
{
    if (t.inicio == NULL)   return 1;
    else    return 0;
}

int pesquisa(TorreDePisa l, int num)
{
    No *aux = l.inicio;
    while(aux != NULL)
    {
        if (aux->valor == num)
        {
            return 1;
        }
        aux = aux->proximo;
    }
    return 0;
}

int inserirInicio(TorreDePisa *l, int num)
{
    int existe;
    existe = pesquisa(*l, num);
    if (existe == 1)
    {
        printf("Elemento %i ja existe\n", num);
        return 0;
    }
    else
    {
        No *aux = malloc(sizeof(No));
        aux->valor = num;
        aux->proximo = l->inicio;
        l->inicio = aux;
        return 1;
    }
}

void removerInicio(TorreDePisa *l, int *num)
{
    No *aux;
    int v;
    v = vazia(*l);
    if (v == 1) return;   // se ela for vazia

    aux = l->inicio;
    l->inicio = aux->proximo;
    *num = aux->valor;  // acabei de retirar da lista

    free(aux);  // deixa de fazer referencia a lista ^^ (head(1))
    return;
}

void ordenar(TorreDePisa *t1, TorreDePisa *t2, TorreDePisa *t3)
{
    int v1, v2, v3, num_Retirado;
    v1 = vazia(*t1);
    v2 = vazia(*t2);
    v3 = vazia(*t3);
    
    // 6 5 4 3 2 1  X  X
    // 5 4 3 2 1  6  X
    // 4 3 2 1  6  5
    // 4 3 2 1  X  6 5
    
    // 1 12 0 8 -5 3 15 5 7 9   X   X
    // 12 0 8 -5 3 15 5 7 9   1   X
    // 0 8 -5 3 15 5 7 9   X   12 1
    
    // 1 12 0 8 -5 3 15 5 7 9
    //9 7 5 15 3 -5 8 0 12 1 


    if (v2 == 1 && v3 == 1)
    {
        removerInicio(t1, &num_Retirado);
        inserirInicio(t2, num_Retirado);
        
        if (t1->inicio->valor < t2->inicio->valor)
        {
            removerInicio(t1, &num_Retirado);
            inserirInicio(t3, num_Retirado);
            
            removerInicio(t2, &num_Retirado);
            inserirInicio(t3, num_Retirado);
        }
        else
        {
            removerInicio(t2, &num_Retirado);
            inserirInicio(t3, num_Retirado);
            
            removerInicio(t1, &num_Retirado);
            inserirInicio(t3, num_Retirado);
        }
        imprimir(*t1);
        printf("\n");
        imprimir(*t2);
        printf("\n");
        imprimir(*t3);
        printf("\n");
        ordenar(t1, t2, t3);
    }
    else
    {
        while(v1 == 0)
        {
            // 13 5 6  X  12 11
            // 5 6   X   13 12 11
            // 0
            // 5 6   13   12 11
            // 5 6   11 12 13   X

            // 0 8 -5 3 15 5 7 9   1 12   X
            // 8 -5 3 15 5 7 9   1  12   0
            // 8 -5 3 15 5 7 9   X   12 1 0
            
            // -5 3 15 5 7 9   0 1 8 12   X
            // 3 15 5 7 9   0 1 8 12   -5
            // 3 15 5 7 9   X    12 8 1 0 -5
            
            imprimir(*t1);
            printf("\n");
            imprimir(*t2);
            printf("\n");
            imprimir(*t3);
            printf("\n");
            
            if (v3 == 1)
            {
                
                removerInicio(t1, &num_Retirado);
                inserirInicio(t3, num_Retirado);
                
                while (v2 == 0)
                {
                    printf("ACERTOU\n");
                    removerInicio(t2, &num_Retirado);
                    inserirInicio(t3, num_Retirado);
                    //printf("-=-=-=-=-v3 vazia-=-=-=-=-=-\n");
                    //imprimir(*t2);
                    //printf("\n");
                    //imprimir(*t3);
                    //printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                    v2 = vazia(*t2);
                }
            }
            // 0 8 -5 3 15 5 7 9   X   12 1
            // 0 8 -5 3 15 5 7 9   12  1
            // 0 8 -5 3 15 5 7 9   1 12   X
            
            // 8 -5 3 15 5 7 9   X   12 1 0
            // 8 -5 3 15 5 7 9   12   1 0
            // -5 3 15 5 7 9   12  8 1 0
            // -5 3 15 5 7 9   0 1 8 12   X
            
            // 3 15 5 7 9   X    12 8 1 0 -5
            // 3 15 5 7 9   12 8    1 0 -5
            // 15 5 7 9   12 8    3 1 0 -5
            //      15 12 8      9 7 5 3 1 0 -5
            
            else if (t1->inicio->valor > t3->inicio->valor)
            {
                removerInicio(t1, &num_Retirado);
                inserirInicio(t3, num_Retirado);
                
                while(v2 == 0)
                {
                    removerInicio(t2, &num_Retirado);
                    inserirInicio(t3, num_Retirado);
                    v2 = vazia(*t2);
                }
            }
            else
            {
                removerInicio(t3, &num_Retirado);
                inserirInicio(t2, num_Retirado);
            }
            //imprimir(*t1);
            //printf("\n");
            //imprimir(*t2);
            //printf("\n");
            //imprimir(*t3);
            //printf("\n");
            
            v1 = vazia(*t1);
            //v2 = vazia(*t2);
            v3 = vazia(*t3);
        }
        // X  11 12 13  6 5
        // X   12 13  11 6 5
        // X    13   12 11 6 5
        // X
        
        v2 = vazia(*t2);
        while (v2 == 0)
        {
            removerInicio(t2, &num_Retirado);
            inserirInicio(t3, num_Retirado);
            v2 = vazia(*t2);
        }
        
        //imprimir(*t1);
        //printf("\n");
        //imprimir(*t2);
        //printf("\n");
        //imprimir(*t3);
        //printf("\n");
        
        while(v3 == 0)
        {
            removerInicio(t3, &num_Retirado);
            inserirInicio(t1, num_Retirado);
            v3 = vazia(*t3);
        }
        
        //imprimir(*t1);
        //printf("\n");
        //imprimir(*t2);
        //printf("\n");
        //imprimir(*t3);
        //printf("\n");
    }
}

int menu()
{
    printf("Digite:\n");
    printf("1 - para inserir na pilha\n");
    printf("2 - para imprimir a pilha\n");
    printf("3 - para ordenar a pilha\n");
    printf("4 - para sair do programa\n");

    int num;
    scanf("%i", &num);
    getchar();
    return num;
}

int main()
{
    TorreDePisa t1;
    TorreDePisa t2;
    TorreDePisa t3;
    criar(&t1);
    criar(&t2);
    criar(&t3);

    int num, quantNumeros;
    num = menu();
    while(num != 4)
    {
        if (num == 1)
        {
            printf("Digite quantos numeros serao lidos:\n");
            scanf("%i", &quantNumeros);
            for (int c = 0; c < quantNumeros; c++)
            {
                printf("Digite um numero:\n");
                scanf("%i", &num);
                inserirInicio(&t1, num);
            }
        }
        else if (num == 2)
        {
            imprimir(t1);
            printf("\n");
        }
        else if (num == 3)
        {
            ordenar(&t1, &t2, &t3);
            printf("ORDENADO:\n");
            imprimir(t1);
            printf("\n");
        }
        num = menu();
    }
    
    //retirarInicio()  // pilha

    return 0;
}
// 12 11 13 5 6  X  X   vazias
// 11 13 5 6  12  X    so joga o 12
// 13 5 6    12  11      11 < 12 jogo na 3

// 13 5 6  X  12 11    jogo 12 na 3

// 5 6  X  13 12 11    13 > 12 (cabeca) jogo na 3


// 5 6  11 12 13  X    5 < 13, entao jogo t3 na t2, e t1 na t3
// 6  11 12 13  5      

// 6  X  13 12 11 5    t2 na t3
// 6  13  12 11 5      6 < 13, jogo 13 na 2ª
// 6  12 13  11 5      6 < 12, jogo 12 na 2ª
// 6  11 12 13  5      6 < 11, jogo 11 na 2ª
// X  11 12 13  6 5    6 > 5 jogo 6 na 3ª
// X  X  13 12 11 6 5      1 vazia  jogo geral na 3ª
// 5 6 11 12 13  X  X     jogo geral na 1ª


// 11 12 13 5 6   X   X
// 12 13 5 6   11   X    if 12 > 11
// 12 13 5 6   X  11
// 13 5 6   X  12 11
