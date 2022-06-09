//Faça um programa que receba um número inteiro maior que zero e verifique se ele é número primo ou não. Imprima mensagens informando ao usuário.
#include <stdio.h>

int main(){
//Variáveis
	int num, i, result = 0;

	printf("\nPor favor, insira um número inteiro maior que zero: ");
	scanf("%d", &num);

	for (i = 2; i <= num / 2; i++){
		if (num % i == 0) {
			result++;
			break;
		}
	}
	if (result == 0)
		printf("%d é primo\n", num);
	else
		printf("%d não é um número primo\n", num);

return 0;

}
