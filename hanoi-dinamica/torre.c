#include <stdlib.h>
#include "torre.h"
#include "pilha.h"

#define PECAS_POR_TORRE 6

struct torre
{
    Pilha *pPilha;
    int pecasPresentes;
    int topo;
};

Torre *criarTorre(void)
{
    Torre *pTorre = (Torre *)malloc(sizeof(Torre));
    Pilha *pPilha = criarPilha();
    pTorre->pPilha = pPilha;

    pTorre->pecasPresentes = 0;
    pTorre->topo = -1;

    return pTorre;
}

int topoTorre(Torre *pTorre)
{
    if (pTorre->topo > -1)
        return topo(pTorre->pPilha);

    return -1;
}

void inicializarTorre(Torre *pTorre, int escolhida)
{
    for (int i = 6; i > 0; i--)
    {
        if (escolhida)
        {
            push(pTorre->pPilha, i);
            pTorre->topo++;
        }
        else
            push(pTorre->pPilha, 0);
    }
}

int popTorre(Torre *pTorre)
{

    if (pTorre->topo > -1)
    {
        int num = pop(pTorre->pPilha);
        pTorre->topo--;
        pTorre->pecasPresentes--;

        return num;
    }

    return -1;
}

int pushTorre(int elemento, Torre *pTorre)
{
    // entra se a torre estiver cheia
    if (pTorre->topo >= PECAS_POR_TORRE - 1)
        return -1;

    // entra se o a posição do topo for no mínimo zero e se o elemento for maior que o elemento no topo
    if (pTorre->topo > -1 && topo(pTorre->pPilha) < elemento)
        return -2;

    push(pTorre->pPilha, elemento);

    pTorre->topo++;
    pTorre->pecasPresentes++;

    return elemento;
}

int torreCompleta(Torre *pTorre)
{
    if (pTorre->pecasPresentes == PECAS_POR_TORRE)
        return 1;

    return 0;
}

int posTopo(Torre *pTorre)
{
    return pTorre->topo;
}

int pecasNaTorre(Torre *pTorre)
{
    return pTorre->pecasPresentes;
}

int lerPecaTorre(Torre*torre, int pos){
    Pilha* pilha = torre->pPilha;
    return lerPeca(pilha, pos);
}