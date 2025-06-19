#ifndef cancelamento_h
#define cancelamento_h

#include "./pedidos/pedidos.h"

#define MAX_CANCELADOS 100  

typedef struct {
    Pedido pedidos[MAX_CANCELADOS];
    int topo;
} Pilha;

// Funções para gerenciar cancelamentos
Pilha inicializar_pilha();
int cancelar_pedido(Fila *fila, PilhaCancelados *pilha);
void exibir_pedidos_cancelados(Pilha *pilha);

#endif

