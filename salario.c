//Faça um algoritmo para calcular o novo salário de um funcionário. Sabe-se que os funcionários que possuem salário até 500,00 terão aumento de 20%, os demais terão aumento de 10%

#include <stdio.h>
#include <stdlib.h>

int main(){
//Variáveis
	char nome[100];
	float s, ns, per;

//Recebe os valores
	printf("Digite o nome do funcionário:\n");
	gets(nome);

	printf("Digite o salário atual de %s:", nome);
	scanf("%f",&s);

//Condições

if (s <= 500.00){
	per = 20.0 / 100.0;//Cálculo da porcentagem
	ns = s + (per * s);//Cálculo do novo salário
		printf("O novo salário de %s é de %f:\n", nome, ns);//Resultado
	}
	else
		per = 10.0 / 100.0;//Cálculo da porcentagem
		ns = s + (per * s);//Cálculo do novo salário
			printf("O novo salário de %s é de %f:\n", nome, ns);//Resultado

}
