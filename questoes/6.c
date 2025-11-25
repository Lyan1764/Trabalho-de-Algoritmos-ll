#include <stdio.h>
#include <stdlib.h>

long long tamanho_Collatz(long long n, FILE *f) {
    long long atual = n;
    long long tamanho = 1;

    fprintf(f, "%lld: %lld", n, atual);

    while (atual > 1) {
        if (atual % 2 == 0) {
            atual = atual / 2;
        } else {
            atual = (3 * atual) + 1;
        }
        
        fprintf(f, " -> %lld", atual);
        tamanho++;
    }

    fprintf(f, "\n");

    return tamanho;
}

int main() {
    long long N, i;
    long long num_maior_cadeia = 1;
    long long tam_maior_cadeia = 1;
    long long tam_atual;

    printf("Digite o valor limite N: ");
   
    scanf("%lld", &N);

    FILE *arquivo = fopen("collatz_sequencias.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de saída!\n");
        return 1;
    }

    fprintf(arquivo, "--- Todas as cadeias de Collatz ---\n");

    for (i = 1; i <= N; i++) {
        tam_atual = tamanho_Collatz(i, arquivo);

        if (tam_atual > tam_maior_cadeia) {
            tam_maior_cadeia = tam_atual;
            num_maior_cadeia = i;
        }
    }

    fclose(arquivo);


    printf("Num_maior_cadeia = %lld\n", num_maior_cadeia);
    printf("Tamanho_maior_cadeia = %lld\n", tam_maior_cadeia);
    printf("Sequencias salvas no arquivo 'collatz_sequencias.txt'.\n");

    return 0;
}