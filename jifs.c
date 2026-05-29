#include <stdio.h>
#include <locale.h>

// Função para encontrar o vencedor
int encontrarVencedor(int n, int temposTotais[]) {
    int vencedor = 0;
    for (int i = 1; i < n; i++) {
        if (temposTotais[i] < temposTotais[vencedor]) {
            vencedor = i;
        }
    }
    return vencedor;
}

int main() {
    int nCompetidores, nVoltas;

    // Leitura da quantidade de competidores
    printf("Quantidade de competidores: ");
    scanf("%d", &nCompetidores);
    printf("\n");
    
    // Array de nomes
    char nomes[nCompetidores][50];
    
    // Leitura dos nomes dos competidores
    for (int i = 0; i < nCompetidores; i++) {
        printf("Competidor %d: ", i + 1);
        scanf(" %[^\n]", nomes[i]);
    }
    
    printf("\n");

    // Leitura da quantidade de voltas
    printf("Quantidade de voltas: ");
    scanf("%d", &nVoltas);
    printf("\n");

    // Matriz para armazenar os tempos das voltas de cada competidor
    int tempos[nCompetidores][nCompetidores]; 
    
    // Leitura dos tempos das voltas
    for (int i = 0; i < nCompetidores; i++) {
        for (int j = 0; j < nVoltas; j++) {
            printf("Tempo da volta %d do competidor %s: ", j + 1, nomes[i]);
            scanf("%d", &tempos[i][j]);
        }
        printf("\n");
    }
    
    // Array para armazenar o tempo total de cada competidor
    int temposTotais[nCompetidores]; 

    // Cálculo do tempo total de cada competidor
    for (int i = 0; i < nCompetidores; i++) {
        int soma = 0;
        for (int j = 0; j < nVoltas; j++) {
            soma += tempos[i][j];
        }
        temposTotais[i] = soma;
    }

    // Exibi��o da tabela
    printf("=======================================================\n");
    printf("               CORRIDA DE CLASSIFICA��O JIFS\n");
    printf("=======================================================\n");
    printf("|         |");
    for (int j = 0; j < nVoltas; j++) {
        printf(" Volta %d |", j + 1);
    }
    printf(" Tempo Total |\n");
    printf("|---------|");
    for (int j = 0; j < nVoltas; j++) {
        printf("---------|");
    }
    printf("-------------|\n");

    // Exibição dos tempos de cada competidor
    for (int i = 0; i < nCompetidores; i++) {
        printf("| %-7s |", nomes[i]);
        for (int j = 0; j < nVoltas; j++) {
            printf(" %7d |", tempos[i][j]);
        }
        printf(" %11d |\n", temposTotais[i]);
    }

    // Encontrar o vencedor
    int vencedor = encontrarVencedor(nCompetidores, temposTotais);

    // Exibição do vencedor
    printf("=======================================================\n");
    printf("O representante será: %s\n", nomes[vencedor]);
    printf("=======================================================\n");

    return 0;
}