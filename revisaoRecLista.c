#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int valor; 
    struct no * proximo; 
} No;

No* criarNo(int valor){
    No *novo = (No *) malloc(sizeof(No));
    if(novo){
        novo->valor = valor;
        return novo;
    } else {
        printf("Erro ao alocar memoria!\n");
    }
    return NULL;
}

void adicionarInicio(No **lista, int valor){
    No *novo = criarNo(valor);
    if(novo){
        novo->proximo = *lista;
        *lista = novo;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

void adicionarFim(No **lista, int valor){
    No *novo = criarNo(valor);
    if(novo){
        if(*lista==NULL){
            novo->proximo = NULL;
            *lista = novo;
            return;
        }else{
            No *aux = *lista;
            while(aux->proximo!=NULL){
                aux = aux->proximo;
            }
            novo->proximo = NULL;
            aux->proximo = novo;
        }
    }
}

void adicionarMeio(No **lista, int valorReferencia, int valor) {
    No *novo = criarNo(valor);
    if(novo){
        if(*lista==NULL){
            novo->proximo = NULL;
            *lista = novo;
        }else{
            No *aux = *lista;
            while(aux->proximo && aux->valor!=valorReferencia){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
}

void removerInicio(No **lista){
    if(*lista){
        No *aux = *lista;
        *lista = aux->proximo;
        free(aux);
    }
}

void removerFim(No **lista){
    if (*lista){
        No *aux = *lista;
        No *anterior = NULL;
        while(aux->proximo){
            anterior = aux;
            aux = aux->proximo;
        }
        if(anterior){
            anterior->proximo = NULL;
        }else{
            *lista = NULL;
        }
        free(aux);
    }
}

void removerMeio (No **lista, int valor){
    if(*lista){
        No *aux = *lista;
        No *anterior = NULL;
        while(aux->proximo && aux->valor!=valor){
            anterior = aux;
            aux = aux->proximo;
        }
        if(anterior){
            anterior->proximo = aux->proximo;
        }else{
            *lista = aux->proximo;
        }
        free(aux);
    }
}


void imprimirLista(No *aux){
    printf("\n Imprimindo: [ ");
    while(aux){
        printf( " %d ", aux->valor);
        aux=aux->proximo;
    }

    printf(" ]\n");
}

void preencherListaComNumerosAleatorios(No **lista, int tamanho, int valorMinimo, int valorMaximo) {
    srand(time(NULL));
    
    for (int i = 0; i < tamanho; i++) {
        int valorAleatorio = rand() % (valorMaximo - valorMinimo + 1) + valorMinimo;
        adicionarFim(lista, valorAleatorio);
    }
}

int menu(){
No *lista = NULL;
    int op = -1;
    int valor = 0;
    int valorReferencia = 0;
    preencherListaComNumerosAleatorios(&lista, 10, 1, 100);
    
    while(op != 0){
        imprimirLista(lista);
        printf ("0 - Sair\n");
        printf ("1 - Adicionar no inicio\n");
        printf ("2 - Adicionar no meio\n");
        printf ("3 - Adicionar no fim\n");
        printf ("4 - Remover do inicio\n");
        printf ("5 - Remover do meio\n");
        printf ("6- Remover do fim\n");
        printf("Digite a opcao: ");
        scanf("%d", &op);
        printf("\n");
        switch(op){
            case 0:
                printf("Saindo...\n");
                break;
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("\n");
                adicionarInicio(&lista, valor);
                break;
            case 2:
                printf("Digite o valor de referencia: ");
                scanf("%d", &valorReferencia); 
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("\n"); 
                adicionarMeio(&lista, valorReferencia, valor);
                printf("\n"); 
                break;
            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor); 
                adicionarFim(&lista, valor);
                printf("\n"); 
                break;
            case 4:
                printf("Valor do inicio removido!\n");
                removerInicio(&lista);
                break;
            case 5:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                removerMeio(&lista, valor);
                printf("Valor removido com sucesso!\n");
                break;
            case 6:
                printf("Valor do fim removido!\n");
                removerFim(&lista);
                break;
            default:
                printf("Opcao invalida!\n");
                break;

        }
    }
}

int main(){
    menu();
    return 0;
}