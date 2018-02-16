#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

typedef struct no {
	int dado;
	int id;
	struct no *prox;
	struct no *ant;
}No;

typedef struct lst {
	No* inicio;
	No* fim;
	int qtd;
	int naoIniciada;
}Lista;

bool iniciaLista(Lista* l);

bool inserePos(Lista* l, int d, int p);

bool insereNoPosicao(Lista* l, No* n, int p);

bool insereInicio(Lista* l, int d);

bool insereFim(Lista* l, int d);

bool removeFim(Lista* l, int* valor);

bool removeInicio(Lista* l, int* valor);

bool removePos(Lista* l, int* valor, int p);

No* removeNoPosicao(Lista* l, int p);

No* buscaNo(Lista* l, int p);

void mostraElementos(Lista* l);

