//Faça um programa que calcule o fatorial de um número lido, utilizando uma função
#include <stdio.h>

int fatorial (int n){
    int result = 1;
    for (int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

int main() {
    int n;
    printf("Insira um número inteiro: ");
    scanf("%d", &n);
    printf("O fatorial de %d é %d\n", n, fatorial(n));
    return 0;
}