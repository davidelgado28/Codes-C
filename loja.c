#include <stdio.h>
#include <locale.h>

float desconto(int vip, float valor){
    if(vip==1 && valor>=300 && valor<500){
        return valor*0.05;
    }else{ if(vip==1 && valor>=500){
        return valor*0.15; 
    }else{ if(vip==2 && valor>=500){
        return valor*0.10; 
    }else{
        return 0; 
    }
    }
}
}

float total(float valor, int vip){  

    return valor-desconto(vip, valor);  
}

char* simNao(int vip){
    if(vip==1){
        return "Sim";
    }else{
        return "Não";
    }
}

void imprimir(char nome[], int vip, float valor){

    printf("-------------------------");
    printf("\nCliente: %s", nome);
    printf("\nVIP: %s", simNao(vip));
    printf("\nValor da compra: R$ %.2f", valor);
    printf("\nDesconto: R$ %.2f", desconto(vip, valor));
    printf("\nValor total: R$ %.2f", total(valor, vip)); 
    printf("\n-----------------------");
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    char nome[20];
    int vip;
    float valor;

    printf("Insira o nome do cliente: ");
    scanf("%s", nome);
    
    printf("1 - Sim");
    printf("\n2 - Não");
    printf("\nVocê é VIP? ");
    scanf("%d", &vip);

    printf("Insira o valor da compra: R$ ");
    scanf("%f", &valor); 

    imprimir(nome, vip, valor);

    return 0; 
} 