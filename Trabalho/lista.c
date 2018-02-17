#include "lista.h"

bool iniciaLista(Lista* l) {
	if (l->naoIniciada) {
		l->fim = NULL;
		l->inicio = NULL;
		l->qtd = 0;
		l->naoIniciada = false;
		return true;
	}
	else {
		printf("iniciaLista(): Lista ja iniciada.");
		return false;
	}
}

bool posicaoInvalida(Lista* l, int p) {
	if (p < 0 || p > l->qtd)
		return true;
	else
		return false;
}

No* buscaNo(Lista* l, int p) {
	int i;
	No *n;
	if (p <= (l->qtd / 2)) {
		n = l->inicio;
		for (i = 0; i < p; i++)
			n = n->prox;
	}
	else {
		n = l->fim;
		for (i = l->qtd; i > p; i--)
			n = n->ant;
	}
	return n;
}

bool insereInicio(Lista* l, int d) {
	if (l->naoIniciada) {
		printf("insereInicio(): erro, lista não foi iniciada.");
		return false;
	}
	
	No *n = malloc(sizeof(No));
	n->dado = d;
	n->ant = NULL;
	n->id = l->qtd;
	if (listaVazia(l)) {
		n->prox = NULL;
		l->inicio = n;
		l->fim = n;
	}
	else {
		n->prox = l->inicio;
		l->inicio->ant = n;
		l->inicio = n;
	}
	++l->qtd;
	return true;
}

bool insereFim(Lista* l, int d) {
	if (l->naoIniciada) {
		printf("insereFim(): erro, lista não foi iniciada corretamente.");
		return false;
	}
	No* n = malloc(sizeof(No));
	n->dado = d;
	n->prox = NULL;
	n->id = l->qtd;
	if (listaVazia(l)) {
		l->fim = n;
		l->inicio = n;
		n->ant = NULL;
	}
	else {
		l->fim->prox = n;
		n->ant = l->fim;
		l->fim = n;
	}
	l->qtd++;
	return true;
}

bool inserePos(Lista* l, int d, int p) {
	if (l->naoIniciada) {
		printf("inserePos(): erro, lista não foi iniciada.");
		return 0;
	}
	if (l->qtd == p)
		return insereFim(l, d);
	if (p == 0)
		return insereInicio(l, d);
	else {
		No* n = buscaNo(l, (p - 1));
		No* novo = malloc(sizeof(No));
		novo->dado = d;
		novo->prox = n->prox;
		novo->ant = n;
		novo->id = l->qtd;
		n->prox->ant = novo;
		n->prox = novo;
		l->qtd++;
		return true;
	}
}

bool insereNoPosicao(Lista* l, No* n, int p) {
	if (l->naoIniciada) {
		printf("inserePos(): erro, lista não foi iniciada.");
		return 0;
	}
	No* nav = buscaNo(l, (p - 1));
	n->prox = nav->prox;
	n->ant = nav;
	nav->prox = n;
	if (n->prox != NULL)
		n->prox->ant = n;
	return true;
}

bool removeInicio(Lista* l, int* valor) {
	if (l->naoIniciada) {
		printf("erro, lista nao foi iniciada corretamente.");
		return false;
	}
	if (!listaVazia(l)) {
		No *lixo = l->inicio;
		*valor = lixo->dado;
		if (lixo->prox == NULL) {
			l->inicio = NULL;
			l->fim = NULL;
		}
		else {
			l->inicio = lixo->prox;
			l->inicio->ant = NULL;
		}
		free(lixo);
		lixo = NULL;
		return true;
	}
	else {
		printf("Lista vazia.");
		return false;
	}
}

bool removeFim(Lista* l, int* valor) {
	if (l->naoIniciada) {
		printf("erro, lista nao foi iniciada corretamente.");
		return false;
	}
	if (!listaVazia(l)) {
		No* lixo = l->fim;
		*valor = lixo->dado;
		if (lixo->ant == NULL) {
			/*Nesse caso, como a lista tem somente um elmento, o primeiro e o ultimo são o mesmo elementos, deve-se tiralos da lista.*/
			l->inicio = NULL;
			l->fim = NULL;
		}
		else {
			l->fim = lixo->ant;
			l->fim->prox = NULL;
		}
		free(lixo);
		lixo = NULL;
		return true;
	}
	else {
		printf("lista vazia.");
		return false;
	}
}

bool removePos(Lista* l, int* valor, int p) {
	if (l->naoIniciada) {
		printf("erro, lista nao foi iniciada corretamente.");
		return false;
	}
	if (!listaVazia(l)) {
		if (p == 0)
			return removeInicio(l, valor);
		if (p == l->qtd)
			return removeFim(l, valor);
		if (posicaoInvalida(l, p)) {
			printf("posicao invalida.");
			return false;
		}
		No* lixo = buscaNo(l, p);
		*valor = lixo->dado;
		lixo->ant->prox = lixo->prox;
		lixo->prox->ant = lixo->ant;
		free(lixo);
		lixo = NULL;
		l->qtd--;
		return true;
	}
	else {
		printf("lista vazia.");
		return false;
	}
}

No* removeNoPosicao(Lista* l, int p) {
	if (l->naoIniciada) {
		printf("erro, lista nao foi iniciada corretamente.");
		return NULL;
	}
	if (!listaVazia(l)) {
		if (posicaoInvalida(l, p)) {
			printf("posicao invalida.");
			return NULL;
		}
		No* lixo = buscaNo(l, p);
		if (p == 0) {
			l->inicio = lixo->prox;
			l->inicio->ant = NULL;
		}
		else if (p == l->qtd) {
			l->fim = lixo->ant;
			l->fim->prox = NULL;
		}
		else {
			lixo->ant->prox = lixo->prox;
			lixo->prox->ant = lixo->ant;
		}
		lixo->ant = NULL;
		lixo->prox = NULL;
		l->qtd--;
		return lixo;
	}
	else {
		printf("lista vazia.");
		return NULL;
	}
}

bool listaVazia(Lista* l) {
	if (l->qtd == 0)
		return true;
	else
		return false;
}

void mostraElementos(Lista* l) {
	if (!l->naoIniciada) {
		printf("\n");
		No* nav = l->inicio;
		while (nav != NULL) {
			printf(" \nID: %d --- V: %d",nav->id, nav->dado);
			nav = nav->prox;
		}
	}
}

