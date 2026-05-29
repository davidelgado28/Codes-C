#include <stdio.h>

void imprimir(int num, int i){
    printf("\n-------Tabuada--------\n"); 
    printf("Soma:\n");
    for (i = 0; i <= 10; i++) {
        printf("%d + %d = %d\n", num, i, num + i);
    }
    printf("\nSubtracao:\n");
    for (i = 0; i <= 10; i++) {
        printf("%d - %d = %d\n", num, i, num - i);
    }
    printf("\nMultiplicacao:\n");
    for (i = 0; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
   printf("\nDivisao:\n");
for (i = 0; i <= 10; i++) {
    if (i == 0) {
        printf("%d / %d = Nulo\n", num, i); 
    } else {
        printf("%d / %d = %.2f\n", num, i, (float)num / i);
    }
}
    printf("----------------------\n"); 
} 

    int main() {

    int num, i;

    printf("Insira um numero: "); 
    scanf("%d", &num);

    imprimir(num, i);

    return 0;
}
