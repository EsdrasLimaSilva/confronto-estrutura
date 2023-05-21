#include <stdlib.h>

#include "pilha.h"

struct peca
{
    int valor;
    struct peca *abaixo;
};

struct pilha
{
    Peca *pTop;
};

Pilha *criarPilha(void)
{
    Pilha *pPilha = (Pilha *)malloc(sizeof(Pilha));
    pPilha->pTop = NULL;
}

int topo(Pilha *pPilha)
{
    return pegarValor(pPilha->pTop);
};

int pop(Pilha *pPilha)
{
    Peca *pAux = pPilha->pTop;
    int num = pAux->valor;
    pPilha->pTop = pAux->abaixo;

    free(pAux);

    return num;
}

void push(Pilha *pPilha, int valor)
{
    Peca *pPeca = (Peca *)malloc(sizeof(Peca));
    if (!pPeca)
        exit(EXIT_FAILURE);

    pPeca->valor = valor;
    pPeca->abaixo = NULL;

    if (pPilha->pTop) // se a pilha não estiver vazia
        pPeca->abaixo = pPilha->pTop->abaixo;
    else // se a pilha estiver vazia
        pPilha->pTop = pPeca;
}