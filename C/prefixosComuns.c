#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestCommonPrefix ( char * * strs, int strsSize )
{
    char * p = strs [ 0 ]; // pega a primeira palavra da lista
    
    for ( int i = 1; i < strsSize; i++ ) // percorrer todas as palavras
    {
        int j = 0; // auxiliar para caracteres
        while ( p [ j ] != '\0' && strs [ i ] [ j ] != '\0' && p [ j ] == strs [ i ] [ j ] ) // enquanto as primeira e proxima palavra != final
        {
            j++; // proximo caracter
        }
        p[j] = '\0'; // particiona a palavra até a parte comum
    }
    return p;
}

int main ( )
{
    //
    return 0;
}