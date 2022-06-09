//Faça um programa que imprima os múltiplos positivos de 7 inferiores a 1000.

#include <stdio.h>

int main(){

	int z = 0, x = 7, i, n = 1000; 

	printf("\n\nEis os múltiplos de 7 inferiores a 1000.\n\n");

	while (z < n){
	i = x * z;
	z ++;
	printf("\n%d\n", i);
	}
	return 0;

}
