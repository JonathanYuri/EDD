#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int valor;
    struct no *left;
    struct no *right;
}No;

void liberar(No *raiz)
{
    if (raiz != NULL)
    {
        liberar(raiz->left);
        liberar(raiz->right);
        free(raiz);   // deixa ele rodar a arvore toda pra depois liberar
    }
}

void imprimir(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%i", raiz->valor);
        //printf("ESQUERDA\n");
        imprimir(raiz->left);
        //printf("DIREITA\n");
        imprimir(raiz->right);
    }
}

No *pesquisa(No *raiz, int num)
{
    if (raiz != NULL)
    {
        if (raiz->valor == num)
        {
            return raiz;
        }
        else
        {
            if (num < raiz->valor)
            {
                return pesquisa(raiz->left, num);
            }
            else
            {
                return pesquisa(raiz->right, num);
            }
        }
    }
    return NULL;
}

No *inserir(No *raiz, int num)
{
    if (raiz == NULL)
    {
        No *aux = (No*) malloc(sizeof(No));   // 7 < 4  <--   --> 
        aux->valor = num;
        aux->left = NULL;
        aux->right = NULL;
        //printf("1");
        return aux;
    }
    else
    {
        //printf("2");
        if (num > raiz->valor)
        {
            raiz->right = inserir(raiz->right, num);
        }
        else if (num < raiz->valor)
        {
            raiz->left = inserir(raiz->left, num);
        }
    }
    return raiz;
}

int main()
{
    No *raiz;

    raiz = NULL;
    int num;
    
    //for (int c = 0; c < 3 ; c++)
    //{
    //    scanf("%i", &num);
    //    raiz = inserir(raiz, num);
    //}
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 9);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 3);
    No *a = pesquisa(raiz, 4);
    if (a == NULL)
    {
        printf(">> Elemento nao encontrado\n");
    }
    else
    {
        printf(">> Elemento encontrado\n");
    }

    imprimir(raiz);
    liberar(raiz);

    return 0;
}
