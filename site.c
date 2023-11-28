#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct Site {
    char url[100];
    struct Site* anterior;
} Site;

typedef struct Historico {
    Site *topo;
    int tamanho;
} Historico;

void inicializarHistorico(Historico* historico){
    historico->topo = NULL;
    historico->tamanho = 0;
}

void visitarSite(Historico* historico, const char* url){
    Site* novoSite = (Site*)malloc(sizeof(Site));
    if (novoSite == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    strncpy(novoSite->url, url, sizeof(novoSite->url));
    novoSite->anterior = historico->topo;
    historico->topo = novoSite;
    historico->tamanho++;
}

void voltar(Historico* historico){
    if(historico->tamanho == 0){
        printf("Historico vazio. Nada para voltar.\n");
        return;
    }

    Site* siteAtual = historico->topo;
    if(siteAtual->anterior != NULL){
        printf("Voltando para o site anterior: %s\n", siteAtual->anterior->url);
        historico->topo = siteAtual->anterior;
        free(siteAtual);
        historico->tamanho--;
    }else {
        printf("Não há site anterior para voltar. Site atual %s\n", siteAtual->url);
    }
}

void exibirHistorico(Historico* historico) {
    printf("Histórico de Navegação:\n");
    Site* siteAtual = historico->topo;
    while (siteAtual != NULL){
        printf("%s\n", siteAtual->url);
        siteAtual = siteAtual->anterior;
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
Historico historico;
inicializarHistorico(&historico);

char url[100];
int escolha;

while(1){
    printf("\nEscolha uma opção:\n");
    printf("1. Visitar um site\n");
    printf("2. Voltar\n");
    printf("3. Exibir todo o histórico\n");
    printf("4. Saior\n");
    scanf("%d", &escolha);

    switch (escolha){
        case 1:
            printf("Digite o site a ser visitado: ");
            scanf("%s", url);
            visitarSite(&historico, url);
            break;
        case 2:
            voltar(&historico);
            break;
        case 3:
            exibirHistorico(&historico);
            break;
        case 4:
            exit(0);
        default:
            printf("Escolha inválida. Tente novamente.\n");    
    }
}
return 0;
}