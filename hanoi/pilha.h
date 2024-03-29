#ifndef PILHA_H
#define PILHA_H

/* Estrutura da pilha */
typedef struct pilha Pilha;

/* Estrutura de cada peça */
typedef struct peca Peca;

/*Cria uma estrutura do tipo pilha*/
Pilha *criarPilha(void);

/* Retorna o ponteiro para o topo da pilha*/
Peca *ponteiroTopo(Pilha *pPilha);

/* Retorna a peça imediatamente inferior */
Peca *abaixo(Peca *pPeca);

/* Pega o valor de uma determinada peça */
int pegarValor(Peca *pPeca);

/* retorna o valor do topo da pilha sem removê-lo da pilha */
int topo(Pilha *pPilha);

/* retorna o valor do topo da pilha removendo-o da pilha*/
int pop(Pilha *pPilha);

/* Adicona um valor à pilha, criando uma peça para o mesmo */
void push(Pilha *pPilha, int valor);

#endif
