#include "pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar strcpy

/* Função para inicializar e retornar uma fila vazia */
FilaPedidos* fila_inicializar()
{
    FilaPedidos* nova_fila = (FilaPedidos*)malloc(sizeof(FilaPedidos));
    if (nova_fila != NULL) {
        nova_fila->inicio = NULL;
        nova_fila->fim = NULL;
        nova_fila->tamanho = 0;
    }
    return nova_fila;
}

/* Insere um pedido na fila circular */
/* Retorna true se inseriu, false se cheia */
bool fila_inserir(FilaPedidos* fila, Pedido* novo)
{
    if (fila == NULL) return false;

    // Cria um novo nó
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) return false;  // Falha na alocação de memória

    novo_no->dado = *novo;     
    novo_no->proximo = NULL;   

    if (fila->fim != NULL) {
        fila->fim->proximo = novo_no;  // Faz o ponteiro do último nó apontar para o novo nó
    }

    fila->fim = novo_no;    // O novo nó agora é o fim da fila

    if (fila->inicio == NULL) {  // Se a fila estava vazia, o novo nó é também o início
        fila->inicio = novo_no;
    }

    fila->tamanho++;
    return true;
}

// Função para cadastrar um novo pedid
void cadastrar_pedido(FilaPedidos* fila, Cliente* cliente,  int codigo_prod, char* produto, float valor) {
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
void listar_pedidos_fila(FilaPedidos* fila) {
      if (fila == NULL || fila->inicio == NULL) {
        printf("Fila vazia\n");
        return;
    }

    No* atual = fila->inicio;
    printf("Pedidos na fila:\n");

    while (atual != NULL) {
        Pedido p = atual->dado;
        printf("Pedido %d: %s - %s - R$%.2f\n", 
               p.codigoPedido, 
               p.cliente.nome, 
               p.produto, 
               p.valorEstimado);
        atual = atual->proximo;  // Avança para o próximo nó
    }
}