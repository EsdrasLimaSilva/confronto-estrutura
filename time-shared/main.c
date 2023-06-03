#include <stdio.h>
#include <locale.h>

#include "sistema-dinamico.h"
#include "menu.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Sistema *pSistema = iniciarSistema();

    int operacao;

    while(
        limparTela(),
        mostraMenu(),
        lerOperacao(&operacao, "Operação: "),
        operacao
        ){

            switch(operacao){
                case SAIR:
                    printf("Sair\n");
                    break;
                case ADICIONAR:
                    limparTela();
                    printf("---------- Adicionar Processo ------------\n\n");
                    adicionarProcesso(pSistema);
                    break;
                case REMOVER:
                    limparTela();
                    removerProcesso(pSistema);
                    break;
                case MOSTRAR:
                    limparTela();
                    printf("---------- Todos os Processos ------------\n\n");
                    mostrarSistema(pSistema);
                    break;
                default:
                    printf("Operação inválida! pressione ENTER para continuar");
                    getchar();
                    continue;
            }

        printf("\n\tPressione ENTER para continuar");
        getchar();
    }
}