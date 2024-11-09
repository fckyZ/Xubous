/*                  Gabriel Carvalho De Souza 08 / 11 / 2024
                Função Para Retornar A Determinante De Uma Matriz                            */

/* Bibliotecas Auxiliarea */
#include <stdio.h>
#include <stdlib.h>
/* Fim Bibliotecas Auxiliarea */

/* Métodos */
// metodo para ler tamanho
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
    printf ( "\n" );
    
    return size;
}

// metodo para preencher matriz
void preencherMatriz ( int * mat, int numberColumns, int numberLines )
{
    for ( int i = 0; i < numberLines; i++ )
    {
        for ( int j = 0; j < numberColumns; j++ )
        {
            printf ( "Digite o Valor Da Posicao [%d] [%d] :\n", i, j );
            scanf ( "%d", & mat [ i * numberColumns + j ] );
        }
    } 
}

// metodo para printar matriz
void printarMatriz ( int * mat, int numberColumns, int numberLines )
{
    for ( int i = 0; i < numberLines; i++ )
    {
        for ( int j = 0; j < numberColumns; j++ )
        {
            printf ( "%d ", mat [ i * numberColumns + j ] );
        }
        printf ( "\n" );
    } 
    printf ( "\n" );
}

// funcao auxiliar Laplaca
int determinante2x2 (int * mat)
{
    return mat [ 0 ] * mat [ 3 ] - mat [ 1 ] * mat [ 2 ];
}

// metodo printar matriz extendida
void printarMatrizExpandida ( int* mat, int numberColumns, int numberLines ) 
{
    printf("%s\n", "Matriz Expandida: ");
    for ( int i = 0; i < numberLines; i++) 
    {
        // Imprime a matriz original
        for ( int j = 0; j < numberColumns; j++ ) 
        {
            printf( "%d ", mat [ i * numberColumns + j ] );
        }
        
        // Imprime as duas primeiras colunas novamente
        printf ("| ");
        for ( int j = 0; j < 2; j++ ) 
        {
            printf ( "%d ", mat [ i * numberColumns + j ] );
        }
        printf ("\n");
    }
    printf ("\n");
}

// metodo calcular determinante
int calcularDeterminante ( int * matriz, int numberColumns, int numberLines )
{
     if ( numberColumns == 1 && numberLines == 1 )
    {
        return matriz [ 0 ];
    }

    if ( numberColumns == 2 && numberLines == 2 )
    {
        return determinante2x2 ( matriz );
    }

    int determinante = 0;
    
    // loop sobre as colunas para realizar a expansão de Laplace
    for ( int i = 0; i < numberColumns; i++ )
    {
        // criando a submatriz removendo a linha 0 e a coluna i
        int * newMatriz = ( int * ) malloc ( ( numberLines - 1 ) * ( numberColumns - 1 ) * sizeof ( int ) );
        int newMatrizIndex = 0;
        
        for ( int j = 1; j < numberLines; j++ )  // começa da linha 1 para remover a linha 0
        {
            for ( int k = 0; k < numberColumns; k++ )
            {
                if ( k != i )  // não copia a coluna i
                {
                    newMatriz [ newMatrizIndex++ ] = matriz [ j * numberColumns + k ];
                }
            }
        }

       

        // Alternando os sinais para a expansão de Laplace
        int coeficiente = ( i % 2 == 0 ) ? 1 : -1;
        determinante += coeficiente * matriz [ i ] * calcularDeterminante ( newMatriz, numberColumns - 1, numberLines - 1 );
        
        free(newMatriz);  // Liberando a memória da submatriz
    }
    return determinante;
}

// metodo para retornar a determinante
int matrizDeterminante ( int * mat, int numberColumns, int numberLines )
{
    printf("%s\n", "Matriz Original: ");
    printarMatriz (mat, numberColumns, numberLines);

    printarMatrizExpandida (mat, numberColumns, numberLines);
    

    return calcularDeterminante ( mat, numberColumns, numberLines );

}
/* Fim Métodos */

/* Função Principal */
int main ()
{
    int numberColumns = readSize ( "Digite a Quantidade de Colunas do Array:" );
    int numberLines = readSize ( "Digite a Quantidade de Linhas Do Array:" );
    int * mat = ( int * ) malloc ( numberLines * numberColumns * sizeof ( int ) );

    preencherMatriz ( mat , numberColumns, numberLines );

    int determinante = matrizDeterminante ( mat , numberColumns, numberLines );
    printf ( "Determinante: %d\n", determinante);

    free ( mat );
    return 0;
}
/* Fim Função Principal */