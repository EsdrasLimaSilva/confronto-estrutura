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

/*

      ==      |
     ====     |
    ======    |
   ========   |
  ==========  |
 ============ |

 14 espaços no máximo

 14 - 12 = 2 espaços => 1 espaço para a esquerda e 1 para a direita

*/
void mostrarDisco(int valor)
{
    const int TAMANHO_DISCO_MAXIMO = 14;
    printf("|");

    if (valor)
    {
        int numeroDeDiscos = valor * 2;
        int espacos = TAMANHO_DISCO_MAXIMO - numeroDeDiscos;
        int espacosInicio = espacos / 2;
        int espacosFim = espacos / 2;

        // mostrando os espaços do início
        for (int i = 0; i < espacosInicio; i++)
            printf(" ");

        // mostrando os discos
        for (int i = 0; i < numeroDeDiscos; i++)
            printf("=");

        // mostrando os espaços do fim
        for (int i = 0; i < espacosFim; i++)
            printf(" ");
    }
    else
    {
        for (int i = 0; i < TAMANHO_DISCO_MAXIMO; i++)
            printf(" ");
    }

    printf("|");
}

void mostrarJogo(Hanoi *pHanoi)
{
    printf("\n");
    int numeroPecasMaximo = maximoPecas();
    for (int i = numeroPecasMaximo - 1; i >= 0; i--)
    {
        // torre 1
        int valorPecaTorre1 = valorPeca(pHanoi->pTorre1, i);
        mostrarDisco(valorPecaTorre1);

        // torre 2
        int valorPecaTorre2 = valorPeca(pHanoi->pTorre2, i);
        mostrarDisco(valorPecaTorre2);

        // torre 3
        int valorPecaTorre3 = valorPeca(pHanoi->pTorre3, i);
        mostrarDisco(valorPecaTorre3);

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

    if (!pTorreOrigem || !pTorreDestino || posTopo(pTorreOrigem) == -1)
        return -1;

    int numOrigem = topoTorre(pTorreOrigem);
    int numDestino = topoTorre(pTorreDestino);

    if (numOrigem > numDestino && numDestino > 0)
        return -1;

    int num = popTorre(pTorreOrigem);
    pushTorre(pTorreDestino, num);

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
