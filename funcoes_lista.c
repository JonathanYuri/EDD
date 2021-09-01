#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[31]; //titulo autor edicao quant
    int idade;
}Elem;

typedef struct no{
    Elem elemento;
    struct no *proximo;
}No;
   
typedef struct{
// resumindo vou ter uma estrutura que aponta pra outra que possui os dados (uma estrutura de elementos)
// elementos (nome, e idade) e aponta pra outro membro da lista
    No *inicio;
}Lista;

void criar(Lista *l)
{
    l->inicio = NULL;
}

int vazia(Lista l)
{
    if (l.inicio == NULL)
    {
        return 1; //esta vazia
    }
    else    return 0;
}

int quantElemen(Lista l)
{
    No *atual;
    int quant = 0; // inicio ta vazia

    atual = l.inicio;
    while (atual != NULL){
        atual = atual->proximo;
        quant++;
    }
    /*
    for(atual = l.inicio; atual != NULL ; atual = atual->proximo){
        quant++
    } (outra forma)
    */
   return quant;
}

int pesquisa(Lista lista, char *nome){
    No *atual = lista.inicio;
    while (atual != NULL){
        if (strcmp(atual->elemento.nome, nome) == 0){  // comparando o nome
            return 1;  // existe
        }
        atual = atual->proximo;
    }
    return 0; // nao existe
}

int inserirInicio(Lista *l, Elem e)
{
    No *novo;
    int var;
    // se o elemento ja existir eu nao posso colocar
    var = pesquisa(*l, e.nome);
    if (var == 1)
    {
        //ja existe
        printf("O elemento %s ja existe \n", e.nome);
        return 0;
    }
    else
    {
        novo = malloc(sizeof(No));
        if (novo == NULL) // nao conseguiu alocar memoria
        {
            return 0;
        }
        novo->elemento = e;   // vai receber o valor que quer
        novo->proximo = l->inicio;  // o proximo do novo vai ser a lista antiga
        l->inicio = novo;  // o inicio da lista vai ser o novo agora
        return 1;
    }
}

int inserirFinal(Lista *l, Elem e)
{
    No *aux, *novo;
    int v;

    v = vazia(*l);
    // se a lista tiver vazia eu insiro no inicio mesmo
    if (v == 1) return inserirInicio(l, e);
    
    aux = l->inicio;
    while (aux->proximo != NULL){
        aux = aux->proximo;
    }
    novo = malloc(sizeof(No));
    if (novo == NULL)    return 0; // nao conseguiu espaco

    novo->elemento = e;
    novo->proximo = NULL;
    aux->proximo = novo;
    return 1;
}

void imprimirLista(Lista l)
{
    No *aux;
    aux = l.inicio;
    while (aux != NULL)
    {
        printf("Nome: %s - ", aux->elemento.nome);
        printf("Idade: %d\n", aux->elemento.idade);
        aux = aux->proximo;
    }
}

int removerInicio(Lista *l, Elem *elem)
{
    No *aux;
    int v;
    v = vazia(*l);
    if (v == 1) return 0;   // se ela for vazia

    aux = l->inicio;
    l->inicio = aux->proximo;
    *elem = aux->elemento;  // acabei de retirar da lista

    free(aux);  // deixa de fazer referencia a lista ^^ (head(1))
    return 1;
}

int removerFinal(Lista *l, Elem *elem)
{
    No *aux, *anterior;
    int v;
    // eu preciso de dois porque eu vou verificar se o proximo é null se for eu tiro o atual
    // e se eu tirar o atual enquanto estiver apontando pra ele eu vou perder o anterior dele

    anterior = NULL; // e bom deixar assim porque no caso de so ter 1 elemento, eu nao vou ter anterior
    // ai eu só removo o unico elemento mesmo
    aux = l->inicio;

    v = vazia(*l);
    if (v == 1) return 0;

    while(aux->proximo != NULL){
        anterior = aux;
        aux = aux->proximo;
    }
    
    if (anterior == NULL)
    {
        return removerInicio(l, elem);
    }
    else
    {
        *elem = aux->elemento;
        anterior->proximo = NULL;  // o anterior vai ser o final agora
        // anterior->proximo = atual->proximo;    (NULL)
        free(aux);
        return 1;
    }
}

int removerTodas(Lista *l, char *nome, Elem *elem)
{
    No *aux, *anterior;
    int v;
    
    anterior = NULL;
    aux = l->inicio;

    v = vazia(*l);
    if (v == 1) return 0;

    /* se eu quisesse fazer um que so deleta a primeira aparicao do elemento, eu mexeria apenas o if dentro dele
    e colocaria um return no final do if, porque se ele achar um igual ele retorna */
    
    while (aux != NULL){
        if (strcmp(aux->elemento.nome, nome) == 0){
            // verificando se eh igual
            if (anterior == NULL){
                // so tem 1 elemento
                return removerInicio(l, elem);
            }
            else
            {
                //  1  (2)(estou no 2)  3 e quero tirar o 2 que e o atual
                //  1 -> 3,   free(2)  o anterior vai apontar pro atual->proximo
                anterior->proximo = aux->proximo;
                *elem = aux->elemento;

                free(aux);
            }
        }
        anterior = aux;
        aux = aux->proximo;
    }
    return 1;
}

