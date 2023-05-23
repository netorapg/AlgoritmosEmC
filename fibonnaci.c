#include <stdio.h>

int fibonacci (int n) {
    if (n <= 1)
    return n;
    else
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int limite;
    printf("Digite o limite da sequência de Fibonacci: ");
    scanf("%d", &limite);

    printf("Sequência de Fibonacci até o %d° termo:\n", limite);
    for (int i = 0; i < limite; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}