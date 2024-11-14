// Autor: Gabriel Carvalho De Souza 846341
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    float *matriz;
    int linhas;
    int colunas;
} Matriz;

void menu ()
{
    printf ( " 0 - Parar \n" );
    printf ( " 1 - Metodo 01  2 - Metodo 02 \n" );
    printf ( " 3 - Metodo 03  4 - Metodo 04 \n" );
    printf ( " 5 - Metodo 05  6 - Metodo 06 \n" );
    printf ( " 7 - Metodo 07  8 - Metodo 08 \n" );
    printf ( " 9 - Metodo 09  10 - Metodo 10 \n" );
}

int readNumberMoreThanZero ( const char* texto )
{
    int opcao = 0;
    printf ( "%s\n", texto );
    scanf ( "%d", &opcao );

    while ( opcao < 0 )
    {
        printf ( "Digite um valor positivo!\n" );
        scanf ( "%d", & opcao );
    }
    return opcao;
}

Matriz met01 () 
{
    int quantLinhas = readNumberMoreThanZero ( "Digite a quantidade de linhas:" );
    int quantColunas = readNumberMoreThanZero ( "Digite a quantidade de colunas:" );

    Matriz m;
    m.linhas = quantLinhas;
    m.colunas = quantColunas;
    m.matriz = NULL;

    m.matriz = ( float * ) malloc ( quantLinhas * quantColunas * sizeof ( float ) );
    if ( m.matriz == NULL ) 
    {
        printf ( "Erro de alocacao de memoria!\n" );
        exit ( 1 );
    }

    for ( int i = 0; i < quantLinhas; i++ ) 
    {
        for ( int j = 0; j < quantColunas; j++ ) 
        {
            m.matriz [ i * quantColunas + j ] = ( float ) ( rand () % 100 ); 
        }
    }

    return m;
}

void met02 ( Matriz m, FILE * arquivo ) 
{
    if ( arquivo == NULL ) return;

    for ( int i = 0; i < m.linhas * m.colunas; i++ ) 
    {
        fprintf ( arquivo, "%.2f\n", m.matriz [ i ] );
    }
}

void met03 ( Matriz m, FILE * arquivo )
{
    if ( arquivo == NULL ) return;

    for ( int i = 0; i < m.linhas && i < m.colunas; i++ ) 
    {
        fprintf ( arquivo, "%.2f\n", m.matriz [ i * m.colunas + i ] );
    }
}

void met04 ( Matriz m ) 
{
    if ( m.linhas != m.colunas ) 
    {
        printf ( "A matriz nao e quadrada. Nao e possivel exibir a diagonal secundaria.\n" );
        return;
    }

    printf ( "Valores na diagonal secundaria:\n" );
    for ( int i = 0; i < m.linhas; i++ ) 
    {
        printf ( "%.2f ", m.matriz [ i * m.colunas + ( m.colunas - 1 - i ) ] );
    }
    printf ( "\n" );
}

void met05 ( Matriz m ) 
{
    if ( m.linhas != m.colunas )
    {
        printf ( "A matriz nao e quadrada. Nao e possivel exibir a diagonal secundaria.\n" );
        return;
    }

    printf(" Valores abaixo e na diagonal principal:\n" );
    for ( int i = 0; i < m.linhas; i++ ) 
    {
        for ( int j = 0; j <= i; j++ ) 
        {
            printf ( "%.2f ", m.matriz [ i * m.colunas + j ] );
        }
        printf ( "\n" );
    }
}

void met06 ( Matriz m ) 
{
    if ( m.linhas != m.colunas )
    {
        printf ( "A matriz nao e quadrada. Nao e possivel exibir a diagonal secundaria.\n" );
        return;
    }

    printf ( " Valores abaixo e na diagonal principal:\n" );
    for ( int i = 0; i < m.linhas; i++ ) 
    {
        for ( int j = i; j < m.colunas; j++ ) 
        {
            printf ( "%.2f ", m.matriz [ i * m.colunas + j ] );
        }
        printf ( "\n" );
    }
}

