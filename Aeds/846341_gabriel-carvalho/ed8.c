    // Autor: Gabriel Carvalho De Souza 846341
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

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
        scanf ( " %d", &opcao );
        return opcao;
    }

    void met01 ()
    {
        printf ( "Metodo 01\n" );
        int size = readNumberMoreThanZero ( "Digite O Tamanho Do Array:" );
        int* array = ( int* ) malloc ( size * sizeof ( int ) );

        for ( int i = 0; i < size; i++ )
        {
            printf ( "Digite O Valor Da Posicao %d:\n", i );
            scanf ( " %d", & array [ i ] );

            while ( array [ i ] < 0 || array [ i ] % 2 == 0 )
            {
                printf ( "Digite O Valor Positivo E Impar Da Posicao %d:\n", i );
                scanf ( " %d", & array [ i ] );
            }
        }

        free ( array );
        getchar (); // Para capturar o '\n' da entrada anterior
    }

    void auxiliarMet02 ( FILE* arquivo, int* array, int size )
    {
        int a = 0;
        int i = 0;
        while ( fscanf ( arquivo, " %d", & a ) != EOF && i < size )
        {
            if ( a % 2 != 0 && a > 0 ) // Verifica se o número é ímpar e positivo
            {
                array [ i ] = a;
                i++;
            }
        }

        for ( int j = 0; j < i; j++ )
        {
            printf ( "%d ", array [ j ] );
        }
        printf ( "\n" );
    }

    void met02 ()
    {
        printf ( "Metodo 02\n" );
        FILE * arquivo;
        int size = 10;
        int array [ size ];

        arquivo = fopen ( "dados.txt", "r" );

        auxiliarMet02 ( arquivo, array, size );
        fclose ( arquivo );
        getchar ();
    }

    int gerarNumeroAleatorio ( int inicio, int fim )
    {
        return rand () % ( fim - inicio + 1 ) + inicio;
    }

    void met03 ()
    {
        int inicio, fim, N;

        inicio = readNumberMoreThanZero ( "Digite o limite inferior do intervalo: " );
        fim = readNumberMoreThanZero ( "Digite o limite superior do intervalo: " );

        N = readNumberMoreThanZero(  "Digite a quantidade de números aleatórios a serem gerados: " );

        int * arranjo = ( int* ) malloc ( N * sizeof ( int ) );

        for ( int i = 0; i < N; i++ )
        {
            arranjo [ i ] = gerarNumeroAleatorio ( inicio, fim );
        }

        FILE * arquivo = fopen ( "DADOS.TXT", "w" );
        if ( arquivo == NULL )
        {
            printf ( "Erro ao abrir o arquivo!\n" );
            free ( arranjo );
            return;
        }

        fprintf ( arquivo, "%d\n", N );

        for ( int i = 0; i < N; i++ )
        {
            fprintf ( arquivo, "%d\n", arranjo [ i ] );
        }

        // Fechar o arquivo
        fclose ( arquivo );

        print ( "Números aleatórios gerados e gravados no arquivo 'DADOS.TXT' com sucesso!" );
        free ( arranjo );
        getchar ();
    }

    void auxiliarMet04 ( FILE * arquivo )
    {
        int menor = 99999999, num;
        while ( fscanf ( arquivo, "%d", & num ) != EOF )
        {
            if ( num % 2 != 0 && num < menor )
            {
                menor = num;
            }
        }
        fclose ( arquivo );

        if ( menor == 99999999 )
        {
            printf ( "Não há números ímpares no arranjo.\n" );
        }
        else
        {
            printf ( "O menor valor ímpar é: %d\n", menor );
        }
    }

    void met04 ()
    {
        FILE * arquivo = fopen ( "DADOS.TXT", "r" );
        if ( arquivo == NULL )
        {
            printf ( "Erro ao abrir o arquivo.\n" );
            return;
        }

        auxiliarMet04 ( arquivo );
    }

    void auxiliarMet05 ( FILE* arquivo )
    {
        int maior = -1, num;
        while ( fscanf ( arquivo, "%d", & num ) != EOF )
        {
            if ( num % 2 == 0 && num % 3 == 0 && num > maior )
            {
                maior = num;
            }
        }
        fclose ( arquivo );

        if ( maior == -1 )
        {
            printf ( "Não há números pares e múltiplos de 3 no arranjo.\n" );
        }
        else
        {
            printf ( "O maior valor par e múltiplo de 3 é: %d\n", maior );
        }
    }

    void met05 ()
    {
        FILE * arquivo = fopen ( "DADOS.TXT", "r" );
        if ( arquivo == NULL )
        {
            printf ( "Erro ao abrir o arquivo.\n" );
            return;
        }

        auxiliarMet05 ( arquivo );
    }

    void met06 ()
    {
        FILE * arquivo = fopen ( "DADOS.TXT", "r" );
        if ( arquivo == NULL )
        {
            printf ( "Erro ao abrir o arquivo.\n" );
            return;
        }

        int arranjo [ 100 ], n = 0;
        while ( fscanf ( arquivo, "%d", & arranjo [ n ] ) != EOF )
        {
            n++;
        }
        fclose ( arquivo );

        int soma = 0;
        for ( int i = 0; i < n; i++ )
        {
            soma += arranjo [ i ];
        }

        float media = n > 0 ? (float) soma / n : 0;
        printf ( "A média dos valores no arranjo é: %.2f\n", media );
    }

    void met07()
    {
        FILE * arquivo = fopen ( "DADOS.TXT", "r" );
        if ( arquivo == NULL )
        {
            printf ( "Erro ao abrir o arquivo.\n" );
            return;
        }

        int arranjo [ 100 ], n = 0;
        while ( fscanf ( arquivo, "%d", & arranjo [ n ] ) != EOF )
        {
            n++;
        }
        fclose ( arquivo );

        int ordenado = 1;
        for ( int i = 0; i < n - 1; i++ )
        {
            if ( arranjo [ i ] < arranjo [ i + 1 ] )
            {
                ordenado = 0;
                break;
            }
        }

        if ( ordenado )
        {
            printf ( "O arranjo está ordenado em ordem decrescente.\n" );
        }
        else
        {
            printf ( "O arranjo não está ordenado em ordem decrescente.\n" );
        }
    }

    int acharValor ( int procurado, int inicio, int n, int * arranjo )
    {
        for ( int i = inicio; i < n; i++ )
        {
            if ( arranjo [ i ] == procurado )
            {
                return 1; // Encontrado
            }
        }
        return 0; // Não encontrado
    }

    void met08()
    {
        FILE * arquivo = fopen ( "DADOS.TXT", "r" );
        if ( arquivo == NULL )
        {
            printf ( "Erro ao abrir o arquivo.\n" );
            return;
        }

        int arranjo [ 100 ], n = 0;
        while ( fscanf ( arquivo, "%d", & arranjo [ n ] ) != EOF )
        {
            n++;
        }
        fclose ( arquivo );

        int procurado = readNumberMoreThanZero ( "Digite o valor a ser procurado no arranjo: " );
        int existe = acharValor ( procurado, 0, n, arranjo );

        if ( existe )
        {
            printf ( "O valor %d foi encontrado no arranjo.\n", procurado );
        }
        else
        {
            printf ( "O valor %d não foi encontrado no arranjo.\n", procurado );
        }
    }

    int acharPosicao ( int procurado, int inicio, int n, int * arranjo )
    {
        for ( int i = inicio; i < n; i++ )
        {
            if ( arranjo [ i ] == procurado )
            {
                return i;
            }
        }
        return -1; // Valor não encontrado
    }

    void met09()
    {
        FILE * arquivo = fopen ( "DADOS.TXT", "r" );
        if ( arquivo == NULL )
        {
            printf ( "Erro ao abrir o arquivo.\n" );
            return;
        }

        int arranjo [ 100 ], n = 0;
        while ( fscanf ( arquivo, "%d", & arranjo [ n ] ) != EOF )
        {
            n++;
        }
        fclose ( arquivo );

        int procurado = readNumberMoreThanZero ( "Digite o valor a ser procurado no arranjo: " );
        int posicao = acharPosicao ( procurado, 0, n, arranjo );

        if ( posicao != -1 )
        {
            printf ( "O valor %d foi encontrado na posição %d do arranjo.\n", procurado, posicao );
        }
        else
        {
            printf ( "O valor %d não foi encontrado no arranjo.\n", procurado );
        }
    }

    int acharQuantos ( int procurado, int inicio, int n, int * arranjo )
    {
    int count = 0;
    for ( int i = inicio; i < n; i++ ) 
    {
        if ( arranjo [ i ] == procurado ) 
        {
            count++;
        }
    }
    return count;
    }

    void met10 ()
    {
        FILE * arquivo = fopen ( "DADOS.TXT", "r" );
        if ( arquivo == NULL )
        {
            printf ( "Erro ao abrir o arquivo.\n" );
            return;
        }

        int arranjo [ 100 ], n = 0;
        while ( fscanf ( arquivo, "%d", & arranjo [ n ] ) != EOF )
        {
            n++;
        }
        fclose ( arquivo );

        int procurado = readNumberMoreThanZero ( "Digite o valor a ser procurado no arranjo: " );
        int quantos = acharQuantos ( procurado, 0, n, arranjo );

        printf ( "O valor %d aparece %d vez(es) no arranjo.\n", procurado, quantos );
    }

    int main()
    {
        int opcao = 0;
        srand ( time( NULL ) );

        do
        {
            system ( "cls" );
            menu ();
            opcao = readNumberMoreThanZero ( "Escolha Uma Opcao:" );
            system ( "cls" );

            switch ( opcao )
            {
            case 0: { break; }
            case 1: { met01(); break; }
            case 2: { met02(); break; }
            case 3: { met03(); break; }
            case 4: { met04(); break; }
            case 5: { met05(); break; }
            case 6: { met06(); break; }
            case 7: { met07(); break; }
            case 8: { met08(); break; }
            case 9: { met09(); break; }
            case 10: { met10(); break; }
            default: break;
            }

        } while ( opcao != 0 );

        return 0;
    }
