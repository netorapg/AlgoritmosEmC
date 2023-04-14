#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
int numeroSorteado, tentativa;
int numeroTentativas = 0;

srand(time(NULL));
numeroSorteado = rand() % 101;

do{
printf("Insira um valor de 0 a 100: ");
scanf("%d", &tentativa);

if (tentativa < 0 || tentativa > 100) {
printf("Valor inválido. Insira um número entre 0 e 100.\n");
continue;
}
if(tentativa > numeroSorteado){
printf("O numero sorteado é menor que %d\n", tentativa);
} else if (tentativa < numeroSorteado) {
printf("O numero sorteado é maior que %d\n", tentativa);
} else {
printf("Parabéns, você acertou o numero sorteado!\n");
}
numeroTentativas++;

} while (tentativa != numeroSorteado);
printf("Você precisou de %d tentativas para acertar o numero sorteado\n", numeroTentativas);
return 0;
}