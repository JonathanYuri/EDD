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
    TorreDePisa t;
    criar(&t);

    int num;
    num = menu();
    while(num != 4)
    {
        if (num == 1)
        {
            printf("Digite um numero:\n");
            scanf("%i", &num);
            inserirInicio(&t, num);
        }
        else if (num == 2)
        {
            imprimir(t);
            printf("\n");
        }
        else if (num == 3)
        {

        }
        num = menu();
    }
    
    //retirarInicio()  // pilha

    return 0;
}
