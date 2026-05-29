#include <stdio.h>

/*Não consegui colocar os devidos acentos nas palavras*/ 

void tipoTriangulo(float lado1, float lado2, float lado3) {
    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        if (lado1 == lado2 && lado2 == lado3) {
            printf("O triângulo é equilátero.\n");
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            printf("O triângulo é isósceles.\n");
        } else {
            printf("O triângulo é escaleno.\n");
        }
    } else {
        printf("Nao forma um triangulo.\n"); 
    }
}

int main() {

    float lado1, lado2, lado3;

    printf("Digite o valor do primeiro lado: ");
    scanf("%f", &lado1);
    printf("Digite o valor do segundo lado: ");
    scanf("%f", &lado2);
    printf("Digite o valor do terceiro lado: ");
    scanf("%f", &lado3);

    tipoTriangulo(lado1, lado2, lado3); 

    return 0;
}
