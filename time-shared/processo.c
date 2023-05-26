#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "processo.h"

struct processo
{
    unsigned int id;
    char descricao[100];
};

Processo *criarProcesso(char descricao[])
{
    Processo *pProcesso = (Processo *)malloc(sizeof(Processo));
    if (!pProcesso)
        exit(EXIT_FAILURE);

    srand(time(NULL));

    unsigned int id = ceil(rand() % 10000);

    strcpy(pProcesso->descricao, descricao);
    pProcesso->id = id;

    return pProcesso;
}

void mostrarProcesso(Processo *pProcesso)
{
    puts(" ----------------------------------------------");
    printf(" Id: %d\n", pProcesso->id);
    printf(" Descrição: %s\n", pProcesso->descricao);
    puts(" ----------------------------------------------");
}