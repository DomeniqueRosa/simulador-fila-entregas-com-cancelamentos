#include <stdio.h>
#include "entregas.h"

#define MAX_PEDIDOS 10  // Definindo o tamanho máximo da fila


// Função para realizar a entrega do próximo pedido da fila
void realizarEntrega() {
    if (filaEntregas.tamanho > 0) {
        Pedido pedido = filaEntregas.pedidos[filaEntregas.inicio];
        filaEntregas.inicio = (filaEntregas.inicio + 1) % MAX_PEDIDOS;
        filaEntregas.tamanho--;
        printf("Pedido %d entregue.\n", pedido.codigo);
    } else {
        printf("Erro: Não há pedidos na fila para entregar.\n");
    }
}

// Função para listar os pedidos na fila
void listarPedidosFila() {
    if (filaEntregas.tamanho == 0) {
        printf("A fila está vazia.\n");
        return;
    }

    for (int i = filaEntregas.inicio; i != filaEntregas.fim; i = (i + 1) % MAX_PEDIDOS) {
        printf("Código: %d, Cliente: %s, Produto: %s, Valor: %.2f\n",
               filaEntregas.pedidos[i].codigo,
               filaEntregas.pedidos[i].cliente,
               filaEntregas.pedidos[i].produto,
               filaEntregas.pedidos[i].valor);
    }
}

// Função para gerar as estatísticas finais
void gerarEstatisticas() {
    int totalEntregues = 0;
    float valorEntregues = 0;

    for (int i = filaEntregas.inicio; i != filaEntregas.fim; i = (i + 1) % MAX_PEDIDOS) {
        totalEntregues++;
        valorEntregues += filaEntregas.pedidos[i].valor;
    }

    printf("Estatísticas finais:\n");
    printf("Total de pedidos entregues: %d\n", totalEntregues);
    printf("Valor total das entregas realizadas: %.2f\n", valorEntregues);
}
