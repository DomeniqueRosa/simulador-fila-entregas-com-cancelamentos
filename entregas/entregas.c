#include <stdio.h>
#include "entregas.h"

int realizar_entrega(Fila *fila, Estatisticas *est) {
    
    //antes de remover verifica se a fila esta vazia
    if(fila->inicio = 0 || fila->tamanho == 0){
        printf("Nao existe pedido para entregar");
        return 0;
    }

    //salva pedido na variavel para mostrar qual pedido foi removido
    Pedido pedido = fila->dados[fila->inicio];

    //avança para perder o primeiro
    fila->inicio = (fila->inicio + 1) % MAX_PEDIDOS;
    fila->tamanho--; 

    // Atualizando as estatísticas
    est->pedidos_entregues++;
    est->valor_entregues += pedido.valorEstimado;

    //mostro o pedido entregue
    printf("Pedido com produto %s foi entregue!\n", pedido.produto);  

    return 1; // deu certo

}

void gerar_estatisticas(Estatisticas *est) {
    printf("Total de pedidos entregues: %d\n", est->pedidos_entregues);
    printf("Valor total das entregas realizadas: %.2f\n", est->valor_entregues);
}
