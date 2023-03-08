
//Faça um programa que receba nome, endereço e número de telefone e mostre as informações na tela.

#include <stdio.h>

int main (){
//Coleta de Dados
    char nome[100], endereco[100], tele[100];
    
    printf("Insira seu nome: ");
    gets(nome); 
    
    printf("Agora, o endereço: ");
    gets(endereco);
	
    printf("Agora, seu número de telefone: ");
    gets(tele);

//Entrega de Dados
    printf("%s \n", nome);
    printf("%s \n", endereco);
    printf("%s \n", tele);


}
