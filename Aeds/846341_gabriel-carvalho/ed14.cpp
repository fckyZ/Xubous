// Autor - Gabriel Carvaho de Souza  846341

/* Bibliotecas Principais */
#include <iostream>
#include <cstdlib>
#include <string> 
/* Fim Bibliotecas Principais */


/* Metodos */
// Metodo Ler Inteiro
int readInt ( std :: string texto )
{
    int x = 0;
    std :: cout << texto << std :: endl;
    std :: cin >> x;

    return x;
}
// Fim Metodo Ler Inteiro

// Metodo Menu
void menu ()
{
    system ( "cls" );
    std :: cout << "Opcoes:" << std :: endl;
    std :: cout << "0 - Parar   11 - Reset" << std :: endl;
    std :: cout << "Metodo 1    Metodo 2" << std :: endl;
    std :: cout << "Metodo 3    Metodo 4" << std :: endl;
    std :: cout << "Metodo 5    Metodo 6" << std :: endl;
    std :: cout << "Metodo 7    Metodo 8" << std :: endl;
    std :: cout << "Metodo 9    Metodo 10" << std :: endl;
    std :: cout << std :: endl;
}
// Fim Metodo Menu
/* Fim Metodos */


/* Função Principal */
int main ()
{
    std :: cout << "Gabriel Carvalho de Souza - 846341" << std :: endl;
    std :: cout << "Lista Ed14 07/11/2024" << std :: endl;

    int opc = 0;

    do
    {
        menu ();

        opc = readInt ( "Digite Uma Opcao:" );

        while ( opc < 0 )
        {
            opc = readInt ( "Digite Uma Opcao Valida:" );
        }

        system ( "cls" );

        switch (opc)
        {
            case 0: { break; }

            default: { std :: cout << "Opcao invalida." << std :: endl; break; }
        }
    } while ( opc != 0 );

    return 0;
}
/* Fim Função Principal */