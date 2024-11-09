/*                      Gabriel Carvalho De Souza  08 / 11 / 2024
                 Função Que Recebe Ulma Matriz e Mostra a Sua Transposta                      */

/* Bibliotecas Auxiliares */
#include <stdio.h>
#include <stdlib.h>
/* Fim Bibliotecas Auxiliares */

/* Métodos */
int readSize ( char * texto )
{
    int size = 0;
    printf ( "%s\n", texto );
    scanf ( "%d", & size );

    if ( size <= 0 )
    {
        printf ( "%s\n", "Digite Um Valor Maior Que Zero!!!" );
        while ( size <= 0 )
        {
            scanf ( "%d", & size );
        }   
    }
    
    return size;
}

void preencherMatriz ( int * arr, int numberColumns, int numberLines )
{
    for ( int i = 0; i < numberLines; i++ )
    {
        for ( int j = 0; j < numberColumns; j++ )
        {
            printf ( "Digite o Valor Da Posicao [%d] [%d] :\n", i, j );
            scanf ( "%d", & arr [ i * numberColumns + j ] );
        }
    } 
}

void printarMatriz ( int * arr, int numberColumns, int numberLines )
{
    for ( int i = 0; i < numberLines; i++ )
    {
        for ( int j = 0; j < numberColumns; j++ )
        {
            printf ( "%d ", arr [ i * numberColumns + j ] );
        }
        printf ( "\n" );
    } 
}

int * matrizTransposta ( int * arr, int numberColumns, int numberLines )
{
    int * arrTransposta = ( int * ) malloc ( numberColumns * numberLines * sizeof ( int ) );

    for ( int i = 0; i < numberLines; i++ )
    {
        for ( int j = 0; j < numberColumns; j++ )
        {
             arrTransposta [ j * numberColumns + i ] = arr [ i * numberColumns + j ];
        }
    } 

    return arrTransposta;
}
/* Fim Métodos */


/* Função Principal */
int main ()
{
    int numberColumns = readSize ( "Digite a Quantidade de Colunas do Array:" );
    int numberLines = readSize ( "Digite a Quantidade de Linhas Do Array:" );
    int * arr = ( int * ) malloc ( numberLines * numberColumns * sizeof ( int ) );

    preencherMatriz ( arr , numberColumns, numberLines );
    printf ( "Matriz Original: \n" );
    printarMatriz ( arr , numberColumns, numberLines );

    int * arrTransposta = matrizTransposta ( arr , numberColumns, numberLines );
    printf ( "Matriz Traansposta: \n" );
    printarMatriz ( arrTransposta , numberColumns, numberLines );
 
    free ( arr );
    free ( arrTransposta );
    return 0;
}
/* Fim Função Principal */
