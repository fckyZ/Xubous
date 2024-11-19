#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) 
{
    // Calcula o comprimento da string de entrada
    int len = strlen(s);

    // Aloca dinamicamente uma pilha com o tamanho da string
    // No pior caso, a pilha terá o mesmo tamanho da string
    char* pilha = (char*)malloc(len * sizeof(char));

    // Inicializa o topo da pilha em -1 
    // -1 indica que a pilha está vazia
    // Quando empilharmos, incrementaremos antes de inserir
    int topo = -1;

    // Percorre cada caractere da string
    for (int i = 0; i < len; i++) 
    {
        // Verifica se o caractere atual é um símbolo de abertura
        // Empilha símbolos de abertura: '(', '{', '['
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
        {
            // Incrementa o topo e insere o símbolo de abertura
            // ++topo: primeiro incrementa, depois insere
            pilha[++topo] = s[i];
        } 
        // Se não for símbolo de abertura, é um símbolo de fechamento
        else 
        {
            // Condições para invalidar a sequência:
            // 1. Pilha vazia (topo == -1)
            // 2. Topo não vazio, mas par de símbolos não corresponde
            if (topo == -1 || 
                (topo >= 0 && 
                 ((pilha[topo] == '(' && s[i] != ')') || 
                  (pilha[topo] == '{' && s[i] != '}') || 
                  (pilha[topo] == '[' && s[i] != ']')))) 
            {
                // Libera memória alocada antes de retornar
                free(pilha);
                // Sequência inválida
                return false;
            }
            
            // Remove o topo da pilha (fecha o par de símbolos)
            // Decrementa o topo, efetivamente "removendo" o símbolo
            topo--;
        }
    }

    // Verifica se todos os símbolos foram pareados
    // Se a pilha estiver vazia (topo == -1), todos símbolos têm par
    bool resultado = (topo == -1);

    // Libera a memória alocada para a pilha
    free(pilha);

    // Retorna se a sequência é válida
    return resultado;
}