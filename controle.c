#include <stdio.h>

void resultado(int quant[], char nome[][10]){

 printf("Cod\t|\tnome\t|\tquantidade\t|\n");
    for (int valores = 1; valores < 6; valores++)
    {
        printf("%d\t|\t%s\t|\t%d\t|\n", valores, nome[valores], quant[valores]);
    }
}

int main()
{
    int quant[5];
    char nome[5][10];

    for(int valores=1; valores<6; valores++){
        printf("Digite o nome do produto: ");
        scanf("%s", nome[valores]);
        printf("Digite a quantidade: ");
        scanf("%d", &quant[valores]);
        resultado(quant,nome);
    }
    return 0; 
}