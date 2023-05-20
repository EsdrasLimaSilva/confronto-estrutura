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

    // inicializando a torre 1
    inicializarTorre(pHanoi->pTorre1);

    return pHanoi;
}

void mostrarJogo(Hanoi *pHanoi){
    printf("  %d  |  %d  |  %d\n", topo(pHanoi->pTorre1), topo(pHanoi->pTorre2), topo(pHanoi->pTorre3));
}
