#include <stdio.h>

int main() {
    FILE *arquivo;
    char linha[100];

    arquivo = fopen("arquivo.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%ss", linha);
    }

    fclose(arquivo);
    return 0;

}