#include <stdio.h>
#include <locale.h>

#include "processo.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Processo *pProcesso = criarProcesso("O melhor processo do mundo");
    mostrarProcesso(pProcesso);
}