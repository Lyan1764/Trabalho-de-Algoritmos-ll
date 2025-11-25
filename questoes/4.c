#include <stdio.h>

#define N 6

int contarPares(int *tamanhos, char *lados) {
    int i, j, pares = 0;

    for (i = 0; i < N; i++) {
        
        if (*(lados + i) == 'X') {
            continue;
        }

        for (j = i + 1; j < N; j++) {
            
            if (*(lados + j) == 'X') {
                continue;
            }

            if (*(tamanhos + i) == *(tamanhos + j) && *(lados + i) != *(lados + j)) {
                
                pares++; 

                *(lados + i) = 'X'; 
                *(lados + j) = 'X';
                
                break; 
            }
        }
    }
    return pares;
}

int main() {
    int tamanhos[N];
    char lados[N];
    int i;

    printf("Digite os %d tamanhos das botas (entre 30 e 60):\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", (tamanhos + i));
    }

    printf("Digite os %d lados das botas (E ou D):\n", N);
    for (i = 0; i < N; i++) {
        scanf(" %c", (lados + i));
    }

    int total = contarPares(tamanhos, lados);

    printf("\nNumero de pares: %d\n", total);

    return 0;
}