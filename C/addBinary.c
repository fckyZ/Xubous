#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * addBinary ( char * a, char * b ) 
{
    int carry = 0; // valor de carry
    int lenWord1 = strlen ( a ); // tamanho de a
    int lenWord2 = strlen ( b ); // tamanho de b
    int maxLen = lenWord1 > lenWord2 ? lenWord1 : lenWord2; // verifica qual o maior
        
    char * resultado = ( char * ) malloc ( ( maxLen + 2 ) * sizeof ( char ) ); // alocando
    if ( ! resultado ) return NULL; // teste alocação

    resultado [ maxLen + 1 ] = '\0';

    for ( int i = 0; i <= maxLen; i++ ) // inicializando com 0
    {
        resultado [ i ] = '0';
    }

    for ( int i = 0; i < maxLen; i++ ) // percorrendo para somar os valores
    { 
        int bit_a = ( i < lenWord1 ) ? a [ lenWord1 - 1 - i ] - '0' : 0; // obtendo o bit_a
        int bit_b = ( i < lenWord2 ) ? b [ lenWord2 - 1 - i ] - '0' : 0; // obtendo o bit_b
        int soma = 0; // declarando soma

        soma = bit_a + bit_b + carry; // somando bit_a com bit_b + o carry caso exista overflow
        resultado [ maxLen - 1 - i ] = ( soma % 2 ) + '0'; // armazena o bit atual
        carry = soma / 2; // pegando o bit mais significativop
    }

    if ( carry )
    {
        resultado [ 0 ] = '1';
        resultado[maxLen + 1] = '\0';
    } else
        { 
            resultado [ maxLen ] = '\0';
        }

    return resultado;
}

int main ( )
{
    return 0;
}