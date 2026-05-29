#include <stdio.h>

float calcIMC(float peso, float altura){

    return peso/(altura*altura); 

}

void resultIMC(float result){ 

    if(result<18.5)
        printf("Abaixo do Peso"); 
    else if(result>=18.5 && result<=24.9) 
        printf( "Peso Normal"); 
    else if(result>=25 && result<=29.9)
        printf( "Sobrepeso");
    else if(result>=30 && result<34.9)
        printf( "Obesidade Grau I");
    else if(result>=35 && result<39.9)
        printf( "Obesidade Grau II");
    else
        printf( "Obesidade Grau III");                   
}

int main(){

    float peso, altura; 

    printf("Insira o seu peso (em kg): "); 
    scanf("%f", &peso); 
    printf("Insira a sua altura (em metros): "); 
    scanf("%f", &altura); 

    resultIMC(calcIMC(peso, altura));  
    return 0;
 
}