#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char letra;
    int quant_filhos;
    struct no *filhos[quant_filhos];
}No;

void inicializar(No *raiz)
{
    raiz = NULL;
}

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
        printf("%i", raiz->letra);
        //printf("ESQUERDA\n");
        imprimir(raiz->left);
        //printf("DIREITA\n");
        imprimir(raiz->right);
    }
}

int pesquisa(No *raiz, int num)
{
    if (raiz != NULL)
    {
        if (raiz->letra == num)
        {
            return 1;
        }
        else
        {
            if (num < raiz->letra)
            {
                return pesquisa(raiz->left, num);
            }
            else
            {
                return pesquisa(raiz->right, num);
            }
        }
    }
    return 0;
}

No *inserir(No *raiz, char letra, int cont)
{
    if (raiz == NULL)
    {
        No *aux = (No*) malloc(sizeof(No));   // 7 < 4  <--   --> 
        aux->letra = num;
        aux->left = NULL;
        aux->right = NULL;
        //printf("1");
        return aux;
    }
    else
    {
        //printf("2");
        while()
        raiz->filhos[cont] = inserir(raiz->filhos[cont], num, 0);
    }
    return raiz;
}

int menu(){
    int escolha;
    printf("Digite '1' para adicionar um no a arvore\n");
    printf("Digite '2' para imprimir a árvore\n");
    printf("Digite '3' para finalizar o programa\n");

    scanf("%i", &escolha);
    return escolha;
}

int main()
{
    No *raiz;
    int num;
    char letra;

    inicializar(raiz);
    
    //raiz = inserir(raiz, 5);
    num = menu();
    while (num != 3)
    {
        if (num == 1)
        {
            // se o nó já existe (não vou deixar eles terem a mesma letra)
            // se já existe eu adiciono nele, vou perguntar quantos filhos tem e talz
            // quando eu for adicionar um nó eu pergunto o char dele e a quantidade de filhos, e o nome dos filhos
            // talvez dê para mudar a quantidade de filhos dele dentro do inserir
            printf("Digite o nome do elemento que deseja inserir:\n");
            scanf("%c", &letra);
            printf("Digite a quantidade de filhos que este no tem:\n");
            scanf("%i", &num);

            raiz = inserir(raiz, letra);
        }
        else if (num == 2)
        {
            imprimir(raiz);
        }
        else
        {
            printf("Valor Inválido\n");
        }
        num = menu();
    }

    /*
    int a = pesquisa(raiz, 4);
    if (a == 0)
    {
        printf(">> Elemento nao encontrado\n");
    }
    else
    {
        printf(">> Elemento encontrado\n");
    }
    
    imprimir(raiz);
    */
    liberar(raiz);

    return 0;
}
