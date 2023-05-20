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

    //Iniciando a primeira torre
    inicializarTorre(pHanoi->pTorre1);

    return pHanoi;
}

int moverPeca(Hanoi *pHanoi,Torre *origem, Torre *destino){
    if(topo(origem) != -1 && torreCompleta(destino) != 1){
        int elemento = pop(origem);
        if(push(elemento, destino) > 0){
            pHanoi->jogadas++;
            return 1;
        }
        push(elemento, origem);
    }
    return 0;
}

void mostrarJogo(Hanoi *pHanoi)
{
    printf("  %d  |  %d  |  %d\n", topo(pHanoi->pTorre1), topo(pHanoi->pTorre2), topo(pHanoi->pTorre3));
}
