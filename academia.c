#include <stdio.h>

float valorBase(int plano){
    switch(plano){
        case 1:
        return 80;
        break;
        case 2:
        return 120;
        break;
        case 3:
        return 180; 
    } 
}

char* nomePlano(int plano){
    switch(plano){
        case 1:
        return "Basico";
        break;
        case 2:
        return "Intermediario";
        break;
        case 3:
        return "Premium"; 
    } 
}

float fiel(int fidelidade, int plano){
    if(fidelidade==1){
        return valorBase(plano)*0.15;
    }else{
        return 0; 
    }
}

char* nomeFidelidade(int fidelidade){
    if(fidelidade==1){
        return "Sim";
    }else{
        return "Nao"; 
    }
}

float valorTotal(int plano, int fidelidade){
    return valorBase(plano)-fiel(fidelidade, plano); 
}

void imprimir(int plano, int fidelidade){

    printf("--------PLANO DE ACADEMIA--------\n");
    printf("\nPlano Escolhido: %s", nomePlano(plano));
    printf("\nFidelidade de 12 meses? %s", nomeFidelidade(fidelidade));
    printf("\n");
    printf("\nValor sem desconto: R$ %.2f", valorBase(plano));
    printf("\nDesconto aplicado: R$ %.2f", fiel(fidelidade, plano));
    printf("\n--------------------------------\n");
    printf("TOTAL MENSALIDADE: R$ %.2f", valorTotal(plano, fidelidade));
    printf("\n--------------------------------\n");
}

int main(){
    
    int plano, fidelidade;

    printf("1 - Basico\n");
    printf("2 - Intermediario\n");
    printf("3 - Premium\n");
    printf("Escolha seu plano: ");
    scanf("%d", &plano); 

    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Voce deseja fidelidade de 12 meses? ");
    scanf("%d", &fidelidade);

    imprimir(plano, fidelidade);

    return 0; 
}