#ifndef HANOI_C
#define HANOI_C
#include "torre.h"

/* Estrutura que contém toda a lógica do jogo, como o número de jogadas */
typedef struct hanoi Hanoi;

/* cria a estrutura do jogo e retorna um ponteiro para ela */
Hanoi *criarJogo(void);

/* Mostra os topos de cada torre e asteriscos para as demais peças */
void mostrarJogo(Hanoi *pHanoi);

/* Move uma peça de uma torre de origem para uma torre destino se o movimento for válido */
int moverPeca(Hanoi *pHanoi, Torre *origem, Torre *destino);

/* Retorna uma torre de determinado número */
Torre *pegarTorre(Hanoi *pHanoi, int num);

/* retorna o número de jogadas */
int numeroJogadas(Hanoi *pHanoi);

#endif
