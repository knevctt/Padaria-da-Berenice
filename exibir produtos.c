#include "header.h"

// Função para exibir os produtos cadastrados
void exibirProdutos(Produto *produtos)
{
    if (produtos == NULL)
    {
        printf("Nenhum produto cadastrado!\n");
    }
    else
    {
        printf("=== PRODUTOS ===\n");
        Produto *atual = produtos;
        while (atual != NULL)
        {
            printf("Codigo: %llu | Nome: %s | Valor: R$ %.2f | Estoque: %d\n", atual->codigo, atual->nome, atual->valor, atual->estoque);
            atual = atual->prox;
        }
    }
}
