#include <stdio.h>

int main(){
    int quant;

    scanf("%d", &quant);

    int num[quant];

    for(int i=0; i<quant; i++){
        printf(" "); 
        scanf("%d", &num[i]); 
    }

    int par=0;
    int impar=0;

    for(int i=0; i<quant; i++){
    if(num[i] % 2 ==0)
        par++;
    else 
        impar++; 
    }

    printf("Numeros pares: %d", par);
    printf("Numeros ímpares: %d", impar);  
}