// Autor - Gabriel Carvaho de Souza  846341

/* Bibliotecas Principais */

#include <iostream>
#include <cstdlib>
#include <string> 
#include <cstdio>

/* Fim Bibliotecas Principais */


/* Definição de Classes */

class Metodos
{
    private:
        std :: string name;
        int telephone;
        int secondTelephone;
        
        bool telephoneIsValid ( int telephone )
        {
            if ( telephone && telephone > 0 ) 
            {
                std :: cout << "Telefone Valido!!!" << std :: endl;
                return true;
            } else
                {
                   std :: cout << "Telefone Nao E Valido!!!" << std :: endl;
                   return false;
                }
        };

    public:
        Metodos ();                                 // construtor padrão
        ~ Metodos ();                               // destrutor padrão                          

        std :: string getName () ;                  // getter para pegar o nome
        int getTelephone () ;                       // getter para pegar o telefone
        int getSecondTelephone () ;                 // getter para pegar o telefone 2


        void setTelephone ();                       // metodo para definir o telefone
        void setSecondTelephone ();                 // metodo para definir o telefone 2
        void setNewSecondTelephone ();              // metodo para definir um novo valor
        void setName ();                            // metodo para definir o nome 
        int validateTelephone ();                   // metodo para chamar a função privada
        void resetObject ();                        // metodo para resetar os valores
        void readFile ( FILE * arquivo );                          // metodo para ler arquivo
};

/* Fim Definição de Classes */


/* Constutor e Destrutores */

Metodos :: Metodos () // Construtor Padrão
{
    telephone = 0;
    secondTelephone = 0;
    name = "";
    std :: cout << "Objeto Padrao Criado" << std :: endl;
}

Metodos :: ~ Metodos () // Destrutor Padrão
{
    telephone = 0;
    secondTelephone = 0;
    name = "";
    std :: cout << "Dados Resetados" << std :: endl;
}

/* Fim Constutor e Destrutores */


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

// Criar Arquivo Temporario
FILE * tempFile ()
{
    FILE * arquivo = tmpfile ();

    if ( arquivo == NULL )
    {
        std :: cout << "Erro!" << std :: endl;
        return nullptr;
    }

    return arquivo;
}
// Fim Criar Arquivo Temporario

// Getter Nome
std :: string Metodos :: getName ()
{
    return name;
}
// Fim Getter Nome

// Getter Telefone Secundario
int Metodos :: getSecondTelephone ()
{
    return secondTelephone;
}
// Fim Getter Telefone Secundario

// Getter Telefone
int Metodos :: getTelephone ()
{
    return telephone;
}
// Fim Getter Telefone

// Metodo Reset Valores Do Objeto
void Metodos :: resetObject ()
{
    this->telephone = 0;
    this->secondTelephone = 0;
    this->name = "";
    std :: cout << "Objeto Resetado Com Sucesso!" << std :: endl;
    std :: cin.ignore ();
    std :: cin.get ();
}
// Fim Metodo Reset Valores Do Objeto

// Metodo 01 Auxiliar
void Metodos :: setName ()
{
    std :: string name_;
    std :: cout << "Digite Um Nome: " << std :: endl;
    std :: cin.ignore ();
    std :: getline ( std :: cin, name_ );
    this -> name = name_;
}
// Fim Metodo 01 Auxiliar

// Metodo 01
void met01 ( Metodos & metodos )
{
    std :: cout << "Metodo 01" << std :: endl;
    metodos.setName (); // adicionando o metodo definir o nome ao objeto
    std :: cout << "Nome Armazenado: " << metodos.getName () << std :: endl; 
    std :: cin.ignore ();
} 
// Fim Metodo 01

// Metodo 02 Auxiliar
void Metodos :: setTelephone ()
{
    int telephone_;
    std :: cout << "Digite Um Telefone: " << std :: endl;
    std :: cin >> telephone_;
    this -> telephone = telephone_; 
}
// Fim Metodo 02 Auxiliar

// Metodo 02
void met02 ( Metodos & metodos )
{
    std :: cout << "Metodo 02" << std :: endl;
    metodos.setTelephone ();
    std :: cout << "Telefone Armazenado: " << metodos.getTelephone () << std :: endl;
    std :: cin.ignore ();
    std :: cin.get ();
}
// Fim Metodo 02

// Metodo 03 Auxiliar
int Metodos :: validateTelephone ()
{
    if ( telephoneIsValid ( telephone ) )
    {
        return telephone;
    } else   
        {
            std :: cout << "Erro" << std :: endl;
            return -1;
        }
}

// Metodo 03
void met03 ( Metodos & metodos )
{
    std :: cout << "Metodo 03" << std :: endl;
    int resultado = metodos.validateTelephone ();
    if ( resultado != -1 )
    {
        std :: cout << "Telefone Retornado: " << resultado << std :: endl;
    } else
        {
            std :: cout << "Telefone Invalido." << std :: endl;
        }
    std :: cin.ignore ();
    std :: cin.get ();
}
// Fim Metodo 03

