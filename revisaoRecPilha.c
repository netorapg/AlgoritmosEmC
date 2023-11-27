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
    p ->topo = NULL;
}

int verificarPilhaVazia(Pilha *p){
    return (p->topo!=NULL);
}

void push(Pilha *p, int valor){
    No *novo = (No *)malloc(sizeof(No));
    if(novo){
        novo->valor = valor;
        novo ->proximo = p->topo;
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
    }
    return 0;
}

void imprimir(Pilha *p){
    No *aux = p->topo;
    printf("__\n");
    while(aux){
        printf("%d\n", aux->valor);
        printf("--");
        printf("\n");
        aux = aux->proximo;
    }
    printf("\n");
}

int menu(){
    Pilha pilha;
    int op = -1;
    int valor = 0;
    int valorReferencia = 0;
    while(op != 0){
        imprimir(&pilha);
        printf("0 - Sair\n");
        printf("1 - Adicionar elemento\n");
        printf("2 - Remover da pilha \n");
        printf("Digite a opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            push(&pilha, valor);
            break;
        case 2:
            printf("Valor removido do topo\n");
            pop(&pilha);
        default:
            break;
        }

    }
}

int main() {
    menu();
    return 0;
    
}