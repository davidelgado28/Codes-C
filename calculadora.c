#include <stdio.h>

float soma(float num1, float num2, int operacao){
    return num1+num2; 
}

float sub(float num1, float num2, int operacao){
    return num1-num2;
}

float mult(float num1, float num2, int operacao){
    return num1*num2;
}

float div(float num1, float num2, int operacao){
    if(num2!=0){
        return num1/num2;
    }
    return 0;
}

void imprimir(float num1, float num2, int operacao){
    switch(operacao){
        case 1:
            printf("O resultado é: %.2f\n", soma(num1, num2, operacao));
            break;
        case 2:
            printf("O resultado é: %.2f\n", sub(num1, num2, operacao));
            break;
        case 3:
            printf("O resultado é: %.2f\n", mult(num1, num2, operacao));
            break;
        case 4:
            printf("O resultado é: %.2f\n", div(num1, num2, operacao));  
    }
}

int main(){

    float num1, num2, result; 
    int operacao;   

    printf("Insira o primeiro numero: "); 
    scanf("%f", &num1);
    printf("Insira o segundo numero: ");
    scanf("%f", &num2); 

    printf("1) +\n");
    printf("2) -\n");
    printf("3) *\n");
    printf("4) /\n");
    printf("Escolha o sinal: "); 
    scanf("%d", &operacao); 

    imprimir(num1, num2, operacao); 
    return 0; 

}