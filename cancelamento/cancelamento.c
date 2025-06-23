#include <stdio.h>
#include <stdlib.h>
#include "cancelamento.h"
#include "../entregas/entregas.h"
#include "../pedidos/pedidos.h"

// Inicializa a pilha de pedidos cancelados
Pilha* inicializar_pilha() {
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    if (nova_pilha == NULL) {
        printf("Erro ao alocar memória para a pilha. Tente novamente.\n");
        return NULL;
    }

    nova_pilha->topo = NULL;
    nova_pilha->tamanho = 0;

    return nova_pilha;
}

// Cancela o próximo pedido da fila e empilha na pilha de cancelados
int cancelar_pedido(Fila* fila, Pilha* pilha, Estatisticas_Cancelados* est) {
    if (fila == NULL || pilha == NULL || est == NULL) {
        printf("Erro: ponteiro nulo passado para cancelar_pedido.\n");
        return 0;
    }

    // Remove o próximo pedido da fila
    Pedido* pedido = fila_remover(fila);

    // Verifica se o pedido foi removido com sucesso
    if (pedido == NULL) {
        printf("Erro: Não há pedidos na fila para cancelar.\n");
        return 0;
    }

    // Atualizando as estatísticas
    est->pedidos_cancelados++;
    est->valor_cancelados += pedido->valorEstimado;

    // Inserir o pedido cancelado na pilha
    if (push_pilha(pilha, *pedido) == 1) {
        printf("Pedido %s inserido na pilha de cancelados.\n", pedido->produto);
    } else {
        printf("Erro: falha na alocação de memória.\n");
        return 0;
    }
    return 1;
}

// Exibe todos os pedidos cancelados
void exibir_pedidos_cancelados(Pilha* pilha) {
    if (pilha == NULL) {
        printf("Pilha não inicializada.\n");
        return;
    }

    if (pilha->tamanho == 0) {
        printf("Não há pedidos cancelados.\n");
        return;
    }

    printf("Pedidos cancelados:\n");
    No* atual = pilha->topo;
    while (atual != NULL) {
        printf("Pedido: %s, Valor: %.2f\n", atual->dado.produto, atual->dado.valorEstimado);
        atual = atual->proximo;
    }
}

// Insere um pedido no topo da pilha
int push_pilha(Pilha* pilha, Pedido pedido) {
    if (pilha == NULL) return 0;

    // Aloca memória para novo nó
    No* novo = (No*)malloc(sizeof(No));

    // Verifica se a alocação deu certo
    if (novo == NULL) {
        return 0;
    }

    // Configura o novo nó
    novo->dado = pedido;
    novo->proximo = pilha->topo;

    // Atualiza o topo da pilha
    pilha->topo = novo;
    pilha->tamanho++;

    return 1; // Sucesso
}

// Gera estatísticas de pedidos cancelados
void gerar_estatisticas_cancelados(Estatisticas_Cancelados est) {
    printf("Total de pedidos cancelados: %d\n", est.pedidos_cancelados);
    printf("Valor total das entregas canceladas: %.2f\n", est.valor_cancelados);
}
