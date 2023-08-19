#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main() {
    clock_t inicio, fim;
    double tempoCorrido;

    inicio = clock();
    FILE *arquivo;
    char linha[100];

    arquivo = fopen("arquivo.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
    fim = clock();
    tempoCorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %.2f segundos\n", tempoCorrido);

    return 0;
}