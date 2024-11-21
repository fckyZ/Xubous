#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord ( char * s ) 
{
    int len = strlen ( s );
    int countChar = 0;
    int i = len - 1;

    while ( i >= 0 && s [ i ] == ' ' ) // remove os espaços caso sejam colocados depois da ultima palavra
    {
        i--;
    }
    

    while ( i >= 0 && s [ i ] != ' ' ) // com o indice i no certo, verifica ate o proximo espaço
    {
        countChar ++;
        i--;
    }
    

    return countChar;
}

int main ( )
{
    return 0;
}