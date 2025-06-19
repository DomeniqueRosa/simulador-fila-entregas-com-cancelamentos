#include pedidos_h
#include <stdbool.h>

<<<<<<< HEAD
// Definição da fila de pedidos
#define MAX_PEDIDOS 10

/* Função para inicializar e retornar uma fila vazia */
FilaPedidos fila_inicializar()
=======
// Definição da fila de pedidos
#define MAX_PEDIDOS 10;

/* Função para inicializar e retornar uma fila vazia */
FilaPedidos fila_inicializar()
>>>>>>> 6e93971efc379efbbeb510ae05a9a428307527db
{
    FilaPedidos f;
    f.inicio = 0;
    f.fim = 0;
    f.tamanho = 0;
    return f;
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

// Função para cadastrar um novo pedido
void cadastrarPedido(FilaPedidos *fila, int codigo, const char* cliente, const char* produto, float valor) {
    Pedido pedido;
    pedido.codigo = codigo;
    strcpy(pedido.cliente, cliente);
    strcpy(pedido.produto, produto);
    pedido.valor = valor;
    
    // Inserir o pedido na fila de entregas
    fila_inserir(fila, &pedido);
    printf("Pedido %d cadastrado e inserido na fila.\n", pedido.codigo);
}
