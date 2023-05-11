int contarCaractere(char cadeia[], char caractere) {
    int contador = 0;

    for (int i = 0; i < 20; i++) {
        if (cadeia[i] == caractere) {
            contador++;
        }
    }

    return contador;
}

int main() {
    char cadeia[21];
    char caractere;

    printf ("Digite uma cadeia de caracteres: ");
    scanf ("%s", cadeia);

    printf ("Digite um caractere: ");
    scanf (" %c", &caractere);

    int quantidade = contarCaractere(cadeia, caractere);

    printf("O caractere '%c' aparece %d vezes na cadeia.\n", caractere, quantidade);
    return 0;
    }