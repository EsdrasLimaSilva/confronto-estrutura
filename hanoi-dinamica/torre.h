#ifndef TORRE_H
#define TORRE_H

/* Estrutura de uma torre que contém um pilha com os elementos (peças) */
typedef struct torre Torre;

/* Retorna a peça no topo da torre. Caso o topo seja inválido, retorna -1 */
int topo(Torre *pTorre);

/* Cria uma torre e retorna um ponteiro para ela */
Torre *criarTorre(void);

/* Coloca todas as peças na torre */
void inicializarTorre(Torre *pTorre);

#endif
