/*Crie uma pilha que suporta as operações push, pop e imprimir. Inclua um menu para o usuário selecionar a operação desejada.[ok]
Altere o exercício anterior e implemente as funções getMin e getMax (retorna o menor e maior elemento) em tempo constante.[ok]
Escreva um programa que avalie a validade de uma expressão aritmética com operadores +, -, *, /, ( e ) usando uma pilha. []
Você precisa verificar se a sequência dos parênteses estão corretas.[]
Implemente uma pilha para rastrear o histórico de navegação em um navegador da web.[] 
O usuário deve ter as seguintes informações opções: visitar um site, voltar, ou sair.[]
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct pilha{
    struct no *topo;
    int min;
    int max;
}Pilha;

void inicializarPilha(Pilha *p){
    p->topo = NULL;
    p->min = __INT_MAX__;
    p->max = -__INT_MAX__;
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

        if(p->min > valor){
            p->min = valor;
        }
        if(p->max < valor){
            p->max = valor;
        }
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
    while(op != -1){
    printf("MENU\n");
    printf("-1 - Sair\n");
    printf("1 - push\n");
    printf("2 - pop\n");
    printf("3 - imprimir\n");
    printf("4 - Maior valor\n");
    printf("5 - Menor valor\n");
    printf("opcao: ");
    scanf("%d", &op);
    switch(op){
        case -1:
            exit(1);
            break;
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
            printf("Maior valor: %d\n", pilha.max);
            break;
        case 5:
            printf("Menor valor: %d\n", pilha.min);
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