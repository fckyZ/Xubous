#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode * next;
};
 

struct ListNode * mergeTwoLists ( struct ListNode * list1, struct ListNode * list2 )
{
    if ( list1 == NULL ) return list2; if ( list2 == NULL ) return list1;
    
    struct ListNode * head = NULL; // criando cabeça pra manipulação dos nós já criados
    struct ListNode * tail = NULL; // criando cauda ...

    while ( list1 != NULL && list2 != NULL ) // enquanto as listaras tiverem elementos
    {
        struct ListNode * temp; // ponteiro auxiliar pra armazenar valores do nó atual

        if ( list1 -> val <= list2 -> val )
        {
            temp = list1;
            list1 = list1 -> next; // avançar para o próximo nó
        } else
            {
                temp = list2;
                list2 = list2 -> next; // avançar para o próximo nó
            }
        
        if ( head == NULL ) 
        {
            head = temp;  // se for o primeiro nó, ele é o head da lista mesclada
            tail = temp;  // o tail também aponta para esse nó
        } else 
            {
                tail -> next = temp;  // adiciona o nó à cauda
                tail = temp;  // atualiza a cauda para o último nó
            }
    }

    if ( list1 != NULL )
    {
        tail -> next = list1;
    } else if ( list2 != NULL )
    {
        tail -> next = list2;
    }
    
    return head;
}

int main ( )
{

}