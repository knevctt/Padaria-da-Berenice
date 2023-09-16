#include "header.h"

// Função para atualizar os dados de um produto
void atualizarProduto(Produto *produtos, int quantidadeProdutos)
{
    if (quantidadeProdutos == 0)
    {
      printf("Nenhum produto cadastrado!\n");
    }
    else
    {
        unsigned long long codigo;
        printf("Digite o codigo do produto a ser atualizado: ");
        scanf("%llu", &codigo);
        limpaBuffer();

        Produto *atual = produtos;
        while (atual != NULL)
        {
            if (atual->codigo == codigo)
            {
                printf("=== ATUALIZAR PRODUTO ===\n");
                printf("Codigo: %llu\n", atual->codigo);

                // Atualiza o nome do produto
                printf("Nome [%s]: ", atual->nome);
                fgets(atual->nome, sizeof(atual->nome), stdin);
                atual->nome[strcspn(atual->nome, "\n")] = '\0';

                // Atualiza o valor do produto
                printf("Valor [R$ %.2f]: ", atual->valor);
                scanf("%f", &(atual->valor));
                limpaBuffer();

                // Atualiza o estoque do produto
                printf("Estoque [%d]: ", atual->estoque);
                scanf("%d", &(atual->estoque));
                limpaBuffer();

                printf("Produto atualizado com sucesso!\n");
                return;
            }
            atual = atual->prox;
        }

        printf("Produto nao encontrado!\n");
    }
}
