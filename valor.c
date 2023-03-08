//Faça um programa que calcule o valor do total a ser pago pelo cliente, considerando o valor gasto (refeição, bebidas e sobremesas) mais os 10% adicionais do garçom sobre o valor total. O programa deve informar o valor total a ser pago pelo cliente.
#include<stdio.h>

int main(){

//Varáveis
	float valor, valor_total, refeicao, bebida, sobremesa, gorjeta;

	printf("\ninsira o valor da refeição(adicione o ponto flutuante):\n ");
	scanf("%f", &refeicao);
	printf("\nrefeição: R$%0.2f\n", refeicao);

	printf("\ninsira o valor da bebida:\n ");
	scanf("%f", &bebida);
	printf("\nbebida(s):R$%0.2f\n", bebida);

	printf("\ninsira o valor da sobremesa:\n ");
	scanf("%f", &sobremesa);
	printf("\nsobremesa: R$%0.2f\n", sobremesa);

//Cálculos
	valor = refeicao + bebida + sobremesa;
	printf("\nValor:R$%0.2f\n", valor);

	gorjeta = (valor * 10) / 100;

	valor_total = valor + gorjeta;

//Resultado
	printf("\nO Valor total a ser pago é de:R$%0.2f\n", valor_total);


}
