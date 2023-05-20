#include <stdlib.h>
#include "torre.h"

#define PECAS_POR_TORRE 6

struct torre
{
    int pecas[PECAS_POR_TORRE];
    int pecasPresentes;
    int topo;
};

int topo(Torre *pTorre)
{
    if (pTorre->topo > -1)
        return pTorre->pecas[pTorre->topo];

    return -1;
}

Torre *criarTorre(void)
{
    Torre *pTorre = (Torre *)malloc(sizeof(Torre));
    // inicializando com todas as peças iguais a zero
    for (int i = 0; i < PECAS_POR_TORRE; i++)
        pTorre->pecas[i] = 0;

    pTorre->pecasPresentes = 0;
    pTorre->topo = -1;

    return pTorre;
}

void inicializarTorre(Torre *pTorre)
{
    for (int i = 0; i < PECAS_POR_TORRE; i++)
    {
        pTorre->pecas[i] = PECAS_POR_TORRE - i;
        pTorre->topo += 1;
        pTorre->pecasPresentes += 1;
    }
}

int pop(Torre *pTorre)
{

    if (pTorre->topo > -1)
    {
        int num = topo(pTorre);
        pTorre->pecas[pTorre->topo] = 0;
        pTorre->topo--;

        return num;
    }

    return -1;
}

int push(int elemento, Torre *pTorre)
{
    // entra se a torre estiver cheia
    if (pTorre->topo >= PECAS_POR_TORRE - 1)
        return -1;

    // entra se o a posição do topo for no mínimo zero e se o elemento for maior que o elemento no topo
    if (pTorre->topo > -1 && pTorre->pecas[pTorre->topo] < elemento)
        return -2;

    pTorre->topo++;
    pTorre->pecas[pTorre->topo] = elemento;
    return elemento;
}
