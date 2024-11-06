#include <stdio.h>
#include <stdlib.h>

int fatorial ( int numero )
{
    if ( numero == 1 || numero == 0 ) return 1;
    else return numero * fatorial ( numero - 1 );
}

int main ()
{
    int resultado = fatorial ( 5 );
    printf ( "%d", resultado );
}

// testes
/*
    teste = 5
    5 . 4 . 3 . 2 . 1 = 120
*/