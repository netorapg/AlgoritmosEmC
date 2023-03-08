//Faça um programa que receba dois números e mostre o maior
#include <stdio.h>

int main(){

//Variáveis
	int n1, n2;

//Receber os números
	printf("Insira dois números:\n");
	scanf("%d %d", &n1, &n2);

//Condições
	if (n1 > n2){
		printf("%d\n", n1);//Resultado

	}
	else
		printf("%d\n", n2);//Resultado

}
