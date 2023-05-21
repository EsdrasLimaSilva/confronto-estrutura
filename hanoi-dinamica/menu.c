#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

void mostrarMenu()
{
    printf("===================== Torre de Hanoi =====================\n\n");
    printf("\t%d - Jogar\n", MOVER);
    printf("\t%d - Instruções\n", INSTRUCOES);
    printf("\t%d - Sair\n", SAIR);
}

int coletarOperacao()
{
    int operacao;
    printf("\n Informe uma opção: ");
    scanf("%d", &operacao);
    getchar(); // coletando  o caractere de quebra de linha
    return operacao;
}

void limparTela()
{
#ifdef _WIN32
    system("clear");
#else
    system("clear");
#endif
}

void mostrarRegras()
{
    puts("============ Torre de Hanoi ============");
    puts("A tore de hanoi é um jogo que consiste em mover todas as peças de uma torre, para outra. Contudo, existem algumas regras específicas listadas abaixo: ");
    printf("\t1 - só é possível movimentar uma peça por vez\n");
    printf("\t2 - não é possível colocar um peça de maior valor sobre uma de menor valor\n");
    printf("\t3 - o jogo só acaba quando todas as peças tiverem sido colocadas em uma única torre diferente da original\n\n\n");
}
