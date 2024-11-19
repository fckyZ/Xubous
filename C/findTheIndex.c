#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr ( char * haystack, char * needle ) 
{
    int len = strlen ( haystack );
    int lenNeedle = strlen ( needle );
    
    for ( int i = 0; i < len; i++ )
    {
        int h = 0;

        while ( h < lenNeedle || haystack [ i + h ] == needle [ h ] )
        {
            h++;
        }
        
        if ( h == lenNeedle )
        {
            return i;
        }

    }

    return -1;
}

int main ( )
{
    return 0;
}