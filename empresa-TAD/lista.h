#ifndef LIST_H
#define LIST_H

// define a estrutura nodo
typedef struct nodo Nodo;

// define a estrutura da lista
typedef struct lista Lista;

/**
 * Cria uma lista
 */
Lista *criarLista();

// adiciona um elemento na lista
void adicionar(Lista *pLista, Nodo *pNodo);

// remove um elemento da lista
void remover(Lista *pLista, Nodo *pNodo);

/**
 * Percorre toda a lista, chamando, para cada item, a função de mostrar elemento (passada como parâmetro através de um ponteiro)
 */
void mostrarLista(Lista *pLista, void (*mostarElemento)(void *pElemento));

/*
Retorna o ponteiro de Head da lista
*/
Nodo *pegarHead(Lista *pLista);

/*Retorna um ponteiro vazio para o elemento da lista*/
void *pegarElemento(Nodo *pNodo);

/* Retorna um ponteiro para o próximo elemento do nodo */
Nodo *proximo(Nodo *pNodo);

/* Cria um novo Nodo e retorna um ponteiro para ele */
Nodo *criarNodo();

/* busca um nodo com um elemento na lista na lista */
Nodo *buscar(Lista *pLista, char *string, int (*compararElemento)(Nodo *pNodo, char *string));

/* Adiciona um ponteiro para um elemento do Nodo */
void adicionarElemento(Nodo *pNodo, void *pElemento);

#endif
