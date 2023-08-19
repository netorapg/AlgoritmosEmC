#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Estruct para armazenar os dados de um estudante
typedef struct {
    int id;
    int notas[5];
    int ano;
} Estudante;
// Inicio das Funções
// Função para calcular a média de um vetor de inteiros
double media (int *valores, int tamanho) {
    double soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += valores[i];
    }
    return soma / tamanho;
}
// Função para calcular a mediana de um vetor de inteiros
double mediana (int *valores, int tamanho) {
    if (tamanho % 2 == 0) {
        return (valores[tamanho / 2] + valores[tamanho / 2 - 1]) / 2.0;
    } else {
        return valores [tamanho / 2];
    }
}
// Função para calcular o desvio padrão de um vetor de inteiros
double desvioPadrao (int *valores, int tamanho) {
    double m = media (valores, tamanho);
    double soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += pow (valores[i] - m, 2);
    }
    return sqrt (soma / tamanho);
}
// Função para comparar dois inteiros
int compara (const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
// Função para calcular a média de um estudante
double alunoMedia (const Estudante* aluno) {
    double soma = 0;
    for (int i = 0; i < 5; i++) {
        soma += aluno->notas[i];
    }
    return soma / 5;
}
// Função para comparar os estudantes
int comparaEstudante (const void *a, const void *b) {
    Estudante *estudanteA = (Estudante *)a;
    Estudante *estudanteB = (Estudante *)b;
    return estudanteA->ano - estudanteB->ano;
}
// Fim das Funções
int main () {
    // Inicio do cronometro principal
    clock_t inicioTotal, fimTotal;
    double tempoGastoTotal;
    inicioTotal = clock();

    // Inicio do cronometro de leitura
    clock_t inicioLeitura, fimLeitura;
    inicioLeitura = clock();

    // Abre o arquivo para leitura
    FILE *arquivo = fopen ("arquivo.txt", "r");
    Estudante estudantes [100];
    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo) {
        printf ("Erro ao abrir o arquivo\n");
        return 1;
    }
    // Lê os dados do arquivo
    for (int i = 0; i < 100 && !feof(arquivo); i++) {
        fscanf(arquivo, "%d; %d; %d; %d; %d; %d; %d;",
        &estudantes[i].id,
        &estudantes[i].notas[0], &estudantes[i].notas[1], 
        &estudantes[i].notas[2], &estudantes[i].notas[3],
        &estudantes[i].notas[4], &estudantes[i].ano);
    }
    // Fecha o arquivo
    fclose (arquivo);
    // Fim do cronometro de leitura
    fimLeitura = clock();
    tempoGastoTotal = (double)(fimLeitura - inicioLeitura) / CLOCKS_PER_SEC;
    printf ("Tempo gasto na leitura: %5f segundos\n", tempoGastoTotal);
    // Inicio do cronometro de ordenação
    clock_t inicioOrdenacao, fimOrdenacao;
    inicioOrdenacao = clock();
    // Ordena os estudantes
    qsort(estudantes, 100, sizeof(Estudante), comparaEstudante);
    // Fim do cronometro de ordenação
    fimOrdenacao = clock();
    tempoGastoTotal = (double)(fimOrdenacao - inicioOrdenacao) / CLOCKS_PER_SEC;
    printf ("Tempo gasto na ordenação: %5f segundos\n", tempoGastoTotal);
    // Inicio do cronometro de escrita
    clock_t inicioEscrita, fimEscrita;
    double tempoGastoEscrita;
    inicioEscrita = clock();
    // Abre o arquivo para escrita
    FILE *novoArquivo = fopen ("notas.txt", "w");
    // Verifica se o arquivo foi aberto corretamente
    if (!novoArquivo) {
        printf ("Erro ao abrir o arquivo\n");
        return 1;
    }
    // Escreve os dados no arquivo
    for (int i = 0; i < 100; i++) {
        fprintf (novoArquivo, "%d;%d;%d;%d;%d;%d;%d;\n",
        estudantes[i].id,
        estudantes[i].notas[0], estudantes[i].notas[1],
        estudantes[i].notas[2], estudantes[i].notas[3],
        estudantes[i].notas[4], estudantes[i].ano);
    }
    // Fecha o arquivo
    fclose (novoArquivo);
    // Fim do cronometro de escrita
    fimEscrita = clock();
    tempoGastoEscrita = (double)(fimEscrita - inicioEscrita) / CLOCKS_PER_SEC;
    printf ("Tempo gasto na escrita: %5f segundos\n", tempoGastoEscrita);
    printf("\n");

    // Coleta e impressão da media, mediana e desvio padrão
    //das disciplinas por ano
    for (int ano = 2020; ano <= 2023; ano++) {
        printf("Ano: %d\n", ano);
        for (int disciplina = 0; disciplina < 5; disciplina++) {
            int notas [100];
            int n = 0;

            for (int i = 0; i < 100; i++) {
                if (estudantes[i].ano == ano) {
                    notas[n++] = estudantes[i].notas[disciplina];
               
                }
            }

            qsort(notas, n, sizeof(int), compara);

            printf("Disciplina %d - Média: %.2f, Mediana: %.2f, Desvio Padrão: %.2f\n",
                   disciplina+1, media(notas, n), mediana(notas, n), desvioPadrao(notas, n));
        }
        printf("\n");
    }
    // Coleta e impressão da media, mediana e desvio padrão das disciplinas
    printf ("Estatísticas por Disciplina (todos os anos): \n");
    for (int disciplina = 0; disciplina < 5; disciplina++) {
        int notas [100];
        int n = 0;

        for (int i = 0; i < 100; i++) {
            notas[n++] = estudantes[i].notas[disciplina];
        }

        qsort(notas, n, sizeof(int), compara);
        printf("Disciplina %d - Média: %.2f, Mediana: %.2f, Desvio Padrão: %.2f\n",
               disciplina+1, media(notas, n), mediana(notas, n), desvioPadrao(notas, n));
    }
    printf ("\n");
   // Impressão dos resultados de aprovados e reprovados por disciplina
    int aprovados [5] = {0};
    int reprovados [5] = {0};

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 5; j++) {
            if (estudantes[i].notas[j] >= 70) {
                aprovados[j]++;
            } else {
                reprovados[j]++;
            }
        }
    }
    printf ("Resultados:\n");
    printf("Total de alunos: 100\n");
    for (int j = 0; j < 5; j++) {
        printf("Disciplina %d - Aprovados: %d, Reprovados: %d\n", j+1, aprovados[j], reprovados[j]);
    }
    printf("\n");

    // Impressão do melhor e pior aluno
    Estudante *melhorAluno = NULL;
    Estudante *piorAluno = NULL;
    double melhorMedia = -1.0;
    double piorMedia = 100.0;

    for (int i = 0; i < 100; i++) {
        double mediaAtual = alunoMedia(&estudantes[i]);
        if (mediaAtual > melhorMedia) {
            melhorMedia = mediaAtual;
            melhorAluno = &estudantes[i];
        }
        if (mediaAtual < piorMedia) {
            piorMedia = mediaAtual;
            piorAluno = &estudantes[i];
        }
    }

    if (melhorAluno) {
        printf("Melhor aluno: %d - Média: %.2f\n", melhorAluno->id, melhorMedia);
    }
    if (piorAluno) {
        printf("Pior aluno: %d - Média: %.2f\n", piorAluno->id, piorMedia);
    }

    // Fim do cronometro total
    fimTotal = clock();
    tempoGastoTotal = ((double)(fimTotal - inicioTotal)) / CLOCKS_PER_SEC;
    printf("Tempo gasto: %.5f segundos\n", tempoGastoTotal);



    return 0;
}