#include "lista.h"
#include "empresa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cria uma empresa
Lista *criarEmpresa()
{
    Lista *pEmpresa = criarLista();
    return pEmpresa;
}

// remove o funcionário da empresa
void removerFuncionario(unsigned int matricula, Lista *pEmpresa)
{
    Nodo *pNodo = pegarHead(pEmpresa);

    while (pNodo)
    {
        Funcionario *pFuncionario = (Funcionario *)pegarElemento(pNodo);

        // funcionario foi encontrado
        if (pFuncionario->matricula == matricula)
        {
            remover(pEmpresa, pNodo);
            break;
        }

        pNodo = proximo(pNodo);
    }
}

void adicionarFuncionario(Lista *pEmpresa)
{
    // criando o nodo e checando se tudo deu certo
    Nodo *pNodo = criarNodo();

    // alocando memória para o funcionario e checando se tudo deu certo
    Funcionario *pFuncionario = (Funcionario *)malloc(sizeof(Funcionario));
    if (!pFuncionario)
    {
        free(pNodo);
        printf("Algo deu errado");
        exit(EXIT_FAILURE);
    }

    // coletando os dados do funcionário
    printf("Nome do funcinário: ");
    fgets(pFuncionario->nome, 50, stdin);
    pFuncionario->nome[strlen(pFuncionario->nome) - 1] = '\0';

    printf("Matrícula do funcionario: ");
    scanf("%u", &pFuncionario->matricula);
    getchar();

    // associando o elemento do nodo ao endereço de memória do funcionario
    adicionar(pEmpresa, pNodo);
}

void mostrarFuncionario(void *pNodo)
{
    Funcionario *pFuncionario = (Funcionario *)pNodo;
    printf("Nome: %s\n", pFuncionario->nome);
    printf("Matrícula: %u\n\n", pFuncionario->matricula);
}

void mostrarEmpresa(Lista *pEmpresa)
{
    mostrarLista(pEmpresa, mostrarFuncionario);
}

int compararFuncionario(Nodo *pNodo, char *nome)
{
    Funcionario *pFuncionario = (Funcionario *)pegarElemento(pNodo);

    int comp = strcmp(pFuncionario->nome, nome);

    if (!comp)
        return 1;
    return 0;
}

void buscarFuncionario(char *nome, Lista *pEmpresa)
{

    Funcionario *pFuncionario = (Funcionario *)buscar(pEmpresa, nome, compararFuncionario);

    if (!pFuncionario)
    {
        printf("Funcionário encontrado!\n");
    }
    else
    {
        printf("Funcionário Inexistente!\n");
    }
}
