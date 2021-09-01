// GRUPO:
// Jonathan yuri
// Welson Deivid
// Daniel Moreira

// Linguagem : C


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1 atividade) Questão 4.19 da página 148 do livro

2 atividade) Faça um programa de gerenciamento de uma fila de atendimento de banco
considerando que existe 3 tipos de clientes:

o com prioridade zero, que é uma pessoa que não é cliente do banco,

o com prioridade um, que é uma pessoa que é cliente do banco,

o com prioridade dois, que é uma pessoa que não é cliente do banco e que tem prioridade por lei no atendimento,

o com prioridade tres, que é uma pessoa que é cliente do banco e que tem prioridade por lei no atendimento.

Seu programa deve prever um atendimento balanceado de modo que os clientes sejam atendidos em períodos balanceados, 
para que um cliente de prioridade baixa não fica aguardando indefinidamente. 
(dica para balancear, você deve encontrar o número de clientes de cada prioridade que deve ser atendido de forma intercalada. 
Lembre-se que este número de balanceamento se altera a cada entra e/ou sai da cliente na fila, para facilitar esta dinâmica, 
considere o recalculo do balanceamento a cada 4 novos acontecimentos de entrada e/ou saída)

deixar saindo no formato (0, 1, 2, 3)  (3, 2, 1, 0) -> ordem
*/

typedef struct{
    char nome[31];
    int prioridade;
}cliente;

typedef struct no{
    cliente pessoa;
    struct no *next;
}No;
   
typedef struct{
// resumindo vou ter uma estrutura que aponta pra outra que possui os dados (uma estrutura de elementos)
// elementos (nome, e idade) e aponta pra outro membro da lista
    No *inicio;
}Lista;

void criarLista(Lista *l)
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

int verificarPrioridade()
{
    int p;
    printf("Digite a prioridade pessoa:\n");
    scanf("%i", &p);
    getchar();

    if ((p >= 0) && (p <= 3))
    {
        return p;
    }
    else
    {
        return verificarPrioridade();
    }
}

int pesquisa(Lista lista, char *nome){
    No *atual = lista.inicio;
    while (atual != NULL){
        if (strcmp(atual->pessoa.nome, nome) == 0){  // comparando o nome
            return 1;  // existe
        }
        atual = atual->next;
    }
    return 0; // nao existe
}

int inserirInicio(Lista *l, cliente c)
{
    No *aux;
    int var;

    var = pesquisa(*l, c.nome);
    if (var == 1)
    {
        //ja existe
        printf("O elemento %s ja existe \n", c.nome);
        return 0;
    }
    else
    {
        aux = malloc(sizeof(No));

        if (aux == NULL) // nao conseguiu alocar memoria
        {
            return 0;
        }

        aux->pessoa = c;
        aux->next = l->inicio;
        l->inicio = aux;

        return 1;
    }
}

int inserirFinal(Lista *l, cliente c)
{
    No *aux, *novo;

    aux = l->inicio;

    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    novo = malloc(sizeof(No));
    if (novo == NULL) // nao conseguiu alocar memoria
    {
        return 0;
    }
    novo->pessoa = c;
    novo->next = NULL;
    aux->next = novo;

    return 1;
}

void imprimirLista(Lista l)
{
    No *aux;
    aux = l.inicio;

    while (aux != NULL)
    {
        printf("%s ", aux->pessoa.nome);
        printf("%i\n", aux->pessoa.prioridade);
        aux = aux->next;
    }
}

int tamanhoLista(Lista l)
{
    No *aux;
    aux = l.inicio;
    int contador = 0;
    while (aux != NULL)
    {
        contador ++;
        aux = aux->next;
    }
    return contador;
}

void existePrioridade(Lista l, Lista *saida, int p, int jogarFinal)
{
    No *aux;
    cliente auxiliar;
    int jaPertence, valor, var;
    aux = l.inicio;

    while (aux != NULL)
    {
        int contador = 0;
        // aux->pessoa.nome != *saida
        if (((aux->pessoa.prioridade) == p))
        {
            jaPertence = pesquisa(*saida, aux->pessoa.nome);  // verificar se ja pertence a lista de saida

            if (jaPertence == 0) // so vou continuar se nao existe na lista
            {
                sprintf(auxiliar.nome, "%s", aux->pessoa.nome);  // ta passando o nome pra auxiliar.nome (string)
                auxiliar.prioridade = p;
                if (jogarFinal == 0)
                {
                    valor = inserirInicio(saida, auxiliar);
                    if (valor == 0)
                    {
                        printf("Nao foi possivel adicionar o elemento a lista de saida\n");
                    }
                }
                else if (jogarFinal == 1)
                {
                    var = inserirFinal(saida, auxiliar);
                    if (var == 0)
                    {
                        printf("Nao foi possivel adicionar o elemento a lista de saida\n");
                    }
                }
                return;
            }
        }
        // se existir essa prioridade na lista
        aux = aux->next;
    }
    // se nao existir um igual eu retorno 0
    return;
}

