#include <stdio.h>
#include <locale.h>

#include "sistema-dinamico.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Sistema *pSistema = inidicarSistema();

    adicionarProcesso(pSistema, "Processo 1");
    adicionarProcesso(pSistema, "Processo 2");
    adicionarProcesso(pSistema, "Processo 3");
    adicionarProcesso(pSistema, "Processo 4");

    mostrarProcessos(pSistema);
}