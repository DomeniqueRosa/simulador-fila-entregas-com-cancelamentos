#ifndef PEDIDO_H
#define PEDIDO_H

#define maxNome 100
#define maxCPF 12
#define maxTel 20


//Estrutura que representa os dados de um cliente
typedef struct {
  char nome[maxNome];
  char CPF[maxCPF];
  char telefone[maxTel]
} Cliente;

//Estrutura que representa os dados de um pedido
typedef struct {
    Cliente cliente;
    int codigoPedido;
    char produto[100];
    float valorEstimado;
} Pedido;

//definir tipo fila e prototicos das funcoes
typedef struct {
    Pedido pedidos[MAX_PEDIDOS];
    int inicio;
    int fim;
    int tamanho;
} FilaPedidos;

/* Protótipos das funções da fila */
void fila_inicializar(FilaPedidos *f);
bool fila_cheia(const FilaPedidos *f);
bool fila_inserir(FilaPedidos *f, const Pedido *novo);

#endif