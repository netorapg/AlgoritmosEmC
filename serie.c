#include <stdio.h>

float calcularSerie(int n) {
    if (n == 0)
        return 1.0;
    else
        return 1.0 / (2 * n + 1) + calcularSerie(n - 1);
}

int main() {
    int numero;
    printf("Digite um número inteiro não negativo: ");
    scanf("%d", &numero);

    float resultado = calcularSerie(numero);
    printf("O valor da série para %d é: %.4f\n", numero, resultado);

    return 0;
}
