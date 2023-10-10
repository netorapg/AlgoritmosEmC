#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct pilha{
    struct no *topo;
}Pilha;

void inicializarPilha(Pilha *p){
    p->topo = NULL;
}

int verificarPilhaVazia(Pilha *p){
    return (p->topo!=NULL);
}

void push(Pilha *p, int valor){
    No *novo = (No *)malloc(sizeof(No));
    if(novo){
        novo->valor = valor;
        novo->proximo = p->topo;
        p->topo = novo;
    }
}

int pop(Pilha *p){
    if(verificarPilhaVazia(p)){
        int retorno = 0;
        No *remover = p->topo;
        retorno = remover->valor;
        p->topo = remover->proximo;
        free(remover);
        return retorno;
    }else{
        printf("lista vazia");
        //exit(1);
    }
    return 0;
}

void imprimir(Pilha *p){
    No *aux = p->topo;
    printf("__\n");
    printf("\n");
    while(aux){
        printf("%d\n", aux->valor);
        printf("\n");
        aux = aux->proximo;
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);
    push(&pilha, 10);
    imprimir(&pilha);
    push(&pilha, 5);
    imprimir(&pilha);
    push(&pilha, 2);
    imprimir(&pilha);
    push(&pilha, 7);
    imprimir(&pilha);
    push(&pilha, 3);
    imprimir(&pilha);
    push(&pilha, 1);
    imprimir(&pilha);
    push(&pilha, 9);
    imprimir(&pilha);
    pop(&pilha);
    imprimir(&pilha);
    pop(&pilha);
    imprimir(&pilha);
    pop(&pilha);
    imprimir(&pilha);
    pop(&pilha);
    imprimir(&pilha);
    pop(&pilha);
    imprimir(&pilha);
    pop(&pilha);
    imprimir(&pilha);
    pop(&pilha);
    imprimir(&pilha);
    return 0;
}