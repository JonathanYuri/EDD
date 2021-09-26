#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

// GRUPO:

// Welson Deivid
// Jonathan Yuri

// Linguagem: C

typedef struct{
    char r[2];
}Cidade;

void ICLandia (Cidade IClandia[][37], char rua[], int coordenadas[][2], char Rua_atual[][2], char semaforo[][6], int coord_semaforos[][2])
{
    // Preencher tudo com rr
    char a;
    
    // fazer as quadras
    for (int i = 1; i < 28; i+=3)
    {
        for (int j = 1; j < 37; j+=4)
        {
            for (int a = i; a < i+2; a++)
            {
                for (int b = j; b < j+3; b++)
                {
                    IClandia[a][b].r[0] = 'x';
                    IClandia[a][b].r[1] = 'x';
                }
            }
        }
    }
    
    // Ruas Colunas
    //rua[4] = {'c', 'd', 'e', 'b'};
    for (int i = 0; i < 28; i++)
    {
        // Coluna 1: c
        IClandia[i][4].r[0] = rua[0];
        IClandia[i][4].r[1] = rua[0];
        
        // Coluna 2: c
        IClandia[i][8].r[0] = rua[0];
        IClandia[i][8].r[1] = rua[0];
        
        // Coluna 3: c
        IClandia[i][12].r[0] = rua[0];
        IClandia[i][12].r[1] = rua[0];
        
        // Coluna 4: b
        IClandia[i][16].r[0] = rua[3];
        IClandia[i][16].r[1] = rua[3];
        
        // Coluna 5: b
        IClandia[i][20].r[0] = rua[3];
        IClandia[i][20].r[1] = rua[3];
        
        // Coluna 6: b
        IClandia[i][24].r[0] = rua[3];
        IClandia[i][24].r[1] = rua[3];
        
        // Coluna 7: b
        IClandia[i][28].r[0] = rua[3];
        IClandia[i][28].r[1] = rua[3];
        
        // Coluna 8: b
        IClandia[i][32].r[0] = rua[3];
        IClandia[i][32].r[1] = rua[3];
    }
    
    // Ruas Linhas
    //rua[4] = {'c', 'd', 'e', 'b'};
    for (int j = 0; j < 37; j++)
    {
        // Rua 1: e
        IClandia[3][j].r[0] = rua[2];
        IClandia[3][j].r[1] = rua[2];
        
        // Rua 2: e
        IClandia[6][j].r[0] = rua[2];
        IClandia[6][j].r[1] = rua[2];
        
        // Rua 3: d
        IClandia[9][j].r[0] = rua[1];
        IClandia[9][j].r[1] = rua[1];
        
        // Rua 4: d
        IClandia[12][j].r[0] = rua[1];
        IClandia[12][j].r[1] = rua[1];
        
        // Rua 5: d
        IClandia[15][j].r[0] = rua[1];
        IClandia[15][j].r[1] = rua[1];
        
        // Rua 6: e
        IClandia[18][j].r[0] = rua[2];
        IClandia[18][j].r[1] = rua[2];
        
        // Rua 7: e
        IClandia[21][j].r[0] = rua[2];
        IClandia[21][j].r[1] = rua[2];
        
        // Rua 8: e
        IClandia[24][j].r[0] = rua[2];
        IClandia[24][j].r[1] = rua[2];
    }
    
    // Rua linha 0 e 27
    for (int j = 0; j < 37; j++)
    {
        IClandia[0][j].r[0] = 'd';
        IClandia[0][j].r[1] = 'd';
        IClandia[27][j].r[0] = 'e';
        IClandia[27][j].r[1] = 'e';
    }
    
    // Rua coluna 0 e 36
    for (int i = 0; i < 28; i++)
    {
        IClandia[i][0].r[0] = 'c';
        IClandia[i][0].r[1] = 'c';
        IClandia[i][36].r[0] = 'b';
        IClandia[i][36].r[1] = 'b';
    }
    
    // Cruzamentos (MEIOS)
    for (int i = 3; i < 25; i+=3)
    {
        for (int j = 4; j < 33; j+=4)
        {
            IClandia[i][j].r[0] = IClandia[i-1][j].r[0];
        }
    }
    
    // Cruzamentos (BORDAS)
    for (int i = 0; i < 25; i+=3)
    {
        IClandia[i][0].r[1] = IClandia[i][1].r[1];
        IClandia[i][36].r[1] = IClandia[i][35].r[1];
    }
    
    for (int j = 0; j < 36; j+=4)
    {
        IClandia[0][j].r[0] = IClandia[1][j].r[1];
        IClandia[27][j].r[0] = IClandia[26][j].r[1];
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
            Rua_atual[k][0] = IClandia[f+3][g+5].r[0];
            Rua_atual[k][1] = IClandia[f+3][g+5].r[1];
            
            //Coloca o carro na posição
            IClandia[f+3][g+5].r[0] = x +'0';
            IClandia[f+3][g+5].r[1] = y +'0';
            
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
        Rua_atual[g][0] = IClandia[15][y].r[0];
        Rua_atual[g][1] = IClandia[15][y].r[1];
        
        IClandia[15][y].r[0] = '0';
        IClandia[15][y].r[1] = g +'0';
        
        coordenadas[g][0] = 15;
        coordenadas[g][1] = y;
        
        g++;
    }
    //Coordenadas de 10 - 90 (+10)
    f = 1;
    for (int x = 3; x < 28; x+=3)
    {
        Rua_atual[f*10][0] = IClandia[x][23].r[0];
        Rua_atual[f*10][1] = IClandia[x][23].r[1];
        
        IClandia[x][23].r[0] = f +'0';
        IClandia[x][23].r[1] = '0';
        
        coordenadas[f*10][0] = x;
        coordenadas[f*10][1] = 23;
        f++;
    }
    f = 1;
    //Coordenadas de 19 - 99 (+10)
    for (int x = 2; x < 28; x+=3)
    {
        Rua_atual[(f*10)+9][0] = IClandia[x][36].r[0];
        Rua_atual[(f*10)+9][1] = IClandia[x][36].r[1];
        
        IClandia[x][36].r[0] = f +'0';
        IClandia[x][36].r[1] = '9';
        
        coordenadas[(f*10)+9][0] = x;
        coordenadas[(f*10)+9][1] = 36;
        f++;
    }
    
    //Coordenadas do Carro 100
    Rua_atual[100][0] = IClandia[15][19].r[0];
    Rua_atual[100][1] = IClandia[15][19].r[1];
    
    IClandia[15][19].r[0] = '0';
    IClandia[15][19].r[1] = '0';
    
    coordenadas[100][0] = 15;
    coordenadas[100][1] = 19;
    
    //Coordenadas do Carro 09
    Rua_atual[9][0] = IClandia[16][36].r[0];
    Rua_atual[9][1] = IClandia[16][36].r[1];
    
    IClandia[16][36].r[0] = '0';
    IClandia[16][36].r[1] = '9';
    
    coordenadas[9][0] = 16;
    coordenadas[9][1] = 36;
    
    // ERROS
    
    IClandia[0][0].r[0] = 'd';
    IClandia[0][0].r[1] = 'd';
    IClandia[0][36].r[1] = 'b';
    IClandia[27][36].r[0] = 'e';
    IClandia[27][36].r[1] = 'e';
    
    /*
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 37; j++)
        {
            printf("%c", IClandia[i][j].r[0]);
            printf("%c ", IClandia[i][j].r[1]);
        }
        printf("\n");
    }*/
    
    //Semaforos
    k = 0;
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 37; j++)
        {
            if ((IClandia[i][j].r[0] != IClandia[i][j].r[1]) && isalpha(IClandia[i][j].r[0]))
            {
                semaforo[k][0] = 'v';
                semaforo[k][1] = '2';
                semaforo[k][2] = IClandia[i][j].r[0];
                semaforo[k][3] = 'r';
                semaforo[k][4] = '3';
                semaforo[k][5] = IClandia[i][j].r[1];
                
                coord_semaforos[k][0] = i;
                coord_semaforos[k][1] = j;
                
                IClandia[i][j].r[0] = semaforo[k][0];
                IClandia[i][j].r[1] = semaforo[k][1];
                k++;
            }
        }
    }
    
    //Print Semaforo
    /*
    for (int i = 0; i < 96; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%c ", semaforo[i][j]);
        }
        printf("\n");
    }*/
    
    //Print Coord_semaforo
    /*
    for (int i = 0; i < 96; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", coord_semaforos[i][j]);
        }
        printf("\n");
    }*/
    
    
    
    // Print
    /*
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 37; j++)
        {
            printf("%c", IClandia[i][j].r[0]);
            printf("%c ", IClandia[i][j].r[1]);
        }
        printf("\n");
    }*/
    
    /*for (int i = 1; i < 101; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf ("%d ", coordenadas[i][j]);
        }
        printf ("\n");
    }*/
}

