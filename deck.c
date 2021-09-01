// GRUPO:
// Jonathan yuri
// Welson Deivid
// Daniel Moreira

// Linguagem : C

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct no
{
    char inf[100];
    struct no *prox;
}No;

typedef struct
{
    No *inicio;
}Deck;

void criar_deck (Deck *d)
{
    d->inicio = NULL;
}

int vazia (Deck l)
{
    if (l.inicio == NULL)   return 0;
    else    return 1;
}

void imprimir (Deck l)
{
    No *aux;
    aux = l.inicio;
    
    while (aux != NULL)
    {
        printf ("%s\n", aux->inf);
        aux = aux->prox;
    }
    return;
}

int qntElementos(Deck deck)
{
    No *aux;
    aux = deck.inicio;

    int qtde = 0;

    while (aux != NULL)
    {
        qtde ++;
        aux = aux->prox;
    }
    return qtde;
}

void excluirDeck(Deck *deck)
{
    No *aux;
    aux = deck->inicio;

    int qtde = qntElementos(*deck);

    for (int c = 0 ; c < qtde ; c++){
        deck->inicio = aux->prox;
        free (aux);
        aux = deck->inicio;
    }
    deck->inicio = NULL;
}

int pesquisa (Deck d, char info[])
{
    No *aux;
    aux = d.inicio;
    
    while (aux != NULL)
    {
        if (strcmp (aux->inf, info) == 0)
        {
            return 0;
        }
        aux = aux->prox;
    }
    return 1;
}

int inserir_inicio (Deck *d, char info[])
{
    No *aux;
    
    aux = malloc (sizeof(No));
    
    if (aux == NULL)
    {
        return 0;
    }
    
    strcpy(aux->inf, info);     //  AUX -->  LISTA
    aux->prox = d->inicio;
    d->inicio = aux;
    
    return 1;
}

int inserir_final (Deck *d, char info[])
{
    No *aux, *novo;
    aux = d->inicio;
    
    int v = vazia (*d);
    if (v == 0)
    {
        inserir_inicio (d, info);
        return 1;
    }

    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    
    novo = malloc(sizeof (No));
    
    if (novo == NULL)
    {
        return 0;
    }
    strcpy(novo->inf, info);
    novo->prox = NULL;       // aux -- NULL  (novo)  aux -> novo -> null
    aux->prox = novo;
    
    return 1;
}

void copiarDeck(Deck deck, Deck *copia)
{
    No *aux;
    aux = deck.inicio;

    while (aux != NULL)
    {
        inserir_final(copia, aux->inf);
        aux = aux->prox;
    }
}

void remover_inicio (Deck *d)
{
    No *aux;
    int bool;
    aux = d->inicio;
    
    printf ("%s\nTem certeza que deseja remover? 1(sim) ou 0(nao)\n", aux->inf);
    scanf ("%d", &bool);
    
    if (bool == 0)
    {
        return;
    }
    else if (bool == 1)
    {
        d->inicio = aux->prox;
        free (aux);
        printf ("\nRemovido\n");
    }
    else
    {
        printf ("\nComando Invalido\n");
        remover_inicio (d);
    }
}

void remover_final (Deck *d)
{
    No *aux, *anterior;
    aux = d->inicio;
    anterior = NULL;
    int bool;

    while (aux->prox != NULL)
    {
        anterior = aux;
        aux = aux->prox;
    }

    printf ("%s\nTem certeza que deseja remover? 1(sim) ou 0(nao)\n", aux->inf);
    scanf ("%d", &bool);
    if (bool == 0)
    {
        return;
    }
    else if (bool == 1)
    {
        if (anterior == NULL)
        {
            d->inicio = aux->prox;
        }
        else
        {
            anterior->prox = NULL;
        }
        free (aux);
        printf ("\nRemovido\n");
        return;
    }
    else
    {
        printf ("\nComando Invalido\n");
        remover_final (d);
    }
}

void remover(Deck *deck, char nome[100])
{
    No *aux, *anterior;
    anterior = NULL;
    aux = deck->inicio;

    while (aux != NULL)
    {
        if (strcmp(nome, aux->inf) == 0)
        {
            if (anterior == NULL)
            {
                deck->inicio = aux->prox;
            }
            else
            {
                //1 2 3
                anterior->prox = aux->prox;
            }
            free(aux);
            return;
        }
        anterior = aux;
        aux = aux->prox;
    }
}

int checar_num (char nome[], int n)
{
    if (islower(nome[0]))
    {
        nome[0] = toupper(nome[0]);
    }
    if (nome[n] != '\0')
    {
        if (isalpha (nome[n]) && islower (nome[n]))
        {
            if ((int)nome[n] < 0)
            {
                printf ("ERRO: Caractere lido nao e uma letra valida ou e uma letra maiuscula\n\n");
                return 0;
            }
            else
            {
                checar_num (nome, n+1);
            }
        }
        else
        {
            printf ("ERRO: Caractere lido nao e uma letra valida ou e uma letra maiuscula\n\n");
            return 0;
        }
    }
    else
    {
        printf ("Nome Valido\n\n");
        return 1;
    }
}

