#ifndef HANOI_C
#define HANOI_C

#include "torre-estatica.h"

/* estrutura do jogo */
typedef struct hanoi Hanoi;

/* cria um novo jogo e retorna um ponteiro */
Hanoi *criarJogo(void);

/* Mostra todo o jogo */
void mostrarJogo(Hanoi *pHanoi);

/* move uma peça de uma torre de origem para uma torre de destino */
int moverPeca(Hanoi *pHanoi, int torreOrigem, int torreDestino);

/* recebe o número de uma torre e retorna um ponteiro pra ela */
Torre *pegarTorre(Hanoi *pHanoi, int num);

/*checa se o usuário venceu*/
int venceu(Hanoi *pHanoi);

#endif