int Cima (Cidade IClandia[][37], char carro[][2], char Rua_atual[][2], int numeroR, int coordenadas[][2])
{
    int x = coordenadas[numeroR][0];
    int y = coordenadas[numeroR][1];
    
    if ((x - 1) >= 0)  // se ele tentar chegar -1 paro
    {
        if (IClandia[x-1][y].r[0] != 'x' && isalpha(IClandia[x-1][y].r[0])) // uma letra diferente de x
        {
            // vou andar, a que eu estava vai pegar o valor
            IClandia[x][y].r[0] = Rua_atual[numeroR][0];
            IClandia[x][y].r[1] = Rua_atual[numeroR][1];
            // vou guardar o valor da q vai estar o carro
            Rua_atual[numeroR][0] = IClandia[x-1][y].r[0];
            Rua_atual[numeroR][1] = IClandia[x-1][y].r[1];
            // carro vai andar
            IClandia[x-1][y].r[0] = carro[numeroR][0];
            IClandia[x-1][y].r[1] = carro[numeroR][1];
            
            coordenadas[numeroR][0] = x - 1;
            return 1;
        }
    }
    return 0;
}

int Esq (Cidade IClandia[][37], char carro[][2], char Rua_atual[][2], int numeroR, int coordenadas[][2])
{
    int x = coordenadas[numeroR][0];
    int y = coordenadas[numeroR][1];
    
    if ((y - 1) >= 0)
    {
        if (IClandia[x][y-1].r[0] != 'x' && isalpha(IClandia[x][y-1].r[0]))
        {
            
            // vou andar, a que eu estava vai pegar o valor
            IClandia[x][y].r[0] = Rua_atual[numeroR][0];
            IClandia[x][y].r[1] = Rua_atual[numeroR][1];
            // vou guardar o valor da q vai estar o carro
            Rua_atual[numeroR][0] = IClandia[x][y-1].r[0];
            Rua_atual[numeroR][1] = IClandia[x][y-1].r[1];
            // carro vai andar
            IClandia[x][y-1].r[0] = carro[numeroR][0];
            IClandia[x][y-1].r[1] = carro[numeroR][1];
            
            coordenadas[numeroR][1] = y - 1;
            return 1;
        }
    }
    return 0;
}

