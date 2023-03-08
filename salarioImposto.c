//Faça um programa que receba um número inteiro e verifique se esse número é par ou impar.

#include <stdio.h>

int main(){

//Variáveis
	int num;

//Recebe o número
	printf("Insira um número: ");
	scanf("%i", &num);

//Condições
	if(num % 2 == 0){
	printf("\nNúmero Par\n\n");//Resultado
	}
	else{
		printf("\nNúmero Ímpar\n\n");//Resultado

	}
}
