float area (float raio);

int main () {
    float r, a;
    printf("Digite o valor do raio: ");
    scanf("%f", &r);
    a = area(r);
    printf("\n\nArea do circulo: %f\n\n", a);
    return 0;
}

float area (float raio)
{
    float area;
    area = 3.14 * raio * raio;
    return (area);
}