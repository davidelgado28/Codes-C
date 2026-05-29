#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100
#define ARQUIVO_ESTOQUE "estoque.txt"

typedef struct {
    char nome[MAX_NOME];
    int quantidade;
} Item;

void limparBuffer() {
    while (getchar() != '\n');
}

void adicionarItem() {
    FILE *arquivo = fopen(ARQUIVO_ESTOQUE, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Item item;
    printf("Digite o nome do item: ");
    fgets(item.nome, MAX_NOME, stdin);
    item.nome[strcspn(item.nome, "\n")] = '\0'; 
    printf("Digite a quantidade: ");
    scanf("%d", &item.quantidade);
    limparBuffer();

    fprintf(arquivo, "%s\n%d\n", item.nome, item.quantidade);
    printf("Item adicionado com sucesso!\n");

    fclose(arquivo);
}

void removerItem() {
    FILE *arquivo = fopen(ARQUIVO_ESTOQUE, "r+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char nomeItem[MAX_NOME];
    printf("Digite o nome do item: ");
    fgets(nomeItem, MAX_NOME, stdin);
    nomeItem[strcspn(nomeItem, "\n")] = '\0'; 

    Item item;
    int encontrado = 0, quantidadeRemovida;
    long int posicaoInicioItem;

    while (fscanf(arquivo, "%s\n%d", item.nome, &item.quantidade) != EOF) {
        if (strcmp(item.nome, nomeItem) == 0) {
            encontrado = 1;
            posicaoInicioItem = ftell(arquivo) - strlen(item.nome) - 2;
            break;
        }
    }

    if (!encontrado) {
        printf("Item não encontrado.\n");
        fclose(arquivo);
        return;
    }

    printf("Digite a quantidade a ser removida: ");
    scanf("%d", &quantidadeRemovida);
    limparBuffer();

    if (quantidadeRemovida > item.quantidade) {
        printf("Estoque insuficiente. Quantidade disponível: %d\n", item.quantidade);
    } else {
        item.quantidade -= quantidadeRemovida;
        fseek(arquivo, posicaoInicioItem, SEEK_SET);
        fprintf(arquivo, "%s\n%d\n", item.nome, item.quantidade);
        printf("Quantidade atualizada com sucesso!\n");
    }

    fclose(arquivo);
}

void listarEstoque() {
    FILE *arquivo = fopen(ARQUIVO_ESTOQUE, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Item item;
    int encontrado = 0;

    printf("=============================\n");
    printf("        Estoque Atual\n");
    printf("=============================\n");

    while (fscanf(arquivo, "%s\n%d", item.nome, &item.quantidade) != EOF) {
        printf("Nome: %s\nQuantidade: %d\n", item.nome, item.quantidade);
        encontrado = 1;
    }

    if (!encontrado) {
        printf("O estoque está vazio.\n");
    }

    fclose(arquivo);
}

void menu() {
    int opcao;

    do {
        printf("\n================================\n");
        printf("   Controle de Estoque\n");
        printf("================================\n");
        printf("Selecione uma opção:\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Estoque\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                adicionarItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarEstoque();
                break;
            case 4:
                printf("Obrigado por usar o Controle de Estoques! Até a próxima.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

        if (opcao != 4) {
            char continuar;
            printf("Deseja realizar outra operação? (s/n): ");
            scanf("%c", &continuar);
            limparBuffer();

            if (continuar != 's' && continuar != 'S') {
                printf("Obrigado por usar o Controle de Estoques! Até a próxima.\n");
                break;
            }
        }

    } while (opcao != 4);
}

int main() {
    menu();
    return 0;
} 