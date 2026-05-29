#include <stdio.h>

int valorBase(int tipo, int servico){

    if(servico==1){
        if(tipo==1){
            return 25;
        }else{
            if(tipo==2){
                return 15;
            }else{
                return 40;
            }
        }
    }else{
        if(tipo==1){
            return 40;
    }else{
        if(tipo==2){
            return 25;
        }else{
            return 60;
        }
    }
 }
}

int desconto(int valor, int quant){

    if(quant>1){
        return valor*0.1; 
    }else{
        return 0; 
    }
}

char* tipoVeiculo(int tipo){

    if(tipo==1){
        return "Carro";
    }else{
        if(tipo==2){
            return "Moto";
        }else{
            return "Caminhonete";
        }
    }
}

char* tipoServico(int servico){

    if(servico==1){
        return "Simples";
    }else{
        return "Completa";
    }
}

int subtotal(int tipo, int servico, int quant){

    switch(servico){
        case 1:
            switch(tipo){
                case 1:
                    return 25*quant;
                case 2:
                    return 15*quant;
                case 3:
                    return 40*quant;
            }
            break; 
        case 2:
            switch(tipo){
                case 1:
                    return 40*quant;
                case 2:
                    return 25*quant;
                case 3:
                    return 60*quant;
            }
    }
   
}

float valorTotal(int tipo, int servico, int quant){

    return subtotal(tipo, servico, quant)-desconto(subtotal(tipo, servico, quant), quant);  
    
}

void imprimir(int tipo, int servico, int quant){

    printf("--------LAVAGEM DE VEICULO--------\n");
    printf("Tipo de veiculo: %s\n", tipoVeiculo(tipo));
    printf("Tipo de servico: %s\n", tipoServico(servico));
    printf("Quantidade de lavagens: %d\n", quant);
    printf("\n");
    printf("Subtotal: R$ %d\n", subtotal(tipo, servico, quant));
    printf("Desconto: R$ %d\n", desconto(subtotal(tipo, servico, quant), quant));
    printf("-------------------------------\n");
    printf("VALOR TOTAL: R$ %.2f\n", valorTotal(tipo, servico, quant));
    printf("-------------------------------\n");  

} 

int main(){

    int tipo, servico, quant;

    printf("1 - Simples\n");
    printf("2 - Completa\n");
    printf("Escolha o tipo de lavagem: ");
    scanf("%d", &servico);

    printf("\n1 - Carro\n");
    printf("2 - Moto\n");
    printf("3 - Caminhonete\n");
    printf("Escolha o tipo de veiculo: ");
    scanf("%d", &tipo); 

    printf("\nQuantas lavagens? ");
    scanf("%d", &quant); 

    imprimir(tipo, servico, quant); 

    return 0;
}