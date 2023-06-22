#include <stdio.h>
#include <stdlib.h>

typedef struct {
char nome[50];
int matricula;
float notas[3];
float media;
} Aluno;

int main() {
Aluno aluno;

printf("Digite o nome do aluno: ");
scanf("%s", aluno.nome);

printf("Digite a matricula do aluno: ");
scanf("%d", &aluno.matricula);

printf("Digite as notas do aluno: ");
scanf("%f %f %f", &aluno.notas[0], &aluno.notas[1], &aluno.notas[2]);

aluno.media = (aluno.notas[0] + aluno.notas[1] + aluno.notas[2]) / 3;

printf("Notas do aluno %s\n", aluno.nome);
printf("Prova 1: %.2f\n", aluno.notas[0]);
printf("Prova 2: %.2f\n", aluno.notas[1]);
printf("Prova 3: %.2f\n", aluno.notas[2]);
printf("Media: %.2f\n", aluno.media);

return 0;
}