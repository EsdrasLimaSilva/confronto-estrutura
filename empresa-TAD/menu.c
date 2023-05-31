#include "menu.h"
#include <stdio.h>

void mostrarMenu()
{
	puts("---------------- Menu ----------------");
	printf("[%d] Sair\n", SAIR);
	printf("[%d] Adicionar funcionario\n", ADICIONAR);
	printf("[%d] Remover funcionario\n", REMOVER);
	printf("[%d] Buscar funcionário: \n", BUSCAR);
	printf("[%d] Mostrar funcionarios\n\n", MOSTRAR);
}

void limparTela(){
#ifdef _WIN_32
	system("cls");
#else
	system("clear");
#endif
}