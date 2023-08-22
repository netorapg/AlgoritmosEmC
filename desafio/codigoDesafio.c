#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Definição do tamanho máximo de estudantes
#define NUM_ESTUDANTES 1000

// Struct para armazenar os dados de um estudante
typedef struct {
    int id;
    int notas[5];
    int ano;
} Estudante;
// Inicio das Funções
// Função para calcular a média
double media (int *valores, int tamanho) {
    double soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += valores[i];
    }
    return soma / tamanho;
}
// Função para calcular a mediana
double mediana (int *valores, int tamanho) {
    if (tamanho % 2 == 0) {
        return (valores[tamanho / 2] + valores[tamanho / 2 - 1]) / 2.0;
    } else {
        return valores [tamanho / 2];
    }
}
// Função para calcular o desvio padrão
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


void ordenarPorAnoInsertion(Estudante *estudantes, int n) {
    for (int i = 1; i < n; i++) {
        Estudante chave = estudantes[i];
        int j = i - 1;

        while (j >= 0 && estudantes[j].ano > chave.ano) {
            estudantes[j + 1] = estudantes[j];
            j = j - 1;
        }
        estudantes[j + 1] = chave;
    }
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

int lerEstudantesDoArquivo(const char *nomeArquivo, Estudante estudantes[NUM_ESTUDANTES]) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo\n");
        return -1;
    }

    int i;
    for (i = 0; i < NUM_ESTUDANTES && !feof(arquivo); i++) {
        fscanf(arquivo, "%d; %d; %d; %d; %d; %d; %d;",
               &estudantes[i].id,
               &estudantes[i].notas[0], &estudantes[i].notas[1], 
               &estudantes[i].notas[2], &estudantes[i].notas[3],
               &estudantes[i].notas[4], &estudantes[i].ano);
    }
    
    fclose(arquivo);
    return i; // Retorna o número de estudantes lidos
}

int escreverEstudantesNoArquivo(const char *nomeArquivo, Estudante estudantes[NUM_ESTUDANTES]) {
    FILE *novoArquivo = fopen(nomeArquivo, "w");
    
    if (!novoArquivo) {
        printf("Erro ao abrir o arquivo\n");
        return 0; // Retornar falso indicando falha
    }

    for (int i = 0; i < NUM_ESTUDANTES; i++) {
        fprintf(novoArquivo, "%d;%d;%d;%d;%d;%d;%d;\n",
               estudantes[i].id,
               estudantes[i].notas[0], estudantes[i].notas[1],
               estudantes[i].notas[2], estudantes[i].notas[3],
               estudantes[i].notas[4], estudantes[i].ano);
    }

    fclose(novoArquivo);
    return 1; // Retornar verdadeiro indicando sucesso
}

void imprimirEstatisticas(Estudante estudantes[NUM_ESTUDANTES]) {
    // Coleta e impressão da media, mediana e desvio padrão das disciplinas por ano
    for (int ano = 2020; ano <= 2023; ano++) {
        printf("Ano: %d\n", ano);
        for (int disciplina = 0; disciplina < 5; disciplina++) {
            int notas[NUM_ESTUDANTES];
            int n = 0;

            for (int i = 0; i < NUM_ESTUDANTES; i++) {
                if (estudantes[i].ano == ano) {
                    notas[n++] = estudantes[i].notas[disciplina];
                }
            }

            insertionSort(notas, n);
            printf("Disciplina %d - Média: %.2f, Mediana: %.2f, Desvio Padrão: %.2f\n",
                   disciplina+1, media(notas, n), mediana(notas, n), desvioPadrao(notas, n));
        }
        printf("\n");
    }

    // Coleta e impressão da media, mediana e desvio padrão das disciplinas
    printf("Estatísticas por Disciplina (todos os anos):\n");
    for (int disciplina = 0; disciplina < 5; disciplina++) {
        int notas[NUM_ESTUDANTES];
        int n = 0;

        for (int i = 0; i < NUM_ESTUDANTES; i++) {
            notas[n++] = estudantes[i].notas[disciplina];
        }

        insertionSort(notas, n);
        printf("Disciplina %d - Média: %.2f, Mediana: %.2f, Desvio Padrão: %.2f\n",
               disciplina+1, media(notas, n), mediana(notas, n), desvioPadrao(notas, n));
    }
    printf("\n");
}