void ordenarDeck(Deck *deck, Deck *ordenada, int ordem)
{
    No *aux;
    aux = deck->inicio;

    int qntElem = qntElementos(*deck);

    while (qntElem != 0)
    {
        char nomeMenor[100];
        strcpy(nomeMenor, aux->inf);
        while (aux != NULL)
        {
            if (strcmp (aux->inf, nomeMenor) < 0)
            {
                // aux->inf menor
                strcpy(nomeMenor, aux->inf);
                // nomeMenor = aux->inf
            }
            aux = aux->prox;
        }
        if (ordem == 1)
        {
            inserir_inicio(ordenada, nomeMenor);
        }
        else
        {
            inserir_final(ordenada, nomeMenor);
        }
        remover(deck, nomeMenor);
        aux = deck->inicio;  // volto pro inicio
        qntElem--;   // calculo o numero de elementos, para saber quando zero a deck
    }
}

int decisao ()
{
    printf ("Escolha o que deseja fazer:\n");
    printf ("1 Inserir no inicio do deck:\n");
    printf ("2 Inserir no final do deck:\n");
    printf ("3 Remover do inicio do deck:\n");
    printf ("4 Remover do final do deck:\n");
    printf ("5 Imprimir o deck\n");
    printf ("6 Para ordenar o deck\n");
    printf ("7 Encerrar programa\n");
    
    int escolha;
    scanf ("%d", &escolha);
    getchar();
    
    return escolha;
}

int main()
{
    Deck deck, copia, ordenada;
    char info[100];
    int valor, check, p, v, ordem;
    
    criar_deck (&deck);
    criar_deck (&copia);
    criar_deck (&ordenada);
    
    valor = decisao();
    
    while (valor != 7)
    {
        if (valor == 1)
        {
            printf ("Digite a informacao\n");
            scanf ("%s", info);
        
            check = checar_num(info, 1);
            p = pesquisa (deck, info);

            if (p == 0)
            {
                printf ("\nNome ja existe no Deck\n\n");
                check = -1;
            }
            if (check == 1 && p == 1)
            {
                int c = inserir_inicio (&deck, info);
                
                if (c == 0)
                {
                    printf ("\nNao foi possivel inserir na lista\n");
                }
            }
        }
        else if (valor == 2)
        {
            printf ("Digite a informacao\n");
            scanf ("%s", info);
            
            check = checar_num(info, 1);
            p = pesquisa (deck, info);

            if (p == 0)
            {
                printf ("\nNome ja existe no Deck\n\n");
                check = -1;
            }
            if (check == 1 && p == 1)
            {
                int c = inserir_final (&deck, info);
                
                if (c == 0)
                {
                    printf ("\nNao foi possivel inserir na lista\n");
                }
            }
        }
        else if (valor == 3)
        {
            v = vazia (deck);
            if (v == 0)
            {
                printf ("\nDeck Vazio\n");
            }
            else
            {
                remover_inicio (&deck);
            }
        }
        else if (valor == 4)
        {
            v = vazia (deck);
            if (v == 0)
            {
                printf ("\nDeck Vazio\n");
            }
            else
            {
                remover_final (&deck);
            }
        }
        else if (valor == 5)
        {
            printf ("\n");
            imprimir (deck);
            printf ("\n");
        }
        else if (valor == 6)
        {
            printf ("\nEscolha o que deseja fazer:\n");
            // A - Z ordem crescente, ou de Z a A ordem decrescente.
            printf ("0 -> Ordem crescente A - Z\n1 -> Ordem decrescente Z - A\n");
            scanf("%i", &ordem);

            if (ordem == 0 || ordem == 1)
            {
                printf ("\nDeseja manter o deck ordenado\n");
                printf ("0 nao\t1 sim\n");
                scanf("%i", &valor);

                if (valor == 0)
                {
                    copiarDeck(deck, &copia);
                    ordenarDeck(&copia, &ordenada, ordem);

                    printf("Seu deck ordenado: \n");
                    imprimir(ordenada);

                }
                else if (valor == 1)
                {
                    ordenarDeck(&deck, &ordenada, ordem);
                    copiarDeck(ordenada, &deck);
                    // ordenada vou copiar para deck
                }
                else
                {
                    printf("Valor Invalido\n");
                    // manter a deck como tava e excluir o resto
                }
                // tratamento de erro
                printf("Seu deck: \n\n");
                imprimir(deck);
                printf ("\n");

                excluirDeck(&ordenada);
                excluirDeck(&copia);
            }
        }
        else
        {
            printf("Valor Invalido!\n");
        }
        
        valor = decisao();
    }
    printf("\t\tFIM\t\t");
    return 0;
}