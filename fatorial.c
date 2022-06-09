
//Faça um programa que calcule o fatorial de um número.

#include <stdio.h>

int main(){

//Variáveis
	int CONTADOR, N;
	long FATORIAL = 1;

//Variáveis com valor fíxo
	CONTADOR = 1;

//Mensagem no terminal
	printf("\nPrograma Fatorial\n");

//Coleta de dados
	printf("\nPor favor, insira um número para calcular sua fatorial: "); 
	scanf("%d", &N);

//Looping do tipo While
	while (CONTADOR <= N){

	FATORIAL *= CONTADOR;
	CONTADOR ++;
	}
//Resultado
	printf("\nFatorial de %d equivale a %ld\n\n", N, FATORIAL);
	return 0;
}
