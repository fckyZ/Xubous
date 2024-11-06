#include <stdio.h>
#include <stdlib.h>

void retanguloRetangulo ( int base )
{
    while ( base > 0 )  // mudando o valor da base pra Base - 1
    {
        for ( int i = 0; i < base; i++ ) // printa a quantidade equivalente a base
        {
            printf ( "*" );
        }

        printf ( "\n" ); // quebra de linha 

        base --;  
    }
}

int main ()
{
    retanguloRetangulo ( 5 );
}

/*
    Testes

    base = 5
        
    * * * * * 
    * * * *
    * * *
    * *
    *
*/