#include <stdio.h>
#include <ctype.h>

// transformar o y, z, a e b numa matriz e o rodou num array
// o 11 nao e o comeco (mudar isso)

//cima = 1, baixo = 2, esq = 3, dir = 4
typedef struct{
    char r[2];
}locura;

// eu vou andando conforme o sentido da rua, só quando matriz[i][j].r[0] != matriz[i][j].r[1]
// eu vou usar minha decisao

void Quadra (locura matriz[][37], char rua[], int coordenadas[][2], char Rua_atual[][2])
{
    // Matriz
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 37; j++)
        {
            matriz[i][j].r[0] = 'r';
            matriz[i][j].r[1] = 'r';
        }
    }
    
    // Quadra
    for (int i = 1; i < 28; i+=3)
    {
        for (int j = 1; j < 37; j+=4)
        {
            for (int a = i; a < i+2; a++)
            {
                for (int b = j; b < j+3; b++)
                {
                    matriz[a][b].r[0] = 'x';
                    matriz[a][b].r[1] = 'x';
                }
            }
        }
    }
    
    // Ruas Colunas
    //rua[4] = {'c', 'd', 'e', 'b'};
    for (int i = 0; i < 28; i++)
    {
        // Coluna 1: c
        matriz[i][4].r[0] = rua[0];
        matriz[i][4].r[1] = rua[0];
        
        // Coluna 2: c
        matriz[i][8].r[0] = rua[0];
        matriz[i][8].r[1] = rua[0];
        
        // Coluna 3: c
        matriz[i][12].r[0] = rua[0];
        matriz[i][12].r[1] = rua[0];
        
        // Coluna 4: b
        matriz[i][16].r[0] = rua[3];
        matriz[i][16].r[1] = rua[3];
        
        // Coluna 5: b
        matriz[i][20].r[0] = rua[3];
        matriz[i][20].r[1] = rua[3];
        
        // Coluna 6: b
        matriz[i][24].r[0] = rua[3];
        matriz[i][24].r[1] = rua[3];
        
        // Coluna 7: b
        matriz[i][28].r[0] = rua[3];
        matriz[i][28].r[1] = rua[3];
        
        // Coluna 8: b
        matriz[i][32].r[0] = rua[3];
        matriz[i][32].r[1] = rua[3];
    }
    
    // Ruas Linhas
    //rua[4] = {'c', 'd', 'e', 'b'};
    for (int j = 0; j < 37; j++)
    {
        // Rua 1: e
        matriz[3][j].r[0] = rua[2];
        matriz[3][j].r[1] = rua[2];
        
        // Rua 2: e
        matriz[6][j].r[0] = rua[2];
        matriz[6][j].r[1] = rua[2];
        
        // Rua 3: d
        matriz[9][j].r[0] = rua[1];
        matriz[9][j].r[1] = rua[1];
        
        // Rua 4: d
        matriz[12][j].r[0] = rua[1];
        matriz[12][j].r[1] = rua[1];
        
        // Rua 5: d
        matriz[15][j].r[0] = rua[1];
        matriz[15][j].r[1] = rua[1];
        
        // Rua 6: e
        matriz[18][j].r[0] = rua[2];
        matriz[18][j].r[1] = rua[2];
        
        // Rua 7: e
        matriz[21][j].r[0] = rua[2];
        matriz[21][j].r[1] = rua[2];
        
        // Rua 8: e
        matriz[24][j].r[0] = rua[2];
        matriz[24][j].r[1] = rua[2];
    }
    
    // Rua linha 0 e 27
    for (int j = 0; j < 37; j++)
    {
        matriz[0][j].r[0] = 'd';
        matriz[0][j].r[1] = 'd';
        matriz[27][j].r[0] = 'e';
        matriz[27][j].r[1] = 'e';
    }
    
    // Rua coluna 0 e 36
    for (int i = 0; i < 28; i++)
    {
        matriz[i][0].r[0] = 'c';
        matriz[i][0].r[1] = 'c';
        matriz[i][36].r[0] = 'b';
        matriz[i][36].r[1] = 'b';
    }
    
    // Quinas
    matriz[0][0].r[0] = 'd';
    matriz[0][0].r[1] = 'd';
    
    matriz[27][36].r[0] = 'e';
    matriz[27][36].r[1] = 'e';
    
    // Cruzamentos
    for (int i = 3; i < 25; i+=3)
    {
        for (int j = 4; j < 33; j+=4)
        {
            matriz[i][j].r[0] = matriz[i-1][j].r[0];
        }
    }
    //Coordenadas dos carros 11 - 98
    int f = 0, g = 0, k = 11;
    for (int x = 1; x < 10; x++)
    {
        for (int y = 1; y < 9; y++)
        {
            if (k % 10 == 9)
            {
                k += 2;
            }
            //Guarda o valor da rua
            Rua_atual[k][0] = matriz[f+3][g+5].r[0];
            Rua_atual[k][1] = matriz[f+3][g+5].r[1];
            //Coloca o carro na posição
            matriz[f+3][g+5].r[0] = x +'0';
            matriz[f+3][g+5].r[1] = y +'0';
            //Salva as coordenadas do carro
            coordenadas[k][0] = f + 3;
            coordenadas[k][1] = g + 5;
            
            g += 4;
            k++;
        }
        g = 0;
        f += 3;
    }
    //Coordenadas de 01 - 08
    g = 1;
    for (int y = 6; y < 35; y+=4)
    {
        Rua_atual[g][0] = matriz[15][y].r[0];
        Rua_atual[g][1] = matriz[15][y].r[1];
        
        matriz[15][y].r[0] = '0';
        matriz[15][y].r[1] = g +'0';
        
        coordenadas[g][0] = 15;
        coordenadas[g][1] = y;
        
        //printf ("%d %d\n", )
        g++;
    }
    //Coordenadas de 10 - 90 (+10)
    f = 1;
    for (int x = 3; x < 28; x+=3)
    {
        Rua_atual[f*10][0] = matriz[x][23].r[0];
        Rua_atual[f*10][1] = matriz[x][23].r[1];
        
        matriz[x][23].r[0] = f +'0';
        matriz[x][23].r[1] = '0';
        
        coordenadas[f*10][0] = x;
        coordenadas[f*10][1] = 23;
        f++;
    }
    f = 1;
    //Coordenadas de 19 - 99 (+10)
    for (int x = 2; x < 28; x+=3)
    {
        Rua_atual[(f*10)+9][0] = matriz[x][36].r[0];
        Rua_atual[(f*10)+9][1] = matriz[x][36].r[1];
        
        matriz[x][36].r[0] = f +'0';
        matriz[x][36].r[1] = '9';
        
        coordenadas[(f*10)+9][0] = x;
        coordenadas[(f*10)+9][1] = 36;
        f++;
    }
    
    //Coordenadas do Carro 100
    Rua_atual[100][0] = matriz[15][19].r[0];
    Rua_atual[100][1] = matriz[15][19].r[1];
    
    matriz[15][19].r[0] = '0';
    matriz[15][19].r[1] = '0';
    
    coordenadas[100][0] = 15;
    coordenadas[100][1] = 19;
    
    //Coordenadas do Carro 09
    Rua_atual[9][0] = matriz[16][36].r[0];
    Rua_atual[9][1] = matriz[16][36].r[1];
    
    matriz[16][36].r[0] = '0';
    matriz[16][36].r[1] = '9';
    
    coordenadas[9][0] = 16;
    coordenadas[9][1] = 36;
    
    
    // Print
    /*
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 37; j++)
        {
            if (isdigit (matriz[i][j].r[0]))
            {
                printf("%c", matriz[i][j].r[0]);
                printf("%c ", matriz[i][j].r[1]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    */
    
    /*for (int i = 1; i < 101; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf ("%d ", coordenadas[i][j]);
        }
        printf ("\n");
    }*/
}

