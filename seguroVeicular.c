#include <stdio.h>
#include <locale.h>

float valorInicial(int valorBase){
    switch(valorBase){
        case 1: 
        return 1200;
        break;
        case 2:
        return 800; 
        break;
        default:
        return 0; 
    }
}

float acresIdade(int idade, int valorBase){
    if(idade<25){
        return valorInicial(valorBase)*0.2; 
    }else{
        return 0; 
    }
}

float acresBonus(int bonus, int valorBase){
    if(bonus==1){
        return 0;
    }else{
        return valorInicial(valorBase)*0.1;  
    }
}

float totalAcres(int idade, int bonus, int valorBase){

    return acresIdade(idade, valorBase)+acresBonus(bonus, valorBase);  

} 

float valorTotal(int idade, int bonus, int valorBase){

    return valorInicial(valorBase)+totalAcres(idade, bonus, valorBase); 

}

char* tipo(int valorBase){
    switch(valorBase){
        case 1:
        return "Carro";
        break;
        case 2:
        return "Moto"; 
    }
}

char* bonusSim(int bonus){
    if(bonus==1){
        return "Sim";
    }else{
        return "Nao"; 
    }
}

void imprimir(int valorBase, int idade, int bonus){

    printf("--------SEGURO VEICULAR--------\n");
    printf("Veiculo: %s", tipo(valorBase));
    printf("\nIdade: %d", idade);
    printf("\nBonus: %s", bonusSim(bonus));
    printf("\n");
    printf("\nValor Base: R$ %.2f", valorInicial(valorBase));
    printf("\nAcrescimos: R$ %.2f", totalAcres(idade, bonus, valorBase));
    printf("\n--------------------------------\n");
    printf("TOTAL DO SEGURO: R$ %.2f", valorTotal(idade, bonus, valorBase));
    printf("\n--------------------------------\n");

}

int main(){

    int valorBase, idade, bonus;

    printf("1 - Carro\n");
    printf("2 - Moto\n");
    printf("Qual o tipo de seu veiculo: ");
    scanf("%d", &valorBase);

    printf("Qual a sua idade: "); 
    scanf("%d", &idade);

    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Voce deseja bonus? ");
    scanf("%d", &bonus);

    imprimir(valorBase, idade, bonus); 

    return 0; 
}