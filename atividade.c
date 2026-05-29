#include <stdio.h>
#include <locale.h>

int main(){ 
    setlocale(LC_ALL, "Portuguese_Brazil"); 
    float valor = 145.82;
    
    printf("O valor da carne é R$ %.2f", valor);  

    return 0;
} 