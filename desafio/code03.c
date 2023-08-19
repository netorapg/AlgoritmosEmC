#include <stdio.h>

int main() {
    FILE *arquivo;

    arquivo = fopen("arquivo.txt", "w");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "Primeira linha\n");
    fprintf(arquivo, "Segunda linha\n");

    fclose(arquivo);

    return 0;
}