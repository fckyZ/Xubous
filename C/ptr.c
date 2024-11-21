#include <stdio.h>
#include <stdlib.h>

void func01 ( int * a, int * b )
{
    printf ( "%p %p\n", & a, & b ); // printando endereço da memória
}

void func02 ( int c )
{
    int * p;

    p = & c;

    printf ( "Valor De A: %d\n", c );
    printf ( "Endereco De A : %p\n", & c );
    printf ( "Endereco Pra Onde P Aponta: %p\n", p );
    printf ( "Conteudo Pra Onde P Aponta: %d\n", * p );
    printf ( "Conteudo Pra Onde P Aponta Modificado Pelo Ponteiro: %d\n", ++ * p );
}

int main ( )
{
    // Ponteiro para um array
    /*
        int size = 10;
        int arr [ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int * ptr = arr;
        for ( int i = 0; i < size; i++ )
        {
            printf ( "%d\n", * ptr );
            ptr ++;
        } 
    */
    // Fim ponteiro para um 
    
    // Passando ponteiro como parâmetro
    /* 
        int a = 2;
        int b = 3;
        func01 ( & a, & b );
    */
    // Fim passando ponteiro como parâmetro

    // Malinupalção De Ponteiro
    /*
        int c = 10;
        func02 ( c );
    */
    // Fim malinupalção De Ponteiro

}