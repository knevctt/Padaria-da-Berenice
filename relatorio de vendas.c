#include "header.h"

// Função para exibir o relatório de vendas
void relatorioVendas(Produto *produtos, int quantidadeProdutos)
{
    FILE *arquivo = fopen("vendas.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de vendas!\n");
    }
    else
    {
        printf("=== RELATORIO DE VENDAS ===\n");

        float valorTotal = 0;
        unsigned long long codigo;
        int quantidade, dia, mes, ano;
        char linha[100];  // Variável para armazenar cada linha do arquivo

        while (fgets(linha, sizeof(linha), arquivo) != NULL)
        {
            if (sscanf(linha, "codigo: %llu", &codigo) == 1)
            {
                fgets(linha, sizeof(linha), arquivo);  // Lê a próxima linha contendo a quantidade
                sscanf(linha, "quantidade: %d", &quantidade);

                fgets(linha, sizeof(linha), arquivo);  // Lê a próxima linha contendo o valor total
                sscanf(linha, "valor total:%f", &valorTotal);
                valorTotal += valorTotal; // Somar o valor total da venda atual

                fgets(linha, sizeof(linha), arquivo);  // Lê a próxima linha contendo a data da venda
                sscanf(linha, "data da venda:%d/%d/%d", &dia, &mes, &ano);

                Produto *produtoVendido = NULL;
                for (int i = 0; i < quantidadeProdutos; i++)
                {
                    if (produtos[i].codigo == codigo)
                    {
                        produtoVendido = &(produtos[i]);
                        break;
                    }
                }

                if (produtoVendido != NULL)
                {
                    printf("Produto: %s | Quantidade: %d | Valor Total: R$ %.2f | Data: %02d/%02d/%d\n",
                           produtoVendido->nome, quantidade, valorTotal, dia, mes, ano);
                }
            }
        }

        fclose(arquivo);
        printf("Valor total das vendas: R$ %.2f\n", valorTotal);
    }
}
