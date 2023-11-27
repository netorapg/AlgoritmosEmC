#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct no {
    int dado;
    struct no *proximo;
} No;

typedef struct lista {
    No *topo;
} Lista;


void inicio(Lista *lista){
    lista->topo = NULL;
}

int esta_vazio(Lista *lista){
    return (!lista->topo);
}

No *criarNo(int dado){
    No *novoNo = (No *)malloc(sizeof(No));
    if (!novoNo)
    {
        printf("Nó não criado");
    }
    novoNo->dado = dado;
    novoNo->proximo = NULL;
    return novoNo;
}

void printar_lista(Lista *lista){
    No *temporaria = lista->topo;
    printf("[ ");
    while( temporaria){
        printf("%d ", temporaria->dado);
        temporaria = temporaria->proximo;
    }
    printf("]\n");
}

void inserir_no_topo(Lista *lista, int dado){
    No *novoNo = criarNo(dado);
    novoNo->proximo = lista->topo;
}
void inserir_no_meio(Lista *lista, int dado, int valor_de_ref){
    if(lista->topo == NULL){
        printf("Lista vazia, valor inserido no inicio"\n);
        inserir_no_topo(lista, dado);
        return;
    }
    No *novoNo = criarNo(dado);
    No *temporaria = lista->topo;
    while (temporaria->proximo && (temporaria->))
}