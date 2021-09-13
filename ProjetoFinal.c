#include <stdio.h>

//semaforo verde = 2
//semaforo amarelo = 3
//semaforo vermelho = 4
//Posições igual a 7 e 1 não pode andar
//Posição do Carro: Linha X e entre Coluna Y e Y+1 (carro12: X=1, Y entre 2 e 3)
//X = 0 e Y = 0 então se torna 5 e o 100 fica entre X=4, Y entre 4 e 5

void Posição_carro (int matrix[][m])
{
    char string = "carro12";
}

int main()
{
    int matrix[36][37];
    
    //Matrix
    for (int i = 0; i < 36; i++)
    {
       for (int j = 0; j < 37; j++)
       {
           matrix[i][j] = 0;
       }
    }
    
    //Quadra
    for (int l = 1; l < 36; l+=4)
    {
       for (int c = 1; c < 37; c+=4)
       {
          matrix[l][c] = 7;
          matrix[l][c+1] = 7;
          matrix[l][c+2] = 7;
          matrix[l+1][c] = 7;
          matrix[l+1][c+1] = 7;
          matrix[l+1][c+2] = 7;
          
          /*for (int a = l; a < l+2; a++)
          {
              for (int b = c; b < c+3; b++)
              {
                  matrix[a][b] = 1;
              }
          }*/
       }
    }
    
    //Semáforo
    for (int c = 0; c < 37; c+=4) //primeira linha
    {
        matrix[0][c] = 2;
    }
    for (int l = 3; l < 36; l+=4) // resto
    {
        for (int c = 0; c < 37; c+=4)
        {
            matrix[l][c] = 2;
            if (l != 35)
            {
                matrix[l+1][c] = 2;
            }
        }
    } 
    matrix[0][0] = 0;
    matrix[0][36] = 0;
    matrix[35][0] = 0;
    matrix[35][36] = 0;
    
    //Colocar o carro na Posição
    Posição_carro (matrix);
    
    //Print
    for (int i = 0; i < 36; i++)
    {
       for (int j = 0; j < 37; j++)
       {
           printf ("%d ", matrix[i][j]);
       }
       printf ("\n");
    }

    return 0;
}

//11 12 13  15 16 17
//21 22 23  25 26 27


//51 52 53
//61 62 63
