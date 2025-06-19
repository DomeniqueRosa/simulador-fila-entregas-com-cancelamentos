#include <stdio.h>
#include "pedidos.h"
#include "entregas.h"
#include "cancelamento.h"

int main() {
    // Inicializa a fila e a armazena em uma variável
    FilaPedidos fila = fila_inicializar();

    // Cadastrar alguns pedidos
    cadastrarPedido(&fila, 1, "Cliente A", "Produto X", 100.50);
    cadastrarPedido(&fila, 2, "Cliente B", "Produto Y", 200.75);
    cadastrarPedido(&fila, 3, "Cliente C", "Produto Z", 150.00);

    // Listar pedidos na fila
    listarPedidosFila(&fila);

    // Realizar entrega de um pedido
    realizarEntrega(&fila);

    // Cancelar um pedido
    cancelarPedido(&fila, 2);

    // Listar pedidos cancelados
    exibirPedidosCancelados();

    // Gerar estatísticas
    gerarEstatisticas();

    return 0;
}
