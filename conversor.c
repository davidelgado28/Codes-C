#include <stdio.h>

int cent(float metros){
    return metros * 100;
}

int mili(float metros){
    return metros * 1000;
} 

void imprimir(float metros){
    printf("Valor em centimetros: %d\n", cent(metros));
    printf("Valor em milimetros: %d", mili(metros));  
}

int main(){
    float metros;

    printf("Insira um valor em metros: ");
    scanf("%f", &metros);

    imprimir(metros);

    return 0;
}