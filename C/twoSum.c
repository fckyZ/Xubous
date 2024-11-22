#include <stdio.h>
#include <stdlib.h>

int * twoSum ( int * nums, int numsSize, int target, int * returnSize ) 
{   
    int * result = ( int * ) malloc ( 2 * sizeof ( int ) );
    if ( ! result ) return NULL;

    if ( numsSize == 2 && nums [ 0 ] + nums [ 1 ] == target )
    {
        result [ 0 ] = 0;
        result [ 1 ] = 1;
        * returnSize = 2;
        return result;
    } 
    
    for ( int i = 0; i < numsSize; i++ )
    {
        for ( int j = i + 1; j < numsSize; j++ )
        {
            if ( ( nums [ i ] + nums [ j ] ) == target )
            {
                result [ 0 ] = i;
                result [ 1 ] = j;
                * returnSize = 2;
                return result;
            }
        } 
    }

    * returnSize = 0;
    free ( result );
    return NULL;
}

int main ( )
{
    return 0;
}