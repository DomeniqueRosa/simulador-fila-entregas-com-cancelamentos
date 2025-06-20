#include "pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar strcpy

/* Função para inicializar e retornar uma fila vazia */
Fila* fila_inicializar()
{
    Fila* nova_fila = (Fila*)malloc(sizeof(Fila));
    if (nova_fila != NULL) {
        nova_fila->inicio = 0;
        nova_fila->fim = -1;
        nova_fila->tamanho = 0;
    }
    return nova_fila;
}

/* Insere um pedido na fila circular */
/* Retorna true se inseriu, false se cheia */
bool fila_inserir(Fila* fila, Pedido* novo)
{
    if (fila == NULL || fila->tamanho >= MAX_PEDIDOS) return false;
  
    fila->fim = (fila->fim + 1) % MAX_PEDIDOS;
    fila->dados[fila->fim] = *novo;
    fila->tamanho++;

    return true;
}

// Função para cadastrar um novo pedid
void cadastrar_pedido(Fila* fila, Cliente* cliente,  int codigo_prod, char* produto, float valor) {
    Pedido pedido;
    pedido.codigoPedido = codigo_prod;  // Corrigido para 'codigoPedido'
    pedido.valorEstimado = valor;  // Corrigido para 'valorEstimado'
    
    // Copiar os dados do cliente para o pedido
    strcpy(pedido.cliente.nome, cliente->nome);
    strcpy(pedido.cliente.CPF, cliente->CPF);
    strcpy(pedido.cliente.telefone, cliente->telefone);
    
    // Copiar o nome do produto para o pedido
    strcpy(pedido.produto, produto);
    
    // Inserir o pedido na fila de entregas
    fila_inserir(fila, &pedido);
    printf("Pedido %d cadastrado e inserido na fila.\n", pedido.codigoPedido);
}

// Função para listar pedidos na fila
void listar_pedidos_fila(Fila* fila) {

    if(fila->tamanho == 0){
        printf("fila vazia\n");
        return;
    }
    
    for(int i = 0; i < fila->tamanho; i++){
        // Acessando o pedido na posição circular
        Pedido p = fila->dados[(fila->inicio + i) % MAX_PEDIDOS];
        
        // Imprimindo os dados do pedido
        printf("Pedido %d: %s - %s - R$%.2f\n", 
               p.codigoPedido, 
               p.cliente.nome, 
               p.produto, 
               p.valorEstimado);
    }
    
}

Pedido* fila_remover(Fila* fila){
    if(fila->inicio == 0 || fila->tamanho == 0){
        printf("Não existe pedido para cancelar.\n");
        return NULL;
    }

    Pedido* pedido = &fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_PEDIDOS;
    fila->tamanho--;

    return pedido;
}