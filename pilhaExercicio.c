/*Crie uma pilha que suporta as operações push, pop e imprimir. Inclua um menu para o usuário selecionar a operação desejada.
Altere o exercício anterior e implemente as funções getMin e getMax (retorna o menor e maior elemento) em tempo constante.
Escreva um programa que avalie a validade de uma expressão aritmética com operadores +, -, *, /, ( e ) usando uma pilha. 
Você precisa verificar se a sequência dos parênteses estão corretas.
Implemente uma pilha para rastrear o histórico de navegação em um navegador da web. 
O usuário deve ter as seguintes informações opções: visitar um site, voltar, ou sair.
*/

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

int menu(){
    int op = 0;
    int valor = 0;
    Pilha pilha;
    inicializarPilha(&pilha);
    while(op != 4){
    printf("1 - push\n");
    printf("2 - pop\n");
    printf("3 - imprimir\n");
    printf("4 - sair\n");
    printf("opcao: ");
    scanf("%d", &op);
    switch(op){
        case 1:
            printf("valor: ");
            scanf("%d", &valor);
            push(&pilha, valor);
            break;
        case 2:
            pop(&pilha);
            break;
        case 3:
            imprimir(&pilha);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("opcao invalida\n");
            break;
    }
    }
}

int main(){
    menu();
    return 0;
}