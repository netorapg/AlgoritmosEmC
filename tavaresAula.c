#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct list
{
    Node *top;
} List;

void init(List *list)
{
    list->top = NULL;
}

int is_empty(List *list)
{
    return (!list->top);
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Nó não criado");
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void print_list(List *list)
{
    Node *temp = list->top;
    printf("[ ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void insert_head(List *list, int data)
{
    Node *newNode = createNode(data);
    newNode->next = list->top;
    list->top = newNode;
}

void insert_mid(List *list, int data, int value)
{
    if (list->top == NULL)
    {
        printf("Lista Vazia, Valor inserido no começo!\n");
        insert_head(list, data);
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = list->top;
    while (temp->next && (temp->data != value))
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void insert_tail(List *list, int data)
{
    if (list->top == NULL)
    {
        printf("Lista Vazia, Valor inserido no começo!\n");
        insert_head(list, data);
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = list->top;
    while (temp->next)
        temp = temp->next;

    newNode->next = NULL;
    temp->next = newNode;
}

void remove_head(List *list)
{
    if (is_empty(list))
        return;
    Node *temp = list->top;
    list->top = temp->next;
    free(temp);
}

void remove_mid(List *list, int data)
{
    if (is_empty(list))
        return;
    Node *temp = list->top;
    while (temp->next && ((temp->next)->data != data))
        temp = temp->next;
    temp->next = (temp->next)->next;
    temp = temp->next;
    free(temp);
}

void remove_tail(List *list)
{
    if (is_empty(list))
        return;
    if (!list->top->next)
    {
        remove_head(list);
        return;
    }
    Node *temp = list->top;
    while ((temp->next)->next)
        temp = temp->next;
    free((temp->next)->next);
    temp->next = NULL;
}

int count_itens(List *list)
{
    if (is_empty(list))
        return 0;
    Node *temp = list->top;
    int count = 0;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void clear_list(List *list)
{
    if (is_empty(list))
        return;
    Node *temp = list->top;
    while (temp->next)
    {
        Node *remove = temp;
        free(remove);
        temp = temp->next;
    }
    list->top = NULL;
}

int max_number(List *list)
{
    if (is_empty(list))
    {
        printf("Lista Vazia!");
    }
    else
    {
        Node *temp = list->top;

        int max = temp->data;
        while (temp)
        {
            if (max < temp->data)
                max = temp->data;
            temp = temp->next;
        }
        return max;
    }
}

float average(List *list, int size)
{
    if (is_empty(list))
        return 0;
    Node *temp = list->top;
    int sum = 0;
    while (temp)
    {
        sum = sum + temp->data;
        temp = temp->next;
    }
    return ((float)sum / (float)size);
}

void ordenate_list(List *list, int count, int order)
{
    if (is_empty(list))
        return;

    Node *temp = list->top;
    int aux;
    switch (order)
    {
    case 1:
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (temp->data > (temp->next)->data)
                {
                    aux = temp->data;
                    temp->data = ((temp->next)->data);
                    ((temp->next)->data) = aux;
                }
                temp = temp->next;
            }
            temp = list->top;
        }
        break;

    case 2:
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (temp->data < (temp->next)->data)
                {
                    aux = temp->data;
                    temp->data = ((temp->next)->data);
                    ((temp->next)->data) = aux;
                }
                temp = temp->next;
            }
            temp = list->top;
        }
        break;
    }
}

void random_list(List *list)
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        insert_head(list, rand() % 50);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    List list;
    init(&list);
    int alive = 1;
    while (alive)
    {
        print_list(&list);
        printf("--------------------------\n");
        printf("0 - Random List\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no meio por valor\n");
        printf("3 - Inserir no fim\n");
        printf("4 - Remover do início\n");
        printf("5 - Remover do meio por valor\n");
        printf("6 - Remover do fim\n");
        printf("7 - Quantidade de Itens\n");
        printf("8 - Limpar Lista\n");
        printf("9 - Maior Elemento\n");
        printf("10 - Média dos Elementos\n");
        printf("11 - Ordenar Lista\n");
        int op;
        int data;
        int value;
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            random_list(&list);
            break;
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &data);
            insert_head(&list, data);
            break;
        case 2:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &data);
            printf("Digite o valor de referencia: ");
            scanf("%d", &value);
            insert_mid(&list, data, value);
            break;
        case 3:
            printf("Digite o valor: ");
            scanf("%d", &data);
            insert_tail(&list, data);
            break;
        case 4:
            remove_head(&list);
            break;
        case 5:
            printf("Digite o valor: ");
            scanf("%d", &data);
            remove_mid(&list, data);
            break;
        case 6:
            remove_tail(&list);
            break;
        case 7:
            printf("A lista tem %d elementos\n", count_itens(&list));
            break;
        case 8:
            clear_list(&list);
            break;
        case 9:
            printf("Maior elemento é %d\n", max_number(&list));
            break;
        case 10:
            printf("A média é %2.f\n", average(&list, count_itens(&list)));
            break;
        case 11:
            int order;
            printf("1 - Crescente\n");
            printf("2 - Decrescente\n");
            scanf("%d", &order);
            ordenate_list(&list, count_itens(&list), order);
            break;
        }
    }
}