#ifndef MENU_H
#define MENU_H

enum Operacoes
{
    MOVER = 1,
    INSTRUCOES,
    SAIR
};

/* Mostra todas as opções do menu */
void mostrarMenu(void);

/* Limpa a tela completamente */
void limpar(void);

/* coleta uma operação de jogo do usuário e a retorna */
int coletarOperacao(void);

/* limpa a tela do usuário */
void limparTela(void);

/* Mostra as regras do jogo */
void mostrarRegras(void);

#endif
