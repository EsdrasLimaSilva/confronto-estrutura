#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"
#include "torre.h"


void menu(){
    printf("------------Escolha uma opção abaixo------------------------------------\n\n");
    printf("----------- 1 - Jogar                                     --------------\n\n");
    printf("----------- 2 - Instruções                                --------------\n\n");
    printf("----------- 3 - Sair                                      --------------\n\n");
    printf("------------------------------------------------------------------------\n\n");
}

void instrucoes(){
    printf("A torre de hanoi funciona da seguinte forma");
}

void limpar(){
    system("clear");
}


int main(void){
   Hanoi *pHanoi = criarJogo();
   int opc;

   do
   {
    limpar();
    printf("------------------------------------------------------------------------\n\n");
    printf("----------------------------MENU HANOI----------------------------------\n\n");
    printf("------------------------------------------------------------------------\n\n");
    menu();
    printf("Informe uma das opções mostradas no menu: ");
    scanf("%d", &opc);
    limpar();
    getchar();
    switch (opc){
    case 1:
        mostrarJogo(pHanoi);
        break;
    case 2:
        system("clear");
        instrucoes();
        break;
    
    case 3:
        system("clear");
        break;

    default:
        system("clear");
        printf("Valor inválido! informe um valor válido do menu");
        break;
    }
    printf("\n\n");
    printf("Pressione ENTER para continuar\n\n");
    getchar();

   } while (opc != 3);

}
