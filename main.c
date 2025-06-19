#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./pedidos/pedidos.h"



int main() {
    // Inicializa a fila e a armazenar na variavel fila
    FilaPedidos* fila = fila_inicializar();

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

    // Listar pedidos na fila
    listar_pedidos_fila(fila);

    // Verificar se a fila está cheia
    if (fila_cheia(fila)) {
        printf("\nA fila está cheia!\n");
    } else {
        printf("\nA fila não está cheia.\n");
    }

}