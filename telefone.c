#include <stdio.h>

struct Telefone {
int ddd;
int numeroTel;
};

int main() {
struct Telefone tel;
printf("Digite o DDD: ");
scanf("%d", &tel.ddd);

printf("Digite o numero: ");
scanf("%d", &tel.numeroTel);

printf("O número de telefone é: (%2d) %05d-%04d\n", tel.ddd, tel.numeroTel/10000, tel.numeroTel%10000);

return 0;
}