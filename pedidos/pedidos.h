#ifndef pedidos_h
#define pedidos_h
#include <stdbool.h>


#define maxNome 100
#define maxCPF 12
#define maxTel 20
#define MAX_PEDIDOS 10


//Estrutura que representa os dados de um cliente
typedef struct {
  char nome[maxNome];
  char CPF[maxCPF];
  char telefone[maxTel];
}Cliente;

//Estrutura que representa os dados de um pedido
typedef struct {
    Cliente cliente;
    int codigoPedido;
    char produto[100];
    float valorEstimado;
}Pedido;

//definir tipo fila e prototicos das funcoes
typedef struct {
    Pedido pedidos[MAX_PEDIDOS];
    int inicio;
    int fim;
    int tamanho;
}FilaPedidos;

<<<<<<< HEAD
// Função para cadastrar um novo pedido
void cadastrarPedido(int codigo, const char* cliente, const char* produto, float valor);

//* Protótipos das funções da fila */
void fila_inicializar(FilaPedidos *f);
=======
// Função para cadastrar um novo pedido
void cadastrarPedido(int codigo, const char* cliente, const char* produto, float valor);

//* Protótipos das funções da fila */
FilaPedidos fila_inicializar();
>>>>>>> 6e93971efc379efbbeb510ae05a9a428307527db
bool fila_cheia(const FilaPedidos *f);
bool fila_inserir(FilaPedidos *f, const Pedido *novo);

#endif