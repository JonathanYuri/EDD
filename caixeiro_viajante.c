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

int verificar_igual(int vetor[], int num, int cont)
{
    if (cont == 5)
    {
        return 0;
    }
    if (num == vetor[cont])
    {
        return 1;
    }
    else
    {
        return verificar_igual(vetor, num, cont+1);
    }
}

int quant_percorrida(int vetor[], int cont, int qnt)
{
    //printf("cont %i valor %i\n", cont, vetor[cont]);
    if (cont == 5)
    {
        printf("%i\n", qnt);
        return qnt;
    }
    if (vetor[cont] != 0)
    {
        qnt++;
    }
    
    return quant_percorrida(vetor, cont + 1, qnt);
}

void imprimir(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%i\n", raiz->valor);
        printf("((0)) ");
        imprimir(raiz->prox[0]);
        printf("((1)) ");
        imprimir(raiz->prox[1]);
        printf("((2)) ");
        imprimir(raiz->prox[2]);
        printf("((3)) ");
        imprimir(raiz->prox[3]);
        printf("SAIU\n");
    }
}

No *inserir(No *raiz, int num)
{
    int ir = -1, c = 0;
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
            raiz->prox[ir] = inserir(raiz->prox[ir], num);
            //printf("(%i)", raiz->prox[ir]->valor);
        }
        else
        {
            //printf("AINDA N");
            
            raiz->prox[c] = inserir(raiz->prox[c], num);
            while(raiz->prox[c] == NULL)
            {
                raiz->prox[c] = inserir(raiz->prox[c], num);
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

No *pesquisa(No *raiz, int procurar)
{
    int c = 0;
    No *aux = (No*) malloc (sizeof(No));
    aux = NULL;
    //printf("%i ", procurar);
    
    if (raiz->valor == procurar)
    {
        //printf("ACHOU");
        return raiz;
    }
    else
    {
        //printf("11111 ");
        
        if (procurar == 2 || procurar == 3)
        {
            aux = pesquisa(raiz->prox[0], procurar);
            if (aux != NULL)
            {
                return aux;
            }
        }
        else if (procurar == 4)
        {
            aux = pesquisa(raiz->prox[1], procurar);
            if (aux != NULL)
            {
                return aux;
            }
        }
        else if (procurar == 5)
        {
            aux = pesquisa(raiz->prox[2], procurar);
            if (aux != NULL)
            {
                return aux;
            }
        }
        
        //aux = pesquisa(raiz->prox[0], procurar);
        //if (aux != NULL)
        //{
        //    return aux;
        //}
        /*
        aux = pesquisa(raiz->prox[1], procurar);
        if (aux != NULL)
        {
            return aux;
        }
        pesquisa(raiz->prox[2], procurar);*/
        /*
        pesquisa(raiz->prox[0], procurar);
        while(raiz->prox[c] == NULL)
        {
            pesquisa(raiz->prox[c], procurar);
            c++;
        }*/
    }
    return NULL;
}

int looping(No *raiz, int percorridos[], int cont)
{
    int passou, c = 0;
    
    for (int c = 0; c < 4; c++)
    {
        passou = verificar_igual(percorridos, raiz->adjacencia[c].num_adj, 0);
        printf("\n((%i %i %i %i %i))\n", percorridos[0], percorridos[1], percorridos[2], percorridos[3], percorridos[4]);
        printf("c : %i passou : %i\n", c, passou);
        if (passou == 0)
        {
            printf(">> a adjacencia %i da raiz->valor (%i) pode ir\n", c, raiz->valor);
        }
    }
}

void percorrer(No *inicio, No *raiz, int percorridos[], int posicao_atual, int posicao_inicial, int custo_total)
{
    int passou, p, c = 0;
    
    p = quant_percorrida(percorridos, 0, 0);
    printf("---------%i-------", p);
    
    
    if (p == 5)
    {
        // so falta retornar pro inicio
        // em alguns casos eu nao conseguiria voltar para o inicio, por exemplo comecando no 1 e terminando no 3 (ja que o 3 nao tem ligacao com o 1)
        // outro exemplo seria comecando no 3 ou no 2 ou no 5
        // so nao aconteceria no 4 pq o 4 tem ligacao com todos
        
        printf("custo %i\n", custo_total);
        return;
    }
    /*
    if (cont == 1)
    {
        printf("%i (%i %i)\n", cont, posicao_atual, posicao_inicial);
        printf("%i\n", raiz->valor);
        return;
    }*/
    if (raiz->valor == posicao_atual)
    {
        printf("NA POSICAO CERTA\n");
        printf("ADJACENCIAS: \n");
        
        for (int i = 0; i < 4; i++)
        {
            printf("(%i %i) ", raiz->adjacencia[i].num_adj, raiz->adjacencia[i].custo);
        }
        
        looping(raiz, percorridos, 0);
        
        passou = verificar_igual(percorridos, raiz->adjacencia[c].num_adj, 0);
        
        while (passou == 1 && c < 3)
        {
            c++;
            passou = verificar_igual(percorridos, raiz->adjacencia[c].num_adj, 0);
        }
        
        custo_total += raiz->adjacencia[c].custo;
        percorridos[p] = raiz->adjacencia[c].num_adj;   // percorridos[n] vou ter que achar quantos foram escritos
        
        printf("%i %i %i %i %i\n", percorridos[0], percorridos[1], percorridos[2], percorridos[3], percorridos[4]);
        
        if (raiz->prox[c] == NULL)
        {
            //printf("====%i====", percorridos[p]);
            raiz = pesquisa(inicio, percorridos[p]);
            
            /*
            if (cont == 3)
            {
                printf("%i %i -- %i (%i)", posicao_atual, posicao_inicial, passou, c);
                return;
            }*/
            
            percorrer(inicio, raiz, percorridos, percorridos[p], posicao_inicial, custo_total);
        }
        else
        {
            printf("%i", raiz->prox[c]->valor);
            
            percorrer(inicio, raiz->prox[c], percorridos, percorridos[p], posicao_inicial, custo_total);
            
            printf("\n");
        }
        /*
        if (cont == 2)
        {
            //printf("%s", raiz->prox[c]); // null
            
            //printf("-=0 %i 0=-", raiz->prox[c]->valor);
            
            //printf("\ndentro da fun %i", raiz->valor);
            //for (int i = 0; i < 4; i++)
            //{
            //    printf("(%i %i) ", raiz->adjacencia[i].num_adj, raiz->adjacencia[i].custo);
            //}
            
            //printf("raiz %i", raiz->valor);
            //
            return;
        }*/
    }
    else
    {
        
    }
}

int main()
{
    No *raiz;
    int num, percorridos[5] = {0, 0, 0, 0, 0};
    
    raiz = NULL;
    //inicializar(raiz);
    
    // inserir o primeiro elemento
    printf("Digite o numero a ser inserido: ");
    num = verificar_num();
    raiz = inserir(raiz, num);
    
    //INSERIU
    //imprimir(raiz);
    //printf("\n%i\n", raiz->valor);
    
    //printf("((%i %i %i %i %i))", raiz->valor, raiz->prox[0]->valor, raiz->prox[0]->prox[0]->valor, raiz->prox[1]->valor, raiz->prox[2]->valor);
    
    for (int c = 0; c < 4; c++)
    {
        printf("\nDigite o numero a ser inserido: ");
        num = verificar_num();
        //pesquisa_adj(raiz, num);
        raiz = inserir(raiz, num);
        //printf("%i %i\n", raiz->adjacencia[c].num_adj, raiz->adjacencia[c].custo);
    }
    
    printf("\n");
    //existe = pesquisa_adj(raiz, 3);
    //printf("EXISTE %i\n", existe);
    imprimir(raiz);
    
    percorridos[0] = 1;
    percorrer(raiz, raiz, percorridos, 1, 1, 0);
    
    /*na inserir eu antes de colocar ele em algum lugar, eu preciso saber se ele ja existe nas listas de adjacencia
    se ele nao existe e a raiz tiver nao nula eu nao posso adicionar, se ele ja existe, eu tenho que colocar ele 
    na mesma posicao adjacencia[c] em relacao ao proximo (pra deixar mais facil pra mim)*/
    
    return 0;
}

// o que esta acontecendo, eu tenho a arvore e talz, mas quando eu estou procurando
// por exemplo estou no 3 e quero ir pro 4 eu nao posso simplesmente avancar pq o 4 nao é filho do 3, entao eu tenho que voltar procurando o 4
