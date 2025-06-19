#include <stdio.h>
#include "cancelamento.h"
#include "entregas.h"  // Para manipular a fila de entregas

#define MAX_PEDIDOS 10  // Definindo o tamanho máximo da pilha



// Função para cancelar um pedido e movê-lo para a pilha de cancelamentos
void cancelarPedido(int codigo) {
    for (int i = filaEntregas.inicio; i != filaEntregas.fim; i = (i + 1) % MAX_PEDIDOS) {
        if (filaEntregas.pedidos[i].codigo == codigo) {
            // Adiciona o pedido à pilha de cancelamentos
            pilhaCancelamentos.pedidos[++pilhaCancelamentos.topo] = filaEntregas.pedidos[i];

            // Remove o pedido da fila, movendo os seguintes pedidos uma posição para trás
            for (int j = i; j != filaEntregas.fim; j = (j + 1) % MAX_PEDIDOS) {
                filaEntregas.pedidos[j] = filaEntregas.pedidos[(j + 1) % MAX_PEDIDOS];
            }
            filaEntregas.fim = (filaEntregas.fim - 1 + MAX_PEDIDOS) % MAX_PEDIDOS;
            filaEntregas.tamanho--;
            printf("Pedido %d cancelado.\n", codigo);
            return;
        }
    }
    printf("Erro: Pedido %d não encontrado.\n", codigo);
}

// Função para exibir os pedidos cancelados
void exibirPedidosCancelados() {
    if (pilhaCancelamentos.topo == -1) {
        printf("Não há pedidos cancelados.\n");
        return;
    }

    printf("Pedidos cancelados:\n");
    for (int i = 0; i <= pilhaCancelamentos.topo; i++) {
        printf("Código: %d, Cliente: %s, Produto: %s, Valor: %.2f\n",
               pilhaCancelamentos.pedidos[i].codigo,
               pilhaCancelamentos.pedidos[i].cliente,
               pilhaCancelamentos.pedidos[i].produto,
               pilhaCancelamentos.pedidos[i].valor);
    }
}
