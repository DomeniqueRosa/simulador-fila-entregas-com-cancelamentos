#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <stdbool.h>

#define MAX_NOME 100
#define MAX_CPF 12
#define MAX_TEL 20
#define MAX_PEDIDOS 100


// Estrutura cliente
typedef struct {
    char nome[MAX_NOME];
    char CPF[MAX_CPF];
    char telefone[MAX_TEL];
} Cliente;

// Estrutura pedido
typedef struct {
    Cliente cliente;
    int codigoPedido;
    char produto[100];
    float valorEstimado;
} Pedido;

// Nó da lista ligada
typedef struct No {
    Pedido dado;           // Dados do pedido
    struct No* proximo;    // Ponteiro para o próximo nó
} No;

// Definir tipo fila e protótipos das funções
typedef struct {
     No* inicio;            // Ponteiro para o primeiro nó
    No* fim;               // Ponteiro para o último nó
    int tamanho; 
} FilaPedidos;

// Função para cadastrar um novo cliente
bool cadastrar_cliente(char* nome, char* cpf, char* telefone);

// Função para cadastrar um novo pedid
void cadastrar_pedido(FilaPedidos* fila, Cliente* cliente,  int codigo_prod, char* produto, float valor);


// Protótipos das funções da fila
FilaPedidos* fila_inicializar();
bool fila_inserir(FilaPedidos* f, Pedido* novo);
void listar_pedidos_fila(FilaPedidos* fila);

#endif
