#include "header.h"

// Função para salvar os produtos em um arquivo
void salvarProdutos(Produto *produtos, int quantidadeProdutos)
{
    FILE *arquivo = fopen("produtos.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        Produto *atual = produtos;
        while (atual != NULL)
        {
            fprintf(arquivo, "%llu,%s,%.2f,%d\n", atual->codigo, atual->nome, atual->valor, atual->estoque);
            atual = atual->prox;
        }

        fclose(arquivo);
        printf("Produtos salvos com sucesso!\n");
    }
}
