#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

struct peca
{
    int valor;
    struct peca *pAbaixo;
};

struct pilha
{
    Peca *pTop;
};

Pilha *criarPilha(void)
{
    Pilha *pPilha = (Pilha *)malloc(sizeof(Pilha));
    if (!pPilha)
        exit(EXIT_FAILURE);

    pPilha->pTop = NULL;
    return pPilha;
}

int topo(Pilha *pPilha)
{
    return pPilha->pTop->valor;
}

int pop(Pilha *pPilha)
{
    Peca *pAux = pPilha->pTop;
    if (!pAux)
        return -1;

    int num = pAux->valor;

    pPilha->pTop = pAux->pAbaixo;

    // free(pAux);

    return num;
}

void push(Pilha *pPilha, int valor)
{
    Peca *pPeca = (Peca *)malloc(sizeof(Peca));
    if (!pPeca)
        exit(EXIT_FAILURE);

    pPeca->valor = valor;
    pPeca->pAbaixo = NULL;

    if (pPilha->pTop) // se a pilha não estiver vazia
        pPeca->pAbaixo = pPilha->pTop;

    pPilha->pTop = pPeca;
}
