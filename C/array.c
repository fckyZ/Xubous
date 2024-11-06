/*
    •                         Biblioteca Para Alocação Dinâmica                            •

     @author    Gabriel Carvalho de Souza
     @date          30 / 10 / 2024           

    • Funções Principais Para Manipulação De Array
    - Função para verificar se o array tem as condições para a alocação dinâmica
    - Função para alocar o espaço necessário para a quantidade desejada
    - Função para adicionar um valor ao array
    - Função para remover um valor ao array
    
    • Condições e Erros
    - Capacidade > 0, Quantidade Atual < Capacidade, Dados != NULL
    - Criando o array com um espaço a mais para manter a segurança
*/

/* 
---------------------------------- Bibliotecas Auxiliares ------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

/* 
--------------------------------- Fim Bibliotecas Auxiliares ---------------------------------
*/


/* 
--------------------------------- Definições de Tipos -----------------------------------------
*/

// Definindo a estrutura para o array dinâmico
typedef 
struct s_int_array
{
    int capacity;   // Capacidade total do array
    int   length;   // Comprimento atual do array
    int  *  data;   // Ponteiro para os dados do array
} int_array;

/* 
--------------------------------- Fim Definições de Tipos ------------------------------------
*/


/* 
--------------------------------- Pré Definições Dos Métodos ---------------------------------
*/

int readIntSize (char * texto);                              // Função para ler o tamanho do array
int readIntValue (char * texto);                             // Função para ler um valor inteiro
int checker_array (int_array * s);                           // Função para verificar as condições do array
void allocate_array (int_array * s, int capacity_);          // Função para alocar o espaço necessário
int_array make_array ();                                     // Função para criar um array dinâmico
void free_array (int_array * s);                             // Função para liberar a memória do array

/* 
--------------------------------- Fim Pré Definições Dos Métodos ----------------------------- 
*/


/* 
-------------------------------------- Métodos Auxiliares ------------------------------------
*/

// Método Para Ler E Armazenar Um Tamanho
int readIntSize (char * texto)
{
    int intNum = 0;
    printf ("%s\n", texto);
    scanf ("%d", & intNum);

    while (intNum <= 0)
    {
        printf ("Digite um número maior que zero:\n");
        scanf ("%d", & intNum);
    }

    return intNum;
}

// Método Para Ler E Armazenar Valores
int readIntValue (char * texto)
{
    int intNum = 0;
    printf ("%s\n", texto);
    scanf ("%d", & intNum);

    return intNum;
}

// Método Para Testes
void test_array (int_array * s)
{
    for (int i = 0; i < s -> length; i++)
    {
        s -> data [i] = i * 2;
        printf ("%d", s -> data[i]);
    }
}

/*
------------------------------------- Fim Métodos Auxiliares ---------------------------------
*/


/* 
-------------------------------------------- Biblioteca --------------------------------------
*/

// Método Para Validar As Condições Necessárias Pra Fazer Um Array
int checker_array (int_array * s)
{
    return (s && s->capacity > 0 && s->length <= s->capacity && s->length >= 0 && s->data != NULL) ? 1 : 0;
} // Fim Do Método

// Método Para Alocar O Espaço Necessário Do Array
void allocate_array (int_array * s, int capacity_)
{
    s -> capacity = capacity_ + 1;

    // Alocando O Espaço
    s -> data = (int *) malloc (s -> capacity * sizeof (int));
    s -> length = 0; // Inicializa o comprimento como zero

    printf ("%s\n", "Alocado Com Sucesso!");
} // Fim Do Método

// Método Para Criar O Array
int_array make_array ()
{
    int_array s;
    // Definindo O Tamanho Do Array
    int sizeArray = readIntSize ("Digite O Tamanho Do Array: ");

    // Alocando O Espaço
    allocate_array (& s, sizeArray);

    s.length = sizeArray;

    // Condicionamento Para Criar O Array
    if (!checker_array (& s))
    {
        printf ("Condições do array não atendidas!\n");
        exit (1);
    }

    return s; // Retorna o array criado
} // Fim Do Método

// Método Para Liberar O Array
void free_array (int_array * s)
{
    free ( s -> data);
    s ->  data = NULL;
    s -> capacity = 0;
    s ->   length = 0;
} // Fim Do Método

/* 
----------------------------------------- Fim Da Biblioteca ---- ------------------------------
*/


// Método Principal
int main ()
{
    int_array array = make_array ();
    test_array (& array);  

    // Liberar a memória alocada
    free_array (& array); 
    
    return 0;
} // Fim Do Método Principal


/*
---------------------- Testes -------------------------------- Realizado ---------------------
        - Teste 01  30 / 10 / 2024 - ( OK )             • Estrutura Principal
                                                        • Método Checker
                                                        • Método Para Alocação De Espaço
                                                        • Método Para Testar Array
                                                        --------------------------------------
        - Teste 02  31 / 10 / 2024 - (  )
*/
