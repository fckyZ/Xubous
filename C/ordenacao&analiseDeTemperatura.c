/*                  Gabriel Carvalho De Souza 09 / 11 / 2024
                        Ordenação E Análise De Temperatura                                   */
                        
/* Biblioteca Auxiliar */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Fim Biblioteca Auxiliar */


/* Métodos E Funções */
int readSize ( char * texto )
{
    int size = 0;
    printf ( "%s\n", texto );
    scanf ( "%d", & size );

    if ( size <= 0 )
    {   
        printf ( "%s\n", "Digite Um Tamanho Positivo!" );
        while ( size <= 0 )
        {
            scanf ( "%d", & size );
        }
        
    }

    return size;
}

void trocarValores ( int * arr, int a, int b )
{
    int temp = arr [ a ];
    arr [ a ] = arr [ b ];
    arr [ b ] = temp;
}

int particionarArray ( int * arr, int inicio, int final )
{
    int meio = inicio + ( final - inicio ) / 2;
    int pivo = arr [ meio ];
    int i = inicio - 1;

    trocarValores ( arr, meio, final );

    for ( int j = inicio; j < final; j++ )
    {
        if ( arr [ j ] <= pivo )
        {
            i++;
            trocarValores ( arr, i, j );
        }
    }

    trocarValores ( arr, i + 1, final );

    return i + 1; // retornando porque o final passou do inicio
}

void quickSort ( int * arr, int inicio, int final )
{
     if ( inicio >= final ) // caso base 
    {
        return;
    }

    int indicePosicao = particionarArray ( arr, inicio , final ); // retorna o indice do meio
    quickSort ( arr, inicio, indicePosicao - 1 ); // estuda do inicio ate a metade
    quickSort ( arr, indicePosicao + 1, final ); // estuda da metade ate o final;
}

int diferencaMaiorMenor ( int * arr, int size )
{
    int diferencaMaiorMenor = arr [ size - 1 ] - arr [ 0 ];
    return diferencaMaiorMenor;
} 

int mediaTemperatura ( int * arr, int size )
{
    int soma = 0;
    int media = 0;
    for ( int i = 0; i < size; i++ )
    {
        soma += arr [ i ];
    }
    media = soma / size;

    return media;
}

int maisRepete ( int * arr, int size )
{   
    int maiorValorRepetente = arr [ 0 ];
    int frequencia = 1;
    int count = 1;

    for ( int i = 1; i < size; i++ )
    {
        if ( arr [ i ] == arr [ i - 1 ] )
        {
            count ++;
        } else
            {
                if ( count > frequencia )
                {
                    frequencia = count;
                    maiorValorRepetente = arr [ i - 1 ];
                }
                count = 1;
            }
    }
    
    if ( count > frequencia )
    {
        frequencia = count;
        maiorValorRepetente = arr [ size - 1 ];
    }

    return maiorValorRepetente;
}

void printarArray ( int * arr, int size )
{
    for ( int i = 0; i < size; i++ )
    {
        printf ( "%d ", arr [ i ] );
    }
}

void preencherArray ( int * arr, int size )
{
    for ( int i = 0; i < size; i++ )
    {
        arr [ i ] =  rand () % 11 ;
    }
}
/* Fim Métodos E Funções */


/* Função Principal */
int main ()
{
    srand ( time ( NULL ) );
    int size = readSize ( "Digite O Tamanho Do Array:" );
    int * array = ( int * ) malloc ( size * sizeof ( int ) ); 

    preencherArray ( array , size );
    printf ( "%s\n", "Array Ordenado:" );
    quickSort ( array, 0, size - 1 );
    printarArray ( array, size );
    printf ( "\n" );
    
    int diferencaMaiorMenorArray = diferencaMaiorMenor ( array, size );
    int mediaTemperaturaArray = mediaTemperatura ( array, size );
    int valorMaisRepeteArray = maisRepete ( array, size );
    
    printf("Diferenca Maior-Menor: %d\n", diferencaMaiorMenorArray);
    printf("Media das Temperaturas: %d\n", mediaTemperaturaArray);
    printf("Temperatura mais frequente: %d\n", valorMaisRepeteArray);

    free ( array );
    return 0;    
}
/* Fim Função Principal */

// Algoritmo 
/*
    - Ordenar uma lista em ordem crescente 
    - Calcular a diferença entre a maior e a menor
    - Encontrar a media das temperaturas
    - Exibir a temperatura que mais repete
*/