// Metodo 04 Auxiliar 
void Metodos :: readFile ( FILE * arquivo )
{
    int c = 0;
    
    // Ler o arquivo até o fim, tratando números
    while (fscanf(arquivo, "%d", &c) == 1)  // fscanf tenta ler números inteiros
    {
        std::cout << c << std::endl;
    }

    // Agora, lemos as strings no arquivo
    char str[100];
    while (fscanf(arquivo, "%99s", str) == 1)  // fscanf tenta ler strings
    {
        std::cout << str << std::endl;
    }

    // Agora você pode fazer a operação de rewind, se necessário
    rewind(arquivo);  
}
// Fim Metodo 04 Auxiliar 

// Metodo 04
void met04 ( Metodos & metodos )
{
    FILE * arquivo = tempFile ();
    metodos.readFile ( arquivo );
    fclose ( arquivo );
    std :: cin.ignore ();
    std :: cin.get ();
}
// Fim Metodo 04

// Metodo 05
void met05 ( Metodos & metodos )
{
    FILE * arquivo = tempFile ();
    
    // gravando no arquivo temporário
    fprintf ( arquivo, "Nome: %s\n", metodos.getName ().c_str () ); 
    fprintf ( arquivo, "Telefone: %d\n", metodos.getTelephone () ); 
    fprintf ( arquivo, "Telefone Secundario: %d", metodos.getSecondTelephone () ); 

    // volta para o início do arquivo para ler os dados
    rewind ( arquivo );
    
    // le e imprime o conteúdo do arquivo
    metodos.readFile ( arquivo );
    
    fclose ( arquivo );
    std::cin.ignore ();
    std::cin.get ();
}
// Fim Metodo 05

// Metodo 06
void met06 ()
{
    std :: cout << "Construtores Ja Recebem Um Segundo Telefone!!!" << std :: endl;
    std :: cin.ignore ();
    std :: cin.get ();
}
// Fim Metodo 06

// Metodo 07
void met07 ( Metodos & metodos )
{
    std :: cout << "Metodo 07" << std :: endl;

    if ( metodos.getTelephone () == 0 && metodos.getSecondTelephone () == 0 )
    {
        printf ( "%s", "Nenhum Telefone!\n" );
    } else if (  metodos.getTelephone () == 0 || metodos.getSecondTelephone () == 0 )
        {
            printf ( "%s", "Um Telefone!\n" );
        } else
            {
                printf ( "%s", "Dois Telefones!\n" );
            }

    std :: cin.ignore ();
    std :: cin.get ();
}
// Fim Metodo 07

// Metodo 08 Auxiliar
void Metodos :: setSecondTelephone ()
{
    int secondTelephone_;
    std :: cout << "Digite o Segundo Telefone: " << std :: endl;
    std :: cin >> secondTelephone_;
    this -> secondTelephone = secondTelephone_; 
}
// Fim Metodo 08 Auxiliar

// Metodo 08
void met08 ( Metodos & metodos )
{
    std :: cout << "Metodo 08" << std :: endl;
    metodos.setSecondTelephone ();
    std :: cout << "Telefone Armazenado: " << metodos.getSecondTelephone () << std :: endl;
    std :: cin.ignore ();
    std :: cin.get ();
}
// Fim Metodo 08

// Metodo 09 Auxiliar   
void Metodos :: setNewSecondTelephone ()
{
    int newSecondTelephone_;
    std :: cout << "Digite o Novo Segundo Telefone: " << std :: endl;
    std :: cin >> newSecondTelephone_;
    this -> secondTelephone = newSecondTelephone_; 
}
// Fim Metodo 08 Auxiliar

// Metodo 09
void met09 ( Metodos & metodos )
{
    std :: cout << "Metodo 09" << std :: endl;
    metodos.setSecondTelephone ();
    std :: cout << "Novo Telefone Armazenado: " << metodos.getSecondTelephone () << std :: endl;
    std :: cin.ignore ();
    std :: cin.get ();
}
/* Fim Metodos */

// Metodo 10
void met10 ( Metodos & metodos )
{
    std :: cout << "Telefone Deletado!" << std :: endl;
    metodos.setTelephone ();
    metodos.setSecondTelephone ();
}
// Fim Metodo 10

/* Função Principal */

int main ()
{
    std :: cout << "Gabriel Carvalho de Souza - 846341" << std :: endl;
    std :: cout << "Lista Ed13 07/11/2024" << std :: endl;

    int opc = 0;
    Metodos metodos;

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
            case 1: { met01 ( metodos ); break; }
            case 2: { met02 ( metodos ); break; }
            case 3: { met03 ( metodos ); break; }
            case 4: { met04 ( metodos ); break; }
            case 5: { met05 ( metodos ); break; }
            case 6: { met06 (); break; }
            case 7: { met07 ( metodos ); break; }
            case 8: { met08 ( metodos ); break; }
            case 9: { met09 ( metodos ); break; }
            case 10: { met10 ( metodos ); break; }
            case 11: { metodos.resetObject (); break; }
            default: { std :: cout << "Opcao invalida." << std :: endl; break; }
        }
    } while ( opc != 0 );

    return 0;
}

/* Fim Função Principal */