#include <stdio.h>

/*NÃO CONSEGUI INCLUIR O SET LOCALE*/  

float valorPedagio(int veic) {
    switch (veic) {
        case 1: 
        return 5.0;
        break;
        case 2: 
        return 2.5;
        break;
        case 3: 
        return 10.0;
        break;
        case 4: 
        return 8.0; 
    }
}

float valorEixos(int veic, int eixos) {
    if (veic == 3 && eixos > 2) {
        return eixos*2.5;
    }
    return 0; 
}

float fimDeSemana(char fds, float subtotal) {
    if (fds == 'S' || fds == 's') {
        return subtotal * 0.2;
    }
    return 0;
}

char* nomeVeiculo(int veic) {
    switch (veic) {
        case 1: 
        return "Carro";
        break;
        case 2: 
        return "Moto";
        break;
        case 3: 
        return "Caminhao";
        break;
        case 4: 
        return "Onibus"; 
    }
}

void imprimir(int veic, int eixos, char fds) {
    printf("\n---------- Pedagio ----------\n");
    printf("Veiculo: %s\n", nomeVeiculo(veic));
    if (veic == 3) {
        printf("Quant de eixos: %d\n", eixos);
    }
    printf("Valor Base: R$ %.2f\n", valorPedagio(veic));
    printf("Acrescimos por eixos: R$ %.2f\n", valorEixos(veic, eixos)); 
    printf("Acrescimo de final de semana/feriado: R$ %.2f\n", fimDeSemana(fds, valorPedagio(veic) + valorEixos(veic, eixos)));
    printf("Valor Total: R$ %.2f\n", valorPedagio(veic) + valorEixos(veic, eixos) + fimDeSemana(fds, valorPedagio(veic) + valorEixos(veic, eixos)));
}

int main() {
    int veic, eixos;
    char fds;

    printf("1 - Carro");
    printf("\n2 - Moto");
    printf("\n3 - Caminhao");
    printf("\n4 - Onibus");
    printf("\nInsira o tipo de veiculo: ");
    scanf("%d", &veic);

    if (veic==3){
        printf("Insira a quantidade de eixos: "); 
        scanf("%d", &eixos); 
    }

    printf("S/s: Sim");
    printf("\nN/n: Nao");
    printf("\nE final de semana/feriado? ");
    scanf(" %c", &fds);

    imprimir(veic, eixos, fds); 

    return 0;
}