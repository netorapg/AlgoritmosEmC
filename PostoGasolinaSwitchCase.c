#include <stdio.h>

int main()
{
    int op;
    float litros, valorTotal, g, a, d;
    g = 7.10;
    a = 6.05;
    d = 6.10;

    printf ("Escolha uma opcao: \n\n");
    printf ("   1 - Gasolina - R$ 7.10\n\n");
    printf ("   2 - Alcool - R$ 6.05\n\n");
    printf ("   3 - Diesel - R$ 6.10\n\n");

    scanf("%d", &op);
    switch (op)
    {
        case 1: 
            printf ("Gasolina selecionada\n\n");
            printf ("Quantidade de litros:\n\n");
            scanf("%f", &litros);
            valorTotal = litros * g;
            printf ("Valor a pagar: R$ %.2f\n\n", valorTotal);
            break;
        case 2: 
            printf ("Alcool selecionado\n\n");
            printf ("Quantidade de litros:\n\n");
            scanf("%f", &litros);
            valorTotal = litros * g;
            printf ("Valor a pagar: R$ %.2f\n\n", valorTotal);
            break;
        case 3: 
            printf ("Diesel selecionado\n\n");
            printf ("Quantidade de litros:\n\n");
            scanf("%f", &litros);
            valorTotal = litros * g;
            printf ("Valor a pagar: R$ %.2f\n\n", valorTotal);
            break;
        default:
            printf ("Nenhuma opcao selecionada!\n\n");

    }


}