int Cima (locura quadra[][37], char carro[][2], char R_atual[][2], int numeroR, int coordenadas[][2])
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

int Esq (locura quadra[][37], char carro[][2], char R_atual[][2], int numeroR, int coordenadas[][2])
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

int Baixo (locura quadra[][37], char carro[][2], char R_atual[][2], int numeroR, int coordenadas[][2], int limite)
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

int Dir (locura quadra[][37], char carro[][2], char R_atual[][2], int numeroR, int coordenadas[][2], int limite)
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
    int rodou[101], coordenadas[101][2], k = 0, x, y;
    int quant_linhas = 28;
    int quant_colunas = 37;
    
    locura quadra[28][37];
    char rua[4] = {'c', 'd', 'e', 'b'};
    
    
    char seqMov[7][4] = {{'c', 'e', 'b', 'd'}, {'c', 'd', 'b', 'e'}, {'b', 'e', 'c', 'd'}, {'b', 'd', 'c', 'e'}, {'e', 'b', 'd', 'c'}, {'d', 'b', 'e', 'c'}, {'e', 'c', 'd', 'b'}};
    char R_atual[101][2];
    char carro[101][2];
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            carro[k][0] = i+'0';
            carro[k][1] = j+'0';
            k++;
        }
    }
    carro[100][0] = '0';
    carro[100][1] = '0';
    
    //Carro Começando do i = 1 para n usarmos o carro[0][0]
    /*
    for (int i = 1; i < 101; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf ("%c", carro[i][j]);
        }
        printf ("\n");
    }*/
    
    Quadra (quadra, rua, coordenadas, R_atual);
    
    
    for (int m = 0; m < 100; m++)
    {
        for (int i = 0; i < 28; i++)
        {
            for (int j = 0; j < 37; j++)
            {
                printf("%c", quadra[i][j].r[0]);
                printf("%c ", quadra[i][j].r[1]);
            }
            printf("\n");
        }
        printf("\n");
        // carro[x][1] == '1'
        for (int m = 1; m < 101; m++)
        {
            // vao ter o mesmo padrao os carros que terminam com 1 e 9
            
            // a gente so vai observar o seqmov se estiver num sinal se nao a gente so vai andar com ele no sentido da pista
            // se matriz[i][j].r[0] != matriz[i][j].r[1] ele decide pra onde vai (entra no if VV)
            // se nao continuamos no sentido da pista
            
            if (carro[m][1] == '1' || carro[m][1] == '9')
            {
                //printf("%c%c\n", carro[m][0], carro[m][1]);
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
        
    }
    
        
    printf("\n");
    //Guardar o valor da posição atual
    //Antes de andar, verificar pra onde ele PODE ir com base em sua lista de mov. e sentido da rua
    return 0;
}
