#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdint.h>  // Para utilizar o tipo de dado uint64_t
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição da estrutura do Produto
typedef struct Produto
{
    uint64_t codigo;
    char nome[25];
    float valor;
    int estoque;
    struct Produto *prox; // Próximo nó da lista encadeada
} Produto;


void exibirMenuPrincipal(Produto **produtos, int *quantidadeProdutos);
void exibirProdutos(Produto *produtos);
void registrarVenda(unsigned long long codigo, int quantidade, float valorTotal);
void exibirMenuProdutos(Produto **produtos, int *quantidadeProdutos);
void exibirMenuVendas(Produto *produtos, int quantidadeProdutos);
void cadastrarProduto(Produto **produtos, int *quantidadeProdutos);
void atualizarProduto(Produto *produtos, int quantidadeProdutos);
void excluirProduto(Produto **produtos, int *quantidadeProdutos);
void salvarProdutos(Produto *produtos, int quantidadeProdutos);
void lerProdutos(Produto **produtos, int *quantidadeProdutos);
void realizarVenda(Produto *produtos, int quantidadeProdutos);
void relatorioVendas(Produto *produtos, int quantidadeProdutos);
void gerarNotaFiscal(Produto *produtosVendidos, int *quantidadesVendidas, int numProdutos, float totalComDesconto);
void limpaBuffer();

#endif // HEADER_H_INCLUDED
