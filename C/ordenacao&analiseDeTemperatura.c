/*                  Gabriel Carvalho De Souza 09 / 11 / 2024
                        Ordenação E Análise De Temperatura                                   */
                        
/* Biblioteca Auxiliar */
#include <stdio.h>
#include <stdlib.h>
/* Fim Biblioteca Auxiliar */


/* Métodos E Funções */
int readSize ( char * texto )
{
    int size = 0;
    printf ( "%s\n", texto );
    scanf ( "%d", & size );
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
    int pivo = arr [ final ];
    int i = inicio - 1;

    for ( int j = 0; j < final; j++ )
    {
        if ( arr [ j ] <= pivo )
        {
            i++;
            trocarValores ( arr, i, j );
        }
    }
    trocarValores ( arr, arr [ i + 1 ], pivo );

    return i + 1;
}

void quickSort ( int * arr, int inicio, int final )
{
    if ( inicio < final )
    {
        return;
    }
    int pivo = particionarArray ( arr, inicio, final );
    quickSort ( arr, inicio, pivo - 1 );
    quickSort ( arr, pivo + 1, final );
}

void diferencaMaiorMenor ( int * arr, int size )
{
    int diferencaMaiorMenor = arr [ size - 1 ] - arr [ 0 ];
    printf ( "%d\n", diferencaMaiorMenor );
} 

void mediaTemperatura ( int * arr, int size )
{
    int soma = 0;
    int media = 0;
    for ( int i = 0; i < size; i++ )
    {
        soma += arr [ i ];
    }
    media = soma / 12;

    printf ( "%d\n", media );
}

void maisRepete(int *arr, int size)
{
    
}

void preencherArray ( int * arr, int size )
{
    for ( int i = 0; i < size; i++ )
    {
        arr [ i ] = i * 2;
    }
}
/* Fim Métodos E Funções */


/* Função Principal */
int main ()
{
    int size = readSize ( "Digite O Tamanho Do Array:" );
    int array [ size ];

    quickSort ( array, 0, size );
    diferencaMaiorMenor ( array, size );
    mediaTemperatura ( array, size );
    maisRepete ( array, size );
    
}
/* Fim Função Principal */

// Algoritmo 
/*
    - Ordenar uma lista em ordem crescente 
    - Calcular a diferença entre a maior e a menor
    - Encontrar a media das temperaturas
    - Exibir a temperatura que mais repete
*/