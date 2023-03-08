//Faça um programa que realize a conversão de dólar (US$) para real (R$). Deve ser fornecido o valor da cotação em dólar e também a quantidade de dólares disponíveis com o usuário.
#include <stdio.h>

int main(void){

//Variáveis
	float dolar, real, cota;

//Receber valor
	printf("Insira a quantidade em dólar a ser convertida:\n");
	scanf("%f", &dolar);

//Cálculo

cota = 5.60;//valor fixo

real = dolar * cota;

//Resultado
	printf("Cota atual do dólar: U$%0.2f \n", cota);

	printf("Quantidade de dólar disponível: US$%0.2f\n", dolar);

	printf("Valor total convertido: R$%0.2f\n", real);





}
