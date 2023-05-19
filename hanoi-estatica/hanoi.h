#ifndef HANOI_C
#define HANOI_C

/* Estrutura que contém toda a lógica do jogo, como o número de jogadas */
typedef struct hanoi Hanoi;

/* cria a estrutura do jogo e retorna um ponteiro para ela */
Hanoi *criarJogo(void);

/* Mostra os topos de cada torre e asteriscos para as demais peças */
void mostrarJogo(Hanoi *pHanoi);

#endif
