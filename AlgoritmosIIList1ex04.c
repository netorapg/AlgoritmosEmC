//Criar um algoritmo que receba notas de três provas e calcular a sua média, mas
//utilizando uma função.
#include <stdio.h>

int soma(int nota1, int nota2, int nota3) {
    int media = (nota1 + nota2 + nota3) / 3;
    return media;
}

int main(){
    int nota1, nota2, nota3;
    printf("Insira a primeira nota: ");
    scanf("%d", &nota1);
    printf("Insira a segunda nota: ");
    scanf("%d", &nota2);
    printf("Insira a terceira nota: ");
    scanf("%d", &nota3);
    printf("A média é: %d\n", soma(nota1, nota2, nota3));
}