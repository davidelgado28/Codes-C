#include <stdio.h>
#include <locale.h> 

void imprimir(char nome[5][100], int quant[5]){
    
    printf("--------Controle de estoque--------\n");
    printf("COD     |       PRODUTO       |     QUANTIDADE\n");
    for(int i=0; i<5; i++){
        printf("%d       |       %s       |     %d\n", i+1, nome[i], quant[i]); 
    }
    printf("-----------------------------------\n");
    printf("Total de produtos cadastrados: 5\n");
    printf("-----------------------------------\n");
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int i, quant[5];  
    char nome[5][100];

    for(i=0; i<5; i++){ 
        printf("Insira o nome do produto: \n");
        scanf("%s", nome[i]);
        printf("Insira a quantidade que você adicionou ao estoque: \n"); 
        scanf("%d", &quant[i]); 
        
        imprimir(nome, quant); 
    }
} 