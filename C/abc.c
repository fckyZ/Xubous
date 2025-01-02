#include <stdio.h>
#include <stdlib.h>

// parte um : valores a b c
// parte dois : imprimir na tela a soma de a e b
// parte tres : mostrar se a soma é menor que c

int parteUm ( char * texto )
{
    int x;
    printf ( "%s\n", texto );
    scanf ( "%d", & x );
    return x;
}   

void parteDois ( int soma )
{
    printf ( "Parte Dois Do Problema : \n" );
    printf ( "Valor Da Soma : %d\n\n", soma );
}

void parteTres ( int soma, int c )
{
    printf ( "Parte Tres Do Problema : \n" );
    if ( soma > c )
    {
        printf ( "A Soma E Maior Que O Valor De C !!!\n" );
    } else if ( soma < c )
        {
            printf ( "A Soma E Menor Que O Valor De C !!!\n" );
        } else 
            {
                printf ( "A Soma Tem O Valor Igual A C !!!\n" );
            }
    printf ( "\n" );        
}

int main ( )
{
    int a = 0, b = 0, c = 0;
    int soma = 0;

    printf ( "Parte Um Do Problema : \n" );
    a = parteUm ( "Digite O Primeiro Valor : " );
    b = parteUm ( "Digite O Segundo Valor : " );
    c = parteUm ( "Digite O Terceiro Valor : " );
    printf ( "\n" );

    soma = a + b;

    parteDois ( soma );

    parteTres ( soma, c );

    return 0;
}