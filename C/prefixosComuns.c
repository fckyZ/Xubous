#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestCommonPrefix ( char * * strs, int strsSize )
{
    char * p = strs [ 0 ];
    
    for ( int i = 1; i < strsSize; i++ )
    {
        int j = 0;
        while ( p [ j ] != '\0' && strs [ i ] [ j ] != '\0' && p [ j ] == strs [ i ] [ j ] )
        {
            j++;
        }
        p[j] = '\0';
    }
    return p;
}

int main ()
{
    //
    return 0;
}