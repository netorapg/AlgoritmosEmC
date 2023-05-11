int soma (int num1, int num2);

int main (){
    int n1, n2, resultado;
    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("Digite o segundo numero: ");
    scanf("%d", &n2);
    resultado = soma(n1, n2);
    printf("\n\nResultado da soma: %d\n\n", resultado);
    return 0;
}

int soma (int num1, int num2)
{
    int soma;
    soma = num1 + num2;
    return (soma);
}