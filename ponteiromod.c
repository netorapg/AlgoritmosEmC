#include <stdio.h>

void modifyValue(int *x) {
    *x = 10;
}

int main() {
    int num = 5;
    printf("Valor antes da modificação: %d\n", num);

    modifyValue(&num);

    printf("Valor depois da modificação: %d\n", num);

    return 0;
}