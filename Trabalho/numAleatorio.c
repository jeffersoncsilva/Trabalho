#include "numAleatorio.h"

Lista* geraListaAleatoria(int qtd, int intervalo) {
	srand((unsigned)time(NULL));
	int i;
	int aux = 0;
	Lista *l = malloc(sizeof(Lista));
	iniciaLista(l);
	for (i = 0; i < qtd; i++) {
		aux = rand() % intervalo;
		insereFim(l, aux);
	}
	return l;
}

Lista* geraListaCrescente(int qtd) {
	int i;
	Lista *l = malloc(sizeof(Lista));
	iniciaLista(l);
	for (i = 1; i <= qtd; i++) {
		insereFim(l, i);
	}
	return l;
}

Lista* geraListaDecrescente(int qtd) {
	int i;
	Lista *l = malloc(sizeof(Lista));
	iniciaLista(l);
	for (i = qtd; i > 0; i--) {
		insereFim(l, i);
	}
	return l;
}
