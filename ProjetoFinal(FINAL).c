#include <stdio.h>

//cima = 1, baixo = 2, esq = 3, dir = 4
typedef struct{
    char r[2];
    
}locura;

int main()
{
    locura quadra[4][5];
    char seqMov1[4] = {'c', 'e', 'b', 'd'};
    char rua[2] = {'c', 'e'};
    
    // Matriz
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            quadra[i][j].r[0] = 'r';
            quadra[i][j].r[1] = 'r';
        }
    }
    
    // Quadra
    for (int i = 1; i < 3; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            quadra[i][j].r[0] = 'x';
            quadra[i][j].r[1] = 'x';
        }
    }
    
    // Rua linha 0
    for (int j = 0; j < 5; j++)
    {
        quadra[0][j].r[0] = 'd';
        quadra[0][j].r[1] = 'd';
    }
    
    // Rua coluna
    for (int i = 0; i < 4; i++)
    {
        quadra[i][0].r[0] = 'c';
        quadra[i][0].r[1] = 'c';
        quadra[i][4].r[0] = 'b';
        quadra[i][4].r[1] = 'b';
    }
    
    // Rua
    for (int j = 0; j < 5; j++)
    {
        quadra[3][j].r[0] = rua[0];
        quadra[3][j].r[1] = rua[1];
    }
    
    quadra[0][0].r[0] = 'd';
    quadra[0][0].r[1] = 'd';
    
    // Carro 11
    quadra[3][1].r[0] = '1';
    quadra[3][1].r[1] = '1';
    
    // Posicao do carro 11:
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (quadra[i][j].r[0] == '1' && quadra[i][j].r[1] == '1')
            {
                printf("O carro 11 esta na linha %i e na coluna %i\n", i, j);
                break;
            }
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c", quadra[i][j].r[0]);
            printf("%c ", quadra[i][j].r[1]);
        }
        printf("\n");
    }
    
    
    
    
    /*
    ce
    bd
    cd
    */

    return 0;
}
