#include <stdio.h>
int fatorial (int num);

int main () {
    int n, p;
    float combinacao;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    printf("Digite o valor de p: ");
    scanf("%d", &p);
    combinacao = fatorial(n) / (fatorial(p) * fatorial(n - p));
    printf("\n\nValor da combinação: %f\n\n", combinacao);
    return 0;
}

int fatorial (int num)
{
    int i, fat = 1;
    for ( i = num; i >= 1; i--)
    
        fat = fat * i;
        return (fat);
    
}