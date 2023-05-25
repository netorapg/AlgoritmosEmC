//Crie uma função recursiva que receba a razão de uma progressão aritmética e a
//posição a ser descoberta.
#include <stdio.h>

int progressaoAritmetica(int razao, int posicao){
    if (posicao == 1){
        return 1;
} else {
    return razao + progressaoAritmetica(razao, posicao - 1);
}
}

int main() {
    int razao, posicao, resultado;
    printf("Digite a razão da progressão aritmética: ");
    scanf("%d", &razao);
    printf("Digite a posição que deseja descobrir: ");
    scanf("%d", &posicao);
    resultado = progressaoAritmetica(razao, posicao);
    printf("O valor da posição %d é %d", posicao, resultado);
    return 0;
}