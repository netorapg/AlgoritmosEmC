#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[] = "100.50; 50.00;100.0;2.42";
    char *token;

    token = strtok(input, ";");
    while (token != NULL) {
        double valor = atof(token);
        printf("Valor: %.2f\n", valor);
        token = strtok(NULL, ";");
    }

    return 0;
}