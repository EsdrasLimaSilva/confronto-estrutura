#ifndef LISTA_H
#define LISTA_H

#include "processo.h"

/* estrutura do tipo lista */
typedef struct fila Fila;

/* estrutura do tipo nodo */
typedef struct nodo Nodo;

/* cria uma fila e retorna um ponteiro para ela */
Fila *criarFila();

/* Insere um elemento no fim da fila. retorna um se foi bem sucedido */
int inserir(Processo *pProcesso, Fila *pFila);

void remover(Fila *pFila);

/* Mostra todos os elementos da fila */
void mostrarFila(Nodo *pNodo);

/* Retorna a Head da fila */
Nodo *pegarHead(Fila *pFila);

#endif