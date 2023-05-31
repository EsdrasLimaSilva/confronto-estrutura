#include "lista.h"
#include "empresa.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	// ajustando a localidade
	setlocale(LC_ALL, "Portuguese");

	Lista *pEmpresa = criarEmpresa();
	int operacao;

	do
	{
		limparTela();
		mostrarMenu();
		printf("Operacação: ");
		scanf("%d", &operacao);
		getchar(); // coletando caractere de nova linha

		limparTela();
		printf("\n");

		switch (operacao)
		{
		case SAIR:
			printf("Até mais\n");
			exit(EXIT_SUCCESS);
			break;
		case ADICIONAR:
			printf(" ---------- Adicionar Funcionário ---------\n\n");
			adicionarFuncionario(pEmpresa);
			break;
		case REMOVER:			
			removerFuncionario(pEmpresa);
			break;
		case BUSCAR:
			printf(" --------- Buscar Funcionário -------------\n\n");
			buscarFuncionario(pEmpresa);
			break;
		case MOSTRAR:
			printf(" --------- Funcioários -------------\n\n");
			mostrarEmpresa(pEmpresa);
			break;
		}

		printf("\n\tPressione ENTER para continuar\n");
		getchar();

	} while (operacao);

	return EXIT_SUCCESS;
}
