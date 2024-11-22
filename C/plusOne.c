#include <stdio.h>
#include <stdlib.h>

int * plusOne ( int * digits, int digitsSize, int * returnSize ) 
{
    int carry = 1;

    for ( int i = digitsSize - 1; i >= 0; i-- )
    {
        digits [ i ] += carry;
        if ( digits [ i ] == 10 )
        {
            digits [ i ] = 0;
            carry = 1;
        } else
            {
                carry = 0;
            }
    }

    if ( carry == 1 )
    {
        * returnSize = digitsSize + 1;
        digits = realloc ( digits, ( * returnSize ) * sizeof ( int ) );
        if ( ! digits ) return NULL;

        for ( int i = digitsSize; i > 0; i-- ) 
        {
            digits [ i ] = digits [ i - 1 ];
        }
        digits [ 0 ] = 1;
    }

    * returnSize = digitsSize + ( carry == 1 );
    return digits;
}

int main ( )
{
    return 0;
}