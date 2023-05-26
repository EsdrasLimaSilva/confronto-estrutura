#ifndef TORRE_h
#define TORRE_h

/* estrutura da torre */
typedef struct torre Torre;

/* cria uma torre e retorna um ponteiro. Se ela for a torre inicial, todas as peças são colocadas */
Torre *criarTorre(int inicial);

/* adiciona uma peça da torre */
int pushTorre(Torre *pTorre, int elemento);

/* remove uma peça da torre */
int popTorre(Torre *pTorre);

/* retorna o elemento do topo */
int topoTorre(Torre *pTorre);

/* retorna a posição do topo */
int posTopo(Torre *pTorre);

/* retorna o número máximo de peças por torre */
int maximoPecas();

/* verifica se uma torre está completa */
int torreCompleta(Torre *pTorre);

#endif
