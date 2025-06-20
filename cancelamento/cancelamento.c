#include <stdio.h>
#include <stdlib.h>
#include "cancelamento.h"
#include "../entregas/entregas.h"
#include "../pedidos/pedidos.h"


Pilha* inicializar_pilha() {
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    if(nova_pilha == NULL){
        printf("Erro ao alocar memoria para pilha, tente novamente");
        return NULL;
    }

    nova_pilha->topo = NULL;
    nova_pilha->tamanho = 0;

    return nova_pilha;
}

int cancelar_pedido(Fila* fila, Pilha *pilha) {
    //novo o proximo pedido na fila
    //chamar remover_fila para tirar o pedido
    Pedido* pedido = fila_remover(fila);

     // Verifica se o pedido foi removido com sucesso
    if (pedido == NULL) {
        printf("Erro: Não há pedidos na fila para cancelar.\n");
        return 0;  // Se não houver pedido, retorna erro
    }
   
    //chamar push na pilha para inserir pedido que sera cancelado
    if(push_pilha(pilha, *pedido) == 1){
        printf("Pedido %s inserido na pilha de cancelados.\n", pedido->produto);
    }else{
        printf("Erro: falha na alocacao de memoria.\n");
        return 0;
    }
    return 1;
}

void exibir_pedidos_cancelados(Pilha *pilha) {
    if (pilha->tamanho == 0) {
        printf("Não há pedidos cancelados.\n");
        return;
    }

    printf("Pedidos cancelados:\n");
    No* atual = pilha->topo;
    while (atual != NULL) {
        printf("Pedido: %s, Valor: %.2f\n", atual->dado.produto, atual->dado.valorEstimado);
        atual = atual->proximo;  // Move para o próximo nó
    }
    
}

int push_pilha(Pilha* pilha, Pedido pedido){
    //aloca memoria para novo nó
    No* novo = (No*)malloc(sizeof(No));

    //verifica se alocacao deu certo
    if(novo == NULL){      
        return 0;
    }

    //configurar nó 
    novo->dado = pedido;
    novo->proximo = pilha->topo;

    //atualizar o topo da pilha
    pilha->topo = novo;
    pilha->tamanho++;

    return 1; //deu certo 
}