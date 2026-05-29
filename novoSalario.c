#include <stdio.h>
#include <locale.h>

float aumento(float salario, int percentual){
    return (salario*percentual)/100; 
}

float novoSalario(float salario, int percentual){
    return salario + aumento(salario, percentual); 
} 

void imprimir(float salario, int percentual){
    printf("O seu novo salário é: %.2f\n", novoSalario(salario, percentual)); 
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil"); 
    float salario; 
    int percentual;

    printf("Insira o seu salário: ");
    scanf("%f", &salario); 
    printf("Insira o seu percentual de aumento [apenas o número (ex: 15)]: ");
    scanf("%d", &percentual); 

    imprimir(salario, percentual);

    return 0;
} 