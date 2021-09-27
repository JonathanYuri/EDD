#include <stdio.h>
#include <stdlib.h>

// uma atualização boa seria no final o cara só precisar digitar o numero e eu completava o resto

typedef struct{
    int num_adj;
    int custo;
}vet;

typedef struct no{
    int valor;  // valor atual
    vet adjacencia[4];  // os que ligam com ele
    struct no *prox[4];  
}No;

void inicializar(No *raiz)
{
    raiz = NULL;
}

int verificar_num()
{
    int num, a;
    a = scanf("%i", &num);
    getchar();
    
    if (a == 1) return num;
    else
    {
        printf("Digite novamente\n");
        return verificar_num();
    }
}

No *inserir(No *raiz, int num)
{
    if (raiz == NULL)
    {
        // INSERIR
        //printf("ENTROU\n");
        No *aux = (No*) malloc(sizeof(No));
        int qnt, valor_adj, custo;
        
        aux->valor = num;
        printf("Digite a quantidade de elementos que ele esta ligado: ");
        qnt = verificar_num();
        
        for (int c = 0; c < qnt; c++)
        {
            printf("Digite o valor deste elemento: ");
            valor_adj = verificar_num();
            aux->adjacencia[c].num_adj = valor_adj;
            printf("Digite o custo da ligacao com este elemento: ");
            custo = verificar_num();
            aux->adjacencia[c].custo = custo;
        }
        for (int c = 0; c < 4; c++)
        {
            aux->prox[c] = NULL;
        }
        
        return aux;
    }
    else
    {
        // percorrer
    }
}

int main()
{
    No *raiz;
    int num;
    
    inicializar(raiz);
    
    printf("Digite o numero a ser inserido: ");
    num = verificar_num();
    raiz = inserir(raiz, num);
    
    //INSERIU
    //printf("%i ", raiz->valor);
    /*
    for (int c = 0; c < 5; c++)
    {
        
    }*/
    
    return 0;
}
