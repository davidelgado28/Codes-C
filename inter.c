#include <stdio.h>
#include <locale.h>

int pontos2(int gols1, int gols2){
    if(gols2>gols1){
        return 3;
    }else{   if(gols2<gols1){
         return 0;
    }else{
        return 1;
       }
    }
}

int pontos1(int gols1, int gols2){
    if(gols1>gols2){
        return 3;
    }else{   if(gols1<gols2){
         return 0;
    }else{
        return 1;
       }
    }
}

void resultado(char time1[50], char time2[50], int gols1, int gols2, int saldo1, int saldo2){

    setlocale(LC_ALL, "Portuguese");

    printf("===================================================\n");
    printf("                  RESULTADO DO JOGO                \n");
    printf("===================================================\n");
    printf("|              | QTD GOLS | Pontos | Saldo de Gols|\n");
    printf("|--------------|----------|--------|--------------|\n");
    printf("| %s           |    %d    |   %d   |       %d     |\n", time1, gols1, pontos1(gols1, gols2), saldo1); 
    printf("| %s           |    %d    |   %d   |       %d     |\n", time2, gols2, pontos2(gols1, gols2), saldo2); 
    printf("===================================================\n");
    if(gols1>gols2){
        printf("Vitória do time %s somando %d pontos na tabela geral.\n", time1, pontos1(gols1, gols2)+saldo1);
    }else{  if(gols1<gols2){
        printf("Vitória do time %s somando %d pontos na tabela geral.\n", time2, pontos2(gols1, gols2)+saldo2); 
    }else{
        printf("A partida terminou em empate, com o time %s e o time %s somando 1 ponto na tabela geral. \n", time1, time2);
       }
    }
    printf("===================================================\n"); 
}
    
int main(){

    char time1[50], time2[50];
    int gols1, gols2, saldo1, saldo2;

    int i=0;

    printf("Insira o nome do time %d: ", i+1);
    scanf("%s", time1);
    printf("Insira o nome do time %d: ", i+2);
    scanf("%s", time2);

    printf("\n"); 

    printf("Quantidade de gols do time %d: ", i+1); 
    scanf("%d", &gols1);
    printf("Quantidade de gols do time %d: ", i+2);
    scanf("%d", &gols2); 

    saldo1 = gols1 - gols2;
    saldo2 = gols2 - gols1;

    saldo1 = saldo1 < 0 ? 0 : saldo1;
    saldo2 = saldo2 < 0 ? 0 : saldo2;

  resultado(time1, time2, gols1, gols2, saldo1, saldo2); 
}