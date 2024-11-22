#include <stdio.h>
#include <stdlib.h>

char * convertIntToString ( int numero, int numeroTamanho ) 
{
    char * numeroConvertido = ( char * ) malloc ( numeroTamanho * sizeof ( char ) );

    for ( int i = numeroTamanho - 1; i >= 0; i-- )
    {
        numeroConvertido [ i ] = ( numero % 10 ) + '0';
        numero = numero / 10;
    }
    numeroConvertido [ numeroTamanho ] = '\0';
    return numeroConvertido;
}

int main ( )
{
    char * numeroConvertido = convertIntToString ( 123, 3 );
    printf ( "%s\n", numeroConvertido );

    free ( numeroConvertido );
    return 0;
}