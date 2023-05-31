
/*Construa uma função em C que receba como argumentos dois
valores inteiros, calcule e exiba os valores obtidos pela
multiplicação entre ambos e pela adição entre ambos.*/


/*Com passagem de parâmetros por valor*/

#include <stdio.h>

void calcula (int x, int y) {
    int mult = x * y;
    int soma = x + y;
    printf("Multiplicação: %d\n", mult);
    printf("Soma: %d\n", soma);
}

int main () {
    int x, y;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);
    calcula(x, y);
    return 0;
}

/*Com passagem de parâmetros por referência*/

#include <stdio.h>

void calcula (int *x, int *y) {
    int mult = *x * *y;
    int soma = *x + *y;
    printf("Multiplicação: %d\n", mult);
    printf("Soma: %d\n", soma);
}

int main () {
    int x, y;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);
    calcula(&x, &y);
   
}


/*Sem passagem de parâmetros*/

#include <stdio.h>

int x = 10;
int y = 20;

void calcula () {
    int mult = x * y;
    int soma = x + y;
    printf("Multiplicação: %d\n", mult);
    printf("Soma: %d\n", soma);
}

int main () {
   calcula ();
   return 0;
}