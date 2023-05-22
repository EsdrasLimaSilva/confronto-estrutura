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
            do
            {

                limparTela();
                if (venceu(pHanoi))
                {
                    puts("Você venceu o jogo!\n");
                    mostrarJogo(pHanoi);
                    exit(EXIT_SUCCESS);
                }

                puts("Digie 0 na torre de origem para voltar para o menu");
                mostrarJogo(pHanoi);
                coletar(&origem, "torre de origem: ");
                coletar(&destino, "torre de destino: ");
                moverPeca(pHanoi, origem, destino);
            } while (origem != 0);
        }
        }

    } while (operacao != 3);
}
