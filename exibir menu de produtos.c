#include "header.h"

// Função para exibir o menu de Produtos
void exibirMenuProdutos(Produto **produtos, int *quantidadeProdutos)
{
    int opcao;
    do
    {
        printf("\n=== MENU PRODUTOS ===\n");
        printf("1. Exibir Produtos\n");
        printf("2. Cadastrar Produto\n");
        printf("3. Atualizar Produto\n");
        printf("4. Excluir Produto\n");
        printf("5. Salvar Produtos\n");
        printf("6. Ler Produtos\n");
        printf("7. Voltar\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        limpaBuffer();

        switch (opcao)
        {
            case 1:
                exibirProdutos(*produtos);
                break;
            case 2:
                cadastrarProduto(produtos, quantidadeProdutos);
                break;
            case 3:
                atualizarProduto(*produtos, *quantidadeProdutos);
                break;
            case 4:
                excluirProduto(produtos, quantidadeProdutos);
                break;
            case 5:
                salvarProdutos(*produtos, *quantidadeProdutos);
                break;
            case 6:
                lerProdutos(produtos, quantidadeProdutos);
                break;
            case 7:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 7);
}
