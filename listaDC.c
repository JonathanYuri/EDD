#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*              ListaDuplamenteEncadeada

typedef struct{
    int num;
}Elem;

typedef struct no{
    Elem elemento;
    struct no *anterior;
    struct no *proximo;
}No;
   
typedef struct{
    No *inicio;
}ListaDuplamenteEncadeada;
*/

typedef struct{
    int num;
}Elem;

typedef struct no{
    Elem elemento;
    struct no *anterior;
    struct no *proximo;
}No;
   
typedef struct{          // a diferenca na circular e que tem um ponteiro pro inicio e final
    No *inicio;
    No *final;
}ListaD_E_Circular;   // Lista Duplamente Encadeada Circular

void criarLista(ListaD_E_Circular *lista)
{
    lista->inicio = NULL;
    lista->final = NULL;
}

int listaVazia(ListaD_E_Circular lista)
{
    if (lista.inicio == NULL)  return 1;
    else    return 0;
}

void imprimirLista(ListaD_E_Circular lista)
{
    No *aux;
    aux = lista.inicio;

    while (aux != NULL)
    {
        printf("%i\n", aux->elemento.num);
        aux = aux->proximo;
    }
}

int inserirInicio(ListaD_E_Circular *lista, int num)
{
    // meu elemento vai apontar pro inicio da lista e apontar pro meu anterior que é o final da lista
    No *aux;
    aux = malloc(sizeof(No));

    if (aux == NULL)
    {
        return 0;
    }

    int vazia = listaVazia(*lista);
    if (vazia == 1)
    {
        //printf("VAZIA\n");
        aux->anterior = lista->final;
        aux->elemento.num = num;
        aux->proximo = lista->inicio;
    }
    else
    {
        //printf("1+ elemento(s)\n");
        aux->elemento.num = num;
        aux->proximo = lista->inicio;   // proximo vai ser o inicio da lista
        aux->anterior = lista->final;   // o anterior vai ser o anterior da lista antiga
        // poderia colocar tambem aux->anterior = lista->inicio->anterior
        lista->inicio->anterior = aux;
    }
    lista->inicio = aux;
    //printf("%i", aux->elemento.num);
    return 1;
}

int inserirFinal(ListaD_E_Circular *lista, int num)
{
    
}

int menu()
{
    printf("Digite:\n");
    printf("1 para inserir no inicio da lista\n");
    printf("2 para inserir no final da lista\n");
    printf("3 para remover do inicio da lista\n");
    printf("4 para remover do final da lista\n");
    printf("5 para imprimir a lista\n");
    printf("6 para acabar o programa\n");

    int num;
    scanf("%i", &num);
    getchar();

    return num;
}

int main()
{
    ListaD_E_Circular lista;
    criarLista(&lista);

    int valor, adicionar;

    valor = menu();
    while (valor != 6)
    {
        if (valor == 1)
        {
            printf("Digite qual numero deseja adicionar\n");

            scanf("%i", &adicionar);
            getchar();

            int valor = inserirInicio(&lista, adicionar);
            if (valor == 1)
            {
                printf("Elemento adicionado com sucesso\n");
            }
            else
            {
                printf("Nao foi possivel adicionar o elemento\n");
            }
        }
        else if (valor == 2)
        {

        }
        else if (valor == 3)
        {
            
        }
        else if (valor == 4)
        {
            
        }
        else if (valor == 5)
        {
            imprimirLista(lista);
        }
        else
        {
            printf("Valor invalido\n");
        }
        valor = menu();
    }

    return 0;
}