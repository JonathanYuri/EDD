// GRUPO:
// Jonathan yuri
// Welson Deivid
// Daniel Moreira

// Linguagem : C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*3 atividade) Faça um programa de gerenciamento do estoque de produtos de uma fábrica com uma lista. 

Considerando que o registro dos produtos no estoque contenha as seguintes informações: 
código, descrição, marca, data de validade e quantidade. 

Espera-se com este programa poder listar na tela um relatório do estoque atual,
incluir, retira e consultar produtos do estoque. 

Lembre-se que a operação de retirada deve priorizar a saída dos produtos mais antigos 
e só depois dos produtos mais novos, para evitar a perda de produto por prazo de validade.

(observação você vai precisar de uma struct para definir o produto, 
observe que como temos diferentes entradas de um mesmo produto 
é necessário que você subtraia a quantidade de produtos de uma entrada no estoque até que ela seja zero, 
sendo primeiro retirada as entradas com prazo de validade mais próximo e depois a com prazo de validade mais distante)
*/

typedef struct{
    int codigo;
    char descricao[50];
    char marca[50];
    char data[8];   // XX/XX/XXXX, vai ter 8 digitos
    int quantidade;
}Produto;

typedef struct no{
    Produto item;
    struct no *proximoP;
}No;

typedef struct{
    No *inicio;
}ListaP;

void criarLista(ListaP *lista)
{
    lista->inicio = NULL;
}

void imprimirLista(ListaP lista)
{
    No *aux;

    aux = lista.inicio;

    while (aux != NULL)
    {
        printf("Codigo: %i\n", aux->item.codigo);
        printf("Descricao: %s\n", aux->item.descricao);
        printf("Marca: %s\n", aux->item.marca);
        printf("Validade: %s\n", aux->item.data);
        printf("Quantidade: %i\n\n", aux->item.quantidade);
        aux = aux->proximoP;
    }
    return;
}

int verificarCodigo(ListaP lista, int codigo, Produto *p)
{
    No *aux;
    aux = lista.inicio;

    while (aux != NULL)
    {
        if (aux->item.codigo == codigo)
        {
            *p = aux->item;
            return 1;  // ja existe
        }
        aux = aux->proximoP;
    }
    return 0;
}

int inserirInicio(ListaP *lista, Produto a)
{
    No *aux;
    aux = malloc(sizeof(No));

    if (aux == NULL)
    {
        return 0;
    }
    aux->item = a;
    aux->proximoP = lista->inicio;
    lista->inicio = aux;
    return 1;
}

void remover(ListaP *l, char nome[50], Produto *a)
{
    No *aux, *anterior;

    aux = l->inicio;
    anterior = NULL;

    while (aux != NULL)
    {
        if (strcmp(aux->item.descricao, nome) == 0)
        {
            if (anterior == NULL)
            {
                aux = l->inicio;
                l->inicio = aux->proximoP;  // remover inicio
                *a = aux->item;
            }
            else
            {
                // 1 (2) 3
                *a = aux->item;
                anterior->proximoP = aux->proximoP;

            }
            free(aux);
            return;
        }
        anterior = aux;
        aux = aux->proximoP;
    }
    return;
}

int repetidos(ListaP lista, char nome[50], int rep, int *quantidadeTotal)
{
    No *aux;
    int quantidadeAtual = 0;
    aux = lista.inicio;

    while (aux != NULL)
    {
        if (strcmp(aux->item.descricao, nome) == 0)
        {
            //printf("-%i-\n", aux->item.quantidade);
            quantidadeAtual += aux->item.quantidade;
            rep++;
        }
        aux = aux->proximoP;
    }
    //printf("(%i)\n", quantidadeAtual);
    *quantidadeTotal = quantidadeAtual;
    return rep;
}

int removerModificarProduto(ListaP *lista, char nome[50], int quantidade, Produto *removido)
{
    No *aux;
    aux = lista->inicio;
    int valorAux, diferenca;

    while (aux != NULL)
    {
        if (strcmp(aux->item.descricao, nome) == 0)
        {
            valorAux = aux->item.quantidade;
            diferenca = valorAux - quantidade;
            if (diferenca == 0)
            {
                // remover o produto
                remover(lista, nome, removido);
                return 1;
            }
            else
            {
                aux->item.quantidade = diferenca;
                *removido = aux->item;
                return 0;
            }
        }
        aux = aux->proximoP;
    }
}

