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

void imprimir(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%i\n", raiz->valor);
        //printf("((0)) ");
        imprimir(raiz->prox[0]);
        //printf("((1)) ");
        imprimir(raiz->prox[1]);
        //printf("((2)) ");
        imprimir(raiz->prox[2]);
        //printf("((3)) ");
        imprimir(raiz->prox[3]);
        //printf("SAIU\n");
    }
}

No *inserir(No *raiz, int num, int existe)
{
    int ir = -1, c = 0;
    if (raiz == NULL)
    {
        // INSERIR
        printf("ENTROU\n");
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
        
        //printf("--%i--", aux->valor);
        
        return aux;
    }
    else
    {
        // percorrer
        //printf("ACHEI o %i com as ligacoes\n", raiz->valor);
        for (int c = 0; c < 4; c++)
        {
            //printf("%i %i\n", raiz->adjacencia[c].num_adj, raiz->adjacencia[c].custo);
            if (num == raiz->adjacencia[c].num_adj)
            {
                ir = c;
                break;
            }
        }
        if (ir != -1)  // entrou no if
        {
            //printf("(%i)", raiz->valor);
            //printf("*%i*", ir);
            raiz->prox[ir] = inserir(raiz->prox[ir], num, existe);
            //printf("(%i)", raiz->prox[ir]->valor);
        }
        else
        {
            //printf("AINDA N");
            
            raiz->prox[c] = inserir(raiz->prox[c], num, existe);
            while(raiz->prox[c] == NULL)
            {
                raiz->prox[c] = inserir(raiz->prox[c], num, existe);
            }
            /*
            raiz->prox[0] = inserir(raiz->prox[0], num, existe);
            if (raiz->prox[0] == NULL)
            {
                raiz->prox[1] = inserir(raiz->prox[1], num, existe);
                if (raiz->prox[1] == NULL)
                {
                    raiz->prox[2] = inserir(raiz->prox[2], num, existe);
                    if (raiz->prox[2] == NULL)
                    {
                        raiz->prox[3] = inserir(raiz->prox[3], num, existe);
                    }
                }
            }*/
        }
    }
    return raiz;
}

int pesquisa_adj(No *raiz, int num)
{
    int e;
    if (raiz != NULL)
    {
        for (int c = 0; c < 4; c++)
        {
            if (raiz->adjacencia[c].num_adj == num)
            {
                printf("pesquisa pelo num: %i(raiz: %i adjacencia: %i)\n", num, raiz->valor, c);
                return 1;
            }
        }
        
        e = pesquisa_adj(raiz->prox[0], num);
        if (e == 1) return 1;
        e = pesquisa_adj(raiz->prox[1], num);
        if (e == 1) return 1;
        e = pesquisa_adj(raiz->prox[2], num);
        if (e == 1) return 1;
        e = pesquisa_adj(raiz->prox[3], num);
        if (e == 1) return 1;
    }
    return 0;
}

int main()
{
    No *raiz;
    int num, existe;
    
    inicializar(raiz);
    
    // inserir o primeiro elemento
    printf("Digite o numero a ser inserido: ");
    num = verificar_num();
    raiz = inserir(raiz, num, 0);
    
    //INSERIU
    //imprimir(raiz);
    //printf("\n%i\n", raiz->valor);
    for (int c = 0; c < 4; c++)
    {
        printf("\nDigite o numero a ser inserido: ");
        num = verificar_num();
        existe = pesquisa_adj(raiz, num);
        raiz = inserir(raiz, num, existe);
        //printf("%i %i\n", raiz->adjacencia[c].num_adj, raiz->adjacencia[c].custo);
    }
    //pesquisa_adj(raiz, 2);
    
    //printf("Digite o numero a ser inserido: ");
    //num = verificar_num();
    //existe = pesquisa_adj(raiz, num);
    //raiz = inserir(raiz, num, existe);
    
    //printf("Digite o numero a ser inserido: ");
    //num = verificar_num();
    //existe = pesquisa_adj(raiz, num);
    //raiz = inserir(raiz, num, existe);
    
    printf("\n");
    //existe = pesquisa_adj(raiz, 3);
    //printf("EXISTE %i\n", existe);
    imprimir(raiz);
    /*
    for (int c = 0; c < 5; c++)
    {
        
    }*/
    
    /*na inserir eu antes de colocar ele em algum lugar, eu preciso saber se ele ja existe nas listas de adjacencia
    se ele nao existe e a raiz tiver nao nula eu nao posso adicionar, se ele ja existe, eu tenho que colocar ele 
    na mesma posicao adjacencia[c] em relacao ao proximo (pra deixar mais facil pra mim)*/
    
    return 0;
}
