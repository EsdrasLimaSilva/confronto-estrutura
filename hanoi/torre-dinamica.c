#include <stdlib.h>
#include <stdio.h>
#include "torre.h"
#include "pilha.h"

#define PECAS_POR_TORRE 6

struct torre
{
    Pilha *pPilha;
    int pecasPresentes;
    int topo;
};

Torre *criarTorre(int inicial)
{   
    printf(" Criando torre DINÂMICA\n");
    getchar();

    Torre *pTorre = (Torre *)malloc(sizeof(Torre));
    if(!pTorre)
        exit(EXIT_FAILURE);

    Pilha *pPilha = criarPilha();
    if(!pPilha)
        exit(EXIT_FAILURE);


    pTorre->pPilha = pPilha;

    pTorre->pecasPresentes = 0;
    pTorre->topo = -1;

    for (int i = PECAS_POR_TORRE; i > 0; i--)
    {
        if (inicial)
        {
            push(pTorre->pPilha, i);
            pTorre->topo++;
        }
        else
            push(pTorre->pPilha, 0);
    }

    return pTorre;
}

int topoTorre(Torre *pTorre)
{
    if (pTorre->topo > -1)
        return topo(pTorre->pPilha);

    return -1;
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

int pushTorre(Torre *pTorre, int elemento)
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

int maximoPecas(void)
{
    return PECAS_POR_TORRE;
}

int valorPeca(Torre *pTorre, int pos)
{
    if (pos > posTopo(pTorre) || pos < 0)
        return 0;

    Peca *pAux = ponteiroTopo(pTorre->pPilha);

    int caminhada = posTopo(pTorre) - pos;

    for (int i = 0; i < caminhada; i++)
    {
        pAux = abaixo(pAux);
    }

    return pegarValor(pAux);
}
