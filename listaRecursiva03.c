/*Crie uma função recursiva que receba a razão de uma progressão geométrica e a
posição a ser descoberta*/
#include <stdio.h>

int progressaoGeometrica(int razao, int posicao){
    if (posicao == 1) {
        return 1;
    } else {
        return razao * progressaoGeometrica(razao, posicao - 1);
    }
}

int main() {
    int razao, posicao, resultado;
    printf("Digite a razão da progressão geométrica: ");
    scanf("%d", &razao);
    printf("Digite a posição que deseja descobrir: ");
    scanf("%d", &posicao);
    resultado = progressaoGeometrica(razao, posicao);
    printf("O valor da posição %d é %d", posicao, resultado);
    return 0;
}