#include <stdio.h>
#include <math.h>

int main(){


int n;
printf("Insira a quantidade de individuos: ");
scanf("%d", &n);

float vetor[n];
float media, variancia;

for(int i = 0; i < n; i++){
    printf("Insira a altura do individuo %d: ", i + 1);
    scanf("%f", &vetor[i]);
    
}

for (int i = 0; i < n; i++){
    media = media + vetor[i];
}

media = media / n;

for(int i = 0; i < n; i++){
    variancia += pow((vetor[i] - media), 2);


}

variancia = variancia / n;

printf("A média é: %.2f\n", media);

printf("A variância é: %.2f\n", variancia);

return 0;
}