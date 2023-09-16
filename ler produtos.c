#include "header.h"

// Função para ler os produtos de um arquivo
void lerProdutos(Produto **produtos, int *quantidadeProdutos)
{
    FILE *arquivo = fopen("produtos.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        // Limpa a lista de produtos
        *quantidadeProdutos = 0;
        Produto *atual = *produtos;
        Produto *proximo;

        // Libera a memória dos produtos existentes
        while (atual != NULL)
        {
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }

        *produtos = NULL;

        while (1)
        {
            Produto *novoProduto = (Produto *)malloc(sizeof(Produto));

            int result = fscanf(arquivo, "%llu,%[^,],%f,%d\n", &(novoProduto->codigo), novoProduto->nome, &(novoProduto->valor),
                   &(novoProduto->estoque));

            if (result != 4) // Verifica se a leitura foi bem-sucedida
            {
                free(novoProduto); // Libera a memória do produto criado
                break; // Sai do loop caso a leitura falhe
            }

            novoProduto->prox = NULL; // Define o próximo nó como NULL

            if (*produtos == NULL)
            {
                *produtos = novoProduto; // O novo produto se torna o primeiro da lista
            }
            else
            {
                Produto *ultimo = *produtos;
                while (ultimo->prox != NULL)
                {
                    ultimo = ultimo->prox; // Encontra o último nó da lista
                }
                ultimo->prox = novoProduto; // Adiciona o novo produto ao final da lista
            }

            (*quantidadeProdutos)++;
        }

        fclose(arquivo);
        printf("Produtos lidos com sucesso!\n");
    }
}
