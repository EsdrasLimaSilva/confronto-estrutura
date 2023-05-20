#include <stdio.h>

#include "hanoi.h"
#include "torre.h"

int main(void)
{
    Hanoi *pHanoi = criarJogo();
    mostrarJogo(pHanoi);
}
