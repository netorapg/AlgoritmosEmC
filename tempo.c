//Faça um programa que receba o tempo de duração de um evento expresso em segundos e mostre-o expresso em horas, minutos e segundos.

#include <stdio.h>
#include <cstdio>

int main(){

//Variáveis

	float total_seg, horas, min, seg;

//Receber valores
	printf("Insira a quantidade de segundos:\n");
	scanf("%f", &total_seg);

//Cálculos

	horas = total_seg / 3600;

	min = horas / 60;

	seg = min / 60;

//Resultado

	printf("%0.1f horas %0.1f minutos %0.1f segundos", horas, min, seg);
}


