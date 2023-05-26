#include <stdio.h>
#include <stdlib.h>

#include "hanoi.h"
#include "menu.h"

int main(void)
{
    Hanoi *pHanoi = criarJogo();

    int operacao;

    do
    {
        limparTela();
        mostrarMenu();
        coletar(&operacao, "escolha: ");

        switch (operacao)
        {
        case MOVER:
        {
            int origem, destino;
            int error;
            do
            {

                limparTela();
                if (venceu(pHanoi))
                {
                    puts("Você venceu o jogo!\n");
                    mostrarJogo(pHanoi);
                    exit(EXIT_SUCCESS);
                }

                if (error == -1){
                    printf("Jogada invalida, tente novamente!\n");
                }

                printf("Digie 0 na torre de origem para voltar para o menu");
                mostrarJogo(pHanoi);
                coletar(&origem, "torre de origem: ");
                coletar(&destino, "torre de destino: ");

                error = moverPeca(pHanoi, origem, destino);

            } while (origem != 0);
            break;
        }
        case INSTRUCOES:
            limparTela();
            mostrarRegras();
            break;
        case SAIR:
            limparTela();
            printf("Obrigado por jogar!\n");
            exit(EXIT_SUCCESS);
            break;
        }

        printf(" Pressione ENTER para continuar\n");
        getchar();

    } while (operacao != 3);
}
