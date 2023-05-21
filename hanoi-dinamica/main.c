#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"
#include "torre.h"
#include "menu.h"

void instrucoes()
{
    printf("A torre de hanoi funciona da seguinte forma");
}

int main(void)
{
    Hanoi *pHanoi = criarJogo();
    int operacao;

    do
    {
        limparTela();
        mostrarMenu();
        operacao = coletarOperacao();
        limparTela();

        switch (operacao)
        {
        case 1:
        {
            int origem, destino;
            mostrarJogo(pHanoi);
            printf("Informe a torre de origem: ");
            scanf("%d", &origem);
            getchar();
            printf("Informe a torre de destino: ");
            scanf("%d", &destino);
            getchar();

            Torre *torreOrigem = pegarTorre(pHanoi, origem);
            Torre *torreDestino = pegarTorre(pHanoi, destino);

            if (!torreOrigem || !torreDestino)
            {
                printf("Não foi possivel fazer alteracao, torres invalidas");
                break;
            }

            int retorno = moverPeca(pHanoi, torreOrigem, torreDestino);

            if (!retorno)
            {
                printf("Nao eh possivel colocar um numero maior emcima de um menor");
            }

            mostrarJogo(pHanoi);

            break;
        }

        case 2:
            limparTela();
            mostrarRegras();
            break;

        case 3:
            limparTela();
            printf("Obrigado por jogar!\n");
            exit(EXIT_SUCCESS);
            break;

        default:
            limparTela();
            printf("Valor inválido! informe um valor válido do menu");
            break;
        }

        printf("\n\n");
        printf("Pressione ENTER para continuar\n\n");
        getchar();

    } while (operacao != 3);
}
