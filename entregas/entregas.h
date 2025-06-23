#ifndef entregas_h
#define entregas_h

#include "../pedidos/pedidos.h"


typedef struct {
    int pedidos_entregues;
    float valor_entregues;
} Estatisticas;

// Funções para gerenciar entregas
int realizar_entrega(Fila *fila, Estatisticas *est);
void gerar_estatisticas(Estatisticas est);

#endif

