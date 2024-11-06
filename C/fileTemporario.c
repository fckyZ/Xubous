#include <stdio.h>
#include <stdlib.h>

FILE * tempFile ()
{
    FILE * arquivo = tmpfile ();

    if ( arquivo == NULL ) return 0;

    return arquivo;
}

void readFile ( FILE * arquivo )
{
    int x = 0;

    while ( fscanf ( arquivo, "%d", &x ) != EOF )
    {
        printf ( "%d\n", x );
    }
    
}

void fillFile ( FILE * arquivo )
{
    for ( int i = 0; i < 10; i++ )
    {
        fprintf ( arquivo, "%d\n", i );
    }
}

int main ()
{
    FILE * arquivo = tempFile ();
    
    fillFile ( arquivo );
    rewind ( arquivo );
    readFile ( arquivo );
    fclose ( arquivo );

    return 0;
}