#include <stdlib.h>

#include "processo.h"
#include "lista.h"

struct Nodo
{
    Processo *pProcesso;
    Nodo *pProximo;
};

struct lista
{
    Nodo *pHead;
};

Lista *criarLista()
{
    Lista *pLista = (Lista *)malloc(sizeof(Lista));
    if (!pLista)
        return NULL;

    return pLista;
}