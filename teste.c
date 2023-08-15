#include <stdio.h>

int main() {
    int *ponta, *pontb;
    int x, y, z;

    x = 5;
    y = 10;

    ponta = &x;
    pontb = &y;

    z = y;
    *pontb = x;
    *ponta = z;

    printf("%d %d", x, y);
}