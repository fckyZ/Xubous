/*                       Células Na Linguagem De Progranação C
                        Gabriel Carvalho De Souza 18 / 11 / 2024                             */

/* Bibliotecas Auxiliares */
#include <stdio.h>
#include <stdlib.h>
/* Fim Bibliotecas Auxiliares */


/* Definições Globais */
#define null NULL
#define optional_int 0
/* Fim Definições Globais */


/* Definição Das Structs E Referências */
typedef
struct s_int_Cell
{
    int value;
    struct s_int_Cell * link;
} int_Cell;

typedef
int_Cell *
ref_int_Cell;
/* Fim Definição Das Structs */


/* Métodos E Funções */
// Método Para Criar Nova Célula
ref_int_Cell int_new_Cell ( )
{
    ref_int_Cell this = null; // ponteiro começa apontando para null
    this = ( ref_int_Cell ) malloc ( 1 * sizeof ( int_Cell ) ); // memoria pra celula
    if ( this != null ) // caso a alocação funcione
    {  
        this -> value = optional_int; // atribui o valor
        this -> link = null; // indica que nao esta conectado a outro
    }

    return ( this ); // retorna o ponteiro
} // Fim Método Para Criar Nova Célula

// Método Para Setar Valor Da Célula
ref_int_Cell int_Cell_set ( ref_int_Cell this, int value )
{
    if ( this != null ) // se o this tiver espaço na memória
    {
        this -> value = value; // atribui o valor
    }

    return ( this ); // retorna o ponteiro com o valor atribuido
} // Fim Método Para Setar Valor Da Célula

// Método Para Pegar Valores Da Célula
int int_Cell_get ( ref_int_Cell this )
{
    int value = optional_int; // variavel pra receber o valor da célula

    if ( this != null ) // se o this tiver espaços na memória
    {  
        value = this -> value; // pega o valor da célula
    }

    return ( value ); // retorna o valor da célula
} // Fim Método Para Pegar Valores Da Célula

// Método Para Printar 
void int_Cell_print ( ref_int_Cell this )
{
    if ( this == null ) // se a lista for vazia
    {
        printf ( "[]" ); // retorna lista vazia
    }

    ref_int_Cell pointerAssistant = this; // um ponteiro para this

    while ( pointerAssistant != null ) // enquando o ponteiro for diferente de nulo
    {
        printf ( "%d\n", pointerAssistant -> value ); // mostra o valor
        pointerAssistant = pointerAssistant -> link; // passa para o próximo nó
    }
    printf ( "\n" ); // quebra de linha 
} // Fim Método Para Printar 

// Método Para Testar
void int_Cell_test ( )
{   
    // definir dados
    ref_int_Cell a = null;
    // identificar
    printf ( "\nTest int_Cell library (C)\n" );
    // criar armazenador
    a = int_new_Cell(); // usar a função correta
    // mostrar dado
    printf ( "\n01. Testar criacao e armazenamento\n" );
    int_Cell_print ( a );
    // alterar dado
    a = int_Cell_set ( a, 10 ); // passar ponteiro para a função
    // mostrar dado
    printf ( "\n02. Testar alteracao e recuperacao\n" );
    printf ( "%d\n", int_Cell_get ( a ) );
    printf ( "\n" );
} // Fim Método Para Testar
/* Fim Métodos E Funções */


/* Função Principal */
int main ( )
{
    int_Cell_test ( );
    return 0;
}
/* Fim Função Principal */