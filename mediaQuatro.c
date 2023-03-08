//Faça um algoritmo que calcule a média aritmética de quatro notas. Se a média for maior ou igual a 6, então mostrar "Aprovado"; se for maior ou igual a 4 e menor que 6, mostrar "Exame"; se for menor que 4 mostrar "Reprovado".

#include <stdio.h>

int main(){

//Variáveis
	int num1, num2, num3, num4, plus, media;

//Receber as notas
	printf("Digite a primeira nota:\n");
	scanf("%d", &num1);

		printf("Digite a segunda nota:\n");
	scanf("%d", &num2);

		printf("Digite a terceira nota:\n");
	scanf("%d", &num3);

		printf("Digite a quarta nota:\n");
	scanf("%d", &num4);

//Faz a soma das notas
	plus = num1 + num2 + num3 + num4;

//calcula a méda
	media = plus/4;

//condições
if (media == 6){
	printf("O Aluno foi Aprovado\n");
	}
if (media >= 4 && media < 6){
	printf("O Aluno está em Exame\n");
	}
if (media < 4){
	printf("O Aluno foi Reprovado\n");
	}

}
