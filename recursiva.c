#include <stdio.h>

int fatorial(int n) {
    // Considção de parada
    if (n == 0) {
        return 1;
    }
    // Caso recursivo
    else{
        return n * fatorial(n-1);
    }
}

int main() {
    int numero = 5;
    int resultado = fatorial(numero);
    printf("O fatorial de %d é %d", numero, resultado);
    return 0;
}