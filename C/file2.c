#include <stdio.h>
#include <stdlib.h>

int readFile ( FILE * arquivo )
{
    int x;

    while ( fscanf ( arquivo, "%d", & x ) != EOF )
    {
        printf ( "%d\n", x );
    }

    return 1;
    
}

void fillFile ( FILE * arquivo )
{
    for (int i = 0; i <= 10; i++)
    {
        fprintf ( arquivo, "%d\n", i );
    }
}

int main ()
{
    FILE * arquivo = fopen ( "arquivo.txt", "w+" );

    if ( arquivo == NULL )
    {
        printf ( "Erro" );
        return 0;
    }

    fillFile ( arquivo );

    rewind ( arquivo );

    readFile ( arquivo );
    fclose ( arquivo );

    return 0;
}   

