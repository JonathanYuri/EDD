/*
Considere que temos três potes com capacidades de 8, 5 e 3 litros, respectivamente, 
os quais não possuem qualquer marcação. 
O maior deles esta completamente cheio enquanto que os outros dois estão vazios. 
Estamos interessados em dividir o vinho em duas porções iguais de 4 litros, 
tarefa esta que pode ser realizada por sucessivos movimentos de derramar o vinho de um pote em outro pote 
sem deixar transbordar. 
Qual o menor número de movimentações do vinho de um pote à outro necessários para completar a divisão?

posição inicial 8 0 0
posicao que eu quero 4 4 0

de 8 0 0 posso ir para: 3 5 0 ou 5 0 3
de 3 5 0 posso ir para: 0 5 3 ou 8 0 0 se a capacidade no copo for igual ao valor lá esse nó não existe
de 3 5 0 --> 0 5 3 ou 3 2 3
se eu voltar para a posicao anterior (ou 8 0 0) esse nó não existe
se o valor no pote para qual eu quero passar um valor for vazio esse nó tambem não existe
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int valor1;
    int valor2;
    int valor3;

    int capacidade1;
    int capacidade2;
    int capacidade3;
    
    struct no *pt1pt2;
    struct no *pt1pt3;
    struct no *pt2pt1;
    struct no *pt2pt3;
    struct no *pt3pt1;
    struct no *pt3pt2;
}No;

No *posicao_0()
{
    No *aux = (No*) malloc(sizeof(No));
    
    aux->valor1 = 8;
    aux->valor2 = 0;
    aux->valor3 = 0;
    
    aux->pt1pt2 = NULL;
    aux->pt1pt3 = NULL;
    aux->pt2pt1 = NULL;
    aux->pt2pt3 = NULL;
    aux->pt3pt1 = NULL;
    aux->pt3pt2 = NULL;
    
    return aux;
}

int vef_negativo(int num1, int num2, int num3)
{
    if (num1 < 0 || num2 < 0)
    {
        return 1;
    }
    if (num3 < 0)
    {
        return 1;
    }
    return 0;
}

void imprimirVetor(char vetor[], int cont)
{
    if (vetor[cont] != '\0')
    {
        printf("%c ", vetor[cont]);
        imprimirVetor(vetor, cont + 1);
    }
}

void caminho(char vetor[], int cont)
{
    char atual = vetor[cont];
    if (atual != '\0')
    {
        // 1 -> 2
        //printf("(1 -> 3) ");

        //printf("(2 -> 1) ");

        //printf("(2 -> 3) ");

        //printf("(3 -> 1) ");
        
        //printf("(3 -> 2) ");

        if (atual == '1')
        {
            printf("Manda do primeiro pro segundo\n");
        }
        if (atual == '2')
        {
            printf("Manda do primeiro pro terceiro\n");
        }
        if (atual == '3')
        {
            printf("Manda do segundo pro primeiro\n");
        }
        if (atual == '4')
        {
            printf("Manda do segundo pro terceiro\n");
        }
        if (atual == '5')
        {
            printf("Manda do terceiro pro primeiro\n");
        }
        if (atual == '6')
        {
            printf("Manda do terceiro pro segundo\n");
        }

        caminho(vetor, cont + 1);
    }
}

void imprimir(No *vinho, char vetor[], int contador)
{
    if (vinho != NULL)
    {
        if (vinho->valor1 == 4 && vinho->valor2 == 4)
        {
            imprimirVetor(vetor, 0);
            printf("\n");
            caminho(vetor, 0);
            //printf("\nACHADO\n");
        }

        printf("(%i %i %i)\n", vinho->valor1, vinho->valor2, vinho->valor3);
        //printf("(1 -> 2) ");

        vetor[contador] = '1';
        imprimir(vinho->pt1pt2, vetor, contador + 1);

        //printf("(1 -> 3) ");

        vetor[contador] = '2';
        imprimir(vinho->pt1pt3, vetor, contador + 1);

        //printf("(2 -> 1) ");

        vetor[contador] = '3';
        imprimir(vinho->pt2pt1, vetor, contador + 1);

        //printf("(2 -> 3) ");

        vetor[contador] = '4';
        imprimir(vinho->pt2pt3, vetor, contador + 1);

        //printf("(3 -> 1) ");
        vetor[contador] = '5';
        imprimir(vinho->pt3pt1, vetor, contador + 1);

        //printf("(3 -> 2) ");
        vetor[contador] = '6';
        imprimir(vinho->pt3pt2, vetor, contador + 1);

        //printf("SAIU\n");
    }
}

int pesquisa(No *vinho, int valor1, int valor2, int valor3)
{
    int v = 0;
    if (vinho != NULL)
    {
        if (valor1 == vinho->valor1 && valor2 == vinho->valor2 && valor3 == vinho->valor3)
        {
            //printf("EXISTE %i %i %i\n", valor1, valor2, valor3);
            return 1;
        }
        v = pesquisa(vinho->pt1pt2, valor1, valor2, valor3);
        if (v == 1)
        {
            return 1;
        }
        v = pesquisa(vinho->pt1pt3, valor1, valor2, valor3);
        if (v == 1)
        {
            return 1;
        }
        v = pesquisa(vinho->pt2pt1, valor1, valor2, valor3);
        if (v == 1)
        {
            return 1;
        }
        v = pesquisa(vinho->pt2pt3, valor1, valor2, valor3);
        if (v == 1)
        {
            return 1;
        }
        v = pesquisa(vinho->pt3pt1, valor1, valor2, valor3);
        if (v == 1)
        {
            return 1;
        }
        v = pesquisa(vinho->pt3pt2, valor1, valor2, valor3);
        if (v == 1)
        {
            return 1;
        }
    }
    return 0;
}

No *inserir(No *vinho, No *inicial, int v1, int v2, int v3, int cond)
{
    No *aux = (No*) malloc(sizeof(No));
    int var, n1, n2, n3, v;
    if (vinho == NULL)
    {
        n1 = v1;
        n2 = v2;
        n3 = v3;
        //aux->capacidade1 = 8;
        //aux->capacidade2 = 5;
        //aux->capacidade3 = 3;
        //printf("1\n");
        if (cond == 1)
        {
            // 1 -> 2
            var = v2 + v1;
            // 7 1 0,  v2 = 1 + 7 = 8,  3 5 0, 
            if (var > 5)
            {
                // 8 0 0  -> 3 5 0
                v1 = var - 5;
                v2 = 5;
            }
            else
            {
                // 3 2 3,  0 5 3
                v2 = var;
                v1 = 0;
            }
        }
        else if (cond == 2)
        {
            // 1 -> 3
            var = v1 + v3;
            if (var > 3)
            {
                // 8 0 0  -> 3 5 0
                v1 = var - 3;
                v3 = 3;
            }
            else
            {
                // 3 2 3,  0 5 3
                v3 = var;
                v1 = 0;
            }
        }
        else if (cond == 3)
        {
            // 2 -> 1
            var = v2 + v1;
            if (var > 8)
            {
                // 8 0 0  -> 3 5 0
                v2 = var - 8;
                v1 = 8;
            }
            else
            {
                // 3 2 3,  0 5 3
                v1 = var;
                v2 = 0;
            }
        }
        else if (cond == 4)
        {
            // 2 -> 3
            var = v2 + v3;
            if (var > 3)
            {
                // 8 0 0  -> 3 5 0
                v2 = var - 3;
                v3 = 3;
            }
            else
            {
                // 3 2 3,  0 5 3
                v3 = var;
                v2 = 0;
            }
        }
        else if (cond == 5)
        {
            // 3 -> 1
            var = v3 + v1;
            if (var > 8)
            {
                // 8 0 0  -> 3 5 0
                v3 = var - 8;
                v1 = 8;
            }
            else
            {
                // 3 2 3,  0 5 3
                v1 = var;
                v3 = 0;
            }
        }
        else if (cond == 6)
        {
            // 3 -> 2
            var = v3 + v2;
            if (var > 5)
            {
                // 8 0 0  -> 3 5 0
                v3 = var - 5;
                v2 = 5;
            }
            else
            {
                // 3 2 3,  0 5 3
                v2 = var;
                v3 = 0;
            }
        }

        //var = posicao_inicial(v1, v2, v3);
        //v = posicao_antevinhor(v1, v2, v3, n1, n2, n3);

        // tenho que ver se já existem nós como esse na árvore se já existe melhor nem colocar na árvore

        v = pesquisa(inicial, v1, v2, v3);

        if (v == 0)
        {
            aux->valor1 = v1;
            aux->valor2 = v2;
            aux->valor3 = v3;
            
            aux->pt1pt2 = NULL;
            aux->pt1pt3 = NULL;
            aux->pt2pt1 = NULL;
            aux->pt2pt3 = NULL;
            aux->pt3pt1 = NULL;
            aux->pt3pt2 = NULL;
                    
            return aux;
        }
    }
    else
    {
        vinho->pt1pt2 = inserir(vinho->pt1pt2, inicial, vinho->valor1, vinho->valor2, vinho->valor3, 1);
        vinho->pt1pt3 = inserir(vinho->pt1pt3, inicial, vinho->valor1, vinho->valor2, vinho->valor3, 2);
        vinho->pt2pt1 = inserir(vinho->pt2pt1, inicial, vinho->valor1, vinho->valor2, vinho->valor3, 3);
        vinho->pt2pt3 = inserir(vinho->pt2pt3, inicial, vinho->valor1, vinho->valor2, vinho->valor3, 4);
        vinho->pt3pt1 = inserir(vinho->pt3pt1, inicial, vinho->valor1, vinho->valor2, vinho->valor3, 5);
        vinho->pt3pt2 = inserir(vinho->pt3pt2, inicial, vinho->valor1, vinho->valor2, vinho->valor3, 6);
        //printf("%i %i %i\n", vinho->valor1, vinho->valor2, vinho->valor3);
        //printf("SAIU\n");
    }
    return vinho;
}


int main()
{
    No *vinho;
    char caminho[7];
    vinho = posicao_0();

    for (int c = 0; c < 7; c++)
    {
        vinho = inserir(vinho, vinho, 8, 0, 0, 0);
    }
    imprimir(vinho, caminho, 0);
    // fazer uma função para mostrar o "caminho" (mandei 3 litros pro pote 3 etc.)
    
    return 0;
}