#include <stdio.h>
#include <stdlib.h>

#include "torre.h"

#define PECAS_POR_TORRE 6

struct torre
{
    int pecas[PECAS_POR_TORRE];
    int topo;
};

Torre *criarTorre(int inicial)
{
    Torre *pTorre = malloc(sizeof(Torre));
    if (!pTorre)
        exit(EXIT_FAILURE);

    pTorre->topo = -1;

    // inicializando as posições da torre
    for (int i = 0; i < PECAS_POR_TORRE; i++)
    {
        int num;
        if (inicial)
        {
            num = PECAS_POR_TORRE - i;
            pTorre->topo++;
        }
        else
            num = 0;

        pTorre->pecas[i] = num;
    }

    return pTorre;
}

int push(Torre *pTorre, int elemento)
{
    if (pTorre->topo < -1)
        return -1;

    pTorre->topo++;
    pTorre->pecas[pTorre->topo] = elemento;

    return elemento;
}

int pop(Torre *pTorre)
{
    if (pTorre->topo < 0)
        return -1;

    int num = pTorre->pecas[pTorre->topo];
    pTorre->pecas[pTorre->topo] = 0;
    pTorre->topo--;

    return num;
}

int top(Torre *pTorre)
{
    return pTorre->pecas[pTorre->topo];
}

int posTop(Torre *pTorre)
{
    return pTorre->topo;
}

int maximoPecas()
{
    return PECAS_POR_TORRE;
}

int torreCompleta(Torre *pTorre)
{
    if (pTorre->topo == PECAS_POR_TORRE - 1)
        return 1;
    return 0;
}
