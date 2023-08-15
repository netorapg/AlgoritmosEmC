#include <stdio.h>

int main() {
    int num = 10;
    int x = 5;
    int *ptr;

    ptr = &num;
    num = x;

    printf ("O valor de num é %d\n", num);
    printf ("O endereço de num é %p\n", &num);
    printf ("O valor apontado por ptr é %d\n", *ptr);
    printf ("O endereço armarenado por ptr é %p\n", ptr);

    return 0;
}