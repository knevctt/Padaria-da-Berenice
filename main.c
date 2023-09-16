#include "header.h"

int main()
{
    int quantidadeProdutos = 0;
    Produto *produtos = NULL;

    lerProdutos(&produtos, &quantidadeProdutos);

    exibirMenuPrincipal(produtos, quantidadeProdutos);

    exibirMenuProdutos(&produtos, &quantidadeProdutos);

    salvarProdutos(produtos, quantidadeProdutos);

    // Libera a memória alocada para os produtos
    Produto *atual = produtos;
    while (atual != NULL)
    {
        Produto *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    return 0;
}
