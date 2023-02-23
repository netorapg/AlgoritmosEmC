//Faça um algoritmo para calcular o novo salário de um funcionário. Sabe-se que os funcionários que possuem salário até 500,00 terão aumento de 20%, os demais terão aumento de 10%

#include <stdlib.h>

int main(){
//Variáveis
	char nome[100];
	float salario, novoSalario, percent;

//Recebe os valores
	printf("Digite o nome do funcionário:\n");
	gets(nome);

	printf("Digite o salário atual de %s:", nome);
	scanf("%f",&salario);

//Condições

if (salario <= 500.00){
	percent = 20.0 / 100.0;//Cálculo da porcentagem
	novoSalario = salario + (percent * salario);//Cálculo do novo salário
		printf("O novo salário de %s é de %.2f:\n", nome, novoSalario);//Resultado
	}
	else
		percent = 10.0 / 100.0;//Cálculo da porcentagem
		novoSalario = salario + (percent * salario);//Cálculo do novo salário
			printf("O novo salário de %s é de %.2f:\n", nome, novoSalario);//Resultado

}
