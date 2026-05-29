#include <stdio.h>

int adicionarBorda(int borda){
    if(borda == 1){
        return 5;
    }else{
        return 0; 
    }
}

int adicionarRefri(int refri){
    if(refri==1){
        return 8;
    }else{
        return 0; 
    }
}

int valorPizza(int tamanho){
    if(tamanho==1){
        return 20;
    }else if(tamanho==2){
        return 30;
    }else if(tamanho==3){
        return 40;
    }else{
        return 0; 
    }
}

char* tamanhoPizza(int tamanho){
    if(tamanho==1){
        return "Pequena";
    }else if(tamanho==2){
        return "Media";
    }else if(tamanho==3){
        return "Grande";
}
} 

char* bordaRecheada(int borda){
    if(borda==1){
        return "Sim";
    }else{
        return "Nao"; 
    }
}

char* refrigerante(int refri){
    if(refri==1){
        return "Sim";
    }else{
        return "Nao"; 
    }
}

int adicionais(int borda, int refri){

    return adicionarBorda(borda)+adicionarRefri(refri);

}

int total(int tamanho, int borda, int refri){

    return valorPizza(tamanho)+adicionais(borda, refri);

}

void imprimir(int tamanho, int borda, int refri){

    printf("\n--------PEDIDO--------\n");
    printf("Tamanho da pizza: %s \n", tamanhoPizza(tamanho));
    printf("Borda recheada: %s \n", bordaRecheada(borda));
    printf("Refrigerante: %s \n", refrigerante(refri));
    printf("\n");
    printf("Subtotal: R$ %d,00 \n", valorPizza(tamanho));
    printf("Adicionais: R$ %d,00 \n", adicionais(borda, refri));
    printf("-----------------------\n");
    printf("Total a pagar: R$ %d,00 \n", total(tamanho, borda, refri));
    printf("-----------------------\n");

}

int main(){

    int tamanho, borda, refri;

    printf("1 - Pequena \n");
    printf("2 - Media \n");
    printf("3 - Grande \n");
    printf("Insira o tamanho da pizza que voce deseja: ");
    scanf("%d", &tamanho);

    printf("1 - Sim \n");
    printf("2 - Nao \n");
    printf("Voce deseja borda recheada? ");
    scanf("%d", &borda);

    printf("1 - Sim \n");
    printf("2 - Nao \n");
    printf("Voce deseja refrigerante? ");
    scanf("%d", &refri); 

    imprimir(tamanho, borda, refri); 

    return 0;

}