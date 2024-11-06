#include <stdio.h>
#include <stdlib.h>

void forzin ( int inicio, int final )
{
    if ( inicio > final ) return;
    
    printf ( "%d\n", inicio );

    forzin ( inicio + 1, final );
}

void met ()
{
    
}

int main ()
{
    forzin ( 1, 10 );
    return 0;
}