void retirarProdutos(ListaP lista, char nome[50], int QntQuero, Produto *menor)
{
    No *aux;
    aux = lista.inicio;

    int diferenca;
    int contador = 0;

    while (aux != NULL)
    {
        if (strcmp(aux->item.descricao, nome) == 0)
        {// iguais
            if (contador == 0)
            {
                *menor = aux->item;
            }
            else
            {
                if (strcmp(aux->item.data, menor->data) < 0) // aux(data) < menor(data)
                {
                    *menor = aux->item;
                }
            }
            contador ++;
        }
        aux = aux->proximoP;
    }

    return;
}

void modificar(ListaP *lista, Produto *menor, int valorDiferenca)
{
    No *aux, *anterior;
    aux = lista->inicio;

    while (aux != NULL)
    {
        if (aux->item.codigo == menor->codigo)
        {
            aux->item.quantidade = valorDiferenca;
            return;
        }
        anterior = aux;
        aux = aux->proximoP;
    }
}

void removerPorCodigo(ListaP *lista, Produto *menor)
{
    No *aux, *anterior;

    aux = lista->inicio;
    anterior = NULL;

    while (aux != NULL)
    {
        if (aux->item.codigo == menor->codigo)
        {
            if (anterior == NULL)
            {
                aux = lista->inicio;
                lista->inicio = aux->proximoP;  // remover iniciar
            }
            else
            {
                // 1 (2) 3  1->3
                anterior->proximoP = aux->proximoP;
            }
            free(aux);
            printf("REMOVIDO\n");
            return;
        }
        anterior = aux;
        aux = aux->proximoP;
    }
    return;
}

int removerDataMenor(ListaP *lista, Produto *menor, int qnt)
{
    int diferenca = menor->quantidade - qnt;

    if (diferenca <= 0)
    {
        //printf("aaaaaa%i\n", diferenca);
        removerPorCodigo(lista, menor);
        return (qnt - menor->quantidade);
        // vou ter que tirar desse e ir pra outro

    }
    else
    {
        // diferenca eh maior que 0, e eu so preciso modificar o valor do no
        modificar(lista, menor, diferenca);
        return 0;
    }
}

int menu()
{
    int num;
    printf("Digite:\n");
    printf("(1) - Para incluir produtos no estoque\n");
    printf("(2) - Para retirar produtos do estoque\n");
    printf("(3) - Para consultar produtos do estoque\n");
    // na 3 perguntar se tem um determinado codigo no estoque
    printf("(4) - Para fazer um relatorio do estoque atual\n");
    // 4 imprimir a lista
    printf("(5) - Para encerrar o programa\n");

    scanf("%i", &num);
    return num;
}

