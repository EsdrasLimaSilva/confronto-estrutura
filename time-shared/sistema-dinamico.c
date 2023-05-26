#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sistema-dinamico.h"
#include "fila.h"

struct sistema
{
    Fila *pFilaProcessos;
    int numeroDeProcessos;
};

Sistema *inidicarSistema()
{
    // aidionando seed nula para gerador de número de processos
    srand(time(NULL));

    Sistema *pSistema = (Sistema *)malloc(sizeof(Sistema));
    if (!pSistema)
        exit(EXIT_FAILURE);

    Fila *pProcessos = criarFila();

    pSistema->pFilaProcessos = pProcessos;
    pSistema->numeroDeProcessos = 0;

    return pSistema;
}

void adicionarProcesso(Sistema *pSistema, char descricaoProcesso[])
{
    Processo *pProcesso = criarProcesso(descricaoProcesso);
    inserir(pProcesso, pSistema->pFilaProcessos);
    pSistema->numeroDeProcessos++;
}

void mostrarProcessos(Sistema *pSistema)
{
    Nodo *pHead = pegarHead(pSistema->pFilaProcessos);

    printf(" ========== Sistema time-shared dinâmico ============\n\n");
    printf(" Número de processos: %d\n\n processos presentes: \n\n", pSistema->numeroDeProcessos);

    mostrarFila(pHead);
}
