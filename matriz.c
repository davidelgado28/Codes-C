#include <stdio.h>

int main() {
    int num[5][3], soma = 0, coluna[3] = {0, 0, 0}, linha;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Valor (conforme a posicao) [%d][%d]: ", i, j); 
            scanf("%d", &num[i][j]);
        }
    }
    printf("\n------------ MATRIZ DIGITADA ------------\n");
    printf("\t     | J0 | J1 | J2 | Resultado [Linha]\n");
    for (int i = 0; i < 5; i++) {
        linha = 0;
        printf("  I%d   |", i);
        for (int j = 0; j < 3; j++) {
            printf(" %d |", num[i][j]);
            linha = linha + num[i][j];       
            coluna[j] = coluna[j] + num[i][j]; 
        }
        printf(" %d\n", linha);
        soma = soma + linha; 
    }
    printf("Resultado [Coluna] |");
    for (int j = 0; j < 3; j++) {
        printf(" %d |", coluna[j]);
    }
    printf(" %d\n", soma);
    printf("\nSoma total da Matriz: %d\n", soma);
    printf("------------------------------------------\n"); 

    return 0;
}
