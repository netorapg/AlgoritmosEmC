//Faça um programa que receba o raio de um circulo, calcule e mostre sua área.(Área = π * R²)

#include <stdio.h>

int main(){

//Variáveis
	float A, r, pi = 3.14;

//Coleta de Dados	
	printf("Insira o valor do raio:\n ");
	scanf("%f", &r);

//Aplicação da fórmula	
	A = pi * (r * r);

//Entrega do resultado	
	printf("A área é: %f\n", A);

}
