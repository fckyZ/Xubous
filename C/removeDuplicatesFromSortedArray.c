#include <stdio.h>
#include <stdlib.h>

int removeDuplicates ( int * nums, int numsSize ) 
{
    if ( numsSize == 0 ) return 0;
    int * expectedNums = ( int * ) malloc ( numsSize * sizeof ( int ) ); // array pra nums
    int k = 0;                                                           // sem repetir

        for ( int i = 0; i < numsSize; i++ ) // percorre o array
        {
            if ( i == numsSize - 1 || nums [ i ] != nums [ i + 1 ]  )
            {
                expectedNums [ k++ ] = nums [ i ];
            }
                    
        }

        for ( int i = 0; i < numsSize; i++ )
        {
            nums [ i ] = expectedNums [ i ];
        }  


    free ( expectedNums );
    return k; // retorna a quantidade de números
}

int main ( )
{
    // int valuesRemoved = removeDuplicates (  );
    return 0;
}