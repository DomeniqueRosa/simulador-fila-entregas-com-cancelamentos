# simulador-fila-entregas-com-cancelamentos

Uma empresa de entregas recebe pedidos de clientes via aplicativo. Os pedidos entram automaticamente em uma fila de entregas por ordem de chegada. No entanto, alguns clientes cancelam o pedido antes da entrega. Nesse caso, o pedido é retirado da fila e armazenado em uma pilha de cancelamentos.

Ao final do expediente, o sistema deve gerar:

· Relatório dos pedidos entregues

· Lista dos pedidos cancelados

· Estatísticas gerais de desempenho

Regras e Restrições Didáticas

### Cada grupo deverá entregar um diário de bordo com relatos semanais do processo de desenvolvimento, contendo:

· Quem fez o quê (responsabilidade individual)

· Dificuldades encontradas e como foram resolvidas

· Trechos de código explicados em suas palavras

### Cada membro do grupo apresentará oralmente ao professor (ou banca) uma das funções implementadas, explicando:

· A lógica por trás da função

· Como a estrutura de fila foi usada

· Por que essa estrutura foi a mais adequada

O código deve conter um comentário de autoria no topo de cada função, com nome do responsável e descrição funcional.

Funcionalidades Mínimas Obrigatórias

ok - 1. Cadastrar novo pedido (cliente, código do pedido, produto, valor estimado)

ok - 2. Inserir pedido na fila de entregas (fila circular)

ok - 3. Cancelar pedido, retirando-o da fila e movendo para a pilha de cancelamentos

ok - 4. Realizar entrega do próximo pedido da fila

ok - 5. Listar pedidos na fila

ok - 6. Exibir pedidos cancelados

7. Gerar estatísticas finais:

a. Total de pedidos entregues e cancelados

ok - b. Valor total das entregas realizadas

c. Valor total dos pedidos cancelados
