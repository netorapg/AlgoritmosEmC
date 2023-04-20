#include <stdio.h>

int main() {
char operacao;
float n1, n2, resultado;

printf("Digite a operação(use os simbolos +,-,/,*): ");
scanf("%c", &operacao);
printf("Digite o primeiro número: ");
scanf("%f", &n1);
printf("Digite o segundo número: ");
scanf("%f", &n2);

switch(operacao) {
case '+':
resultado = n1 + n2;
printf("Resultado: %.2f", resultado);
break;
case '-':
resultado = n1 - n2;
printf("Resultado: %.2f", resultado);
break;
case '/':
resultado = n1 / n2;
printf("Resultado: %.2f", resultado);
break;
case '*':
resultado = n1 * n2;
printf("Resultado: %.2f", resultado);
break;
default:
printf("Operação inválida!");
return 1;
}

return 0;
}