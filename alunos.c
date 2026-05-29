#include <stdio.h>
#include <locale.h> 

float media(float nota[], int quant, float soma){

    for (int i=0; i<quant; i++) { 
        soma = soma+nota[i]; 
    }
    return soma/quant;
}

void imprimir(char nome[], float nota[], int quant, float TotalMedia, float soma){

    printf("\n-------------CADASTRO DE ALUNOS E NOTAS----------------"); 
    printf("\n%s", nome); 
    printf("\n-------------------------------------------------------");
    for(int i=0; i<quant; i++){  
        printf("\nNotas: %.2f ", nota[i]); 
    }  
    printf("\n-------------------------------------------------------");
    printf("\nMédia: %.2f\n", media(nota, quant, soma)); 
    printf("\n-------------------------------------------------------\n");
}

int main(){ 

    setlocale(LC_ALL, "Portuguese_Brazil");
    
    char nome[3][100];   
    float nota[3][4], totalMedia[3], soma;
     
    for (int i = 0; i < 3; i++){ 
        printf("\nDigite o nome do aluno: ");
        scanf("%s", nome[i]);

        for (int j = 0; j < 4; j++){
            printf("\nDigite a %d° nota  de %s: ", j + 1, nome[i]);
            scanf("%f", &nota[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        totalMedia[i] = media(nota[i], 4, soma);
    }
    for (int i = 0; i < 3; i++){
        imprimir(nome[i], nota[i], 4, totalMedia[i], soma);
    } 
    return 0;
}