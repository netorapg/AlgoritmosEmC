#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    int id;
    int notas[5];
    int ano;
} Estudante;

double media (int *valores, int tamanho) {
    double soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += valores[i];
    }
    return soma / tamanho;
}

double mediana (int *valores, int tamanho) {
    if (tamanho % 2 == 0) {
        return (valores[tamanho / 2] + valores[tamanho / 2 - 1]) / 2.0;
    } else {
        return valores [tamanho / 2];
    }
}

double desvioPadrao (int *valores, int tamanho) {
    double m = media (valores, tamanho);
    double soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += pow (valores[i] - m, 2);
    }
    return sqrt (soma / tamanho);
}

int compara (const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main () {
    FILE *arquivo = fopen ("arquivo.txt", "r");
    Estudante estudantes [100];

    for (int i = 0; i < 100 && !feof(arquivo); i++) {
        fscanf(arquivo, "%d; %d; %d; %d; %d; %d; %d;",
        &estudantes[i].id,
        &estudantes[i].notas[0], &estudantes[i].notas[1], 
        &estudantes[i].notas[2], &estudantes[i].notas[3],
        &estudantes[i].notas[4], &estudantes[i].ano);
    }

    fclose (arquivo);

    for (int ano = 2020; ano <= 2023; ano++) {
        printf("Ano: %d\n", ano);
        for (int disciplina = 0; disciplina < 5; disciplina++) {
            int notas [100];
            int n = 0;

            for (int i = 0; i < 100; i++) {
                if (estudantes[i].ano == ano) {
                    notas[n++] = estudantes[i].notas[disciplina];
                n++;
                }
            }

            qsort(notas, n, sizeof(int), compara);

            printf("Disciplina %d - Média: %.2f, Mediana: %.2f, Desvio Padrão: %.2f\n",
                   disciplina+1, media(notas, n), mediana(notas, n), desvioPadrao(notas, n));
        }
        printf("\n");
    }

    return 0;
}