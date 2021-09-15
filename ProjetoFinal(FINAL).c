#include <stdio.h>
#include <ctype.h>

// transformar o y, z, a e b numa matriz e o rodou num array
// o 11 nao e o comeco (mudar isso)

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

// quando for rodar para todos os carros o numero da coordenada, r atual e numero do carro é o mesmo
int Cima (locura quadra[][5], int carro[][2], char R_atual[][2], int numeroR, int coordenadas[][2])
{
    int x = coordenadas[numeroR][0];
    int y = coordenadas[numeroR][1];
    
    if ((x - 1) >= 0)  // se ele tentar chegar -1 paro
    {
        if (quadra[x-1][y].r[0] != 'x' && isalpha(quadra[x-1][y].r[0])) // uma letra diferente de x
        {
            // vou andar, a que eu estava vai pegar o valor
            quadra[x][y].r[0] = R_atual[numeroR][0];
            quadra[x][y].r[1] = R_atual[numeroR][1];
            // vou guardar o valor da q vai estar o carro
            R_atual[numeroR][0] = quadra[x-1][y].r[0];
            R_atual[numeroR][1] = quadra[x-1][y].r[1];
            // carro vai andar
            quadra[x-1][y].r[0] = carro[numeroR][0];
            quadra[x-1][y].r[1] = carro[numeroR][1];
            
            coordenadas[numeroR][0] = x - 1;
            return 1;
        }
    }
    return 0;
}

int Esq (locura quadra[][5], int carro[][2], char R_atual[][2], int numeroR, int coordenadas[][2])
{
    int x = coordenadas[numeroR][0];
    int y = coordenadas[numeroR][1];
    
    if ((y - 1) >= 0)
    {
        if (quadra[x][y-1].r[0] != 'x' && isalpha(quadra[x][y-1].r[0]))
        {
            
            // vou andar, a que eu estava vai pegar o valor
            quadra[x][y].r[0] = R_atual[numeroR][0];
            quadra[x][y].r[1] = R_atual[numeroR][1];
            // vou guardar o valor da q vai estar o carro
            R_atual[numeroR][0] = quadra[x][y-1].r[0];
            R_atual[numeroR][1] = quadra[x][y-1].r[1];
            // carro vai andar
            quadra[x][y-1].r[0] = carro[numeroR][0];
            quadra[x][y-1].r[1] = carro[numeroR][1];
            
            coordenadas[numeroR][1] = y - 1;
            return 1;
        }
    }
    return 0;
}

int Baixo (locura quadra[][5], int carro[][2], char R_atual[][2], int numeroR, int coordenadas[][2], int limite)
{
    int x = coordenadas[numeroR][0];
    int y = coordenadas[numeroR][1];
    
    if ((x + 1) < limite)
    {
        if (quadra[x+1][y].r[0] != 'x' && isalpha(quadra[x+1][y].r[0]))
        {
            // vou andar, a que eu estava vai pegar o valor
            quadra[x][y].r[0] = R_atual[numeroR][0];
            quadra[x][y].r[1] = R_atual[numeroR][1];
            // vou guardar o valor da q vai estar o carro
            R_atual[numeroR][0] = quadra[x+1][y].r[0];
            R_atual[numeroR][1] = quadra[x+1][y].r[1];
            // carro vai andar
            quadra[x+1][y].r[0] = carro[numeroR][0];
            quadra[x+1][y].r[1] = carro[numeroR][1];
            
            coordenadas[numeroR][0] = x + 1;
            return 1;
        }
    }
    return 0;
}

