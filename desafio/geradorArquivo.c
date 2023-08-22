#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp = fopen("arquivoMaior.txt", "w");

    if (fp == NULL) {
        printf("Não foi possível criar o arquivo.\n");
        return 1;
    }

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    for (int i = 1; i <= 1000; i++) {
        fprintf(fp, "%d;%d;%d;%d;%d;%d;%d\n", 
            i, 
            rand() % 101, // Gera um valor entre 0 e 100
            rand() % 101,
            rand() % 101,
            rand() % 101,
            rand() % 101,
            2020 + (rand() % 4) // Gera um valor entre 2020 e 2023
        );
    }

    fclose(fp);
    printf("Arquivo criado com sucesso.\n");

    return 0;
}
