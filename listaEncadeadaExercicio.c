/*
Escreva uma função que encontre a média dos elementos na lista. [Work in progress]
Crie uma função que verifique se a lista contém um número específico.
Implemente uma função que ordene os elementos na lista em ordem crescente ou decrescente.
Crie uma função que remova todos os elementos repetidos da lista.
Crie uma função que faça a concatenação de duas listas e retorne a lista resultante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int encontrarMedia(No **lista){
    int media = 0;
    int contador = 0;
    No *aux = *lista;
    while(aux){
        contador++;
        media += aux->valor;
        aux = aux->proximo;
    }
    return media/contador;
}




int adicionarInicio(No **lista, int valor){
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

int adicionarMeio(No **lista, int valoreReferencia, int valor){
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

int maiorelementoNaLista(No *lista){
    int maior = 0;
    while(lista){
        if(lista->valor > maior){
            maior = lista->valor;
        }
        lista = lista->proximo;
    }
    return maior;
}

void imprimirLista(No *aux){
    printf("Lista: ");
    while(aux){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

void preencherListaComNumerosAleatorios(No **lista, int tamanho, int valorMinimo, int valorMaximo) {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios com o tempo atual.
    
    for (int i = 0; i < tamanho; i++) {
        int valorAleatorio = rand() % (valorMaximo - valorMinimo + 1) + valorMinimo;
        adicionarFim(lista, valorAleatorio); // Adiciona o valor aleatório ao final da lista.
    }
}


void identificarNumero(No **lista){
    int numero = 0;
    printf("Digite o numero que deseja verificar: ");
    scanf("%d", &numero);
    printf("\n");
    No *aux = *lista;
    while(aux != NULL){
        if(aux->valor == numero){
            printf("O numero %d esta na lista!\n", numero);
            return;
        }
        aux = aux->proximo;
    }
    printf("O numero %d nao esta na lista!\n", numero);
}


int menu(){
    int op = 0;
    int valor = 0;
    int valorReferencia = 0;
    No *lista = NULL;
    while(op != 10){
        printf("1 - Adicionar no inicio\n");
        printf("2 - Adicionar no meio\n");
        printf("3 - Adicionar no fim\n");
        printf("4 - Remover\n");
        printf("5 - Imprimir\n");
        printf("6 - Remover todos\n");
        printf("7 - Contar elementos na lista\n");
        printf("8 - Maior elemento da lista\n");
        printf("9 - Media dos elementos da lista\n");
        printf("10 - Verificar se um numero esta na lista\n");
        printf("11 - Preencher lista com numeros aleatorios\n");
        printf("12 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &op);
        printf("\n");
            
        switch(op){
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
                printf("Digite o valor: ");
                scanf("%d", &valor); 
                remover(&lista, valor);
                printf("\n"); 
                break;
            case 5:
                imprimirLista(lista);
                printf("\n"); 
                break;
            case 6:
                removerTodos(&lista);
                printf("\n"); 
                break;
            case 7:
                printf("A lista possui %d elementos\n", contarElementosNaLista(lista));
                printf("\n"); 
                break;
            case 8:
                printf("O maior elemento da lista é: %d\n", maiorelementoNaLista(lista));
                printf("\n"); 
                break;
            case 9:
                printf("A media dos elementos da lista é: %d\n", encontrarMedia(&lista));
                printf("\n"); 
                break;
            case 10:
                identificarNumero(&lista);
                break;
            case 11:
                preencherListaComNumerosAleatorios(&lista, 10, 1, 100);
                break;
            case 12:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
    return 0;
}

int main(){
    menu();
    return 0;
}