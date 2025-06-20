#ifndef cancelamento_h
#define cancelamento_h
#include "../pedidos/pedidos.h"

typedef struct No {
    Pedido dado;           // Valor armazenado no nó
    struct No* proximo; // Ponteiro para o próximo nó 
} No;

typedef struct {
    No* topo;      // Ponteiro para o nó do topo
    int tamanho;   
} Pilha;

// Funções para gerenciar cancelamentos
Pilha* inicializar_pilha();
int cancelar_pedido(Fila *fila, Pilha *pilha);
void exibir_pedidos_cancelados(Pilha *pilha);
int push_pilha(Pilha* pilha, Pedido pedido);

#endif

