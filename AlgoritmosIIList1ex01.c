//Faça um programa que receba valores para duas variáveis e troque os valores entre
//elas, utilizando uma função.

#include <stdio.h>

int change(int A, int B) {
    int tmp = A;
    A = B;
    B = tmp;
    return printf("A = %d, B = %d\n", A, B);
}

int main() {
    int A, B;
    printf("Insira o valor de A: ");
    scanf("%d", &A);
    printf("Insira o valor de B: ");
    scanf("%d", &B);
    change(A, B);
    return 0;
}