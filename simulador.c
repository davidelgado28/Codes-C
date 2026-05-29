#include <stdio.h>
#include <locale.h>

void imprimir(int notas[], int quantN[], int tem[], float valor, int falta){
 
    for(int i = 0; i < 4; i++){
        int max = falta/notas[i];   

        if(max > quantN[i]){
            max = quantN[i];           
        }
        tem[i] = max;
        falta -= tem[i] * notas[i];
    }
    if(falta == 0){
        printf("\nO seu saque de R$ %.2f podera ser realizado.\n", valor);
        printf("Voce recebera:\n");
        for(int i = 0; i < 4; i++){ 
            if (tem[i] > 0) {
                printf("R$ %.2f --> %d notas\n", (float)notas[i], tem[i]);   
                quantN[i] -= tem[i];
            }
        }
    }else{ 
        printf("\nO valor inserido nao pode ser sacado com as notas disponiveis. \n"); 
    } 
}

int main() {

    setlocale(LC_ALL, "Portuguese"); 

    int notas[4] = {100, 50, 20, 10};     
    int quantN[4] = {10, 10, 10, 10};   
    int valor, falta, tem[4] = {0};  

    printf("--------Caixa Eletronico--------\n");
    printf("Notas disponiveis: \n R$ 100,00 \n R$ 50,00 \n R$ 20,00 \n R$ 10,00\n");
    printf("Insira o valor do saque: ");   
    scanf("%d", &valor);

    falta = valor; 

    imprimir(notas, quantN, tem, valor, falta); 
    
    return 0; 
}
