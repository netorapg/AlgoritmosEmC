//faça um programa que calcule a média aritimética entre três valores informados. Mostre a média na tela.

#include <stdio.h>

int main(){

//Variáveis
	int num1, num2, num3, plus, media;

//Recebe os valores	
	printf("Digite o primeiro número:\n");
	scanf("%d", &num1);
	
	printf("Digite o segundo número:\n");
	scanf("%d", &num2);
	
	printf("Digite o terceiro número:\n");
	scanf("%d", &num3);

//Faz a soma dos valores	
	plus = num1 + num2 + num3;

//Calcula a média	
	media = plus / 3;

//Entrega o resultado	
	printf("a média é: %d ", media);

}
