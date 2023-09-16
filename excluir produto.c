#include "header.h"

// Fun��o para excluir um produto
void excluirProduto(Produto **produtos, int *quantidadeProdutos)
{
    if (*quantidadeProdutos == 0)
    {
        printf("Nenhum produto cadastrado!\n");
    }
    else
    {
        unsigned long long codigo;
        printf("Digite o codigo do produto a ser excluido: ");
        scanf("%llu", &codigo);
        limpaBuffer();

        Produto *atual = *produtos;
        Produto *anterior = NULL;

        while (atual != NULL)
        {
            if (atual->codigo == codigo)
            {
                if (anterior == NULL)
                {
                    // Remove o primeiro n� da lista
                    *produtos = atual->prox;
                }
                else
                {
                    // Remove um n� no meio ou no final da lista
                    anterior->prox = atual->prox;
                }

                free(atual); // Libera a mem�ria do produto exclu�do

                (*quantidadeProdutos)--;
                printf("Produto excluido com sucesso!\n");
                return;
            }

            anterior = atual;
            atual = atual->prox;
        }

        printf("Produto nao encontrado!\n");
    }
}
