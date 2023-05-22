#include <stdio.h>
#include <stdlib.h>

#include "hanoi.h"
#include "torre.h"

struct hanoi
{
    Torre *pTorre1;
    Torre *pTorre2;
    Torre *pTorre3;
    int numeroJogadas;
};

Hanoi *criarJogo(void)
{
    Hanoi *pHanoi = (Hanoi *)malloc(sizeof(Hanoi));
    if (!pHanoi)
        exit(EXIT_FAILURE);

    pHanoi->pTorre1 = criarTorre(1);
    pHanoi->pTorre2 = criarTorre(0);
    pHanoi->pTorre3 = criarTorre(0);

    return pHanoi;
}

void mostrarJogo(Hanoi *pHanoi)
{
    int topoTorre1 = posTop(pHanoi->pTorre1);
    int topoTorre2 = posTop(pHanoi->pTorre2);
    int topoTorre3 = posTop(pHanoi->pTorre3);

    printf("\n");
    int numeroPecasMaximo = maximoPecas();
    for (int i = numeroPecasMaximo - 1; i >= 0; i--)
    {
        // torre 1
        if (i > topoTorre1)
            printf("     |");
        else if (i == topoTorre1)
            printf("  %d  |", top(pHanoi->pTorre1));
        else
            printf("  *  |");

        // torre 2
        if (i > topoTorre2)
            printf("     |");
        else if (i == topoTorre2)
            printf("  %d  |", top(pHanoi->pTorre2));
        else
            printf("  *  |");

        // torre 3
        if (i > topoTorre3)
            printf("     |");
        else if (i == topoTorre3)
            printf("  %d  |", top(pHanoi->pTorre3));
        else
            printf("  *  |");

        printf("\n");
    }
}

Torre *pegarTorre(Hanoi *pHanoi, int num)
{
    switch (num)
    {
    case 1:
        return pHanoi->pTorre1;
    case 2:
        return pHanoi->pTorre2;
    case 3:
        return pHanoi->pTorre3;
    }

    return NULL;
}

int moverPeca(Hanoi *pHanoi, int torreOrigem, int torreDestino)
{
    if (torreOrigem < 1 || torreOrigem > 3 || torreDestino < 1 || torreDestino > 3)
        return -1;

    Torre *pTorreOrigem = pegarTorre(pHanoi, torreOrigem);
    Torre *pTorreDestino = pegarTorre(pHanoi, torreDestino);

    if (!pTorreOrigem || !pTorreDestino || posTop(pTorreOrigem) == -1)
        return -1;

    int numOrigem = top(pTorreOrigem);
    int numDestino = top(pTorreDestino);

    if (numOrigem > numDestino && numDestino > 0)
        return -1;

    int num = pop(pTorreOrigem);
    push(pTorreDestino, num);

    return 1;
}

int venceu(Hanoi *pHanoi)
{
    int torre2Completa = torreCompleta(pHanoi->pTorre2);
    int torre3Completa = torreCompleta(pHanoi->pTorre3);

    if (torre2Completa || torre3Completa)
        return 1;
    return 0;
}
