#include<stdio.h>
#include<stdlib.h>
#include"menu.h"

void mostraMenu(void){
    printf("------------- Time Shared System --------------\n\n");
    printf("[%d] - Sair\n", SAIR);
    printf("[%d] - Adicionar Processo\n", ADICIONAR);
    printf("[%d] - Remover Processo\n", REMOVER);
    printf("[%d] - Mostrar Fila\n", MOSTRAR);
}


void lerOperacao(int *operacao, char *mensagem){
    printf("%s", mensagem);
    scanf("%d", operacao);
    getchar();
}

void limparTela(void){
#ifdef _WIN_32
    system("cls");
#else
    system("clear");
#endif
}