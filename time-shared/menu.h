#ifndef MENU_H
#define MENU_H

enum OPCOES {
    SAIR = 0,
    ADICIONAR,
    REMOVER, 
    MOSTRAR
};

/* Mostra o menu com as opções */
void mostraMenu(void);

/* Lê uma operação */
void lerOperacao(int *operacao, char *mensagem);

/* Limpa a tela */
void limparTela(void);

#endif