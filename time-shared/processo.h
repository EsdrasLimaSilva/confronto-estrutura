#ifndef PROCESSO_H
#define PROCESSO_H

/* Estrutura do tipo processo */
typedef struct processo Processo;

/*Cria um processo e retorna um ponteiro para ele*/
Processo * criarProcesso(char descricao[]);

/*Mostra os detalhes do processo*/
void mostrarProcesso(Processo *pProcesso);

#endif