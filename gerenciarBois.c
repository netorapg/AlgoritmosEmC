#include <stdio.h>

#define MAXBOI 10

int main() {
int identificadores[MAXBOI];
float pesos[MAXBOI];
int i = 0;
int numBois = 0;
int maisGordo = 0;
int maisMagro = 0.0;

printf("Digite o peso do boi %d (0 para encerrar): ", i + 1);
scanf("%f", &pesos[i]);

while (pesos[i] != 0) {
identificadores[i] = i + 1;
numBois++;
i++;

if (i == MAXBOI) {
printf("Numero maximo de bois atingido!\n");
break;
}

printf("Digite o peso do boi %d (0 para encerrar): ", i + 1);
scanf("%f", &pesos[i]);
}

for (i = 1; i < numBois; i++) {
if (pesos[i] > pesos[maisGordo]) {
maisGordo = i;
}
if (pesos[i] < pesos[maisMagro]) {
maisMagro = i;
}
}

printf("\nLista de bois:\n");
for (i = 0; i < numBois; i++) {
printf("Boi %d - Peso: %.2f\n", identificadores[i], pesos[i]);
}

printf("\nBoi mais gordo: %d - Peso: %.2f\n", identificadores[maisGordo], pesos[maisGordo]);
printf("Boi mais magro: %d - Peso: %.2f\n", identificadores[maisMagro], pesos[maisMagro]);

return 0;
}