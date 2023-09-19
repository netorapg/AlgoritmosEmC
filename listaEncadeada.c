#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;


//Criar um novo nó para reaproveita esta funcionalidade
//nas demais funções
criarNo(int valor){
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
       // novo->valor = valor;
        novo->proximo = *lista;
        *lista = novo;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

void adicionarMeio(No **lista, int valorReferencia, int valor) {
    No *novo = criarNo(valor);
    if(novo){
       // novo->valor = valor;
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

void adicionarFim(No **lista, int valor){
    No *novo = criarNo(valor);
    if(novo){
        if(*lista==NULL){
          //  novo->valor = valor;
            novo->proximo = NULL;
            *lista = novo;
            return;
        }else{
            No *aux = *lista;
            while(aux->proximo!=NULL){
                aux = aux->proximo;
            }

            novo->valor = valor;
            novo->proximo = NULL;
            aux->proximo = novo;
        }
    }
}


void imprimirLista(No *aux){
    //No *aux = lista;
    printf("\nImprimindo: [ ");
    while(aux){
        printf(" %d ", aux->valor);
        aux=aux->proximo;
    }

    printf(" ]\n");
}

int main(){
    No *lista = NULL;
     imprimirLista(lista);
    adicionarInicio(&lista, 10);
     imprimirLista(lista);
    adicionarInicio(&lista, 20);
     imprimirLista(lista);
    adicionarInicio(&lista, 50);
     imprimirLista(lista);
    adicionarFim(&lista, 5);
     imprimirLista(lista);
    adicionarFim(&lista, 1);
     imprimirLista(lista);
    adicionarInicio(&lista, 100);
    imprimirLista(lista);
    adicionarMeio(&lista, 20, 21);
    imprimirLista(lista);

    return 0;
}