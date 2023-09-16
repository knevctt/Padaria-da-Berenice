#include  "header.h"

// Função para exibir o menu principal
void exibirMenuPrincipal(Produto *produtos, int quantidadeProdutos)
{
    int opcao;
    do
    {
        printf("Tecle enter\n");
        getchar();
        system("cls");

        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Produtos\n");
        printf("2. Vendas\n");
        printf("3. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        limpaBuffer();

        switch (opcao)
        {
        case 1:
            exibirMenuProdutos(&produtos, &quantidadeProdutos);
            break;
        case 2:
            exibirMenuVendas(produtos, quantidadeProdutos);
            break;
        case 3:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 3);
}
