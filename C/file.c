#include <stdio.h>
#include <stdlib.h>

void readFile(FILE *arquivo)
{
    int numero;
    // Leia cada número até o final do arquivo
    while (fscanf(arquivo, "%d", &numero) != EOF)
    {
        printf("%d ", numero); // Imprime o número na tela
    }
    printf("\n"); // Para uma nova linha após o fim do arquivo
}

int main()
{
    FILE *arquivo = fopen("meu_arquivo.txt", "r"); // Abre o arquivo em modo leitura

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Sai do programa caso o arquivo não possa ser aberto
    }

    readFile(arquivo); // Chama a função para ler e imprimir os números do arquivo

    fclose(arquivo); // Fecha o arquivo após a leitura
    return 0;
}
