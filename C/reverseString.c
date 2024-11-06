#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString ( char * string )
{
    int lenght = strlen ( string );

    char * pInit = string;
    char * pFinal = string + lenght - 1;

    for ( int i = 0; i < lenght / 2; i++ )
    {
        char temp = * pInit;
        * pInit = * pFinal;
        * pFinal = temp;

        pInit ++;
        pFinal --;
    }   

}

int main ()
{
    char teste [] = "uva";
    reverseString ( teste );
    printf ( "%s\n", teste );
    return 0;
}