#include <stdio.h>
#include "cancelados.h"

void inicializar_pilha() {
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    if(nova_pilha == NULL){
        printf("Erro ao alocar memoria para pilha, tente novamente");
        return;
    }

    nova_pilha->topo = -1;
    return nova_pilha
}

int cancelar_pedido(Fila *fila, Pilha *pilha) {
     if (pilha->topo < MAX_CANCELADOS - 1) {
        pilha->topo++;
        pilha->pedidos[pilha->topo] = p;
        return 1;  // Sucesso
    } else {
        printf("Pilha cheia!\n");
        return 0;  // Falha
    }
}

void exibir_pedidos_cancelados(Pilha *pilha) {
    if (pilha->topo >= 0) {
        for (int i = 0; i <= pilha->topo; i++) {
            printf("Pedido cancelado %d: Cliente: %s, Produto: %s, Valor: %.2f\n", 
                   pilha->pedidos[i].codigoPedido, 
                   pilha->pedidos[i].cliente.nome, 
                   pilha->pedidos[i].produto, 
                   pilha->pedidos[i].valorEstimado);
        }
    } else {
        printf("Nenhum pedido cancelado!\n");
    }
}
