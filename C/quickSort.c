/*
                            QuickSort Na Linguagem De Programação C
                                   Gabriel Carvalho de Souza
                                       18 / 11 / 2024
*/


/* Bibliotecas Auxiliares */
#include <stdio.h>
#include <stdlib.h>
/* Fim Bibliotecas Auxiliares */


/* Métodos */
// metodo auxiliar para printar os vetores
void printarArray ( int * arr, int tamanho )
{
    for ( int i = 0; i < tamanho; i++ )
    {
        printf ( "%d ", arr [ i ] );
    }
    printf ( "\n" );
}

void trocandoPosicoes ( int * vet, int inicio, int final )
{
    int aux = vet [ inicio ];
    vet [ inicio ] = vet [ final ];
    vet [ final ] = aux;
}

int particionarVetor ( int * vet, int inicio, int final )
{
    int meio = inicio + ( final - inicio ) / 2;
    int pivo = vet [ meio ];
    int i = inicio - 1;

    trocandoPosicoes ( vet, meio, final );

    for ( int j = inicio; j < final; j++ )
    {
        if ( vet [ j ] <= pivo )
        {
            i++;
            trocandoPosicoes ( vet, i, j );
        }
    }

    trocandoPosicoes ( vet, i + 1, final );

    return i + 1; // retornando porque o final passou do inicio
}

void quickSort ( int * vet, int inicio, int final )
{
    if ( inicio >= final ) // caso base 
    {
        return;
    }

    int indicePosicao = particionarVetor ( vet, inicio , final ); // retorna o indice do meio
    quickSort ( vet, inicio, indicePosicao - 1 ); // estuda do inicio ate a metade
    quickSort ( vet, indicePosicao + 1, final ); // estuda da metade ate o final
}
/* Fim Métodos */


/* Função Principal */
int main ()
{
    int arr [] = { 10, 2, 3, 12, 43, 1, 10 }; // array definido
    printarArray ( arr, 7 );
    quickSort ( arr, 0, 6 );
    printarArray ( arr, 7 );
}
/* Fim Função Principal */

/* Algoritmo :
   1 - escolher um valor oara o pivo
   2 - percorrer o array para a direita verificando valores menores que o pivo
   3 - percorrer o array para a esquerda verificando valores maiores que o pivo
   4 - trocar os elementos

   Teste :
   int arr [] = { 10, 2, 3, 12, 43, 1, 10 };
   1, 2, 3, 10, 10, 12, 43


*/