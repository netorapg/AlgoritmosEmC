//Faça um programa que leia a velocidade máxima permitida em uma avenida e a velocidade com que o motorista estava dirigindo nela e calcule a multa que uma pessoa vai receber, sabendo que são pagos:
//a) 50 reais se o motorista ultrapassar em até 10km/h a velocidade permitida (ex.: velocidade máxima: 50km/h; motorista a 60km/h ou a 56km/h);
//b) 100 reais, se o motorista ultrapassar de 11 a 30 km/h a velocidade permitida.
//sc) 200 reais, se estiver acima de 31km/h da velocidade permitida.
#include<stdio.h>

int main(){

//Variáveis
	int vel_motorista, vel_permitida;

//Receber valores
	printf("\nInsira a velocidade atingida pelo motorista: ");
	scanf("%d", &vel_motorista);

	printf("\nInsira a velocidade máxima permitida: ");
	scanf("%d", &vel_permitida);

//Condições

  if (vel_motorista == vel_permitida +10) {

    printf("\nO motorista será multado em R$50.00\n\n");
    
    }
    else if (vel_motorista >= vel_permitida + 11 && vel_motorista <= vel_permitida + 30){
        printf("O motorista foi multado em R$ 100.00\n\n");

    }
    else if (vel_motorista >= vel_permitida + 31 ) {
        printf("O motorista foi multado em R$200.00\n\n");
    }
    else if (vel_motorista <= vel_permitida){
        printf("Velocidade Ok\n\n");
    }

    return 0;


}
