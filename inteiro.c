//Faça um programa que receba um número inteiro positivo e maior que zero, calcule e mostre: a) o número digitado ao quadrado; b)O número digitado ao cubo.

#include <stdio.h>
#include <stdlib.h>

int main(){

int n, q, c;

//Receber o valor
	printf("Insira um número inteiro positivo e maior que zero: ");
	scanf("%d", &n);

//Cálculos
	q = n * n;
	printf("%d ao quadrado: %d\n", n, q);//Resultado

	c = n * n * n;
	printf("%d ao cubo: %d\n",n, c);//Resultado


}
