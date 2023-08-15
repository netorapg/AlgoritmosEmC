#include <stdio.h>

void trocarValores(int *a, int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
}

void bubbleSort(int *arr, int tamanho) {
    for (int i = 0; i < tamanho - i - 1; i++) {
        printf("%d: ", i);
          for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocarValores(&arr[j], &arr[j + 1]);
            }
        }
    }
}