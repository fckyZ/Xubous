/*                  Biblioteca String Na Linguagem De Programação C
                        Gabriel Carvalho De Souza 27 / 11 / 2024                             */

/* Bibliotecas Auxiliares */
#include <stdio.h>
#include <stdlib.h>
/* Fim Bibliotecas Auxiliares */


/* Defines E Constantes */
#define null NULL
int global_tests = 0;
/* Fim Defines E Constantes */


/* Definições Métodos E Funções */
// Função Para Copiar 
int str_count ( char * word )
{
    int count = 0; // contador 
    if ( ! word || word [ 0 ] == '\0' ) return 0; // verificação se word existe 
    while (  word [ count ] != '\0' )
    {
        count ++ ;
    }

    return count;
}
// Fim Função Para Copiar 

// Função Para Copiar Uma String
char * str_cpy ( char * word )
{
    int sizeWord = str_count ( word );
    if ( ! word || word [ 0 ] == '\0' ) return null;

    char * copy = malloc ( ( str_count ( word ) + 1 ) * sizeof ( char ) );
    if ( ! copy ) return null;

    for ( int i = 0; i < sizeWord; i++ )
    {
        copy [ i ] = word [ i ];
    }

    copy [ sizeWord ] = '\0';

    return copy;
}
// Fim Função Para Copiar Uma String

// Função Para Substituir
char * str_replace ( char * word, char * lettersToReplace, char substitute )
{
    if ( ! word || word [ 0 ] == '\0' ) return null;

    if ( substitute == '\0' ) 
    {
        char * copy = str_cpy ( word );
        return copy;
    }

    int sizeWord = str_count ( word );
    int sizeLettersToReplace = str_count ( lettersToReplace );

    char * modifiedWord = malloc ( ( str_count ( word ) + 1 ) * sizeof ( char ) );
    if ( ! modifiedWord ) return null;

    for ( int i = 0; i < sizeWord; i++ )
    {
        int substituted = 0;
        for ( int j = 0; j < sizeLettersToReplace; j++ )
        {
            if ( word [ i ] == lettersToReplace [ j ] )
            {
                modifiedWord [ i ] = substitute;
                substituted = 1;
            }
        }

        if ( ! substituted )
        {
            modifiedWord [ i ] = word [ i ];
        }
    }
    
    modifiedWord [ sizeWord ] = '\0';

    return modifiedWord;
}
// Fim Função Para Substituir

// Função Concatenar 
char * str_conc ( char * firstWord, char * secondWord )
{
    if ( ! firstWord && ! secondWord ) return null;

    int sizeFirstWord = str_count ( firstWord );
    int sizeSecondWord = str_count ( secondWord );
    int newSize = sizeFirstWord + sizeSecondWord + 1;

    char * newWord = ( char * ) malloc ( newSize * sizeof ( char ) );
    if ( ! newWord ) return null;

    char * base = newWord;

    while ( * firstWord )
    {
        * newWord = * firstWord;
        firstWord ++ ;
        newWord ++ ;
    }

    while ( * secondWord )
    {
        * newWord = * secondWord;
        secondWord ++ ;
        newWord ++ ;
    }
    
    * newWord = '\0';
    
    return base;
}
// Fim Função Concatenar 

// Método Para Testes
void test ( )
{
    printf ( "\n" );
    printf ( "PRIMEIRO TESTE:\n" );
    char palavra [ ] = "uva";
    printf ( "palavra : %s\n", palavra );
    int contador = str_count ( palavra );
    printf ( "%s tem : %d letras\n", palavra, contador );

    printf ( "\n" );

    printf ( "SEGUNDO TESTE:\n" );
    char * copia = str_cpy ( palavra );
    printf ( "palavra copiada : %s\n", copia );
    int contadorCopia = str_count ( copia );
    printf ( "palavra %s copiada tem : %d letras\n", copia, contadorCopia );

    printf ( "\n" );

    printf ( "TERCEIRO TESTE:\n" );
    char palavra2 [ ] = "garoto";
    int contadorPalavra2 = str_count ( palavra2 );
    printf ( "%s tem : %d letras\n", palavra2, contadorPalavra2 );
    char * modificada = str_replace ( palavra2, "ao", 'b' );
    printf ( "palavra modificada: %s\n", modificada );
    free ( modificada );

    printf ( "\n" );

    printf ( "QUARTO TESTE:\n" );
    char um [ ] = "abc";
    char dois [ ] = "def";

    char * oi = str_conc ( um, dois );
    printf ( "String concatenadas: %s\n", oi );
}
// Método Para Testes
/* Fim Definições Métodos E Funções */


/* Função Principal */
int main ( )
{
    test ( );
    return 0;
}
/* Função Principal */


// metodo para concatenar