void atendimento(Lista l, Lista *saida, int jogarFinal)
{
    if (jogarFinal == 0)
    {
        for(int p = 0; p < 4; p++){
            existePrioridade(l, saida, p, jogarFinal);
        }
    }
    else
    {
        for(int p = 3; p > -1; p--){ // vai jogar no final do maior para o menor
            existePrioridade(l, saida, p, jogarFinal);
        }
    }
    return;
}

int removerInicio(Lista *l, cliente *elem)
{
    No *aux;
    int v;
    v = vazia(*l);
    if (v == 1) return 0;   // se ela for vazia

    aux = l->inicio;
    l->inicio = aux->next;
    *elem = aux->pessoa;  // acabei de retirar da lista

    free(aux);  // deixa de fazer referencia a lista ^^ (head(1))
    return 1;
}

int removerElemento(Lista *l, cliente *elem)
{
    No *aux, *anterior;
    anterior = NULL;
    aux = l->inicio;

    while (aux != NULL)
    {
        if (strcmp(aux->pessoa.nome, elem->nome) == 0){ // se achar um igual
            if (anterior == NULL)  // to no 1 elemento
            {
                return removerInicio(l, elem);
            }
            else
            {
                //  1  (2)(estou no 2)  3 e quero tirar o 2 que e o atual
                //  1 -> 3,   free(2)  o anterior vai apontar pro atual->proximo
                anterior->next = aux->next;
                *elem = aux->pessoa;

                free(aux);
            }
        }
        anterior = aux; // se nao for igual o anterior vai pegar o atual
        aux = aux->next; // e o atual vai pegar o proximo
    }
    return 1;
}

int menu()
{
    int escolha;
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Digite:\n(1) - para adicionar as pessoas\n");
    printf("(2) - para ver sua lista\n");
    printf("(3) - para atender um item da lista\n");
    printf("(4) - para sair do programa\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    scanf("%i", &escolha);
    return escolha;
}

int main()
{
    Lista lista;
    Lista saida;
    cliente qualquer, removido;
    int valor, tamanhoL, tamanhoS, remover;

    criarLista(&lista);
    criarLista(&saida);

    valor = menu();

    while (valor != 4)
    {
        if (valor == 1)
        {
            printf("Digite o nome da pessoa:\n");
            scanf("%s", qualquer.nome);
            qualquer.prioridade = verificarPrioridade();
            
            valor = inserirInicio(&lista, qualquer);
            if (valor == 0)
            {
                printf("Nao foi possivel colocar o elemento na lista\n");
            }
            else
            {
                printf("\t\t(Elemento adicionado com sucesso)\n");
            }
        }
        else if (valor == 2)
        {
            imprimirLista(lista);
        }
        else if (valor == 3)
        {
            //remover(&lista);
            remover = removerInicio(&saida, &removido);

            // se ele nao conseguiu remover do inicio da lista eu vou pedir outra lista de atendimento
            // se ele nao conseguiu (ainda tem gente na lista principal)
            if (remover == 0)
            {
                tamanhoL = tamanhoLista(lista);
                tamanhoS = tamanhoLista(saida);
                if (tamanhoL != 0)
                {
                    atendimento(lista, &saida, 0);

                    while(tamanhoS != tamanhoL)
                    {
                        atendimento(lista, &saida, 1);

                        tamanhoL = tamanhoLista(lista);
                        tamanhoS = tamanhoLista(saida);
                    }
                    remover = removerInicio(&saida, &removido);
                    removerElemento(&lista, &removido);

                    printf("Elemento atendido com sucesso: %s - %i\n", removido.nome, removido.prioridade);
                    removerElemento(&lista, &removido);

                    printf("-=-=-=-=-Sua Lista-=-=-=-=-\n");
                    imprimirLista(saida);
                }
                else
                {
                    printf("Nao foi possivel atender o elemento\n");
                }
            }
            else
            {
                printf("Elemento atendido com sucesso: %s - %i\n", removido.nome, removido.prioridade);
                removerElemento(&lista, &removido);

                printf("-=-=-=-=-Sua Lista-=-=-=-=-\n");
                imprimirLista(saida);
            }
        }
        else
        {
            printf("Valor Invalido!\n");
        }
        valor = menu();
    }
    printf("\t\t-=-=-=-=-=-FIM-=-=-=-=-=-");

    return 0;
}

// vou receber a entrada adicionando os elementos
// vou pesquisar na lista pra ver se tenho (prioridade 3) else if (prioridade 2) else if (prioridade 1)
// else if (prioridade 0) else (nao tem nenhuma pessoa) printf("NAO TEM NINGUEM) return;

// agora quando eu paro um for por ter completado um ciclo for na funcao atendimento, eu jogo algumas prioridades
// baixas para frente ex: 3 0 1 1,  fica -> 1 3 1 0, mas era pra ser 3 1 1 0

// remover eu vou tirar o elemento inicial da lista de saida, e tirar o mesmo elemento da string da lista
// para retirar da lista eu verifico o caso do anterior ser null, de o ponteiro pro proximo ser NULL

// remover se for igual a zero e o tamanho da lista != NULL eu vou colocar a opcao2 e vou atender