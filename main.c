#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./pedidos/pedidos.h"
#include "./entregas/entregas.h"
#include "./cancelamento/cancelamento.h"

void limparTela() {
    #ifdef _WIN32 // Verifica se está compilando para Windows
        system("cls");
    #else // Assume que é Unix/Linux ou outro
        system("clear");
    #endif
}

int main() {
    
    
    Fila* fila = fila_inicializar();
    Pilha* pilha = inicializar_pilha();

    if (fila == NULL || pilha == NULL) {
        printf("Erro ao inicializar estruturas.\n");
        return 1;
    }

    Estatisticas est_entregues = {0, 0.0};
    Estatisticas_Cancelados est_cancelados = {0, 0.0};
    int pedidos_recebidos = 0;

    int opcao;
    do {
        limparTela();
        printf("\n==== MENU ====\n");
        printf("1 - Cadastrar pedido\n");
        printf("2 - Listar pedidos na fila\n");
        printf("3 - Realizar entrega\n");
        printf("4 - Cancelar pedido\n");
        printf("5 - Mostrar pedidos cancelados\n");
        printf("6 - Mostrar estatísticas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1: {
                Cliente cliente;
                int id;
                char produto[50];
                float valor;

                printf("Nome do cliente: ");
                fgets(cliente.nome, sizeof(cliente.nome), stdin);
                cliente.nome[strcspn(cliente.nome, "\n")] = 0;

                printf("CPF: ");
                fgets(cliente.CPF, sizeof(cliente.CPF), stdin);
                cliente.CPF[strcspn(cliente.CPF, "\n")] = 0;

                printf("Telefone: ");
                fgets(cliente.telefone, sizeof(cliente.telefone), stdin);
                cliente.telefone[strcspn(cliente.telefone, "\n")] = 0;

                printf("ID do pedido: ");
                scanf("%d", &id);
                getchar();

                printf("Produto: ");
                fgets(produto, sizeof(produto), stdin);
                produto[strcspn(produto, "\n")] = 0;

                printf("Valor estimado: ");
                scanf("%f", &valor);
                getchar();

                cadastrar_pedido(fila, &cliente, id, produto, valor);
                pedidos_recebidos++;
                printf("Pedido cadastrado com sucesso!\n");
                getchar();
                break;
            }
            case 2:
                listar_pedidos_fila(fila);
                getchar();
                break;
            case 3:
                if (realizar_entrega(fila, &est_entregues)) {
                    printf("Entrega realizada com sucesso.\n");
                } else {
                    printf("Não há pedidos para entregar.\n");
                }
                getchar();
                break;
            case 4:
                if (cancelar_pedido(fila, pilha, &est_cancelados)) {
                    printf("Pedido cancelado com sucesso.\n");
                } else {
                    printf("Não há pedidos para cancelar.\n");
                }
                getchar();
                break;
            case 5:
                exibir_pedidos_cancelados(pilha);
                getchar();
                break;
            case 6:
                printf("\n--- Estatísticas de Entregues ---\n");
                gerar_estatisticas(est_entregues);
                printf("\n--- Estatísticas de Cancelados ---\n");
                gerar_estatisticas_cancelados(est_cancelados);
                printf("\nTotal de pedidos recebidos: %d\n", pedidos_recebidos);
                printf("Total de pedidos em aberto: %d\n", fila->tamanho);
                getchar();
                break;
            case 0:
                printf("Clique enter para finalizar\n");
                getchar();
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                getchar();
        }
    } while (opcao != 0);

    return 0;
}