void met07 ( Matriz m ) 
{
    if ( m.linhas != m.colunas )
    {
        printf ( "A matriz nao e quadrada. Nao e possivel exibir a diagonal secundaria.\n" );
        return;
    }

    printf ( " Valores abaixo e na diagonal principal:\n" );
    for ( int i = 0; i < m.linhas; i++ ) 
    {
        for ( int j = m.colunas - 1 - i; j < m.colunas; j++ ) 
        {
            printf ( "%.2f ", m.matriz [ i * m.colunas + j ] );
        }
        printf ( "\n" );
    }
}

void met08 ( Matriz m )
{
    if ( m.linhas != m.colunas )
    {
        printf ( "A matriz nao e quadrada. Nao e possivel exibir a diagonal secundaria.\n" );
        return;
    }

    printf ( " Valores abaixo e na diagonal principal:\n" );
    for ( int i = 0; i < m.linhas; i++ ) 
    {
        for ( int j = m.colunas - 1 - i; j >= i; j-- ) 
        {
            printf ( "%.2f ", m.matriz [ i * m.colunas + j ] );
        }
        printf ( "\n" );
    }
}

void met09 ( Matriz m )
{
    if ( m.linhas != m.colunas ) 
    {
        printf ( "A matriz nao e quadrada. Nao e possivel verificar os valores abaixo da diagonal principal.\n" );
        return;
    }

    int todosZeros = 1;
    for ( int i = 1; i < m.linhas; i++ ) 
    {
        for ( int j = 0; j < i; j++ ) 
        {
            if ( m.matriz [ i * m.colunas + j ] != 0 )
            {
                todosZeros = 0;
            }
        }
    }

    if ( todosZeros ) 
    {
        printf ( "Todos os valores abaixo da diagonal principal sao zeros.\n" );
    } 
    else 
    {
        printf ( "Existem valores diferentes de zero abaixo da diagonal principal.\n" );
    }
}

void met10 ( Matriz m )
{
    if ( m.linhas != m.colunas ) 
    {
        printf ( "A matriz nao e quadrada. Nao e possivel verificar os valores abaixo da diagonal principal.\n" );
        return;
    }

    int todosZeros = 1;
    for ( int i = 0; i < m.linhas; i++ ) 
    {
        for ( int j = i + 1; j < m.colunas; j++ ) 
        {
            if ( m.matriz [ i * m.colunas + j ] != 0 )
            {
                todosZeros = 0;
            }
        }
    }

    if ( todosZeros ) 
    {
        printf ( "Todos os valores abaixo da diagonal principal sao zeros.\n" );
    } 
    else 
    {
        printf ( "Existem valores diferentes de zero abaixo da diagonal principal.\n" );
    }
}

int main ()
{
    int opcao = 0;
    FILE * arquivo = fopen ( "arquivo.txt", "r+" );

    Matriz matriz;
    matriz.matriz = NULL;

    srand ( time ( NULL ) );

    do
    {
        system ( "cls" );
        menu ();
        opcao = readNumberMoreThanZero ( "Escolha Uma Opcao:" );
        system ( "cls" );

        switch ( opcao )
        {
            case 0: break; 
            case 1: matriz = met01 (); break; 
            case 2: met02 ( matriz, arquivo ); break; 
            case 3: met03 ( matriz, arquivo ); break; 
            case 4: met04 ( matriz ); break; 
            case 5: met05 ( matriz ); break; 
            case 6: met06 ( matriz ); break; 
            case 7: met07 ( matriz ); break; 
            case 8: met08 ( matriz ); break; 
            case 9: met09 ( matriz ); break; 
            case 10: met10 ( matriz ); break; 
            default: break;
        }

    } while ( opcao != 0 );

    fclose (arquivo);
    return 0;
}
