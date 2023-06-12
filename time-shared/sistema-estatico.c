#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include"sistema.h"
#include"processo.h"

#define MAX_PROCESSOS 200

struct sistema {
    Processo *pfilaProcessos[MAX_PROCESSOS];
    int numeroProcessos;
};

Sistema *iniciarSistema(){
    printf(">> Iniciando sistema ESTÁTICO");
    getchar();
    // aidionando seed nula para gerador de número de processos
    srand(time(NULL));

    Sistema *pSistema = (Sistema*) malloc(sizeof(Sistema));
    if(!pSistema)
        exit(EXIT_FAILURE);
    
    pSistema->numeroProcessos = 0;

    return pSistema;
}

void adicionarProcesso(Sistema *pSistema){
   if(pSistema->numeroProcessos >= MAX_PROCESSOS){

    printf(" Fila cheia!\n");

   }else{ 
    //lendo a descrição do processo
    char descricaoProcesso[50];
    printf(" Informe a descrição: ");
    fgets(descricaoProcesso, 50, stdin);
    descricaoProcesso[strlen(descricaoProcesso) - 1] = '\0';

    Processo *pProcesso = criarProcesso(descricaoProcesso);
    pSistema->pfilaProcessos[pSistema->numeroProcessos] = pProcesso;
    
    pSistema->numeroProcessos += 1;
    
    printf(" Processo adicionado com sucesso:\n");
    mostrarProcesso(pSistema->pfilaProcessos[pSistema->numeroProcessos - 1]);
    }
}



void mostrarSistema(Sistema *pSistema){
    printf(" ------------- Sistema Estático Time-Shared -------------\n\n");

    printf(" Processos presentes: %d\n\n Lista: \n", pSistema->numeroProcessos);
   

    if(pSistema->numeroProcessos > 0){
         for(int i = 0; i < pSistema->numeroProcessos; i++){
        mostrarProcesso(pSistema->pfilaProcessos[i]);
    }
    }else{
        printf(" Vazio!\n");
    }

}

void removerProcesso(Sistema *pSistema){
    if(pSistema->numeroProcessos > 0){

        if(pSistema->numeroProcessos == 1){
            pSistema->pfilaProcessos[0] = NULL;
        } else {
            for(int i = 0; i < pSistema->numeroProcessos - 1; i++){
            pSistema->pfilaProcessos[i] = pSistema->pfilaProcessos[i+1];
        }
        }

        pSistema->numeroProcessos--;
        printf("Processo removido");

    } else {
        printf("Vazio!\n");
    }
}