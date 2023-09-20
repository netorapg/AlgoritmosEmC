/*Implemente um menu para cada operação a ser realizada na lista (inserir no início, inserir no meio, inserir no fim e remover).
Escreva uma função para contar quantos elementos existem na lista.
Crie uma função que remova todos os elementos da lista.
Crie uma função que encontre o maior elemento da lista.
Escreva uma função que encontre a média dos elementos na lista.
Crie uma função que verifique se a lista contém um número específico.
Implemente uma função que ordene os elementos na lista em ordem crescente ou decrescente.
Crie uma função que remova todos os elementos repetidos da lista.
Crie uma função que faça a concatenação de duas listas e retorne a lista resultante.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;


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
        novo->proximo = *lista;
        *lista = novo;
    }
}

void adicionarMeio(No **lista, int valoreReferencia, int valor){
    No *novo = criarNo(valor);
    if(novo){
        if(*lista==NULL){
            novo->proximo = NULL;
            *lista = novo;
        }else{
            No *aux = *lista;
            while(aux->proximo && aux->valor!=valoreReferencia){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
}

void adicionarFim(No **lista, int valor) {
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

            novo->valor = valor;
            novo->proximo = NULL;
            aux->proximo = novo;
        }
    }
}

void remover(No **lista, int valor) {
    if(*lista){
        No *aux = *lista;
        No *anterior = NULL;
        while(aux->proximo && aux->valor!=valor){
            anterior = aux;
            aux = aux->proximo;
        }
        if(anterior){
            anterior->proximo = aux->proximo;
        } else {
            *lista = aux->proximo;
        }
        free(aux);
    }
}

void imprimirLista(No *aux){
    printf("Lista: ");
    while(aux){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}


int main(){

    int op = 5;
    int valor = 0;
    No *lista = NULL;

    switch(op){
        case 1:
            adicionarInicio(&lista, valor);
            break;
        case 2:
            adicionarMeio(&lista, valor, valor);
            break;
        case 3:
            adicionarFim(&lista, valor);
            break;
        case 4:
            remover(&lista, valor);
            break;
        case 5:
            imprimirLista(lista);
            break;

    }    
}