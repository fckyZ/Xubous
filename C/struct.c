#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void q_02(char *p, char *q) {
    char *r = calloc(strlen(p) * strlen(q) + 1, sizeof(char)); // Alocação de memória
    int k = 0; // Inicialização do índice

    for (int x = 0; x < strlen(p); x++) {
        for (int y = 0; y < strlen(q); y++) {
            if (x == strlen(p) / 2) {
                r[k] = p[x];
                r[k+1] = q[y];
                k += 2;
                if (k > 6) {
                    y = strlen(q);
                    x = strlen(p);
                }
            }
        }
    }
    printf("[%s]\n", r);
}

int main ()
{
    q_02 ( "goiabada", "queijo" );
    return 0;
}