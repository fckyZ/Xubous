#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ver o valor atual, ver o proximo valor
// valor atual > prox  || soma += valor atual ? soma -= valor atual 
// somar os valores

typedef
struct s_mapa_romano {
    char simbolos [ 7 ];
    int valores [ 7 ];
} M;

int romanToInt ( char * s )
{
    M t = { { 'I', 'V', 'X', 'L', 'C', 'D', 'M' }, { 1, 5, 10, 50, 100, 500, 1000 } }; 
    int soma = 0;
    int lenWord = strlen ( s );

    // valor atual
    // valores de s, comparar com a lista da struct
    for ( int j = 0; j < lenWord; j++ )
    {
        int a = 0, p = 0;
        for ( int i = 0; i < 7; i++ )
        {
            if ( s [ j ] == t.simbolos [ i ] )
            {
                a = t.valores [ i ];
            }
        }

        if ( j + 1 < lenWord )
        {
            for ( int i = 0; i < 7; i++ )
            {
                if ( s [ j + 1 ] == t.simbolos [ i ] )
                {
                    p = t.valores [ i ];
                }
            }
        }
        if ( a < p )
        {
            soma -= a;
        } else
            {
                soma += a;
            }
    }

    return soma;
}

int main ()
{
    char * numeroRomano = "V";
    printf ( "%d\n", romanToInt ( numeroRomano ) );
    return 0;
}