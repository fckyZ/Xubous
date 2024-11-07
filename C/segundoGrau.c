#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Retornar as raizes de uma equação do segundo grau

int segundoGrau (int a, int b, int c, int * resultados)
{
    printf ( "Equacao : %dx^2 + %dx + %d\n", a, b, c );

    // calcular delta
    int delta = 0;
    delta = pow ( b, 2 ) - 4 * a * c;

    // se delta < 0, erro    // se delta = 0, só uma raiz
    if ( delta < 0 )
    {
        return 1; // Erro delta negativo
    }

    // calcular x1, x2    

    resultados [0] = ( - b + sqrt ( delta ) ) / ( 2 * a );
    resultados [1] = ( - b - sqrt ( delta ) ) / ( 2 * a );

    return 0;
}

int main ()
{
    int resultados [2];

    // mostrando os resultados / raizes
    if ( segundoGrau ( 1, -3, -10, resultados ) == 0 )
    {
        printf ( "Raizes: %d, %d\n", resultados [0], resultados [1] );
    } else
        {
            printf ( "Sem Raizes !!\n" );
        }

    return 0;
}