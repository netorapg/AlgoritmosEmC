#include <stdio.h>

int somaDigitos (int n) {
    if (n == 0)
    return 0;
    else
    return (n % 10) + somaDigitos (n / 10);
}

int main() {
    int numero;
    printf("Digite um número inteiro não negativo: ");
    scanf("%d", &numero);

    int resultado = somaDigitos(numero);
    printf("A soma dos dígitos de %d é %d", numero, resultado);

    return 0;
}