int Baixo (Cidade IClandia[][37], char carro[][2], char Rua_atual[][2], int numeroR, int coordenadas[][2], int limite)
{
    int x = coordenadas[numeroR][0];
    int y = coordenadas[numeroR][1];
    
    if ((x + 1) < limite)
    {
        if (IClandia[x+1][y].r[0] != 'x' && isalpha(IClandia[x+1][y].r[0]))
        {
            // vou andar, a que eu estava vai pegar o valor
            IClandia[x][y].r[0] = Rua_atual[numeroR][0];
            IClandia[x][y].r[1] = Rua_atual[numeroR][1];
            // vou guardar o valor da q vai estar o carro
            Rua_atual[numeroR][0] = IClandia[x+1][y].r[0];
            Rua_atual[numeroR][1] = IClandia[x+1][y].r[1];
            // carro vai andar
            IClandia[x+1][y].r[0] = carro[numeroR][0];
            IClandia[x+1][y].r[1] = carro[numeroR][1];
            
            coordenadas[numeroR][0] = x + 1;
            return 1;
        }
    }
    return 0;
}

int Dir (Cidade IClandia[][37], char carro[][2], char Rua_atual[][2], int numeroR, int coordenadas[][2], int limite)
{
    int x = coordenadas[numeroR][0];
    int y = coordenadas[numeroR][1];
    
    if ((y + 1) < limite)
    {
        if (IClandia[x][y+1].r[0] != 'x' && isalpha(IClandia[x][y+1].r[0]))
        {
            
            // vou andar, a que eu estava vai pegar o valor
            IClandia[x][y].r[0] = Rua_atual[numeroR][0];
            IClandia[x][y].r[1] = Rua_atual[numeroR][1];
            // vou guardar o valor da q vai estar o carro
            Rua_atual[numeroR][0] = IClandia[x][y+1].r[0];
            Rua_atual[numeroR][1] = IClandia[x][y+1].r[1];
            // carro vai andar
            IClandia[x][y+1].r[0] = carro[numeroR][0];
            IClandia[x][y+1].r[1] = carro[numeroR][1];
            
            coordenadas[numeroR][1] = y + 1;
            return 1;
        }
    }
    return 0;
}

