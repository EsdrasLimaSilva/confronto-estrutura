#ifndef TORRE_h
#define TORRE_h

/* estrutura da torre */
typedef struct torre Torre;

/* cria uma torre e retorna um ponteiro. Se ela for a torre inicial, todas as peças são colocadas */
Torre *criarTorre(int inicial);

/* adiciona uma peça da torre */
int push(Torre *pTorre, int elemento);

/* remove uma peça da torre */
int pop(Torre *pTorre);

/* retorna o elemento do topo */
int top(Torre *pTorre);

/* retorna a posição do topo */
int posTop(Torre *pTorre);

/* retorna o número máximo de peças por torre */
int maximoPecas();

/* verifica se uma torre está completa */
int torreCompleta(Torre *pTorre);

#endif
