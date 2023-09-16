#include "header.h"

// Função para registrar uma venda no arquivo de vendas
void registrarVenda(unsigned long long codigo, int quantidade, float valorTotal)
{
    FILE *arquivo = fopen("vendas.txt", "a");

     if (arquivo == NULL) {
         printf("Erro ao abrir o arquivo de vendas!\n");
     } else {
         time_t now = time(NULL);
         struct tm *data = localtime(&now);
         fprintf(arquivo, "codigo: %llu\nquantidade: %d\nvalor total:%.2f\ndata da venda:%02d/%02d/%d\n\n", codigo, quantidade, valorTotal,
                data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);

    fclose(arquivo);
    }
}
