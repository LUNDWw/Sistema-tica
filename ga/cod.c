#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CLIENTES 100
#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
    float orcamento;
} Cliente;

// Função para salvar os dados no arquivo
void salvar_clientes(Cliente clientes[], int total) {
    FILE *arquivo = fopen("clientes.txt", "w");
    if (!arquivo) {
        printf("Erro ao salvar clientes!\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%s;%f\n", clientes[i].nome, clientes[i].orcamento);
    }
    fclose(arquivo);
}

// Função para carregar os dados do arquivo
int carregar_clientes(Cliente clientes[]) {
    FILE *arquivo = fopen("clientes.txt", "r");
    if (!arquivo) return 0;

    int total = 0;
    while (fscanf(arquivo, "%99[^;];%f\n", clientes[total].nome, &clientes[total].orcamento) == 2) {
        total++;
        if (total >= MAX_CLIENTES) break;
    }
    fclose(arquivo);
    return total;
}

int main() {
    Cliente clientes[MAX_CLIENTES];
    int total_clientes = carregar_clientes(clientes);  // Carrega clientes ao iniciar
    int opcao;
    char resposta[10];

    printf("Bem vindo a Ótica da Família!\n");

    while (1) {
        printf("\n1 - Óculos de grau\n");
        printf("2 - Óculos de sol\n");
        printf("3 - Lentes de contato\n");
        printf("4 - Finalizar\n");
        if (total_clientes > 0) {
            printf("5 - Buscar cliente\n");
        }

        printf("\nComo podemos ajudar você: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Por favor, digite um número válido.\n");
            while (getchar() != '\n');
            continue;
        }

        if (opcao == 4) {
            printf("Encerrando o sistema. Obrigado!\n");
            salvar_clientes(clientes, total_clientes);  // Salva ao encerrar
            break;
        }

        if (opcao == 5 && total_clientes > 0) {
            char nome_busca[TAM_NOME];
            int encontrado = 0;
            printf("Digite o nome do cliente: ");
            while (getchar() != '\n');
            fgets(nome_busca, TAM_NOME, stdin);
            nome_busca[strcspn(nome_busca, "\n")] = 0;

            for (int i = 0; i < total_clientes; i++) {
                if (strcasecmp(clientes[i].nome, nome_busca) == 0) {
                    printf("Cliente: %s - Orçamento: R$ %.2f\n", clientes[i].nome, clientes[i].orcamento);
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Cliente não encontrado.\n");
            }
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Você escolheu a opção 1: Óculos de grau\n");
                break;
            case 2:
                printf("Você escolheu a opção 2: Óculos de sol\n");
                break;
            case 3:
                printf("Você escolheu a opção 3: Lentes de contato\n");
                break;
            default:
                printf("Opção inválida.\n");
                continue;
        }

        printf("Deseja continuar? (S/N): ");
        while (getchar() != '\n');
        fgets(resposta, sizeof(resposta), stdin);

        if (tolower(resposta[0]) == 's') {
            float orcamento;
            char nome[TAM_NOME];

            printf("\nÓtimo! Vamos prosseguir.\n");
            printf("Por favor, informe o valor do orçamento.\n");
            printf("Qual o valor do orçamento? ");
            if (scanf("%f", &orcamento) != 1) {
                printf("Valor inválido.\n");
                while (getchar() != '\n');
                continue;
            }

            while (getchar() != '\n');
            printf("Qual o seu nome? ");
            fgets(nome, TAM_NOME, stdin);
            nome[strcspn(nome, "\n")] = 0;

            if (total_clientes < MAX_CLIENTES) {
                strcpy(clientes[total_clientes].nome, nome);
                clientes[total_clientes].orcamento = orcamento;
                total_clientes++;
                printf("\nObrigado, %s! Seu orçamento de R$ %.2f foi registrado.\n", nome, orcamento);
            } else {
                printf("Limite de clientes atingido.\n");
            }
        } else {
            printf("Operação cancelada.\n");
        }
    }

    return 0;
}
