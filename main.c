#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./pedidos/pedidos.h"
#include "./entregas/entregas.h"
int main() {
    // Inicializa a fila e a armazenar na variavel fila
    Fila* fila = fila_inicializar();


    listar_pedidos_fila(fila);
    // Verificar se a fila foi inicializada corretamente
    if (fila == NULL) {
        printf("Falha ao inicializar a fila.\n");
        return 1;
    }
    printf("Fila inicializada com sucesso!\n");

    // Criar clientes
    Cliente clienteA = {"Cliente A", "12345678901", "111-222-3333"};
    Cliente clienteB = {"Cliente B", "12345678902", "444-555-6666"};
    Cliente clienteC = {"Cliente C", "12345678903", "777-888-9999"};

    // Cadastrar pedidos
    printf("\nCadastrando pedidos...\n");
    cadastrar_pedido(fila, &clienteA, 1,"Produto X", 100.50);
    cadastrar_pedido(fila, &clienteB, 2,"Produto Y", 200.75);
    cadastrar_pedido(fila, &clienteC, 3,"Produto Z", 150.00);

    // Exibir pedidos na fila antes da entrega
    printf("\nPedidos na fila antes da entrega:\n");
    // Listar pedidos na fila
    listar_pedidos_fila(fila);

    Estatisticas est = {0, 0.0};

    // Realizar entrega de um pedido (remover o primeiro pedido da fila)
    printf("\nRealizando entrega do primeiro pedido...\n");
    int resultado = realizar_entrega(fila, &est);
    
    if (resultado) {
        printf("\nEntrega realizada com sucesso!\n");
    } else {
        printf("\nFalha ao realizar a entrega.\n");
    }

    // Exibir estatísticas após a entrega
    printf("\nEstatísticas após a entrega:\n");
    printf("Pedidos entregues: %d\n", est.pedidos_entregues);
    printf("Valor total das entregas: %.2f\n", est.valor_entregues);

    // Exibir pedidos na fila após a entrega
    printf("\nPedidos na fila após a entrega:\n");
    listar_pedidos_fila(fila);

    return 0;

}