#include <stdio.h>

void operacoes(double x, double y) {
    double soma = x + y;
    double subtracao = x - y;
    double multiplicacao = x * y;
    double divisao = x / y;
    printf("Soma: %.2lf\n", soma);
    printf("Subtração: %.2lf\n", subtracao);
    printf("Multiplicação: %.2lf\n", multiplicacao);
    printf("Divisão: %.2lf\n", divisao);
}

int main () {
    double x, y;
    printf("Digite o valor de x: ");
    scanf("%lf", &x);
    printf("Digite o valor de y: ");
    scanf("%lf", &y);
    operacoes(x, y);
    return 0;
}