int prox_semaforo(Cidade IClandia[][37], int coord_semaforos[][2], char semaforo_atual[][2], char semaforo[][6], int x, int y, int m, char condicao)
{
    //printf ("Entrou: x:%d y:%d\n", x, y);
    char proximo[2];
    proximo[0] = IClandia[x][y].r[0];
    proximo[1] = IClandia[x][y].r[1];
    
    int cond;
    
    if (condicao == 'c' || condicao == 'b') cond = 0;
    else    cond = 3;
    
    if (proximo[0] != proximo[1] && isalpha(proximo[0])) // Verifica se é um semáforo
    {
        // QUAL SEMAFORO É?
        //semaforo[2][8] = {{'v', '2', 'c', 'r', '3', 'e'}, {'v', '2', 'b', 'r', '3', 'e'}};
        //coord_semaforos[2][2] = {{3, 0}, {3, 4}};
        for (int i = 0; i < 96; i++)
        {
            if (coord_semaforos[i][0] == x && coord_semaforos[i][1] == y) //Guarda as coordenadas de um semaforo
            {
                //printf("É o semaforo da pos i:%i j:%i\n", x, y);
                x = i;
                break;
            }
        }
        if (semaforo[x][cond] != 'a' && semaforo[x][cond] != 'r') // Verifica se ta verde
        {
            semaforo_atual[m][0] = semaforo[x][2];
            semaforo_atual[m][1] = semaforo[x][5];
            //printf ("estado:%c tempo:%c sentido:%c estado:%c tempo%c sentido%c n°:%d\n", semaforo[x][0], semaforo[x][1], semaforo[x][2], semaforo[x][3], semaforo[x][4], semaforo[x][5], x);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int contar_carros (char verif, int x, int y, Cidade IClandia[][37])
{
    int cont_carros = 0;
    
    if (verif == 'c')
    {
        for (int i = x-1; i >= x-3; i--)
        {
            if (i < 0)  break;
            
            if (isdigit(IClandia[i][y].r[0]))   cont_carros++;
        }
    }
    else if (verif == 'b')
    {
        for (int i = x+1; i <= x+3; i++)
        {
            if (i > 27) break;
            
            if (isdigit(IClandia[i][y].r[0]))   cont_carros++;
        }
    }
    else if (verif == 'd')
    {
        for (int i = y+1; i <= y+4; i++)
        {
            if (i > 36) break;
            
            if (isdigit(IClandia[x][i].r[0]))   cont_carros++;
        }
    }
    else if (verif == 'e')
    {
        for (int i = y-1; i >= y-4; i--)
        {
            if (i < 0)  break;
            
            if (isdigit(IClandia[x][i].r[0]))   cont_carros++;
        }
    }
    
    return cont_carros;
}

int Fluxo (int coord_semaforos[][2], char semaforo[][6], Cidade IClandia[][37], int diferenca[], int p, int quant_carros[][2])
{
    int x = coord_semaforos[p][0];
    int y = coord_semaforos[p][1];
    char verX = semaforo[p][2];
    char verY = semaforo[p][5];
    
    if (verX == 'c')    verX = 'b';
    else    verX = 'c';
    
    if (verY == 'd')    verY = 'e';
    else    verY = 'd';
    
    int quantV = contar_carros (verX, x, y, IClandia);
    int quantH = contar_carros (verY, x, y, IClandia);
    
    int dif = 0;
    
    if (quantV > quantH) // Escrever no vetor, baixar o tempo vermelho do Vertical
    {
        dif = quantV - quantH;
        diferenca[0] = 1;
        diferenca[1] = 0;
        
        quant_carros[p][0] = quantV;
        quant_carros[p][1] = quantH;
    }
    else if (quantH > quantV) // Escrever no vetor, baixar o tempo vermelho do Horizontal
    {
        dif = quantH - quantV;
        diferenca[0] = 0;
        diferenca[1] = 1;
        
        quant_carros[p][0] = quantV;
        quant_carros[p][1] = quantH;
    }
    else //mantém o tempo
    {
        quant_carros[p][0] = 0;
        quant_carros[p][1] = 0;
    }
    return dif;
}

int main()
{
    int k = 0, x, y, quant_linhas = 28, quant_colunas = 37;
    
    Cidade IClandia[28][37];
    char rua[4] = {'c', 'd', 'e', 'b'};
    
    // Carro
    char carro[101][2], semaforo_atual[101][2], Rua_atual[101][2];
    int coordenadas[101][2], rodou[101];
    
    
    // Padrao de movimento
    char seqMov[7][4] = {{'c', 'e', 'b', 'd'}, {'c', 'd', 'b', 'e'}, {'b', 'e', 'c', 'd'}, {'b', 'd', 'c', 'e'}, {'e', 'b', 'd', 'c'}, {'d', 'b', 'e', 'c'}, {'e', 'c', 'd', 'b'}};
    
    // Numero dos carros
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
    
    // Semaforo
    char semaforo[96][6];
    int coord_semaforos[96][2], diferenca[2], contH = 0, contV = 0, quant_carros[96][2], mudancas[96][2];
    
    // preencher mudancas
    for (int i = 0; i < 96; i++)
    {
        mudancas[i][0] = 0;
        mudancas[i][1] = 0;
    }
    
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
    
    ICLandia (IClandia, rua, coordenadas, Rua_atual, semaforo, coord_semaforos);
    int mudanca;
    
    for (int m = 0; m < 15; m++)
    {
        for (int i = 0; i < 2; i++) // Printando limite Superior da IClandia
        {
            for (int j = 0; j < 118; j++)
            {
                printf ("X"); 
            }
            printf ("\n");
        }
        
        for (int i = 0; i < 28; i++) // Printando a Matrix
        {
            for (int j = 0; j < 37; j++)
            {
                if (j == 0) printf ("XXX "); //Printando o limite Esquerdo da IClandia
                
                if (j == 36) // Printando o limite Direito da IClandia
                {
                    // ((((((((mexer no de baixo deixar 0 VVV que ai é ctz que e carro ou quadra
                    if (isdigit (IClandia[i][j].r[0]) || IClandia[i][j].r[0] == 'x') // Printando apenas carros e quadras
                    {
                        printf("%c", IClandia[i][j].r[0]); 
                        printf("%c ", IClandia[i][j].r[1]); 
                    }
                    else if (IClandia[i][j].r[0] != IClandia[i][j].r[1]) // Printando estados do semaforos
                    {
                        for (int h = 0; h < 97; h++) // procurando o semaforo correspondente
                        {
                            if (coord_semaforos[h][0] == i && coord_semaforos[h][1] == 36)
                            {
                                printf("%c%c ", semaforo[h][0], semaforo[h][3]); // Printando Semaforos
                            }
                        }
                    }
                    //Printando limite direito do resto
                    else    printf("   ");
                    
                    printf("XXX"); //Printando limite direito dos semaforos
                }
                else // Printando o meio (carros, quadras e semaforos)
                {
                    if (isdigit (IClandia[i][j].r[0]) || IClandia[i][j].r[0] == 'x')
                    {
                        printf("%c", IClandia[i][j].r[0]);
                        printf("%c ", IClandia[i][j].r[1]);
                    }
                    else if (IClandia[i][j].r[0] != IClandia[i][j].r[1])
                    {
                        for (int h = 0; h < 97; h++)
                        {
                            if (coord_semaforos[h][0] == i && coord_semaforos[h][1] == j)
                            {
                                printf("%c%c ", semaforo[h][0], semaforo[h][3]);
                            }
                        }
                    }
                    else    printf("   ");
                }
            }
            printf("\n");
        }
        
        for (int i = 0; i < 2; i++) // Printando limite Inferior da IClandia
        {
            for (int j = 0; j < 118; j++)
            {
                printf ("X"); 
            }
            printf ("\n");
        }
        printf ("\n");
        
        for (int j = 0; j < 96; j++)
        {
            //printf("SEMAFORO ANTES DO CALCULO: %c %c\n", semaforo[j][0], semaforo[j][1]);
            semaforo[j][1] = semaforo[j][1] - 1;
            semaforo[j][4] = semaforo[j][4] - 1;
            //printf("SEMAFORO DEPOIS DO CALCULO: %c %c\n", semaforo[j][0], semaforo[j][1]);
            
            //printf("SEMAFORO ANTES DO CALCULO: %c %c\n", semaforo[j][3], semaforo[j][4]);
            //printf("SEMAFORO DEPOIS DO CALCULO: %c %c\n", semaforo[j][3], semaforo[j][4]);
            for (int i = 0; i < 6; i+=3)
            {
                if (semaforo[j][i] == 'v' && semaforo[j][i+1] == '0')
                {
                    semaforo[j][i] = 'a';
                    semaforo[j][i+1] = '1';
                }
                else if (semaforo[j][i] == 'a' && semaforo[j][i+1] == '0')
                {
                    semaforo[j][i] = 'r';
                    semaforo[j][i+1] = '3';
                }
                else if (semaforo[j][i] == 'r' && semaforo[j][i+1] == '0')
                {
                    semaforo[j][i] = 'v';
                    semaforo[j][i+1] = '2';
                }
            }
        }
        
        for (int p = 0; p < 96; p++)
        {
            mudanca = Fluxo (coord_semaforos, semaforo, IClandia, diferenca, p, quant_carros);
            //printf("%i %i\n", quant_carros[p][0], quant_carros[p][1]);
            if (quant_carros[p][0] != 0 && quant_carros[p][1] != 0)
            {
                printf("ENTROU %d\n", p);
                if ((mudancas[p][0] - mudancas[p][1]) % 3 == 0 && mudancas[p][0] > mudancas[p][1]) //(1, 4) (4, 1)
                {
                    printf("%i %i %d carros: %d %d mudar o semaforo na direcao horizontal\n", mudancas[p][0], mudancas[p][1], p, quant_carros[p][0], quant_carros[p][1]);
                    mudancas[p][0] = 0;
                    mudancas[p][1] = 0;
                    
                    //mudar o semaforo na direção horizontal
                    //zera contH e contV
                    
                }
                else if ((mudancas[p][1] - mudancas[p][0]) % 3 == 0 && mudancas[p][1] > mudancas[p][0])
                {
                    printf("%i %i %d carros: %d %d mudar o semaforo na direcao vertical\n", mudancas[p][0], mudancas[p][1], p, quant_carros[p][0], quant_carros[p][1]);
                    mudancas[p][0] = 0;
                    mudancas[p][1] = 0;
                    //mudar o semaforo na direção vertical
                    //zera contH e contV
                    
                }
            }
            else if (mudanca != 0)
            {
                // se a diferenca[0] == 1, tenho que mudar o sinal do vertical para verde
                // se a diferenca[1] == 1, tenho que mudar o sinal do horizontal para verde
                
                // v 2 r 3 -- mudar 1,  v 1 r 2
                /*
                if (p == 0)
                {
                    printf("%i %i %i\n", mudanca, diferenca[0], diferenca[1]);
                }
                */
                if (diferenca[0] == 1)  // mudar a horizontal
                {
                    if (semaforo[p][3] == 'v') // horizontal verde  vertical vermelho
                    {
                        semaforo[p][3] = 'a';
                        semaforo[p][4] = '1';
                        
                        semaforo[p][0] = 'r';
                        semaforo[p][1] = '1';
                        contV++;
                    }
                }
                else  // mudar a vertical
                {
                    // sinal do horizontal para verde
                    if (semaforo[p][0] == 'v')   // v2 r3   v1 r2  a1 r1  r3 v2
                    {
                        semaforo[p][0] = 'a';
                        semaforo[p][1] = '1';
                        
                        semaforo[p][3] = 'r';
                        semaforo[p][4] = '1';
                        contH++;
                    }
                }
                //printf("%i %i (%i) (-%i-) -- ", contV, contH, p, mudanca);
                mudancas[p][0] = contV + mudancas[p][0];
                mudancas[p][1] = contH + mudancas[p][1];
                
                contH = 0;
                contV = 0;
                //printf("ENTROU\n");
            }
            
            //printf("(%i %i)\n", mudancas[p][0], mudancas[p][1]);
            
            //printf("%i %i\n", quant_carros[p][0], quant_carros[p][1]);
        }
        
        //sleep(1);
        //system("clear");
        
        // carro[x][1] == '1'
        for (int m = 1; m < 101; m++)
        {
            // vao ter o mesmo padrao os carros que terminam com 1 e 9
            
            // a gente so vai observar o seqmov se estiver num sinal se nao a gente so vai andar com ele no sentido da pista
            // se IClandia[i][j].r[0] != IClandia[i][j].r[1] ele decide pra onde vai (entra no if VV)
            // se nao continuamos no sentido da pista
            
            if (Rua_atual[m][0] != Rua_atual[m][1])
            {
                if (carro[m][1] == '1' || carro[m][1] == '9')
                {
                    rodou[m] = 0;
                    
                    if ((seqMov[0][0] == semaforo_atual[m][0] || seqMov[0][0] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        rodou[m] = Cima (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                    if ((seqMov[0][1] == semaforo_atual[m][0] || seqMov[0][1] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        rodou[m] = Esq (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                    if ((seqMov[0][2] == semaforo_atual[m][0] || seqMov[0][2] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        rodou[m] = Baixo (IClandia, carro, Rua_atual, m, coordenadas, quant_linhas);
                    }
                    if ((seqMov[0][3] == semaforo_atual[m][0] || seqMov[0][3] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        rodou[m] = Dir (IClandia, carro, Rua_atual, m, coordenadas, quant_colunas);
                    }
                }
                else if (carro[m][1] == '2' || carro[m][1] == '0')
                {
                    rodou[m] = 0;
                    
                    if ((seqMov[1][0] == semaforo_atual[m][0] || seqMov[1][0] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // cima
                        //printf ("%c %c subiu\n", carro[m][0], carro[m][1]);
                        rodou[m] = Cima (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                    if ((seqMov[1][1] == semaforo_atual[m][0] || seqMov[1][1] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // Dir
                        //printf ("%c %c dir\n", carro[m][0], carro[m][1]);
                        rodou[m] = Dir (IClandia, carro, Rua_atual, m, coordenadas, quant_colunas);
                    }
                    if ((seqMov[1][2] == semaforo_atual[m][0] || seqMov[1][2] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // baixo
                        //printf ("%c %c desceu\n", carro[m][0], carro[m][1]);
                        //printf ("%c %c\n", semaforo_atual[m][0], semaforo_atual[m][1]);
                        rodou[m] = Baixo (IClandia, carro, Rua_atual, m, coordenadas, quant_linhas);
                    }
                    if ((seqMov[1][3] == semaforo_atual[m][0] || seqMov[1][3] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // esq
                        //printf ("%c %c esq\n", carro[m][0], carro[m][1]);
                        rodou[m] = Esq (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                }
                else if (carro[m][1] == '3')
                {
                    rodou[m] = 0;
                    
                    if ((seqMov[2][0] == semaforo_atual[m][0] || seqMov[2][0] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // baixo
                        rodou[m] = Baixo (IClandia, carro, Rua_atual, m, coordenadas, quant_linhas);
                    }
                    if ((seqMov[2][1] == semaforo_atual[m][0] || seqMov[2][1] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // esq
                        rodou[m] = Esq (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                    if ((seqMov[2][2] == semaforo_atual[m][0] || seqMov[2][2] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // cima
                        rodou[m] = Cima (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                    if ((seqMov[2][3] == semaforo_atual[m][0] || seqMov[2][3] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // Dir
                        rodou[m] = Dir (IClandia, carro, Rua_atual, m, coordenadas, quant_colunas);
                    }
                }
                else if (carro[m][1] == '4')
                {
                    rodou[m] = 0;
                    
                    if ((seqMov[3][0] == semaforo_atual[m][0] || seqMov[3][0] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // baixo
                        rodou[m] = Baixo (IClandia, carro, Rua_atual, m, coordenadas, quant_linhas);
                    }
                    if ((seqMov[3][1] == semaforo_atual[m][0] || seqMov[3][1] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // Dir
                        rodou[m] = Dir (IClandia, carro, Rua_atual, m, coordenadas, quant_colunas);
                    }
                    if ((seqMov[3][2] == semaforo_atual[m][0] || seqMov[3][2] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // cima
                        rodou[m] = Cima (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                    if ((seqMov[3][3] == semaforo_atual[m][0] || seqMov[3][3] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // esq
                        rodou[m] = Esq (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                }
                else if (carro[m][1] == '5')
                {
                    rodou[m] = 0;
                    
                    if ((seqMov[4][0] == semaforo_atual[m][0] || seqMov[4][0] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // esq
                        rodou[m] = Esq (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                    if ((seqMov[4][1] == semaforo_atual[m][0] || seqMov[4][1] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // baixo
                        rodou[m] = Baixo (IClandia, carro, Rua_atual, m, coordenadas, quant_linhas);
                    }
                    if ((seqMov[4][2] == semaforo_atual[m][0] || seqMov[4][2] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // Dir
                        rodou[m] = Dir (IClandia, carro, Rua_atual, m, coordenadas, quant_colunas);
                    }
                    if ((seqMov[4][3] == semaforo_atual[m][0] || seqMov[4][3] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // cima
                        rodou[m] = Cima (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                }
                else if (carro[m][1] == '6' || carro[m][1] == '8')
                {
                    rodou[m] = 0;
                    
                    if ((seqMov[5][0] == semaforo_atual[m][0] || seqMov[5][0] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // Dir
                        rodou[m] = Dir (IClandia, carro, Rua_atual, m, coordenadas, quant_colunas);
                    }
                    if ((seqMov[5][1] == semaforo_atual[m][0] || seqMov[5][1] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // baixo
                        rodou[m] = Baixo (IClandia, carro, Rua_atual, m, coordenadas, quant_linhas);
                    }
                    if ((seqMov[5][2] == semaforo_atual[m][0] || seqMov[5][2] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // esq
                        rodou[m] = Esq (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                    if ((seqMov[5][3] == semaforo_atual[m][0] || seqMov[5][3] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // cima
                        rodou[m] = Cima (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                }
                else if (carro[m][1] == '7')
                {
                    rodou[m] = 0;
                    
                    if ((seqMov[6][0] == semaforo_atual[m][0] || seqMov[6][0] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // esq
                        rodou[m] = Esq (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                    if ((seqMov[6][1] == semaforo_atual[m][0] || seqMov[6][1] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // cima
                        rodou[m] = Cima (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                    if ((seqMov[6][2] == semaforo_atual[m][0] || seqMov[6][2] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // Dir
                        rodou[m] = Dir (IClandia, carro, Rua_atual, m, coordenadas, quant_colunas);
                    }
                    if ((seqMov[6][3] == semaforo_atual[m][0] || seqMov[6][3] == semaforo_atual[m][1]) && rodou[m] == 0)
                    {
                        // baixo
                        rodou[m] = Baixo (IClandia, carro, Rua_atual, m, coordenadas, quant_linhas);
                    }
                }
            }
            else
            {
                // ele esta numa rua normal e vai seguir o sentido da pista
                if (Rua_atual[m][0] == 'c')
                {
                    x = coordenadas[m][0] - 1;   // x e y sao as coordenadas do semaforo se ele existir
                    y = coordenadas[m][1];
                    
                    //printf ("x:%d y:%d\n", x, y);
                    if (x >= 0) // Se estiver na beira, não sairá do mapa
                    {
                        // vai verificar se naquela posicao que ele quer ir tem um semaforo, se tiver ele escreve na IClandia
                        // so vai escrever na IClandia e andar se ele for verde, se não, não anda
                        x = prox_semaforo(IClandia, coord_semaforos, semaforo_atual, semaforo, x, y, m, Rua_atual[m][0]);
                        
                        if (x == 1) rodou[m] = Cima (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                }
                else if (Rua_atual[m][0] == 'e')
                {
                    x = coordenadas[m][0];
                    y = coordenadas[m][1] - 1;
                    
                    //printf ("x:%d y:%d\n", x, y);
                    if (y >= 0)
                    {
                        x = prox_semaforo(IClandia, coord_semaforos, semaforo_atual, semaforo, x, y, m, Rua_atual[m][0]);
                        
                        if (x == 1) rodou[m] = Esq (IClandia, carro, Rua_atual, m, coordenadas);
                    }
                }
                else if (Rua_atual[m][0] == 'b')
                {
                    x = coordenadas[m][0] + 1;
                    y = coordenadas[m][1];
                    
                    //printf ("x:%d y:%d\n", x, y);
                    if (x <= 27)
                    {
                        x = prox_semaforo(IClandia, coord_semaforos, semaforo_atual, semaforo, x, y, m, Rua_atual[m][0]);
                        
                        if (x == 1) rodou[m] = Baixo (IClandia, carro, Rua_atual, m, coordenadas, quant_linhas);
                    }
                }
                else if (Rua_atual[m][0] == 'd')
                {
                    x = coordenadas[m][0];
                    y = coordenadas[m][1] + 1;
                    
                    //printf ("x:%d y:%d\n", x, y);
                    if (y <= 36)
                    {
                        x = prox_semaforo(IClandia, coord_semaforos, semaforo_atual, semaforo, x, y, m, Rua_atual[m][0]);
                        
                        if (x == 1) rodou[m] = Dir (IClandia, carro, Rua_atual, m, coordenadas, quant_colunas);
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
/*
if ((contV - contH) % 3 == 0 && contV > contH)   (1, 4) (4, 1)
{
    mudar o semaforo na direção horizontal
    zera contH e contV
}
else if ((contH - contV) % 3 == 0 && contH > contV)
{
    mudar o semaforo na direção vertical
    zera contH e contV
}
*/
