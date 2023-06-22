#include <stdio.h>

int main() {
float n1, n2, n3, maior, menor, media;

printf("Digite o primeiro valor: ");
scanf("%f", &n1);
printf("Digite o segundo valor: ");
scanf("%f", &n2);
printf("Digite o terceiro valor: ");
scanf("%f", &n3);

if (n1 > n2 && n1 > n3) {
maior = n1;
printf("O maior valor é: %.2f \n", maior);
} else if (n2 > n1 && n2 > n3) {
maior = n2;
printf("O maior valor é: %.2f \n", maior);
} else {
maior = n3;
printf("O maior valor é: %.2f \n", maior);
}

if (n1 < n2 && n1 < n3) {
menor = n1;
printf("O menor valor é: %.2f \n", menor);
} else if (n2 < n1 && n2 < n3) {
menor = n2;
printf("O menor valor é: %.2f \n", menor);
} else {
menor = n3;
printf("O menor valor é: %.2f \n", menor);
}

media = (n1 + n2 + n3) / 3;
printf("A média dos valores é: %.2f \n", media);

}