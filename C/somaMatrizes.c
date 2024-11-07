#include <stdio.h>
#include <stdlib.h>

int * somaMatrizes ( int mat1 [2][2], int mat2 [2][2] )
{
    int * matrizResultado = ( int * ) malloc ( 2 * 2 * sizeof ( int ) );

    for ( int i = 0; i < 2; i++ )
    {
        for ( int j = 0; j < 2; j++ )
        {
           * ( matrizResultado + i * 2 + j ) = mat1 [i][j] + mat2 [i][j]; 
        }
    }

    return matrizResultado;
}

void printarMatriz ( int * matrizFinalSomada )
{
    for ( int i = 0; i < 2; i++ )
    {
        for ( int j = 0; j < 2; j++ )
        {
           printf ( "%d ", * ( matrizFinalSomada + i * 2 + j ) );
        }
        printf ( "\n" );
    }
}

int main ()
{
    int mat1 [2][2] = {
        { 10, 20 },
        { 30, 40 },
    };

    int mat2 [2][2] = {
        { 10, 20 },
        { 30, 40 },
    };

    int * matrizFinalSomada = somaMatrizes ( mat1, mat2 );

    printarMatriz ( matrizFinalSomada );
    
    free ( matrizFinalSomada );
    return 0;
}

// Calculo para definir uma matriz como um array linear 
// i * numero de colunas + j;