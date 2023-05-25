//1. Crie uma função recursiva para realizar uma somatória de de número inteiros de n até
//1, sendo n um número inteiro informado pelo usuário
#include <stdio.h>

int somatoria(int n){
    if(n == 1){
        return 1;
    }else{
        return n + somatoria(n-1);
    }
}

int main(){
    int numero;
    printf("Digite um número inteiro não negativo: ");
    scanf("%d", &numero);

    int resultado = somatoria(numero);
    printf("A soma dos numeros até %d é %d \n", numero, resultado);

    return 0;
}