#include <stdio.h>
#include <ctype.h>

// transformar o y, z, a e b numa matriz e o andou num array

//cima = 1, baixo = 2, esq = 3, dir = 4
typedef struct{
    char r[2];
}locura;

// para verificar se ja tem um carro ali, é mais facil verificar se não existe uma rua naquele lugar
// pq sim

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
    
    quadra[3][4].r[0] = 'b';
}

int main()
{
    int andou, andou2, k = 0, y, z, a, b;
    int quant_linhas = 4;
    int quant_colunas = 5;
    
    locura quadra[4][5];
    char seqMov[7][4] = {{'c', 'e', 'b', 'd'}, {'c', 'd', 'b', 'e'}, {'b', 'e', 'c', 'd'}, {'b', 'd', 'c', 'e'}, {'e', 'b', 'd', 'c'}, {'d', 'b', 'e', 'c'}, {'e', 'c', 'd', 'b'}};
    char rua[2] = {'c', 'e'};
    char R_atual[100][2];
    int carro[100][2];
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            carro[k][0] = i+'0';
            carro[k][1] = j+'0';
            k++;
        }
    }
    
    Quadra (quadra, rua);
    
    // Carro 11
    R_atual[0][0] = quadra[3][1].r[0];
    R_atual[0][1] = quadra[3][1].r[1];
    quadra[3][1].r[0] = carro[11][0];
    quadra[3][1].r[1] = carro[11][1];
     // Carro 12
    R_atual[1][0] = quadra[3][2].r[0];
    R_atual[1][1] = quadra[3][2].r[1];
    quadra[3][2].r[0] = carro[12][0];
    quadra[3][2].r[1] = carro[12][1];
    
    
    // Posicao do carro 11:
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (quadra[i][j].r[0] == carro[11][0] && quadra[i][j].r[1] == carro[11][1])
            {
                y = i;
                z = j;
                break;
            }
        }
    }
    //posicao do carro 12:
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (quadra[i][j].r[0] == carro[12][0] && quadra[i][j].r[1] == carro[12][1])
            {
                a = i;
                b = j;
                break;
            }
        }
    }
    
    for (int m = 0; m < 13; m++)
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
        // carro[x][1] == '1'
        if (carro[11][1] == '1') //final 1 mesmo padrão
        {
            //Se o seqMov1[0] falhar, olhamos o próximo até o seqMov1[4], "return" o move true
            andou = 0;
            
            if ((seqMov[0][0] == R_atual[0][0] || seqMov[0][0] == R_atual[0][1]) && andou == 0)
            {
                // cima
                if ((y - 1) >= 0)  // se ele tentar chegar -1 paro
                {
                    if (quadra[y-1][z].r[0] != 'x' && isalpha(quadra[y-1][z].r[0])) // uma letra diferente de x
                    {
                        // guardar o carro
                            
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[y][z].r[0] = R_atual[0][0];
                        quadra[y][z].r[1] = R_atual[0][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[0][0] = quadra[y-1][z].r[0];
                        R_atual[0][1] = quadra[y-1][z].r[1];
                        // carro vai andar
                        quadra[y-1][z].r[0] = carro[11][0];
                        quadra[y-1][z].r[1] = carro[11][1];
                        
                        y = y - 1;
                        andou = 1;
                    }
                }
            }
            if ((seqMov[0][1] == R_atual[0][0] || seqMov[0][1] == R_atual[0][1]) && andou == 0)
            {
                // esq
                if ((z - 1) >= 0)
                {
                    if (quadra[y][z-1].r[0] != 'x' && isalpha(quadra[y][z-1].r[0]))
                    {
                        // guardar o carro
                            
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[y][z].r[0] = R_atual[0][0];
                        quadra[y][z].r[1] = R_atual[0][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[0][0] = quadra[y][z-1].r[0];
                        R_atual[0][1] = quadra[y][z-1].r[1];
                        // carro vai andar
                        quadra[y][z-1].r[0] = carro[11][0];
                        quadra[y][z-1].r[1] = carro[11][1];
                        
                        z = z - 1;
                        andou = 1;
                    }
                }
            }
            if ((seqMov[0][2] == R_atual[0][0] || seqMov[0][2] == R_atual[0][1]) && andou == 0)
            {
                // baixo
                if ((y + 1) < quant_linhas)
                {
                    if (quadra[y+1][z].r[0] != 'x' && isalpha(quadra[y+1][z].r[0]))
                    {
                        // guardar o carro
                            
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[y][z].r[0] = R_atual[0][0];
                        quadra[y][z].r[1] = R_atual[0][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[0][0] = quadra[y+1][z].r[0];
                        R_atual[0][1] = quadra[y+1][z].r[1];
                        // carro vai andar
                        quadra[y+1][z].r[0] = carro[11][0];
                        quadra[y+1][z].r[1] = carro[11][1];
                        
                        y = y + 1;
                        andou = 1;
                    }
                }
            }
            if ((seqMov[0][3] == R_atual[0][0] || seqMov[0][3] == R_atual[0][1]) && andou == 0)
            {
                // dir
                if ((z + 1) < quant_colunas)
                {
                    if (quadra[y][z+1].r[0] != 'x' && isalpha(quadra[y][z+1].r[0]))
                    {
                        // guardar o carro
                            
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[y][z].r[0] = R_atual[0][0];
                        quadra[y][z].r[1] = R_atual[0][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[0][0] = quadra[y][z+1].r[0];
                        R_atual[0][1] = quadra[y][z+1].r[1];
                        // carro vai andar
                        quadra[y][z+1].r[0] = carro[11][0];
                        quadra[y][z+1].r[1] = carro[11][1];
                        
                        z = z + 1;
                        andou = 1;
                    }
                }
            }
        }
        if (carro[12][1] == '2')
        {
            andou2 = 0;
            if ((seqMov[1][0] == R_atual[1][0] || seqMov[1][0] == R_atual[1][1]) && andou2 == 0)
            {
                // cima
                if ((a - 1) >= 0)  // se ele tentar chegar -1 paro
                {
                    // tenho que verificar se ela pode mover de acordo com o sentido da rua
                    if (quadra[a-1][b].r[0] != 'x' && isalpha(quadra[a-1][b].r[0]))
                    {
                        // guardar o carro
                            
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[a][b].r[0] = R_atual[1][0];
                        quadra[a][b].r[1] = R_atual[1][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[1][0] = quadra[a-1][b].r[0];
                        R_atual[1][1] = quadra[a-1][b].r[1];
                        // carro vai andar
                        quadra[a-1][b].r[0] = carro[12][0];
                        quadra[a-1][b].r[1] = carro[12][1];
                        
                        a = a - 1;
                        andou2 = 1;
                    }
                }
            }
            if ((seqMov[1][1] == R_atual[1][0] || seqMov[1][1] == R_atual[1][1]) && andou2 == 0)
            {
                // dir
                if ((b + 1) >= 0)
                {
                    if (quadra[a][b+1].r[0] != 'x' && isalpha(quadra[a][b+1].r[0]))
                    {
                        // guardar o carro
                            
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[a][b].r[0] = R_atual[1][0];
                        quadra[a][b].r[1] = R_atual[1][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[1][0] = quadra[a][b+1].r[0];
                        R_atual[1][1] = quadra[a][b+1].r[1];
                        // carro vai andar
                        quadra[a][b+1].r[0] = carro[12][0];
                        quadra[a][b+1].r[1] = carro[12][1];
                        
                        b = b + 1;
                        andou2 = 1;
                    }
                }
            }
            if ((seqMov[1][2] == R_atual[1][0] || seqMov[1][2] == R_atual[1][1]) && andou2 == 0)
            {
                // baixo
                if ((a + 1) < quant_linhas)
                {
                    if (quadra[a+1][b].r[0] != 'x' && isalpha(quadra[a+1][b].r[0]))
                    {
                        // guardar o carro
                            
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[a][b].r[0] = R_atual[1][0];
                        quadra[a][b].r[1] = R_atual[1][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[1][0] = quadra[a+1][b].r[0];
                        R_atual[1][1] = quadra[a+1][b].r[1];
                        // carro vai andar
                        quadra[a+1][b].r[0] = carro[12][0];
                        quadra[a+1][b].r[1] = carro[12][1];
                        
                        a = a + 1;
                        andou2 = 1;
                    }
                }
            }
            if ((seqMov[1][3] == R_atual[1][0] || seqMov[1][3] == R_atual[1][1]) && andou2 == 0)
            {
                // esq
                if ((b - 1) < quant_colunas)
                {
                    if (quadra[a][b-1].r[0] != 'x' && isalpha(quadra[a][b-1].r[0]))
                    {
                        // guardar o carro
                            
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[a][b].r[0] = R_atual[1][0];
                        quadra[a][b].r[1] = R_atual[1][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[1][0] = quadra[a][b-1].r[0];
                        R_atual[1][1] = quadra[a][b-1].r[1];
                        // carro vai andar
                        quadra[a][b-1].r[0] = carro[12][0];
                        quadra[a][b-1].r[1] = carro[12][1];
                        
                        b = b - 1;
                        andou2 = 1;
                    }
                }
            }
        }
    }
        
    printf("\n");
    //Guardar o valor da posição atual
    //Antes de andar, verificar pra onde ele PODE ir com base em sua lista de mov. e sentido da rua
    return 0;
}
