/*                         Structs Na Linguagem De Programação C                            
                          Gabriel Carvalho De Souza 14 / 11 / 2024                           */

/* Bibliotecas Auxiliares */
#include <stdio.h>
#include <stdlib.h>
/* Fim Bibliotecas Auxiliares */


/* Definindo Structs */
typedef
struct s_Carro_Modelo_
{
    int ano;
    float preco;
    char * nome;
} Carro;

// definindo getter e setter para carro
Carro * Getter;
Carro * Setter;
/* Fim Definindo Structs */


/* Contrutor E Destrutor Padrao */
Carro construtorPadrao ( )
{
    Setter -> ano = 0;
    Setter -> preco = 0.0;
    Setter -> nome = "";
}

Carro destrutorPadrao ( )
{
    Carro carro ( int ano, float preco, char * nome );
}
/* Fim Contrutor E Destrutor Padrao */


/* Getters Setters */
void carroGetter ( Carro * Getter )
{
    printf ( "Ano: %d\n", Getter -> ano );
    printf ( "Preco: %lf\n", Getter -> preco );
    printf ( "Nome: %s\n", Getter -> nome );
}

void carroSetter ( int ano_, float preco_, char * nome_ )
{
    Setter -> ano = ano_;
    Setter -> preco = preco_;
    Setter -> nome = nome_;
}
/* Fim Getters Setters */
