#include <stdio.h>

int main() {
int n1, n2, n;

printf("Insira o primeiro número inteiro: ");
scanf("%d", &n1);
printf("Insira o segundo número inteiro: ");
scanf("%d", &n2);
printf("Digite o número de múltiplos que deseja: ");
scanf("%d", &n);

int count = 1;
int i = 1;
printf("Os %d primeiros múltiplos de %d e %d são: \n");
while (count <= n) {
if (i % n1 == 0 && i % n2 == 0) {
printf("%d ", i);
count++;
}
i++;
}
return 0;

}