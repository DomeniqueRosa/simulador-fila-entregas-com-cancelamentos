#include "PEDIDO_H"
#include <stdbool.h>

/* Inicializa a fila vazia */
void fila_inicializar(FilaPedidos *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

/* Verifica se a fila está cheia */
bool fila_cheia(const FilaPedidos *f)
{
    return f->tamanho == MAX_PEDIDOS;
}

/* Insere um pedido na fila circular */
/* Retorna true se inseriu, false se cheia */
bool fila_inserir(FilaPedidos *f, const Pedido *novo)
{
    if (fila_cheia(f))
        return false;

    f->pedidos[f->fim] = *novo;               // copia o pedido para a posição fim
    f->fim = (f->fim + 1) % MAX_PEDIDOS;      // avança índice fim circularmente
    f->tamanho++;                             // incrementa tamanho da fila
    return true;
}