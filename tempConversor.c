//Faça um algoritmo que calcule a temperatura em Fahrenheit e apresente-a covertida em graus celsius. Nota:°C = (°F - 32) / 1.8

#include <stdio.h>
#include <stdlib.h>

int main(){

//Variaveis
	float F, C;

//Receber o valor
	printf("Digite o valor de Fahrenheit:\n");
	scanf("%f", &F);

//Conversão
	C = (F - 32) / 1.8;

//Resultado
	printf("o valor de %f° Fahrenheit convertido para Celsius é de: %f°\n", F, C);

}
