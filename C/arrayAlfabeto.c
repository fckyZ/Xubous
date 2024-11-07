#include <stdio.h>
#include <stdlib.h>

int readAmount ( char * texto )
{
    int x = 0;
    printf ( "%s", texto );
    scanf ( "%d", &x );

    if ( x > 26 || x <= 0 )
    {
        printf ( "Digite Um Valor Entre 1 e 26!!!\n" );

        while ( x > 26 || x <= 0 )
        {
            scanf ( "%d", &x );
        }
    }

    return x;
}

char * arrayAlfabetico ( int quantidade )
{
    char alfabeto [26];
    for ( int i = 0; i < 26; i++ )
    {
         alfabeto [i] = 'A' + i;
    }

    /*
        Teste Para Validade o Alfabeto
            for ( int i = 0; i < 26; i++ )
            {
                printf ( "%c ", alfabeto [i] );
            }
     */

    // array para retornar os valores
    char * arrayAlfabeticoFinal = ( char * ) malloc ( quantidade * sizeof ( char ) ); 
   
    // usuario escolhe uma quantidade a ser retornada
    for ( int i = 0; i < quantidade; i++ )
    {
         arrayAlfabeticoFinal [i] = alfabeto [i]; 
    }

    return arrayAlfabeticoFinal;
}

void printarArray ( char * arrayResultado, int quantidade )
{
    for ( int i = 0; i < quantidade; i++ )
    {
        printf ( "%c ", arrayResultado [i] );
    }
}

int main ()
{
    int quantidade = readAmount ( "Digite Uma Quantidade:\n" );

    char * arrayResutado = ( char * ) malloc ( quantidade * sizeof ( char ) );

    arrayResutado = arrayAlfabetico ( quantidade );

    printarArray ( arrayResutado, quantidade );

    free ( arrayResutado );
    return 0;
}