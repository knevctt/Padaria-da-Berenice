#include "header.h"

float totalComDesconto = 0.0;  // Variável global para armazenar o total com desconto de todas as compras

// Função para realizar uma venda
void realizarVenda(Produto *produtos, int quantidadeProdutos)
{
    char resposta;
    int numProdutosVendidos = 0;
    Produto produtosVendidos[quantidadeProdutos];
    int quantidadesVendidas[quantidadeProdutos];

    do
    {
        if (quantidadeProdutos == 0)
        {
            printf("Nenhum produto cadastrado!\n");
            return;
        }

        unsigned long long codigo;

        printf("=== PRODUTOS ===\n");
        for (int i = 0; i < quantidadeProdutos; i++)
        {
            printf("Codigo: %llu | Nome: %s | Valor: R$ %.2f | Estoque: %d\n",
                   produtos[i].codigo, produtos[i].nome, produtos[i].valor, produtos[i].estoque);
        }

        printf("Digite o codigo do produto a ser vendido: ");
        scanf("%llu", &codigo);
        limpaBuffer();

        int indice = -1;
        for (int i = 0; i < quantidadeProdutos; i++)
        {
            if (produtos[i].codigo == codigo)
            {
                indice = i;
                break;
            }
        }

        if (indice == -1)
        {
            printf("Produto nao encontrado!\n");
        }
        else
        {
            Produto *produtoVendido = &(produtos[indice]);

            int quantidade;
            printf("Digite a quantidade vendida: ");
            scanf("%d", &quantidade);
            limpaBuffer();

            if (quantidade > produtoVendido->estoque || quantidade < 0)
            {
                printf("Estoque insuficiente!\n");
                continue;
            }
            else
            {
                produtoVendido->estoque -= quantidade;
                float valorTotal = produtoVendido->valor * quantidade;

                printf("Produto selecionado com sucesso!\n");
                printf("Produto: %s | Quantidade: %d | Valor Total: R$ %.2f\n", produtoVendido->nome, quantidade,
                       valorTotal);

                float valorFinal;

                // Opções de pagamento
                int opcao;
                do
                {
                    printf("\n=== OPCOES DE PAGAMENTO ===\n");
                    printf("1. A vista\n");
                    printf("2. A prazo\n");
                    printf("Digite a opcao desejada: ");
                    scanf("%d", &opcao);
                    limpaBuffer();

                    switch (opcao)
                    {
                        case 1:
                        {
                            float valorComDesconto;
                            if (valorTotal <= 50)
                            {
                                valorComDesconto = valorTotal - (valorTotal * 0.05);
                            }
                            else if (valorTotal > 50 && valorTotal < 100)
                            {
                                valorComDesconto = valorTotal - (valorTotal * 0.1);
                            }
                            else
                            {
                                valorComDesconto = valorTotal - (valorTotal * 0.18);
                            }
                            printf("Valor com desconto: R$ %.2f\n", valorComDesconto);
                            valorFinal = valorComDesconto;
                            totalComDesconto += valorComDesconto;  // Adiciona o valor com desconto ao total
                            break;
                        }
                        case 2:
                        {
                            int parcelas;
                            printf("Digite o numero de parcelas: ");
                            scanf("%d%*c", &parcelas);

                            if (parcelas < 1)
                            {
                                printf("Numero de parcelas invalido, digite um valor igual ou acima de 1 parcela.\n");
                                break;
                            }

                            float valorComAcrescimo;
                            if (parcelas <= 3)
                            {
                                valorComAcrescimo = valorTotal + (valorTotal * 0.05);
                            }
                            else
                            {
                                valorComAcrescimo = valorTotal + (valorTotal * 0.08);
                            }
                            printf("Valor com acrescimo: R$ %.2f\n", valorComAcrescimo);
                            valorFinal = valorComAcrescimo;

                            // Registro da venda
                            registrarVenda(produtoVendido->codigo, quantidade, valorFinal);
                            break;
                        }
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                } while (opcao != 1 && opcao != 2);

                // Adicionar produto vendido e quantidade aos arrays correspondentes
                produtosVendidos[numProdutosVendidos] = *produtoVendido;
                quantidadesVendidas[numProdutosVendidos] = quantidade;
                numProdutosVendidos++;

                // Troco
                char opcaoTroco;
                printf("O clente deseja troco? (S/N): ");
                scanf(" %c", &opcaoTroco);
                limpaBuffer();

                if (opcaoTroco == 'S' || opcaoTroco == 's')
                {
                    float valorTroco;
                    printf("Digite o valor para troco: ");
                    scanf("%f", &valorTroco);
                    limpaBuffer();

                    float troco = valorTroco - valorFinal;
                    printf("Troco: R$ %.2f\n", troco);
                }

                // Verifica se o usuário deseja fazer outra compra
                printf("Deseja fazer outra compra? (S/N): ");
                scanf(" %c", &resposta);
                limpaBuffer();
            }
        }
    } while (resposta == 'S' || resposta == 's');

    if (numProdutosVendidos > 0)
    {
        gerarNotaFiscal(produtosVendidos, quantidadesVendidas, numProdutosVendidos, totalComDesconto);
        totalComDesconto = 0.0;
    }
}

void gerarNotaFiscal(Produto *produtosVendidos, int *quantidadesVendidas, int numProdutos, float totalComDesconto)
{
    printf("\n=== NOTA FISCAL ===\n");
    printf("Item | Produto                 | Valor Unitario(R$) | Quantidade | Sub-Total(R$)\n");
    printf("------------------------------------------------------------------------------\n");

    float valorTotal = 0.0;

    for (int i = 0; i < numProdutos; i++)
    {
        Produto *produto = &produtosVendidos[i];
        int quantidade = quantidadesVendidas[i];
        float valorUnitario = produto->valor;
        float subtotal = valorUnitario * quantidade;
        valorTotal += subtotal;

        printf("%-4d | %-24s | %-18.2f | %-10d | %-12.2f\n",
               i + 1, produto->nome, valorUnitario, quantidade, subtotal);
    }

    printf("------------------------------------------------------------------------------\n");
    printf("Valor Total da Compra:              R$ %.2f\n", valorTotal);
    printf("Valor Total com Desconto:           R$ %.2f\n", totalComDesconto);
}