void imprimirResultados(Estudante estudantes[NUM_ESTUDANTES]) {
    // Impressão dos resultados de aprovados e reprovados por disciplina
    int aprovados[5] = {0};
    int reprovados[5] = {0};

    for (int i = 0; i < NUM_ESTUDANTES; i++) {
        for (int j = 0; j < 5; j++) {
            if (estudantes[i].notas[j] >= 70) {
                aprovados[j]++;
            } else {
                reprovados[j]++;
            }
        }
    }

    printf("Resultados:\n");
    printf("Total de alunos: %d\n", NUM_ESTUDANTES);
    for (int j = 0; j < 5; j++) {
        printf("Disciplina %d - Aprovados: %d, Reprovados: %d\n", j+1, aprovados[j], reprovados[j]);
    }
    printf("\n");
}

void imprimirMelhorEPiorAluno(Estudante estudantes[NUM_ESTUDANTES]) {
    // Impressão do melhor e pior aluno
    Estudante *melhorAluno = NULL;
    Estudante *piorAluno = NULL;
    double melhorMedia = -1.0;
    double piorMedia = NUM_ESTUDANTES;

    for (int i = 0; i < NUM_ESTUDANTES; i++) {
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

    // Declaração da variavel estudantes do tipo Estudante com NUM_ESTUDANTES posições
    Estudante estudantes[NUM_ESTUDANTES];

    // Ler os estudantes do arquivo
    int numEstudantesLidos = lerEstudantesDoArquivo("arquivo.txt", estudantes);
    
    if (numEstudantesLidos == -1) {
        return 1; // Houve erro ao ler o arquivo
    }
    // Fim do cronometro de leitura
    fimLeitura = clock();
    tempoGastoTotal = (double)(fimLeitura - inicioLeitura) / CLOCKS_PER_SEC;
    printf ("Tempo gasto na leitura: %5f segundos\n", tempoGastoTotal);
    // Inicio do cronometro de ordenação

    clock_t inicioOrdenacao, fimOrdenacao;
    inicioOrdenacao = clock();
    // Ordena os estudantes
    ordenarPorAnoInsertion(estudantes, NUM_ESTUDANTES);
    // Fim do cronometro de ordenação
    fimOrdenacao = clock();
    tempoGastoTotal = (double)(fimOrdenacao - inicioOrdenacao) / CLOCKS_PER_SEC;
    printf ("Tempo gasto na ordenação: %5f segundos\n", tempoGastoTotal);

    // Inicio do cronometro de escrita
    clock_t inicioEscrita, fimEscrita;
    double tempoGastoEscrita;
    inicioEscrita = clock();

    if (!escreverEstudantesNoArquivo("notas.txt", estudantes)) {
        return 1; // Houve erro ao escrever no arquivo
    }
    // Fim do cronometro de escrita
    fimEscrita = clock();
    tempoGastoEscrita = (double)(fimEscrita - inicioEscrita) / CLOCKS_PER_SEC;
    printf ("Tempo gasto na escrita: %5f segundos\n", tempoGastoEscrita);
    printf("\n");

    // Coleta e impressão da media, mediana e desvio padrão
    //das disciplinas por ano
    clock_t inicioEstatisticas, fimEstatisticas;
    inicioEstatisticas = clock();
    imprimirEstatisticas(estudantes);
    fimEstatisticas = clock();
    tempoGastoTotal = (double)(fimEstatisticas - inicioEstatisticas) / CLOCKS_PER_SEC;
    printf ("Tempo gasto na coleta e impressão das estatísticas: %5f segundos\n", tempoGastoTotal);
    printf("\n");
    
    clock_t inicioResultado, fimResultado;
    inicioResultado = clock();
    imprimirResultados(estudantes);
    fimResultado = clock();
    tempoGastoTotal = (double)(fimResultado - inicioResultado) / CLOCKS_PER_SEC;
    printf ("Tempo gasto na coleta e impressão dos resultados: %5f segundos\n", tempoGastoTotal);

    printf("\n");

    clock_t inicioMelhorPior, fimMelhorPior;
    inicioMelhorPior = clock();
    imprimirMelhorEPiorAluno(estudantes);
    fimMelhorPior = clock();
    tempoGastoTotal = (double)(fimMelhorPior - inicioMelhorPior) / CLOCKS_PER_SEC;
    printf ("Tempo gasto na coleta e impressão do melhor e pior aluno: %5f segundos\n", tempoGastoTotal);
    printf("\n");
   
    fimTotal = clock();
    tempoGastoTotal = ((double)(fimTotal - inicioTotal)) / CLOCKS_PER_SEC;
    printf("Tempo gasto: %.5f segundos\n", tempoGastoTotal);
    
    return 0;
}