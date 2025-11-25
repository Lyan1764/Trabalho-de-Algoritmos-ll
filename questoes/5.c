#include <stdio.h>

float raiz_quadrada(float numero) {
    if (numero == 0) return 0;
    
    float x_atual = numero / 2.0;
    float x_anterior;
    float diferenca;
    
    if (numero == 1) x_atual = 1;

    do {
        x_anterior = x_atual;
        
        x_atual = (x_anterior + (numero / x_anterior)) / 2.0;
        
        diferenca = x_atual - x_anterior;
        if (diferenca < 0) {
            diferenca = -diferenca;
        }
        
    } while (diferenca > 0.000001);
    
    return x_atual;
}

int main() {
    float numero;
    
    while (1) {
        printf("Digite um numero real positivo (ou 0/negativo para sair): ");
        scanf("%f", &numero);
        
        if (numero <= 0) {
            printf("Encerrando o programa.\n");
            break;
        }
        
        float raiz = raiz_quadrada(numero);
        
        printf("raiz quadrada = %g\n\n", raiz);
    }
    
    return 0;
}