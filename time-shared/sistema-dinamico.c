#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sistema-dinamico.h"
#include "fila.h"

struct sistema
{
    Fila *pFilaProcessos;
    int numeroDeProcessos;
};

Sistema *iniciarSistema()
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

void adicionarProcesso(Sistema *pSistema)
{
    char descricaoProcesso[50];
    printf("Informe a descrição: ");
    fgets(descricaoProcesso, 50, stdin);
    descricaoProcesso[strlen(descricaoProcesso) - 1] = '\0';

    Processo *pProcesso = criarProcesso(descricaoProcesso);
    inserir(pProcesso, pSistema->pFilaProcessos);
    pSistema->numeroDeProcessos++;

    printf("Processo adicionado com sucesso: \n\n");
    mostrarProcesso(pProcesso);
    printf("\n\n");
}

void mostrarProcessos(Sistema *pSistema)
{
    Nodo *pHead = pegarHead(pSistema->pFilaProcessos);

    printf("---------------- Sistema time-shared dinâmico ----------------------\n\n");
    printf(" Número de processos: %d\n\n processos presentes: \n\n", pSistema->numeroDeProcessos);

    mostrarFila(pHead);
}

void mostrarSistema(Sistema *pSistema){

    Nodo *pHead = pegarHead(pSistema->pFilaProcessos);

    if(pHead)
        mostrarProcessos(pSistema);
    else
        printf(" Vazio!\n\n");
    
} 

void removerProcesso(Sistema *pSistema){

    Nodo *pHead = pegarHead(pSistema -> pFilaProcessos);

    if(pHead){
        remover(pSistema -> pFilaProcessos);
        printf("Processo removido com sucesso!");
    } else {
        printf("Não foi possivel remover, a está lista vazia");
    }
    
    
}