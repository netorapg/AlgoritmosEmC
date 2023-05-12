//Criar uma função que verifique se um número é par
#include <stdio.h>

int par(int n) {
    if(n % 2 == 0) {
        return printf("O número %d é par\n", n);
    }else {
        return printf("O número %d é ímpar\n", n);
    }
}

int main() {
    int n;
    printf("Insira um número inteiro: ");
    scanf("%d", &n);
    par(n);
    return 0;
}