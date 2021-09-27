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

int pesquisa_adj(No *raiz, int num)
{
    if (raiz != NULL)
    {
        for (int c = 0; c < 4; c++)
        {
            if (raiz->adjacencia[c].num_adj == num)
            {
                printf("(%i %i)", raiz->valor, c);
                return 1;
            }
        }
        
        pesquisa_adj(raiz->prox[0], num);
        pesquisa_adj(raiz->prox[1], num);
        pesquisa_adj(raiz->prox[2], num);
        pesquisa_adj(raiz->prox[3], num);
    }
    return 0;
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
    printf("\n%i\n", raiz->valor);
    for (int c = 0; c < 4; c++)
    {
        printf("%i %i\n", raiz->adjacencia[c].num_adj, raiz->adjacencia[c].custo);
    }
    pesquisa_adj(raiz, 2);
    /*
    for (int c = 0; c < 5; c++)
    {
        
    }*/
    
    /*na inserir eu antes de colocar ele em algum lugar, eu preciso saber se ele ja existe nas listas de adjacencia
    se ele nao existe e a raiz tiver nao nula eu nao posso adicionar, se ele ja existe, eu tenho que colocar ele 
    na mesma posicao adjacencia[c] em relacao ao proximo (pra deixar mais facil pra mim)*/
    
    return 0;
}
