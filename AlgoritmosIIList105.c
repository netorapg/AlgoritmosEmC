//Criar um algoritmo que leia dois números e imprima o maior número, usando uma
//função.
#include <stdio.h>

int maior() {
    int n1, n2;
    printf("Insira o primeiro numero:");
    scanf("%d", &n1);
    printf("Insira o segundo numero:");
    scanf("%d", &n2);
    if(n1 > n2) {
        return printf("O maior número é: %d\n", n1);
    }else {
        return printf("O maior número é: %d\n", n2);
    }
}

int main() {
    maior();
    return 0;
}