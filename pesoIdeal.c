//Faça um programa que receba a altura e o sexo de uma pessoa e que calcule seu peso ideal, utilizando as seguintes fórmulas.
//para homens: (72.7 * h) – 58;
//Para mulheres: (62.1 * h) – 44.7.

#include <stdio.h>

int main(){

//Variáveis
	char sex;

	float altura, peso_ideal;

	printf("diga se você é homem ou mulher(h ou m):\n");
	scanf("%s", &sex);

	printf("diga a sua altura(adicione ponto flutuante):\n");
	scanf("%f", &altura);

		if (sex == 'h'){
		peso_ideal = (72.7 * altura) - 58.0;
		printf("Olá amigo, o seu peso ideal é: %0.2f\n", peso_ideal);
	}
	else{
		peso_ideal = (62.1 * altura) -44.7;
		printf("Olá amiga, o seu peso ideal é: %0.2f\n", peso_ideal);
	}
}