int Dir (locura quadra[][5], int carro[][2], char R_atual[][2], int numeroR, int coordenadas[][2], int limite)
{
    int x = coordenadas[numeroR][0];
    int y = coordenadas[numeroR][1];
    
    if ((y + 1) < limite)
    {
        if (quadra[x][y+1].r[0] != 'x' && isalpha(quadra[x][y+1].r[0]))
        {
            
            // vou andar, a que eu estava vai pegar o valor
            quadra[x][y].r[0] = R_atual[numeroR][0];
            quadra[x][y].r[1] = R_atual[numeroR][1];
            // vou guardar o valor da q vai estar o carro
            R_atual[numeroR][0] = quadra[x][y+1].r[0];
            R_atual[numeroR][1] = quadra[x][y+1].r[1];
            // carro vai andar
            quadra[x][y+1].r[0] = carro[numeroR][0];
            quadra[x][y+1].r[1] = carro[numeroR][1];
            
            coordenadas[numeroR][1] = y + 1;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int rodou[100], coordenadas[100][2], k = 0, x, y;
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
    R_atual[11][0] = quadra[3][1].r[0];
    R_atual[11][1] = quadra[3][1].r[1];
    quadra[3][1].r[0] = carro[11][0];
    quadra[3][1].r[1] = carro[11][1];
    // Carro 12
    R_atual[12][0] = quadra[3][2].r[0];
    R_atual[12][1] = quadra[3][2].r[1];
    quadra[3][2].r[0] = carro[12][0];
    quadra[3][2].r[1] = carro[12][1];
    
    // escrever nas coordenadas antes de andar as coordenadas de todos
    // Posicao do carro 11:
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (quadra[i][j].r[0] == carro[11][0] && quadra[i][j].r[1] == carro[11][1])
            {
                coordenadas[11][0] = i;
                coordenadas[11][1] = j;
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
                coordenadas[12][0] = i;
                coordenadas[12][1] = j;
                break;
            }
        }
    }
    
    // Anda
    for (int a = 0; a < 13; a++)
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
        for (int m = 11; m < 13; m++)
        {
            // vao ter o mesmo padrao os carros que terminam com 1 e 9
            if (carro[m][1] == '1' || carro[m][1] == '9')
            {
                x = coordenadas[m][0];
                y = coordenadas[m][1];
                rodou[m] = 0;
                
                if ((seqMov[0][0] == R_atual[m][0] || seqMov[0][0] == R_atual[m][1]) && rodou[m] == 0)
                {
                    rodou[m] = Cima (quadra, carro, R_atual, m, coordenadas);
                }
                if ((seqMov[0][1] == R_atual[m][0] || seqMov[0][1] == R_atual[m][1]) && rodou[m] == 0)
                {
                    rodou[m] = Esq (quadra, carro, R_atual, m, coordenadas);
                }
                if ((seqMov[0][2] == R_atual[m][0] || seqMov[0][2] == R_atual[m][1]) && rodou[m] == 0)
                {
                    rodou[m] = Baixo (quadra, carro, R_atual, m, coordenadas, quant_linhas);
                }
                if ((seqMov[0][3] == R_atual[m][0] || seqMov[0][3] == R_atual[m][1]) && rodou[m] == 0)
                {
                    rodou[m] = Dir (quadra, carro, R_atual, m, coordenadas, quant_colunas);
                }
            }
            if (carro[m][1] == '2' || carro[m][1] == '0')
            {
                x = coordenadas[m][0];
                y = coordenadas[m][1];
                rodou[m] = 0;
                if ((seqMov[1][0] == R_atual[m][0] || seqMov[1][0] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // cima
                    rodou[m] = Cima (quadra, carro, R_atual, m, coordenadas);
                }
                if ((seqMov[1][1] == R_atual[m][0] || seqMov[1][1] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // Dir
                    rodou[m] = Dir (quadra, carro, R_atual, m, coordenadas, quant_colunas);
                }
                if ((seqMov[1][2] == R_atual[m][0] || seqMov[1][2] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // baixo
                    rodou[m] = Baixo (quadra, carro, R_atual, m, coordenadas, quant_linhas);
                }
                if ((seqMov[1][3] == R_atual[m][0] || seqMov[1][3] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // esq
                    rodou[m] = Esq (quadra, carro, R_atual, m, coordenadas);
                }
            }
            if (carro[m][1] == '3')
            {
                x = coordenadas[m][0];
                y = coordenadas[m][1];
                rodou[m] = 0;
                if ((seqMov[2][0] == R_atual[m][0] || seqMov[2][0] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // baixo
                    rodou[m] = Baixo (quadra, carro, R_atual, m, coordenadas, quant_linhas);
                }
                if ((seqMov[2][1] == R_atual[m][0] || seqMov[2][1] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // esq
                    rodou[m] = Esq (quadra, carro, R_atual, m, coordenadas);
                }
                if ((seqMov[2][2] == R_atual[m][0] || seqMov[2][2] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // cima
                    rodou[m] = Cima (quadra, carro, R_atual, m, coordenadas);
                }
                if ((seqMov[2][3] == R_atual[m][0] || seqMov[2][3] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // Dir
                    rodou[m] = Dir (quadra, carro, R_atual, m, coordenadas, quant_colunas);
                }
            }
            if (carro[m][1] == '4')
            {
                x = coordenadas[m][0];
                y = coordenadas[m][1];
                rodou[m] = 0;
                if ((seqMov[3][0] == R_atual[m][0] || seqMov[3][0] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // baixo
                    rodou[m] = Baixo (quadra, carro, R_atual, m, coordenadas, quant_linhas);
                }
                if ((seqMov[3][1] == R_atual[m][0] || seqMov[3][1] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // Dir
                    rodou[m] = Dir (quadra, carro, R_atual, m, coordenadas, quant_colunas);
                }
                if ((seqMov[3][2] == R_atual[m][0] || seqMov[3][2] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // cima
                    rodou[m] = Cima (quadra, carro, R_atual, m, coordenadas);
                }
                if ((seqMov[3][3] == R_atual[m][0] || seqMov[3][3] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // esq
                    rodou[m] = Esq (quadra, carro, R_atual, m, coordenadas);
                }
            }
            if (carro[m][1] == '5')
            {
                x = coordenadas[m][0];
                y = coordenadas[m][1];
                rodou[m] = 0;
                if ((seqMov[4][0] == R_atual[m][0] || seqMov[4][0] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // esq
                    rodou[m] = Esq (quadra, carro, R_atual, m, coordenadas);
                }
                if ((seqMov[4][1] == R_atual[m][0] || seqMov[4][1] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // baixo
                    rodou[m] = Baixo (quadra, carro, R_atual, m, coordenadas, quant_linhas);
                }
                if ((seqMov[4][2] == R_atual[m][0] || seqMov[4][2] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // Dir
                    rodou[m] = Dir (quadra, carro, R_atual, m, coordenadas, quant_colunas);
                }
                if ((seqMov[4][3] == R_atual[m][0] || seqMov[4][3] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // cima
                    rodou[m] = Cima (quadra, carro, R_atual, m, coordenadas);
                }
            }
            if (carro[m][1] == '6' || carro[m][1] == '8')
            {
                x = coordenadas[m][0];
                y = coordenadas[m][1];
                rodou[m] = 0;
                if ((seqMov[5][0] == R_atual[m][0] || seqMov[5][0] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // Dir
                    rodou[m] = Dir (quadra, carro, R_atual, m, coordenadas, quant_colunas);
                }
                if ((seqMov[5][1] == R_atual[m][0] || seqMov[5][1] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // baixo
                    rodou[m] = Baixo (quadra, carro, R_atual, m, coordenadas, quant_linhas);
                }
                if ((seqMov[5][2] == R_atual[m][0] || seqMov[5][2] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // esq
                    rodou[m] = Esq (quadra, carro, R_atual, m, coordenadas);
                }
                if ((seqMov[5][3] == R_atual[m][0] || seqMov[5][3] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // cima
                    rodou[m] = Cima (quadra, carro, R_atual, m, coordenadas);
                }
            }
            if (carro[m][1] == '7')
            {
                x = coordenadas[m][0];
                y = coordenadas[m][1];
                rodou[m] = 0;
                if ((seqMov[6][0] == R_atual[m][0] || seqMov[6][0] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // esq
                    rodou[m] = Esq (quadra, carro, R_atual, m, coordenadas);
                }
                if ((seqMov[6][1] == R_atual[m][0] || seqMov[6][1] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // cima
                    rodou[m] = Cima (quadra, carro, R_atual, m, coordenadas);
                }
                if ((seqMov[6][2] == R_atual[m][0] || seqMov[6][2] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // Dir
                    rodou[m] = Dir (quadra, carro, R_atual, m, coordenadas, quant_colunas);
                }
                if ((seqMov[6][3] == R_atual[m][0] || seqMov[6][3] == R_atual[m][1]) && rodou[m] == 0)
                {
                    // baixo
                    rodou[m] = Baixo (quadra, carro, R_atual, m, coordenadas, quant_linhas);
                }
            }
        }
        /*
        if (carro[11][1] == '1' || carro[11][1] == '9') //final 1 mesmo padrão
        {
            //Se o seqMov1[0] falhar, olhamos o próximo até o seqMov1[4], "return" o move true
            x = coordenadas[0][0];
            y = coordenadas[0][1];
            rodou[0] = 0;
            
            if ((seqMov[0][0] == R_atual[0][0] || seqMov[0][0] == R_atual[0][1]) && rodou[0] == 0)
            {
                rodou[0] = Cima (quadra, carro, R_atual, 11, 0, coordenadas);
            }
            if ((seqMov[0][1] == R_atual[0][0] || seqMov[0][1] == R_atual[0][1]) && rodou[0] == 0)
            {
                rodou[0] = Esq (quadra, carro, R_atual, 11, 0, coordenadas);
            }
            if ((seqMov[0][2] == R_atual[0][0] || seqMov[0][2] == R_atual[0][1]) && rodou[0] == 0)
            {
                rodou[0] = Baixo (quadra, carro, R_atual, 11, 0, coordenadas, quant_linhas);
            }
            if ((seqMov[0][3] == R_atual[0][0] || seqMov[0][3] == R_atual[0][1]) && rodou[0] == 0)
            {
                rodou[0] = Dir (quadra, carro, R_atual, 11, 0, coordenadas, quant_colunas);
            }
        }
        if (carro[12][1] == '2' || carro[12][1] == '0')
        {
            x = coordenadas[1][0];
            y = coordenadas[1][1];
            rodou[1] = 0;
            if ((seqMov[1][0] == R_atual[1][0] || seqMov[1][0] == R_atual[1][1]) && rodou[1] == 0)
            {
                // cima
                rodou[1] = Cima (quadra, carro, R_atual, 12, 1, coordenadas);
            }
            if ((seqMov[1][1] == R_atual[1][0] || seqMov[1][1] == R_atual[1][1]) && rodou[1] == 0)
            {
                // Dir
                rodou[1] = Dir (quadra, carro, R_atual, 12, 1, coordenadas, quant_colunas);
            }
            if ((seqMov[1][2] == R_atual[1][0] || seqMov[1][2] == R_atual[1][1]) && rodou[1] == 0)
            {
                // baixo
                rodou[1] = Baixo (quadra, carro, R_atual, 12, 1, coordenadas, quant_linhas);
            }
            if ((seqMov[1][3] == R_atual[1][0] || seqMov[1][3] == R_atual[1][1]) && rodou[1] == 0)
            {
                // esq
                rodou[1] = Esq (quadra, carro, R_atual, 12, 1, coordenadas);
            }
        }
        */
    }
        
    printf("\n");
    //Guardar o valor da posição atual
    //Antes de andar, verificar pra onde ele PODE ir com base em sua lista de mov. e sentido da rua
    return 0;
}
