#include <stdio.h>
#include <stdlib.h>

int str_count ( char * word )
{
    int count = 0; // contador 
    if ( ! word || word [ 0 ] == '\0' ) return 0; // verificação se word existe 
    while (  word [ count ] != '\0' )
    {
        count ++ ;
    }

    return count;
}

int scoreOfString ( char * s ) 
{
    int i = 0, subtracao = 0, soma = 0;
    int size = str_count ( s );

    while ( i < size - 1 )
    {
        subtracao = s [ i ] - s [ i + 1 ];

        if ( subtracao < 0 )
        {
            subtracao *= -1;
        }
        soma += subtracao;
        i ++;
    }    

    return soma;
}

int main ( )
{
    return 0;
}