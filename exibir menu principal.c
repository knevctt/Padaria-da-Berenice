#include "header.h"

void exibirMenuVendas(Produto *produtos, int quantidadeProdutos)
{
    int opcao;
    do
    {
        printf("Tecle enter\n");
        getchar();
        system("cls");

        printf("\n=== MENU VENDAS ===\n");
        printf("1. Realizar Venda\n");
        printf("2. Relatorio de Vendas\n");
        printf("3. Voltar\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        limpaBuffer();

        switch (opcao)
        {
            case 1:
                realizarVenda(produtos, quantidadeProdutos);
                break;
            case 2:
                relatorioVendas(produtos, quantidadeProdutos);
                break;
            case 3:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 3);
}
