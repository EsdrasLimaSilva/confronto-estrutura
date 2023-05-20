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
