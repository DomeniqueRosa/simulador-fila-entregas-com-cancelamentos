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

typedef struct {
    int pedidos_cancelados;
    float valor_cancelados;
} Estatisticas_Cancelados;

// Funções para gerenciar cancelamentos
Pilha* inicializar_pilha();
int cancelar_pedido(Fila *fila, Pilha *pilha, Estatisticas_Cancelados *est);
void exibir_pedidos_cancelados(Pilha *pilha);
int push_pilha(Pilha* pilha, Pedido pedido);
void gerar_estatisticas_cancelados(Estatisticas_Cancelados est);

#endif

