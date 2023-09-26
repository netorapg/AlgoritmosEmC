/*
Escreva uma função para contar quantos elementos existem na lista.
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
    }   int contador = 0;
    No *aux = *lista;
    while(aux){
        contador++;
        aux = aux->proximo;
    }
    return contador;
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

void removerTodos(No **lista){
    if(*lista){
        No *aux = *lista;
        No *anterior = NULL;
        while(aux->proximo){
            anterior = aux;
            aux = aux->proximo;
            free(anterior);
        }
        *lista = NULL;
}
}

int contarElementosNaLista(No *lista){
    int cont = 0;
    while(lista){
        cont++;
        lista = lista->proximo;
    }
    return cont;
}

void imprimirLista(No *aux){
    printf("Lista: ");
    while(aux){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

int menu(){
    int op = 0;
    int valor = 0;
    int valorReferencia = 0;
    No *lista = NULL;
    while(op != 8){
          printf("1 - Adicionar no inicio\n");
        printf("2 - Adicionar no meio\n");
        printf("3 - Adicionar no fim\n");
        printf("4 - Remover\n");
        printf("5 - Imprimir\n");
        printf("6 - Remover todos\n");
        printf("7 - Contar elementos na lista\n");
        printf("8 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &op);
            
        switch(op){
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);    
                adicionarInicio(&lista, valor);
                break;
            case 2:
                printf("Digite o valor de referencia: ");
                scanf("%d", &valorReferencia); 
                printf("Digite o valor: ");
                scanf("%d", &valor);
                adicionarMeio(&lista, valorReferencia, valor);
                break;
            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor); 
                adicionarFim(&lista, valor);
                break;
            case 4:
                printf("Digite o valor: ");
                scanf("%d", &valor); 
                remover(&lista, valor);
                break;
            case 5:
                imprimirLista(lista);
                break;
            case 6:
                removerTodos(&lista);
                break;
            case 7:
                printf("A lista possui %d elementos\n", contarElementosNaLista(lista));
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}

int main(){
// No *lista = NULL;
    menu();
    return 0;
}