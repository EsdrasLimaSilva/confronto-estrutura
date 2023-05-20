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

/* Retorna o elemento do topo retirando-o da pilha. Caso a operação seja inválida (como pilha vazia por exemplo), retorna -1 */
int pop(Torre *pTorre);

/* Adiciona um elemento no topo da pilha de elementos. Se a operação for bem sucedia, retorna o prórprio elemento.
Caso contrário retorna o seguinte:

- Pilha cheia:  -1
- Elemento maior que o topo: -2
*/
int push(int elemento, Torre *pTorre);

#endif
