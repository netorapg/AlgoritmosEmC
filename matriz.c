#include <stdio.h>

int main() {
int matriz[5][5];
int linha, coluna;
printf("Digite os valores da matriz:\n");
for (linha = 0; linha < 5; linha++) {
for (coluna = 0; coluna < 5; coluna++) {
scanf("%d", &matriz[linha][coluna]);
}
}
printf("Matriz original:\n");
for (linha = 0; linha < 5; linha++) {
for (coluna = 0; coluna < 5; coluna++) {
printf("%d ", matriz[linha][coluna]);
}
printf("\n");
}
printf("Matriz transposta:\n");
for (coluna = 0; coluna < 5; coluna++) {
for (linha = 0; linha < 5; linha++) {
printf("%d ", matriz[linha][coluna]);
}
printf("\n");
}
return 0;
}