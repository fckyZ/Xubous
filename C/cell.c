#include <stdio.h>
#include <stdlib.h>

#define int_opc 0
#define null NULL

typedef
struct s_int_cell
{
    int value;
    struct s_int_cell * link;
} int_cell;

typedef
int_cell *
ref_int_cell;

ref_int_cell int_new_Cell ( ref_int_cell * tail, int value_ )
{
    ref_int_cell newCell = null;

    newCell = ( ref_int_cell ) malloc ( 1 * sizeof ( int_cell ) );
    if ( ! newCell ) return null; 

    newCell -> value = value_; 
    newCell -> link = null; 

    if ( * tail == null )
    {
        * tail = newCell; 
    } else
        {
            ( * tail ) -> link = newCell;
            * tail = newCell;
        }

    return newCell;
}

void int_print_Cell ( ref_int_cell head )
{
    ref_int_cell current = head;
    if ( head == null )
    {
        printf ( "[]" ); // retorna lista vazia
    } else 
        {
            while ( current != null )
            {
                printf ( "Valor: %d   Link: %p \n", current -> value, current -> link );
                current = current -> link;  
            }          
        }
}

int int_get_value_Cell ( ref_int_cell this )
{
    if ( ! this ) return -1;
    return this -> value;
}

ref_int_cell int_connect_Cell ( ref_int_cell tail, ref_int_cell cell )
{
    if ( tail == NULL ) return cell;

    tail -> link = cell;
    tail = cell;
    return cell;
}

void testes ( )
{
    printf ( "\n%s\n", "Metodo Testes" );
    printf ( "\n" );

    ref_int_cell tail = null;
    ref_int_cell head = null;
    
    // testando criação do novo nó
    ref_int_cell newCell = null;
    newCell = int_new_Cell ( & tail, 5 );

    // confirmando valor adicionado ao nó
    printf ( "\n%s\n", "Teste Confirmar Informacoes Do No 1:" );
    int_print_Cell ( newCell );
    if ( head == null ) head = newCell;
    printf ( "\n" );

/*
    // testando pegar o valor do nó
    int valueNewCell = int_get_value_Cell ( newCell );
    printf ( "\n%s %d\n", "Pegando O Valor Pelo Metodo:", valueNewCell );
    printf ( "\n" );
*/

    // criando novo nó
    ref_int_cell newCell2 = null;
    newCell2 = int_new_Cell ( & tail, 10 );
    // confirmando valor e link adicionado ao nó
    printf ( "\n%s\n", "Teste Confirmar Informacoes Do No 2:" );
    int_print_Cell ( newCell2 );
    printf ( "\n" );

    // testando conexão
    printf ( "\n%s\n", "Teste Confirmar Conexao Do No 2:" );
    newCell = int_connect_Cell ( newCell, newCell2 );
    int_print_Cell ( head );
    printf ( "\n" );
    
    // criando novo nó
    ref_int_cell newCell3 = null;
    newCell3 = int_new_Cell ( & tail, 15 );
    // confirmando valor e link adicionado ao nó
    printf ( "\n%s\n", "Teste Confirmar Informacoes Do No 3:" );
    int_print_Cell ( newCell3 );
    printf ( "\n" );

    // testando conexão
    printf ( "\n%s\n", "Teste Confirmar Conexao Do No 3:" );
    newCell = int_connect_Cell ( newCell, newCell3 );
    int_print_Cell ( head );
    printf ( "\n" );
    
}

int main ( )
{
    testes ( );
    return 0;
}