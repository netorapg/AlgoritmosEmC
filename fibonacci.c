//Faça um programa que calcule os 20 primeiros números da sequência de Fibonacci. 0 1 1 2 3 5 8 13 21 34 ...

#include <stdio.h>

	int main(){

//Variáveis
	int a = 0, b = 1, auxiliar, i, n = 20;

//Mensagem no terminal e primeiro número
	printf("Série de Fibonacci:\n");
	printf("%d\n", b);

//Laço com Variável de Controle
	for(i = 0; i < n; i++){
//instruções
	auxiliar = a + b;

	a = b;

	b = auxiliar;

//Demais números
	printf("%d\n", auxiliar);

	}
}
