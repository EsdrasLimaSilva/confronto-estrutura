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
    time_t horaCriacao;
};

Processo *criarProcesso(char descricao[])
{
    Processo *pProcesso = (Processo *)malloc(sizeof(Processo));
    if (!pProcesso)
        exit(EXIT_FAILURE);

    unsigned int id = ceil(rand() % 10000);

    strcpy(pProcesso->descricao, descricao);
    pProcesso->id = id;
    pProcesso->horaCriacao = time(NULL);

    return pProcesso;
}

void mostrarHora(time_t tempoCriacao){

    time_t tempoAtual = time(NULL);

    time_t tempoPassado = tempoAtual - tempoCriacao;

    long horas = tempoPassado / 3600;
    long minutos = (tempoPassado%3600) / 60;
    long segundos = (tempoPassado%3600) % 60;

    printf(" Tempo: %.02ld : %.02ld : %.02ld\n", horas, minutos, segundos);
}

void mostrarProcesso(Processo *pProcesso)
{
    puts(" ----------------------------------------------");
    printf(" Id: %d\n", pProcesso->id);
    printf(" Descrição: %s\n", pProcesso->descricao);
    mostrarHora(pProcesso->horaCriacao);
    puts(" ----------------------------------------------");
}