int escolha()
{
    int n;
    printf(" Digite um valor de 1 para criar uma lista \n ");
    printf("Digite um valor de 2 para saber se a lista esta vazia \n ");
    printf("Digite um valor de 3 para saber a quantidade de elementos na lista \n ");
    printf("Digite um valor de 4 para inserir um elemento no inicio da lista \n ");
    printf("Digite um valor de 5 para inserir um elemento no final da lista \n ");
    printf("Digite um valor de 6 para imprimir a lista \n ");
    printf("Digite um valor de 7 para saber se um elemento pertence a lista \n ");
    printf("Digite um valor de 8 para remover um elemento no inicio da lista \n ");
    printf("Digite um valor de 9 para remover um elemento no final da lista \n ");
    printf("Digite um valor de 10 para remover um elemento da lista \n ");
    printf("Digite um valor de 11 para sair do programa \n ");
    scanf("%i", &n);
    return n;
}

int main()
{
    int num, valor;
    num = escolha();
    Lista l;
    Elem qualquer;

    while(num != 11) // saida
    {
        if (num == 1)
        {
            criar(&l);
            printf("Lista Criada\n");
        }
        else if (num == 2)
        {
            valor = vazia(l);
            if (valor == 1)
            {
                printf("A lista esta vazia\n");
            }
            else
            {
                printf("A lista nao esta vazia\n");
            }
        }
        else if (num == 3)
        {
            printf("A quantidade de elementos e %i\n", quantElemen(l));
        }
        else if (num == 4)
        {
            printf("************************************* \n");
            printf("Digite o nome do aluno \n ");
            scanf("%s",qualquer.nome);
            printf("Digite a idade do aluno \n ");
            scanf("%d",&qualquer.idade);
            valor = inserirInicio(&l, qualquer);

            if (valor == 0)
            {
                printf("O elemento nao foi inserido \n");
            }
            else
            {
                printf("O elemento foi inserido \n");
            }
        }
        else if (num == 5)
        {
            printf("************************************* \n");
            printf("Digite o nome do aluno \n ");
            scanf("%s",qualquer.nome);
            printf("Digite a idade do aluno \n ");
            scanf("%d",&qualquer.idade);
            valor = inserirFinal(&l, qualquer);

            if (valor == 0)
            {
                printf("O elemento nao foi inserido \n");
            }
            else
            {
                printf("O elemento foi inserido \n");
            }
        }
        else if (num == 6)
        {
            imprimirLista(l);
        }
        else if (num == 7)
        {
            printf("************************************* \n");
            printf("Digite o nome do aluno \n ");
            scanf("%s", qualquer.nome);
            printf("************************************* \n");
            valor = pesquisa(l, qualquer.nome);
            printf("************************************* \n");

            if (valor == 1)
            {
                printf("O elemento pertence a lista \n");
            }
            else
            {
                printf("O elemento nao pertence a lista \n");
            }
            printf("************************************* \n");
        }
        else if (num == 8)
        {
            valor = removerInicio(&l, &qualquer);

            if (valor == 1)
            {
                printf("O elemento %s foi removido da lista \n", qualquer.nome);
            }
            else
            {
                printf("O elemento %s nao foi removido da lista \n", qualquer.nome);
            }
            printf("************************************* \n");
        }
        else if (num == 9)
        {
            valor = removerFinal(&l, &qualquer);

            if (valor == 1)
            {
                printf("O elemento %s foi removido da lista \n", qualquer.nome);
            }
            else
            {
                printf("O elemento %s nao foi removido da lista \n", qualquer.nome);
            }
            printf("************************************* \n");
        }
        else if (num == 10)
        {
            printf("************************************* \n");
            printf("Digite o nome do aluno \n ");
            scanf("%s", qualquer.nome);
            valor = removerTodas(&l, qualquer.nome, &qualquer);
            printf("************************************* \n");

            if (valor == 1)
            {
                printf("O elemento %s foi removido da lista \n", qualquer.nome);
            }
            else
            {
                printf("O elemento %s nao foi removido da lista \n", qualquer.nome);
            }

            printf("************************************* \n");
        }
        else
        {
            printf("Valor Invalido!\n");
        }
        num = escolha();
    }
    printf("-=-=-=-FIM-=-=-=-");
    return 0;
}