//Faça um programa que leia um número inteiro de 1 a 7 e informe o dia da semana correspondente, sendo domingo o dia de número 1.
//Se o número não corresponder a um dia da semana, mostre uma mensagem de erro.

#include<stdio.h>

int main(){

//Variáveis

	int dom = 1, seg = 2, ter = 3, qua = 4, qui = 5, sex = 6, sab = 7, x;

//Receber o valor
	printf("\ninsira um número de 1 a 7: ");
	scanf("%d", &x);

//Condições
	if (x == dom){
		printf("\nEsse número é equivalente ao primeiro dia da semana, domingo.\n");
	}

	else if (x == seg){
		printf("\nEsse número é equivalente ao segundo dia da semana, segunda-feira.\n");
	}

	else if (x == ter){
		printf("\nEsse número é equivalente ao terceiro dia da semana, terça-feira.\n");
	}

	else if (x == qua){
		printf("\nEsse número é equivalente ao quarto dia da semana, quarta-feira.\n");
	}

	else if (x == qui){
		printf("\nEsse número é equivalente ao quinto dia da semana, quinta-feira.\n");
	}

	else if (x == sex){
		printf("\nEsse número é equivalente ao melhor dia da semana, sexta-feira \\(°o°)/\n");
	}

	else if (x == sab){
		printf("\nEsse número é equivalente ao último dia da semana, sábado.\n");
	}

	else{
		printf("\nincorreto, por favor, reinicie o programa e adicione um número de 1(um) a 7(sete).\n");
	}

}
