//Faça um programa que calcule a área de um triângulo retângulo, dados os valores de sua base e altura.

#include <stdio.h>

int main()
{
//Variáveis
    int b, h, A;
    
//Entrada de Dados    
    printf("\nInforme o valor da base: ");
    scanf("%d", &b);
    
    printf("\nInforme o valor da altura: ");
    scanf("%d", &h);

//Fórmula
    A = (b * h) / 2;

//Entrega do Resultado
    printf("A área do triângulo é: %d\n", A);
}
