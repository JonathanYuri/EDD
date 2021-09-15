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

void Quadra (locura matriz[][37], char rua[])
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
    
    // Rua linha 0 e 27
    for (int j = 0; j < 37; j++)
    {
        matriz[0][j].r[0] = 'd';
        matriz[0][j].r[1] = 'd';
        matriz[27][j].r[0] = 'e';
        matriz[27][j].r[1] = 'e';
    }
    
    // Rua coluna
    for (int i = 0; i < 28; i++)
    {
        matriz[i][0].r[0] = 'c';
        matriz[i][0].r[1] = 'c';
        matriz[i][36].r[0] = 'b';
        matriz[i][36].r[1] = 'b';
    }
    /*
    
    // Rua
    for (int j = 0; j < 5; j++)
    {
        quadra[3][j].r[0] = rua[0];
        quadra[3][j].r[1] = rua[1];
    }
    
    quadra[0][0].r[0] = 'd';
    quadra[0][0].r[1] = 'd';
    
    quadra[3][4].r[0] = 'b';
    */
    
    // Print
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 37; j++)
        {
            printf("%c", matriz[i][j].r[0]);
            printf("%c ", matriz[i][j].r[1]);
        }
        printf("\n");
    }
}

int main()
{
    int rodou[100], coordenadas[100][2], k = 0, x, y;
    int quant_linhas = 4;
    int quant_colunas = 5;
    
    locura quadra[28][37];
    char rua[2] = {'c', 'e'};
    /*
    char seqMov[7][4] = {{'c', 'e', 'b', 'd'}, {'c', 'd', 'b', 'e'}, {'b', 'e', 'c', 'd'}, {'b', 'd', 'c', 'e'}, {'e', 'b', 'd', 'c'}, {'d', 'b', 'e', 'c'}, {'e', 'c', 'd', 'b'}};
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
    */
    Quadra (quadra, rua);
    /*
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
                coordenadas[0][0] = i;
                coordenadas[0][1] = j;
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
                coordenadas[1][0] = i;
                coordenadas[1][1] = j;
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
        if (carro[11][1] == '1' || carro[11][1] == '9') //final 1 mesmo padrão
        {
            //Se o seqMov1[0] falhar, olhamos o próximo até o seqMov1[4], "return" o move true
            x = coordenadas[0][0];
            y = coordenadas[0][1];
            rodou[0] = 0;
            
            if ((seqMov[0][0] == R_atual[0][0] || seqMov[0][0] == R_atual[0][1]) && rodou[0] == 0)
            {
                // cima
                if ((x - 1) >= 0)  // se ele tentar chegar -1 paro
                {
                    if (quadra[x-1][y].r[0] != 'x' && isalpha(quadra[x-1][y].r[0])) // uma letra diferente de x
                    {
                        
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[x][y].r[0] = R_atual[0][0];
                        quadra[x][y].r[1] = R_atual[0][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[0][0] = quadra[x-1][y].r[0];
                        R_atual[0][1] = quadra[x-1][y].r[1];
                        // carro vai andar
                        quadra[x-1][y].r[0] = carro[11][0];
                        quadra[x-1][y].r[1] = carro[11][1];
                        
                        coordenadas[0][0] = x - 1;
                        rodou[0] = 1;
                    }
                }
            }
            if ((seqMov[0][1] == R_atual[0][0] || seqMov[0][1] == R_atual[0][1]) && rodou[0] == 0)
            {
                // esq
                if ((y - 1) >= 0)
                {
                    if (quadra[x][y-1].r[0] != 'x' && isalpha(quadra[x][y-1].r[0]))
                    {
                        
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[x][y].r[0] = R_atual[0][0];
                        quadra[x][y].r[1] = R_atual[0][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[0][0] = quadra[x][y-1].r[0];
                        R_atual[0][1] = quadra[x][y-1].r[1];
                        // carro vai andar
                        quadra[x][y-1].r[0] = carro[11][0];
                        quadra[x][y-1].r[1] = carro[11][1];
                        
                        coordenadas[0][1] = y - 1;
                        rodou[0] = 1;
                    }
                }
            }
            if ((seqMov[0][2] == R_atual[0][0] || seqMov[0][2] == R_atual[0][1]) && rodou[0] == 0)
            {
                // baixo
                if ((x + 1) < quant_linhas)
                {
                    if (quadra[x+1][y].r[0] != 'x' && isalpha(quadra[x+1][y].r[0]))
                    {
                        
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[x][y].r[0] = R_atual[0][0];
                        quadra[x][y].r[1] = R_atual[0][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[0][0] = quadra[x+1][y].r[0];
                        R_atual[0][1] = quadra[x+1][y].r[1];
                        // carro vai andar
                        quadra[x+1][y].r[0] = carro[11][0];
                        quadra[x+1][y].r[1] = carro[11][1];
                        
                        coordenadas[0][0] = x + 1;
                        rodou[0] = 1;
                    }
                }
            }
            if ((seqMov[0][3] == R_atual[0][0] || seqMov[0][3] == R_atual[0][1]) && rodou[0] == 0)
            {
                // dir
                if ((y + 1) < quant_colunas)
                {
                    if (quadra[x][y+1].r[0] != 'x' && isalpha(quadra[x][y+1].r[0]))
                    {
                        
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[x][y].r[0] = R_atual[0][0];
                        quadra[x][y].r[1] = R_atual[0][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[0][0] = quadra[x][y+1].r[0];
                        R_atual[0][1] = quadra[x][y+1].r[1];
                        // carro vai andar
                        quadra[x][y+1].r[0] = carro[11][0];
                        quadra[x][y+1].r[1] = carro[11][1];
                        
                        coordenadas[0][1] = y + 1;
                        rodou[0] = 1;
                    }
                }
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
                if ((x - 1) >= 0)  // se ele tentar chegar -1 paro
                {
                    // tenho que verificar se ela pode mover de acordo com o sentido da rua
                    if (quadra[x-1][y].r[0] != 'x' && isalpha(quadra[x-1][y].r[0]))
                    {
                        
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[x][y].r[0] = R_atual[1][0];
                        quadra[x][y].r[1] = R_atual[1][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[1][0] = quadra[x-1][y].r[0];
                        R_atual[1][1] = quadra[x-1][y].r[1];
                        // carro vai andar
                        quadra[x-1][y].r[0] = carro[12][0];
                        quadra[x-1][y].r[1] = carro[12][1];
                        
                        coordenadas[1][0] = x - 1;
                        rodou[1] = 1;
                    }
                }
            }
            if ((seqMov[1][1] == R_atual[1][0] || seqMov[1][1] == R_atual[1][1]) && rodou[1] == 0)
            {
                // dir
                if ((y + 1) >= 0)
                {
                    if (quadra[x][y+1].r[0] != 'x' && isalpha(quadra[x][y+1].r[0]))
                    {
                        
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[x][y].r[0] = R_atual[1][0];
                        quadra[x][y].r[1] = R_atual[1][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[1][0] = quadra[x][y+1].r[0];
                        R_atual[1][1] = quadra[x][y+1].r[1];
                        // carro vai andar
                        quadra[x][y+1].r[0] = carro[12][0];
                        quadra[x][y+1].r[1] = carro[12][1];
                        
                        coordenadas[1][1] = y + 1;
                        rodou[1] = 1;
                    }
                }
            }
            if ((seqMov[1][2] == R_atual[1][0] || seqMov[1][2] == R_atual[1][1]) && rodou[1] == 0)
            {
                // baixo
                if ((x + 1) < quant_linhas)
                {
                    if (quadra[x+1][y].r[0] != 'x' && isalpha(quadra[x+1][y].r[0]))
                    {
                        
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[x][y].r[0] = R_atual[1][0];
                        quadra[x][y].r[1] = R_atual[1][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[1][0] = quadra[x+1][y].r[0];
                        R_atual[1][1] = quadra[x+1][y].r[1];
                        // carro vai andar
                        quadra[x+1][y].r[0] = carro[12][0];
                        quadra[x+1][y].r[1] = carro[12][1];
                        
                        coordenadas[1][0] = x + 1;
                        rodou[1] = 1;
                    }
                }
            }
            if ((seqMov[1][3] == R_atual[1][0] || seqMov[1][3] == R_atual[1][1]) && rodou[1] == 0)
            {
                // esq
                if ((y - 1) < quant_colunas)
                {
                    if (quadra[x][y-1].r[0] != 'x' && isalpha(quadra[x][y-1].r[0]))
                    {
                        
                        // vou andar, a que eu estava vai pegar o valor
                        quadra[x][y].r[0] = R_atual[1][0];
                        quadra[x][y].r[1] = R_atual[1][1];
                        // vou guardar o valor da q vai estar o carro
                        R_atual[1][0] = quadra[x][y-1].r[0];
                        R_atual[1][1] = quadra[x][y-1].r[1];
                        // carro vai andar
                        quadra[x][y-1].r[0] = carro[12][0];
                        quadra[x][y-1].r[1] = carro[12][1];
                        
                        coordenadas[1][1] = y - 1;
                        rodou[1] = 1;
                    }
                }
            }
        }
        
    }
    */
        
    printf("\n");
    //Guardar o valor da posição atual
    //Antes de andar, verificar pra onde ele PODE ir com base em sua lista de mov. e sentido da rua
    return 0;
}

/*
  int matriz[28][37];
    
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 37; j++)
        {
            matriz[i][j] = 0;
        }
    }
    // Semaforo
    for (int i = 0; i < 28; i+=3)
    {
        for (int j = 0; j < 37; j+=4)
        {
            matriz[i][j] = 3;
        }
    }
    // tirar semaforos das quinas
    matriz[0][0] = 0;
    matriz[0][36] = 0;
    matriz[27][0] = 0;
    matriz[27][36] = 0;
    
    // Quadra
    for (int i = 1; i < 28; i+=3)
    {
        for (int j = 1; j < 37; j+=4)
        {
            for (int a = i; a < i+2; a++)
            {
                for (int b = j; b < j+3; b++)
                {
                    matriz[a][b] = 1;
                }
            }
            /*
            matriz[i][j] = 1;
            matriz[i][j+1] = 1;
            matriz[i][j+2] = 1;
            matriz[i+1][j] = 1;
            matriz[i+1][j+1] = 1;
            matriz[i+1][j+2] = 1;
            */
        }
    }
    
    // Print
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 37; j++)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
*/
