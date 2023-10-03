#include <stdio.h>

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
    return (p->topo == NULL);
}

void push(Pilha *p, int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo){
        novo->valor = valor;
        
    }
}

int main() {
    printf("Hello World!\n");

    return 0;
}