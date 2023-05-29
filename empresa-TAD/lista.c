#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct nodo
{
    Nodo *pProximo;
    Nodo *pAnterior;
    void *pElemento;
};

struct lista
{
    Nodo *pHead;
};

Lista *criarLista()
{
    Lista *pLista = (Lista *)malloc(sizeof(Lista));
    pLista->pHead = NULL;

    return pLista;
}

void remover(Lista *pLista, Nodo *pNodo)
{
    if (!pNodo->pAnterior)
    { // remove do início da lista
        pLista->pHead = pNodo->pProximo;
    }

    if (pNodo->pProximo)
        pNodo->pProximo->pAnterior = pNodo->pAnterior;

    if (pNodo->pAnterior)
    {
        printf("Oi meu chapa\n");
        pNodo->pAnterior->pProximo = pNodo->pProximo;
    }

    free(pNodo->pElemento);
    free(pNodo);
}

void adicionar(Lista *pLista, Nodo *pNodo)
{
    Nodo *pAux = pLista->pHead;

    if (!pAux)
    { // lista vazia
        pLista->pHead = pNodo;
    }
    else
    { // lista preenchida

        while (pAux->pProximo)
            pAux = pAux->pProximo;

        pAux->pProximo = pNodo;
        pNodo->pAnterior = pAux;
    }
}

void mostrarLista(Lista *pLista, void (*mostrarElemento)(void *pElemento))
{
    Nodo *pAux = pLista->pHead;

    if (pAux)
        mostrarElemento(pAux->pElemento);
    else
        printf("Lista vazia!\n");

    while (pAux && pAux->pProximo)
    {
        pAux = pAux->pProximo;
        mostrarElemento(pAux->pElemento);
    }
}

Nodo *pegarHead(Lista *pLista)
{
    return pLista->pHead;
}

void *pegarElemento(Nodo *pNodo)
{
    return pNodo->pElemento;
}

Nodo *proximo(Nodo *pNodo)
{
    return pNodo->pProximo;
}

Nodo *buscar(Lista *pLista, char *string, int (*compararElemento)(Nodo *pNodo, char *string))
{
    Nodo *pAux = pegarHead(pLista);
    while (pAux->pProximo)
    {
        int equal = compararElemento(pAux, string);
        if (equal)
            return pAux;
    }

    return NULL;
}

Nodo *criarNodo()
{
    // criando o nodo e checando se tudo deu certo
    Nodo *pNodo = (Nodo *)malloc(sizeof(Nodo));
    if (!pNodo)
        exit(EXIT_FAILURE);

    pNodo->pAnterior = pNodo->pProximo = NULL;

    return pNodo;
}

void adicionarElemento(Nodo *pNodo, void *pElemento)
{
    pNodo->pElemento = pElemento;
}
