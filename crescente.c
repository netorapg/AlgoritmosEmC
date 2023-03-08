//Faça um programa  que receba três números e os exiba em ordem crescente.

#include <stdio.h>

int main(){

//variáveis
	int n1, n2, n3;

//Recebe os dados
	printf("Digite 3 (três) números:\n");
	scanf("%d %d %d", &n1, &n2, &n3);

//Condições
	if (n1 > n3) {
		int tmp = n3;
		n3 = n1;
		n1 = tmp;
	}
	if (n1 > n2){
		int tmp = n2;
		n2 = n1;
		n1 = tmp;
	}
	if (n2 > n3){
		int tmp = n3;
		n3 = n2;
		n2 = tmp;
	}

//Resultado
	printf("%d %d %d", n1, n2, n3);
}
