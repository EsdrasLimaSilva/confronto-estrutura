#include <stdio.h>
#include <stdlib.h>

#include "processo.h"
#include "fila.h"

struct nodo
{
    Processo *pProcesso;
    Nodo *pProximo;
};

struct fila
{
    Nodo *pHead;
};

Fila *criarFila()
{
    Fila *pFila = (Fila *)malloc(sizeof(Fila));
    if (!pFila)
        return NULL;

    pFila->pHead = NULL;

    return pFila;
}

int inserir(Processo *pProcesso, Fila *pFila)
{
    if (!pProcesso || !pFila)
        return 0;

    Nodo *pNodo = (Nodo *)malloc(sizeof(Nodo));
    if (!pNodo)
        exit(EXIT_FAILURE);

    pNodo->pProximo = NULL;
    pNodo->pProcesso = pProcesso;

    if (!pFila->pHead)
    { // lista vazia

        pFila->pHead = pNodo;
        return 1;
    }

    // inserindo o nodo no fim da fila
    Nodo *pAux = pFila->pHead;
    while (pAux->pProximo)
        pAux = pAux->pProximo;

    pAux->pProximo = pNodo;
    return 1;
}

void remover(Fila *pFila){

    Nodo *aux = pFila->pHead;
    pFila -> pHead  = pFila -> pHead -> pProximo;

    free(aux);
    
}

void mostrarFila(Nodo *pNodo)
{
    if (pNodo)
        mostrarProcesso(pNodo->pProcesso);

    if (pNodo->pProximo)
        mostrarFila(pNodo->pProximo);
}

Nodo *pegarHead(Fila *pFila)
{
    return pFila->pHead;
}
