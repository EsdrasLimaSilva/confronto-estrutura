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
    inicializarTorre(pHanoi->pTorre1);

    return pHanoi;
}

int moverPeca(Hanoi *pHanoi, Torre *origem, Torre *destino)
{
    if (topo(origem) != -1 && torreCompleta(destino) != 1)
    {
        int elemento = pop(origem);
        if (push(elemento, destino) > 0)
        {
            pHanoi->jogadas++;
            return 1;
        }
        push(elemento, origem);
    }
    return 0;
}

void mostrarJogo(Hanoi *pHanoi)
{
    for (int i = 0; i < 6; i++)
    {
        if (pecasNaTorre(pHanoi->pTorre1) == 6 - i)
        {
            printf("%d ", topo(pHanoi->pTorre1));
        }
        else if (pecasNaTorre(pHanoi->pTorre1) < 6 - i || topo(pHanoi->pTorre1) == -1)
        {
            printf("  ");
        }
        else
        {
            printf("* ");
        }
        if (pecasNaTorre(pHanoi->pTorre2) == 6 - i)
        {
            printf("| %d |", topo(pHanoi->pTorre2));
        }
        else if (pecasNaTorre(pHanoi->pTorre2) < 6 - i || topo(pHanoi->pTorre2) == -1)
        {
            printf("|   |");
        }
        else
        {
            printf("| * |");
        }
        if (pecasNaTorre(pHanoi->pTorre3) == 6 - i)
        {
            printf("%d ", topo(pHanoi->pTorre3));
        }
        else if (pecasNaTorre(pHanoi->pTorre3) < 6 - i || topo(pHanoi->pTorre3) == -1)
        {
            printf("   ");
        }
        else
        {
            printf("* ");
        }
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
