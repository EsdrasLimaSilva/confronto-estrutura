#ifndef TORRE_H
#define TORRE_H

/* Estrutura de uma torre que contém um pilha com os elementos (peças) */
typedef struct torre Torre;

/* Retorna a peça no topo da torre. Caso o topo seja inválido, retorna -1 */
int topoTorre(Torre *pTorre);

/* Cria uma torre e retorna um ponteiro para ela */
Torre *criarTorre(int inicial);

/* Retorna 1 se a torre estiver com todas as peças, e 0 caso contrário */
int torreCompleta(Torre *pTorre);

/* Retorna o elemento do topo retirando-o da pilha. Caso a operação seja inválida (como pilha vazia por exemplo), retorna -1 */
int popTorre(Torre *pTorre);

/* Adiciona um elemento no topo da pilha de elementos. Se a operação for bem sucedia, retorna o prórprio elemento.
Caso contrário retorna o seguinte:

- Pilha cheia:  -1
- Elemento maior que o topo: -2
*/
int pushTorre(Torre *pTorre, int elemento);

/*
Retorna o a posição do topo da torre
*/
int posTopo(Torre *pTorre);

/*
Retrorna o número de peças presente na torre
*/
int pecasNaTorre(Torre *pTorre);

/* Retorna um número máximo de peças por torre */
int maximoPecas(void);

/* Retorna o valor de uma peça em uma determinada posição.  */
int valorPeca(Torre *pTorre, int pos);

#endif
