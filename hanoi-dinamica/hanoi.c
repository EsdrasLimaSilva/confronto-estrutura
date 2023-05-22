#include <stdlib.h>
#include <stdio.h>

#include "hanoi.h"
#include "torre.h"

struct hanoi
{
    int jogadas;
    Torre *pTorre1;
    Torre *pTorre2;
    Torre *pTorre3;
};

Hanoi *criarJogo(void)
{
    Hanoi *pHanoi = (Hanoi *)malloc(sizeof(Hanoi));
    // criando as três torres
    pHanoi->pTorre1 = criarTorre();
    pHanoi->pTorre2 = criarTorre();
    pHanoi->pTorre3 = criarTorre();
    pHanoi->jogadas = 0;

    // Iniciando a primeira torre
    inicializarTorre(pHanoi->pTorre1, 1);
    inicializarTorre(pHanoi->pTorre2, 0);
    inicializarTorre(pHanoi->pTorre2, 0);

    return pHanoi;
}

int moverPeca(Hanoi *pHanoi, int torreNum1, int torreNum2)
{
    Torre* origem = pegarTorre(pHanoi, torreNum1);
    Torre* destino = pegarTorre(pHanoi, torreNum2);
    if (topoTorre(origem) != -1 && torreCompleta(destino) != 1)
    {
        int elemento = popTorre(origem);
        if (pushTorre(elemento, destino) > 0)
        {
            pHanoi->jogadas++;
            return 1;
        }
        pushTorre(elemento, origem);
    }
    return 0;
}

void mostrarJogo(Hanoi *pHanoi)
{
    int topoTorre1 = posTopo(pHanoi->pTorre1);
    int topoTorre2 = posTopo(pHanoi->pTorre2);
    int topoTorre3 = posTopo(pHanoi->pTorre3);

    printf("\n");
    for (int i = 5; i >= 0; i--)
    {
        // torre 1
        if (i > topoTorre1)
            printf("     |");
        else if (i == topoTorre1)
            printf("  %d  |", topoTorre(pHanoi->pTorre1));
        else
            printf("  *  |");

        // torre2
        if (i > topoTorre2)
            printf("     |");
        else if (i == topoTorre2)
            printf("  %d  |", topoTorre(pHanoi->pTorre2));
        else
            printf("  *  |");

        // torre3
        if (i > topoTorre3)
            printf("    ");
        else if (i == topoTorre3)
            printf("  %d", topoTorre(pHanoi->pTorre3));
        else
            printf("  *");

        printf("\n");
    }
}

Torre *pegarTorre(Hanoi *pHanoi, int num)
{

    if (num == 1)
    {
        return pHanoi->pTorre1;
    }
    if (num == 2)
    {
        return pHanoi->pTorre2;
    }
    if (num == 3)
    {
        return pHanoi->pTorre3;
    }
    return NULL;
}

int numeroJogadas(Hanoi *pHanoi)
{
    return pHanoi->jogadas;
}

int jogoVencido(Hanoi *pHanoi)
{
    int torre2Completa = torreCompleta(pHanoi->pTorre2);
    int torre3Completa = torreCompleta(pHanoi->pTorre3);

    if (torre2Completa || torre3Completa)
        return 1;

    return 0;
}
