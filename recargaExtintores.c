#include <stdio.h>

float valor(int tipo){

    switch(tipo){
        case 1:
        return 30.0;
        break;
        case 2:
        return 40.0;
        break;
        case 3:
        return 50.0; 
    }
}

float valorQ(int quant, int tipo){

    return quant*valor(tipo);  

}

float desconto(int quant, int tipo){
    if(quant>5){
        return 0.15*valorQ(quant, tipo); 
    }else{
        return 0; 
    }
}

char* tipoExtintor(int tipo){

    switch(tipo){
        case 1:
        return "Água";
        break;
        case 2:
        return "Pó Químico";
        break;
        case 3:
        return "CO2"; 
    } 
}

float valorTotal(int quant, int tipo){

    return valorQ(quant, tipo)-desconto(quant, tipo); 

}

void imprimir(int quant, int tipo){

    printf("--------RECARGA DE EXTINTORES--------\n");
    printf("Tipo de Extintor: %s\n", tipoExtintor(tipo));
    printf("Quantidade: %d\n", quant);
    printf("Subtotal: R$ %.2f\n", valorQ(quant, tipo)); 
    printf("Desconto: R$ %.2f\n", desconto(quant, tipo));
    printf("-------------------------------------\n");
    printf("VALOR FINAL: R$ %.2f\n", valorTotal(quant, tipo)); 
    printf("-------------------------------------\n"); 

}

int main(){

    int tipo, quant;

    printf("1 - Água\n");
    printf("2 - Pó Químico\n");
    printf("3 - CO2\n");
    printf("Escolha o tipo do extintor: ");
    scanf("%d", &tipo);

    printf("Insira a quantidade de extintores que você deseja recarregar: ");
    scanf("%d", &quant);


    imprimir(quant, tipo);

    return 0; 
}