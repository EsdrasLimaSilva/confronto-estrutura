#ifndef SISTEMA_H
#define SISTEMA_H

/* Estrutura de controle do sistema */
typedef struct sistema Sistema;

/* Inicia o sisema de controle */
Sistema *iniciarSistema();

/* Adiciona um processo na fila de processos */
void adicionarProcesso(Sistema*pSistema);

void removerProcesso(Sistema*pSistema);

/* Mostra todos os processos, e o número de processos presentes na fila de processos */
void mostrarProcessos(Sistema *pSistema);

/* Mostra todos os processos criados */
void mostrarSistema(Sistema *pSistema);

#endif