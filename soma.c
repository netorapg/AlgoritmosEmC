//Faça um programa que receba dois números, efetue a soma e mostre o resultado na tela.

#include <stdio.h>

int main(){
//Variáveis     
    int num1, num2, plus;
    
//Recebe os valores 
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    
//faz a soma dos valores
    plus = num1 + num2;

//entrega o resultado
    printf("%.2d + %.2d = %.2d\n", num1, num2, plus);

}

