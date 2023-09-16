#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void cadastrarProduto(Produto **produtos, int *quantidadeProdutos)
{
    int quantidadeNovosProdutos;
    printf("Quantidade de novos produtos a cadastrar: ");
    scanf("%d", &quantidadeNovosProdutos);
    limpaBuffer();

    if (quantidadeNovosProdutos <= 0)
    {
        printf("Quantidade inválida de produtos.\n");
        return;
    }

    printf("=== CADASTRAR PRODUTO ===\n");

    for (int i = 0; i < quantidadeNovosProdutos; i++)
    {
        Produto *novoProduto = (Produto *)malloc(sizeof(Produto));

        do
        {
            printf("Codigo: ");
            scanf("%llu", &(novoProduto->codigo));

            if (novoProduto->codigo == 0)
            {
                printf("\nO codigo precisa ser diferente de zero\n");
            }
            limpaBuffer();

        } while (novoProduto->codigo == 0);

        printf("Nome: ");
        fgets(novoProduto->nome, sizeof(novoProduto->nome), stdin);
        novoProduto->nome[strcspn(novoProduto->nome, "\n")] = '\0';

        do
        {
            printf("Valor: R$ ");
            scanf("%f", &(novoProduto->valor));

            if (novoProduto->valor < 0)
            {
                printf("\nO valor precisa ser maior ou igual a zero\n");
            }
            limpaBuffer();

        } while (novoProduto->valor < 0);

        do
        {
            printf("Estoque: ");
            scanf("%d", &(novoProduto->estoque));
            limpaBuffer();

            if (novoProduto->estoque < 0)
            {
                printf("\nO estoque precisa ser maior ou igual a zero\n");
            }

        } while (novoProduto->estoque < 0);

        novoProduto->prox = NULL;

        if (*produtos == NULL)
        {
            *produtos = novoProduto;
        }
        else
        {
            Produto *atual = *produtos;
            while (atual->prox != NULL)
            {
                atual = atual->prox;
            }

            atual->prox = novoProduto;
        }

        (*quantidadeProdutos)++;
    }
}



