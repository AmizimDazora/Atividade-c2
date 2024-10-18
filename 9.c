#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_NOME 50

// Estrutura para armazenar os dados de um produto
typedef struct {
    char nome[MAX_NOME];
    int quantidade;
} Produto;

// Protótipos das funções
void adicionarProduto(Produto estoque[], int *totalProdutos);
void removerProduto(Produto estoque[], int *totalProdutos);
void exibirEstoque(Produto estoque[], int totalProdutos);

int main() {
    Produto estoque[MAX_PRODUTOS];  // Array para armazenar os produtos
    int totalProdutos = 0;  // Contador do número total de produtos no estoque
    int opcao;

    do {
        printf("\nSistema de Estoque do Supermercado\n");
        printf("1. Adicionar produto ao estoque\n");
        printf("2. Remover produto do estoque\n");
        printf("3. Exibir todos os produtos disponíveis\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarProduto(estoque, &totalProdutos);
                break;
            case 2:
                removerProduto(estoque, &totalProdutos);
                break;
            case 3:
                exibirEstoque(estoque, totalProdutos);
                break;
            case 4:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(opcao != 4);

    return 0;
}

// Função para adicionar um produto ao estoque (inserido no início da lista)
void adicionarProduto(Produto estoque[], int *totalProdutos) {
    if (*totalProdutos < MAX_PRODUTOS) {
        Produto novoProduto;
        printf("Digite o nome do produto: ");
        scanf("%s", novoProduto.nome);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &novoProduto.quantidade);

        // Inserir o novo produto no início da lista
        for (int i = *totalProdutos; i > 0; i--) {
            estoque[i] = estoque[i - 1];
        }
        estoque[0] = novoProduto;
        (*totalProdutos)++;

        printf("Produto '%s' adicionado ao estoque com sucesso!\n", novoProduto.nome);
    } else {
        printf("Estoque cheio. Não é possível adicionar mais produtos.\n");
    }
}

// Função para remover um produto do estoque (conforme ele for vendido)
void removerProduto(Produto estoque[], int *totalProdutos) {
    if (*totalProdutos > 0) {
        printf("Produto '%s' removido do estoque.\n", estoque[0].nome);
        
        // Remover o primeiro produto (deslocando os demais)
        for (int i = 0; i < *totalProdutos - 1; i++) {
            estoque[i] = estoque[i + 1];
        }
        (*totalProdutos)--;
    } else {
        printf("Não há produtos no estoque para remover.\n");
    }
}

// Função para exibir todos os produtos no estoque
void exibirEstoque(Produto estoque[], int totalProdutos) {
    if (totalProdutos > 0) {
        printf("Produtos disponíveis no estoque:\n");
        for (int i = 0; i < totalProdutos; i++) {
            printf("Produto: %s | Quantidade: %d\n", estoque[i].nome, estoque[i].quantidade);
        }
    } else {
        printf("Não há produtos no estoque.\n");
    }
}
