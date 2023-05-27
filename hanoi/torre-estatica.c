#include <stdio.h>
#include <stdlib.h>

#include "torre-estatica.h"
#include "pilha.h"

#define PECAS_POR_TORRE 6

struct torre
{
    int pecas[PECAS_POR_TORRE];
    int topo;
};

Torre *criarTorre(int inicial){

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

int pushTorre(Torre *pTorre, int elemento)
{
    if (pTorre->topo < -1)
        return -1;

    pTorre->topo++;
    pTorre->pecas[pTorre->topo] = elemento;

    return elemento;
}

int popTorre(Torre *pTorre)
{
    if (pTorre->topo < 0)
        return -1;

    int num = pTorre->pecas[pTorre->topo];
    pTorre->pecas[pTorre->topo] = 0;
    pTorre->topo--;

    return num;
}

int topoTorre(Torre *pTorre)
{
    return pTorre->pecas[pTorre->topo];
}

int posTopo(Torre *pTorre)
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


// preciso arruamar essa função
int valorPeca(Torre *pTorre, int pos)
{
    if (pos > posTopo(pTorre) || pos < 0)
        return 0;
    
    int caminhada = posTopo(pTorre);

    for (int i = 0; i < caminhada + 1; i++)
    {
        if (i == pos){
            return pTorre -> pecas[i];
        }
    }
}
