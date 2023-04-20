#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, j, k;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &n);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &m);

    int matriz[n][m];
    int vetor[n*m];

    printf("Digite os elementos da matriz:\n");
    for(i = 0, k = 0; i < n; i++) {
        for(j = 0; j < m; j++, k++) {
            scanf("%d", &matriz[i][j]);
            vetor[k] = matriz[i][j];
        }
    }

    printf("A matriz transformada em vetor é:\n");
    for(i = 0; i < n * m; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
