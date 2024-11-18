#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef
struct s_simbolos_abreFecha {
    char entrada;
    char saidas;
} T;

bool isValid ( char * s ) 
{
    T t [] = { 
        { '{', '}' },
        { '[', ']' },
        { '(', ')' }
    };
    int lenS = strlen ( s );
    int countIsValid [ 3 ] = { 0, 0, 0 };

    // passando por todos os simbolos
    for ( int i = 0; i < lenS; i++ )
    {
        // verifica a entrada
        for ( int j = 0; j < 3; j++ )
        {
            if ( s [ i ] == t [ j ].entrada )
            {
                countIsValid [ j ]++;
            }
        }

        // verifica a saida
        for ( int j = 0; j < 3; j++ )
        {
            if ( s [ i ] == t [ j ].saidas )
            {
                if ( countIsValid [ j ] > 0 )
                {
                    countIsValid [ j ]--;
                } else 
                {
                    return false;
                }
            } 
        }
    }
    return countIsValid [ 0 ] == 0 && countIsValid [ 1 ] == 0 && countIsValid [ 2 ] == 0;
}

int main ( )
{
    char s1 [ ] = "()";

    printf ( "s1: %s -> %s\n", s1, isValid ( s1 ) ? "Valid" : "Invalid" );
    return 0;
}