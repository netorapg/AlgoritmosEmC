#include <stdio.h>

int main(){
//Variáveis
	 int ano, mes, dia, total_dias;

//Receber valores

	printf("insira a quantidade de anos:\n");
	scanf("%d", &ano);

	printf("insira a quantidade de meses:\n");
	scanf("%d", &mes);

	printf("insira a quantidade de dias:\n");
	scanf("%d", &dia);

//Conversões

total_dias = (ano*365) + (mes * 30) + dia;

printf("%d dias\n", total_dias);

}