int main()
{
    ListaP lista;
    Produto qualquer, removido, menor;

    int num, v, quantidadeTotal, quantidadeRestante, remov;
    int a = 1, b = 1;
    num = menu();

    criarLista(&lista);

    while (num != 5)
    {
        if (num == 1)
        {
            printf("Digite:\n");
            printf("O codigo do produto: ");
            scanf("%i", &qualquer.codigo);
            
            // codigo e o que vai dizer quem e diferente de quem
            v = verificarCodigo(lista, qualquer.codigo, &qualquer);
            if (v == 1)
            {
                printf("Codigo ja existente\n");
            }
            else
            {
                printf("\nA descricao do produto: ");
                scanf("%s", qualquer.descricao);
                // a descricao e o que vai dizer que um produto e igual ao outro (arroz) = (arroz)
                printf("\nA marca do produto: ");
                scanf("%s", qualquer.marca);
                printf("\nA validade do produto: ");
                printf("\nANO-MES-DIA: ");
                
                scanf("%s", qualquer.data);
                getchar();
                //printf("%s\n", qualquer.data);
                printf("\nA quantidade do produto: ");
                scanf("%i", &qualquer.quantidade);

                v = inserirInicio(&lista, qualquer);

                if (v == 0)
                {
                    printf("Nao foi possivel concluir a operacao\n");
                }
                else
                {
                    printf("Produto adicionado com sucesso\n");
                }

                //printf("%i/%i/%i\n", qualquer.data.dia, qualquer.data.mes, qualquer.data.ano);
                //printf("\nA descricao do produto: ");
            }
        }
        else if (num == 2)
        {
            printf("Digite: \nA descricao do produto que deseja retirar: ");
            scanf("%s", qualquer.descricao);
            printf("\nA quantidade que deseja retirar: ");
            scanf("%i", &qualquer.quantidade);

            v = repetidos(lista, qualquer.descricao, -1, &quantidadeTotal);
            if (v == -1)  // nao tem nenhum igual
            {
                printf("Esse produto nao esta na lista\n");
            }
            else if (v == 0)
            {
                //printf("EXISTE SO 1 ELEMENTO\n");
                //printf("%i\n", quantidadeTotal);
                if (qualquer.quantidade > quantidadeTotal)
                {
                    printf("Nao tem estoque suficiente\n");
                }
                else
                {
                    remov = removerModificarProduto(&lista, qualquer.descricao, qualquer.quantidade, &removido);
                    if (remov == 0)
                    {
                        printf("Produto modificado com sucesso\n");
                    }
                    else
                    {
                        printf("Produto removido com sucesso\n");
                    }
                    printf("codigo: %i\ndescricao: %s\nmarca: %s\n", removido.codigo, removido.descricao, removido.marca);
                    printf("validade: %s\n", removido.data);
                    printf("quantidade: %i\n", removido.quantidade);
                    // a quantidade dele vai ser agora a quantidade_dele - qualquer.quantidade;
                    // se a quantidade for 0 eu removo o elemento
                }
            }
            else // v > 0
            {
                //printf("(%i)\n", quantidadeTotal);
                if (qualquer.quantidade > quantidadeTotal)
                {
                    printf("Nao tem estoque suficiente\n");
                }
                else
                {
                    quantidadeRestante = qualquer.quantidade;
                    while (quantidadeRestante != 0)
                    {
                        retirarProdutos(lista, qualquer.descricao, qualquer.quantidade, &menor);
                        quantidadeRestante = removerDataMenor(&lista, &menor, quantidadeRestante);
                    }
                    // agora eu vou ver quem sao as menores validades e deixar no inicio da lista
                    // ai eu vou tirar as quantidades assim: se a quantidadePedida for maior que a quntDoPrimeiro
                    // ai eu tiro o primeiro e vou pro segundo, tirando o primeiro da lista (das duas)
                    // tiro da lista procurando o codigo

                    // ter cuidado nesse tenho que verificar quem tem a menor validade e tirar dele
                    // se a quantidade que eu pedi for maior que a que eu tenho nesse bloco eu tiro dele e do prox
                }
                //printf("TEM MAIS DE 1 ELEMENTO\n");
            }
            
            // vou identificar um produto pelo nome nao pelo codigo
        }
        else if (num == 3)
        {
            printf("Digite o codigo do produto a ser consultado: ");
            scanf("%i", &qualquer.codigo);

            v = verificarCodigo(lista, qualquer.codigo, &qualquer);
            if (v == 0)
            {
                printf("Produto nao existe na lista\n\n");
            }
            else
            {
                printf("Codigo do produto: %i\n", qualquer.codigo);
                printf("Descricao do produto: %s\n", qualquer.descricao);
                printf("Marca do produto: %s\n", qualquer.marca);
                printf("Validade do produto: %s\n", qualquer.data);
                printf("Quantidade do produto: %i\n\n", qualquer.quantidade);
            }
        }
        else if (num == 4)
        {
            imprimirLista(lista);
        }
        else
        {
            printf("Valor Invalido\n");
        }
        num = menu();
    }
    printf("FIM\n");
    return 0;
}

// vou verificar se a descricao desse que eu estou olhando ja nao esta na lista de saida
// 392 367