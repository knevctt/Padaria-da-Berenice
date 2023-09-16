#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Função para limpar o buffer do teclado
void limpaBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
