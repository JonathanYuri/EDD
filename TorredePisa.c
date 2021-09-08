#include <stdio.h>
#include <stdlib.h>

// GRUPO

//JONATHAN YURI
//WELSON DEIVID

//LINGUAGEM : C

typedef struct no
{
    int valor;
    struct no *proximo;
}No;

typedef struct
{
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
        ordenar(t1, t2, t3);
    }
    else
    {
        while(v1 == 0)
        {
            if (v3 == 1)
            {
                
                removerInicio(t1, &num_Retirado);
                inserirInicio(t3, num_Retirado);
                
                v2 = vazia(*t2);
                while (v2 == 0)
                {
                    removerInicio(t2, &num_Retirado);
                    inserirInicio(t3, num_Retirado);
                    
                    v2 = vazia(*t2);
                }
            }
            
            else if (t1->inicio->valor > t3->inicio->valor)
            {
                removerInicio(t1, &num_Retirado);
                inserirInicio(t3, num_Retirado);
                
                v2 = vazia(*t2);
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
            
            v1 = vazia(*t1);
            v3 = vazia(*t3);
        }
        
        v2 = vazia(*t2);
        while (v2 == 0)
        {
            removerInicio(t2, &num_Retirado);
            inserirInicio(t3, num_Retirado);
            v2 = vazia(*t2);
        }
        
        while(v3 == 0)
        {
            removerInicio(t3, &num_Retirado);
            inserirInicio(t1, num_Retirado);
            v3 = vazia(*t3);
        }
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

int checar_numero ()
{
    int num, n;
    n = scanf ("%d", &num);
    getchar();
    
    if (n > 0)
    {
        return num;
    }
    else
    {
        printf ("Valor invalido, digite novamente:\n");
        return checar_numero();
    }
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
            quantNumeros = checar_numero ();
            
            for (int c = 0; c < quantNumeros; c++)
            {
                printf("Digite um numero:\n");
                num = checar_numero ();
                int a = inserirInicio(&t1, num);
                
                if (a == 0) c--;
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
        else printf ("Valor invalido\n");
        num = menu();
    }
    
    printf ("Mama Mia, encerrando programa");
    return 0;
}
