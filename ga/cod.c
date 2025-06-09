#include <stdio.h>      // Biblioteca para entrada e saída (printf, scanf, fgets, etc)
#include <string.h>     // Biblioteca para manipulação de strings (strcmp, strcpy, etc)
#include <stdlib.h>     // Biblioteca padrão (não usada diretamente aqui, mas comum em C)
#include <ctype.h>      // Biblioteca para funções de caracteres (tolower, etc)

#define MAX_CLIENTES 100    // Define o número máximo de clientes que podem ser cadastrados
#define TAM_NOME 100        // Define o tamanho máximo do nome do cliente

// Estrutura que representa um cliente, com nome e orçamento
typedef struct {
    char nome[TAM_NOME];    // Nome do cliente
    float orcamento;        // Valor do orçamento do cliente
} Cliente;

int main() {
    Cliente clientes[MAX_CLIENTES]; // Vetor para armazenar todos os clientes cadastrados
    int total_clientes = 0;         // Conta quantos clientes já foram cadastrados
    int opcao;                      // Guarda a opção escolhida pelo usuário no menu
    char resposta[10];              // Guarda a resposta do usuário (S/N) para confirmação

    printf("Bem vindo a Ótica da Família!\n"); // Mensagem de boas-vindas

    // Loop principal do sistema, só para quando o usuário escolher finalizar
    while (1) {
        // Mostra o menu de opções
        printf("\n1 - Óculos de grau\n");
        printf("2 - Óculos de sol\n");
        printf("3 - Lentes de contato\n");
        printf("4 - Finalizar\n");
        if (total_clientes > 0) {
            printf("5 - Buscar cliente\n"); // Só mostra a opção de buscar se já houver clientes cadastrados
        }

        printf("\nComo podemos ajudar você: ");
        // Lê a opção escolhida pelo usuário
        if (scanf("%d", &opcao) != 1) {
            printf("Por favor, digite um número válido.\n");
            while (getchar() != '\n'); // Limpa o buffer do teclado
            continue; // Volta para o menu
        }

        // Se o usuário escolher finalizar, sai do loop e encerra o programa
        if (opcao == 4) {
            printf("Encerrando o sistema. Obrigado!\n");
            break;
        }

        // Se o usuário escolher buscar cliente e já houver clientes cadastrados
        if (opcao == 5 && total_clientes > 0) {
            char nome_busca[TAM_NOME]; // Para guardar o nome a ser buscado
            int encontrado = 0;        // Flag para saber se encontrou o cliente
            printf("Digite o nome do cliente: ");
            while (getchar() != '\n'); // Limpa o buffer do teclado
            fgets(nome_busca, TAM_NOME, stdin); // Lê o nome digitado
            nome_busca[strcspn(nome_busca, "\n")] = 0; // Remove o \n do final

            // Procura o cliente pelo nome
            for (int i = 0; i < total_clientes; i++) {
                if (strcasecmp(clientes[i].nome, nome_busca) == 0) { // Compara ignorando maiúsculas/minúsculas
                    printf("Cliente: %s - Orçamento: R$ %.2f\n", clientes[i].nome, clientes[i].orcamento);
                    // encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Cliente não encontrado.\n");
            }
            continue; // Volta para o menu
        }

        // Dependendo da opção escolhida, mostra qual produto foi selecionado
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
                continue; // Volta para o menu
        }

        // Pergunta se o usuário deseja continuar com o cadastro
        printf("Deseja continuar? (S/N): ");
        while (getchar() != '\n'); // Limpa o buffer do teclado
        fgets(resposta, sizeof(resposta), stdin);

        // Se o usuário responder 'S' ou 's', continua o cadastro
        if (tolower(resposta[0]) == 's') {
            float orcamento;
            char nome[TAM_NOME];

            printf("\nÓtimo! Vamos prosseguir.\n");
            printf("Por favor, informe o valor do orçamento.\n");
            printf("Qual o valor do orçamento? ");
            // Lê o valor do orçamento
            if (scanf("%f", &orcamento) != 1) {
                printf("Valor inválido.\n");
                while (getchar() != '\n'); // Limpa o buffer
                continue; // Volta para o menu
            }
            printf("Agora, para finalizar, informe o seu nome.\n");
            while (getchar() != '\n'); // Limpa o buffer
            printf("Qual o seu nome? ");
            fgets(nome, TAM_NOME, stdin); // Lê o nome do cliente
            nome[strcspn(nome, "\n")] = 0; // Remove o \n do final

            // Se ainda houver espaço, cadastra o cliente
            if (total_clientes < MAX_CLIENTES) {
                strcpy(clientes[total_clientes].nome, nome); // Salva o nome
                clientes[total_clientes].orcamento = orcamento; // Salva o orçamento
                total_clientes++; // Incrementa o total de clientes
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