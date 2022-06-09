//Faça um programa que receba um número real, calcule e mostre sua parte fracionária, sua parte inteira e o arredondamento desse número.

#include <stdio.h>
#include <stdlib.h>

int main(){

//variáveis
	float real;
//Recebe o número
	printf("Digite um número real:\n");
	scanf("%f", &real);
//Faz o cálculo e entrega o resultado
	printf("A parte inteira deste número é: %d\n", (int)real);
	printf("A parte fracionária deste número é: %.2f\n",real-(int)real);
	printf("O arredondamento deste número é: %0f.\n", real);

}
