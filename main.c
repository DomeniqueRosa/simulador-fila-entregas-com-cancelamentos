#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./pedidos/pedidos.h"
#include "./entregas/entregas.h"
#include "./cancelamento/cancelamento.h"

int main() {
    // Inicializa a fila e a armazena na variável 'fila'
    Fila* fila = fila_inicializar();

    // Verificar se a fila foi inicializada corretamente
    if (fila == NULL) {
        printf("Erro: Falha ao inicializar a fila.\n");
        return 1;
    }
    printf("Sucesso: Fila de pedidos inicializada com sucesso!\n");

    // Criar clientes
    Cliente clienteA = {"Cliente A", "12345678901", "111-222-3333"};
    Cliente clienteB = {"Cliente B", "12345678902", "444-555-6666"};
    Cliente clienteC = {"Cliente C", "12345678903", "777-888-9999"};

    // Cadastrar pedidos
    printf("\nIniciando o cadastro de pedidos...\n");
    cadastrar_pedido(fila, &clienteA, 1, "Produto X", 100.50);
    cadastrar_pedido(fila, &clienteB, 2, "Produto Y", 200.75);
    cadastrar_pedido(fila, &clienteC, 3, "Produto Z", 150.00);

    // Exibir pedidos na fila antes da entrega
    printf("\nLista de pedidos na fila antes da entrega:\n");
    listar_pedidos_fila(fila);

    // Inicializa as estatísticas de entrega
    Estatisticas est = {0, 0.0};

    // Realizar entrega de um pedido (remover o primeiro pedido da fila)
    printf("\nIniciando a entrega do primeiro pedido da fila...\n");
    int resultado = realizar_entrega(fila, &est);

    if (resultado) {
        printf("\nSucesso: Pedido entregue com sucesso!\n");
    } else {
        printf("\nErro: Falha ao realizar a entrega. Nenhum pedido na fila.\n");
    }

    // Exibir estatísticas após a entrega
    printf("\nEstatísticas após a entrega:\n");
    printf("Pedidos entregues: %d\n", est.pedidos_entregues);
    printf("Valor total das entregas: %.2f\n", est.valor_entregues);

    // Exibir pedidos na fila após a entrega
    printf("\nLista de pedidos na fila após a entrega:\n");
    listar_pedidos_fila(fila);

    // Testar cancelamento de pedido
    Pilha* pilha = inicializar_pilha();

    printf("\nIniciando o cancelamento de um pedido...\n");
    cancelar_pedido(fila, pilha);

    // Mostrar lista de pedidos após o cancelamento
    printf("\nLista de pedidos na fila após o cancelamento:\n");
    listar_pedidos_fila(fila);
    printf("\n");

    // Mostrar lista de pedidos cancelados
    exibir_pedidos_cancelados(pilha);

    //mostrar lista de pedidos depois de cancelar
    printf("Lista de pedidos depois dos cancelamentos.\n\n");
    listar_pedidos_fila(fila);

    return 0;
}
