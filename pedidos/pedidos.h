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

#endif