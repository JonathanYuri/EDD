#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GRUPO:

// Jonathan Yuri
// Welson Deivid

// Linguagem : C

typedef struct no{
    int valor;
    struct no *esq;
    struct no *dir;
}No;

void inicializar(No *raiz)
{
    raiz = NULL;
}

void liberar(No *raiz)
{
    if (raiz != NULL)
    {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);   // deixa ele rodar a arvore toda pra depois liberar
    }
}

void imprimir(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%i ", raiz->valor);
        //printf("ESQUERDA\n");
        imprimir(raiz->esq);
        //printf("DIREITA\n");
        imprimir(raiz->dir);
    }
}

int verificarNum(int quant_leituras)
{
    int a = scanf("%i", &quant_leituras);
    getchar();
    //printf("%i", a);
    if (a == 0 || quant_leituras <= 0)
    {
        printf("Valor Invalido\n");
        return verificarNum(quant_leituras);
    }
    else
    {
        return quant_leituras;
    }
}

int verificarLetra()
{
    int num, a;
    a = scanf("%i", &num);
    getchar();
    if (a == 0)
    {
        printf("Valor Invalido\n");
        return verificarLetra();
    }
    else
    {
        return num;
    }
}

// diz todos os elementos que estão na borda da arvore vvvv
void profundidade(No *raiz, int contador, int *guardado)
{
    if (raiz != NULL)
    {
        //printf("\n+++++%i %i +++++\n", raiz->valor, contador);
        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            //printf("(%i", raiz->valor);
            //printf("(%i))", contador);
            *guardado = contador;
        }
        //printf("%i", raiz->valor);
        //printf("ESQUERDA\n");
        profundidade(raiz->esq, contador+1, guardado);
        //printf("DIREITA\n");
        profundidade(raiz->dir, contador+1, guardado);
    }
}

int pesquisa(No *raiz, int num)
{
    if (raiz != NULL)
    {
        if (raiz->valor == num)
        {
            return 1;
        }
        else
        {
            if (num < raiz->valor)
            {
                return pesquisa(raiz->esq, num);
            }
            else
            {
                return pesquisa(raiz->dir, num);
            }
        }
    }
    return 0;
}

No *inserir(No *raiz, int num)
{
    if (raiz == NULL)
    {
        No *aux = (No*) malloc(sizeof(No));   // 7 < 4  <--   --> 
        aux->valor = num;
        aux->esq = NULL;
        aux->dir = NULL;
        //printf("1");
        return aux;
    }
    else
    {
        //printf("2");
        if (num > raiz->valor)
        {
            raiz->dir = inserir(raiz->dir, num);
        }
        else if (num < raiz->valor)
        {
            raiz->esq = inserir(raiz->esq, num);
        }
    }
    return raiz;
}

No *removerFolha(No *raiz, int camadaNo, int camadaAtual, int *valorRetirado)
{
    if (raiz != NULL)
    {
        //printf("\n%i %i %i\n", raiz->valor, camadaNo, camadaAtual);
        if (camadaNo == camadaAtual)
        {
            *valorRetirado = raiz->valor;
            free(raiz);
            return NULL;
        }
        else
        {
            raiz->esq = removerFolha(raiz->esq, camadaNo, camadaAtual + 1 ,valorRetirado);
            raiz->dir = removerFolha(raiz->dir, camadaNo ,camadaAtual + 1, valorRetirado);
        }
    }
}

int balancear(No *raiz, int profEsq, int profDir)
{
    int valorRetirado = -1;
    if (profEsq - profDir > 1)  // tenho que retirar do esquerdo para colocar no direito
    {
        //printf("ENTROU ESQ\n");
        removerFolha(raiz->esq, profEsq, 1, &valorRetirado);
        //printf("---%i---", valorRetirado);
    }
    else if (profDir - profEsq > 1)  // tirar do direito e colocar no esquerdo
    {
        //printf("ENTROU DIR\n");
        removerFolha(raiz->dir, profDir, 1, &valorRetirado);
        //printf("---%i---", valorRetirado);
    }
    else
    {
        printf("\nA arvore esta balanceada\n");
    }
    return valorRetirado;
}

int main()
{
    No *raiz;

    inicializar(raiz);
    int num, elementoSaiu = 0, existe;
    int profEsq = 0, profDir = 0, quant_leituras;

    printf("Digite a quantidade de nos que deseja inserir:\n");
    printf("OBS: a insercao sera ordenada\n");

    quant_leituras = verificarNum(quant_leituras);

    for (int c = 0; c < quant_leituras; c++)
    {
        printf("Digite um numero\n");
        num = verificarLetra();
        existe = pesquisa(raiz, num);
        if (existe == 0)
        {
            raiz = inserir(raiz, num);
        }
        else
        {
            printf("\nElemento ja existe, por favor digite outro\n");
            c--;
        }
    }
    
    
    printf("\n");
    printf("Sua arvore:\n");
    imprimir(raiz);
    printf("\n");
    
    while(elementoSaiu != -1)
    {
        profundidade(raiz->esq, 1, &profEsq);
        //printf("\n");
        
        profundidade(raiz->dir, 1, &profDir);
        //printf("\n%i %i\n", profEsq, profDir);
        
        //printf("\n\n");
        //imprimir(raiz);
        //printf("\n\n");
    
        elementoSaiu = balancear(raiz, profEsq, profDir);
        if (elementoSaiu == -1)
        {
            break;
        }
        printf("\nElemento %i saiu ", elementoSaiu);
        
        if (profEsq > profDir)
        {
            printf("para a direita\n");
            raiz->dir = inserir(raiz->dir, elementoSaiu);
        }
        else if (profDir > profEsq)
        {
            printf("para a esquerda\n");
            raiz->esq = inserir(raiz->esq, elementoSaiu);
        }
    }
    
    //raiz = raiz->dir;
    //printf("%i", raiz->valor);
    //raiz = raiz->esq;        o 6 está indo pro lado esquerdo do 9 realmente o calculo que ta dando errado
    //printf("%i", raiz->valor);
    
    printf("\n");
    printf("Sua arvore:\n");
    imprimir(raiz);
    //printf("\n\n");
    
    //elementoSaiu = balancear(raiz, profEsq, profDir);
    //printf("[%i]", elementoSaiu);
    
    liberar(raiz);

    return 0;
}
