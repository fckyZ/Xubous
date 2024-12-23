#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define null NULL

typedef 
struct car_Assembly
{
    int year;
    double price;
    char * model;
} car;

typedef
struct car_Assembly * ref_Car;

ref_Car set_Year ( ref_Car this, int Year )
{
    if ( this && Year > 0 )
    {
        this -> year = Year;
    }

    return this;
}

ref_Car set_Price ( ref_Car this, double Price )
{
    if ( this && Price > 0 )
    {
        this -> price = Price;
    }
    return this;
}

ref_Car set_Model ( ref_Car this, char * Model )
{
    if ( this && Model != null )
    {
        this -> model = Model;
    }

    return this;
}

bool validate_Information ( ref_Car this )
{
    if ( this -> year > 0 && this -> price > 0 && this -> model != null )
    {
        return true;
    } else
        {
            return false;
        }
}

void print_Information ( ref_Car this )
{
    printf ( "Year : %d\n", this -> year );
    printf ( "Price : %lf\n", this -> price );
    printf ( "Model : %s", this -> model );
}

void test_Car ( )
{
    ref_Car this = ( ref_Car ) malloc ( 1 * sizeof ( car ) );
    if ( ! this ) printf ( "%s\n", "Erro Ao Criar Carro!" );
    bool validate = false;

    set_Year ( this, 2017 );
    set_Price ( this, 14500.57 );
    set_Model ( this, "Uno" );
    validate = validate_Information ( this );

    if ( validate )
    {
        printf ( "%s\n", "Carro Criado!" );
        print_Information ( this );
    } else 
        {
            printf ( "%s\n", "Erro Ao Criar Carro!" );
        }


}

int main ( )
{
    test_Car ( );
    return 0;
}