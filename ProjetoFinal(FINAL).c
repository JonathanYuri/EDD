#include <stdio.h>

//cima = 1, baixo = 2, esq = 3, dir = 4
typedef struct{
    char r[2];
}locura;

void Quadra (locura quadra[][5], char rua[])
{
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
    
}

int main()
{
    int y, z, andou;
    locura quadra[4][5];
    char seqMov1[4] = {'c', 'e', 'b', 'd'};
    char rua[2] = {'c', 'e'};
    char R_atual[2];
    char carro11[2] = {'1', '1'};
    
    Quadra (quadra, rua);
    
    // Carro 11
    R_atual[0] = quadra[3][1].r[0];
    R_atual[1] = quadra[3][1].r[1];
    quadra[3][1].r[0] = carro11[0];
    quadra[3][1].r[1] = carro11[1];
    // Posicao do carro 11:
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (quadra[i][j].r[0] == '1' && quadra[i][j].r[1] == '1')
            {
                y = i;
                z = j;
                break;
            }
        }
    }
    
    for (int m = 0; m < 3; m++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%c", quadra[i][j].r[0]);
                printf("%c ", quadra[i][j].r[1]);
            }
            printf("\n");
        }
        printf("\n");
            
        if (carro11[1] == '1')
        {
            //Se o seqMov1[0] falhar, olhamos o próximo até o seqMov1[4], "return" o move true
            andou = 0;
            printf("%c %c %i\n", seqMov1)
            if ((seqMov1[0] == R_atual[0] || seqMov1[0] == R_atual[1]) && andou == 0)
            {
                // cima
                if (quadra[y-1][z].r[0] != 'x')
                {
                    // guardar o carro
                        
                    // vou andar, a que eu estava vai pegar o valor
                    quadra[y][z].r[0] = R_atual[0];
                    quadra[y][z].r[1] = R_atual[1];
                    // vou guardar o valor da q vai estar o carro
                    R_atual[0] = quadra[y-1][z].r[0];
                    R_atual[1] = quadra[y-1][z].r[1];
                    // carro vai andar
                    quadra[y-1][z].r[0] = carro11[0];
                    quadra[y-1][z].r[1] = carro11[1];
                    
                    andou = 1;
                }
            }
            // fazer uma funcao para verificar se deu certo encaixar ele na posicao se nao contador + 1
            // para verificar seqMov1[1]
            if ((seqMov1[1] == R_atual[0] || seqMov1[1] == R_atual[1]) && andou == 0)
            {
                // esq
                if (quadra[y][z-1].r[0] != 'x')
                {
                    // guardar o carro
                        
                    // vou andar, a que eu estava vai pegar o valor
                    quadra[y][z].r[0] = R_atual[0];
                    quadra[y][z].r[1] = R_atual[1];
                    // vou guardar o valor da q vai estar o carro
                    R_atual[0] = quadra[y][z-1].r[0];
                    R_atual[1] = quadra[y][z-1].r[1];
                    // carro vai andar
                    quadra[y][z-1].r[0] = carro11[0];
                    quadra[y][z-1].r[1] = carro11[1];
                    
                    andou = 1;
                }
            }
            if ((seqMov1[2] == R_atual[0] || seqMov1[2] == R_atual[1]) && andou == 1)
            {
                // esq
                if (quadra[y+1][z].r[0] != 'x')
                {
                    // guardar o carro
                        
                    // vou andar, a que eu estava vai pegar o valor
                    quadra[y][z].r[0] = R_atual[0];
                    quadra[y][z].r[1] = R_atual[1];
                    // vou guardar o valor da q vai estar o carro
                    R_atual[0] = quadra[y+1][z].r[0];
                    R_atual[1] = quadra[y+1][z].r[1];
                    // carro vai andar
                    quadra[y+1][z].r[0] = carro11[0];
                    quadra[y+1][z].r[1] = carro11[1];
                    
                    andou = 1;
                }
            }
            if ((seqMov1[3] == R_atual[0] || seqMov1[3] == R_atual[1]) && andou == 1)
            {
                // esq
                if (quadra[y][z+1].r[0] != 'x')
                {
                    // guardar o carro
                        
                    // vou andar, a que eu estava vai pegar o valor
                    quadra[y][z].r[0] = R_atual[0];
                    quadra[y][z].r[1] = R_atual[1];
                    // vou guardar o valor da q vai estar o carro
                    R_atual[0] = quadra[y][z+1].r[0];
                    R_atual[1] = quadra[y][z+1].r[1];
                    // carro vai andar
                    quadra[y][z+1].r[0] = carro11[0];
                    quadra[y][z+1].r[1] = carro11[1];
                    
                    andou = 1;
                }
            }
        }
    }
        
    printf("\n");
    //Guardar o valor da posição atual
    //Antes de andar, verificar pra onde ele PODE ir com base em sua lista de mov. e sentido da rua
    return 0;
}
