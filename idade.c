//Faça um programa que receba o ano de nascimeto de uma pessoa e o ano atual. Calcule e mostre: a) A idade da pessoa; b) Quantos anos essa pessoa terá em 2050.

#include <stdio.h>

int main(){

//Variáveis
	int nascimento, atual, idade, futuro, velho;

//Valor fixo
	futuro = 2050;

//Receber os dados
	printf("Ano de nascimento:\n");
	scanf("%d", &nascimento);

	printf("Ano atual:\n");
	scanf("%d", &atual);

//Cálculos
	idade = atual - nascimento;
	velho = futuro - nascimento;

//Resultado
	printf("Você nasceu em %d, atualmente, no ano %d, voce tem %d, mas em 2050, você terá %d\n", nascimento, atual, idade, velho);

}
