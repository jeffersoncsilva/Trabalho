#include "ordena.h"


/*
ini -> representa o no inicial.
pos -> representa quantas posicoes a frete do no inicial se deseja.
max -> quantidade maxima de nos que se pode avançar (o tamanho da lista).
*/
No* buscaN(No* ini, int pos, int max) {
	/*
	Cada no guarda sua posicao na lista, logo se a posição do no mais o salto que se deseja 
	for maior que o tamanho da lista, isto e, se deseja um elemento que nao está na lista, retorna null.
	Caso contrario retorna o elemento desejado.
	*/
	if (ini->id + pos > max-1)
		return NULL;
	else {
		No *nav = ini;
		while (nav->id < ini->id + pos)
			nav = nav->prox;
		return nav;
	}
}

/*Troca o valor do no a, pelo valor do no b.*/
void troca(No* a, No* b) {
	int temp = a->dado;
	a->dado = b->dado;
	b->dado = temp;
}

/*Realiza uma comparação dois a dois do valor do no da lista, caso um seja maior,
troca o valor do no de um pelo valor do outro.*/
Lista* bubblesort(Lista* l) {
	int tam = l->qtd;
	int i;
	No *aux;
	No *prox;
	for (i = tam; i >= 0; i--) {
		aux = l->inicio;
		while (aux != NULL && aux->prox != NULL) {
			if (aux->dado > aux->prox->dado) {
				int temp = aux->dado;
				aux->dado = aux->prox->dado;
				aux->prox->dado = temp;
			}
			aux = aux->prox;
		}
	}
	return l;
}

Lista* insertionsort(Lista* l) {
	int qtd = l->qtd;
	int j, i, aux;
	No* nav = l->inicio->prox;
	No* nav_aux;
	for (i = 1; i < qtd; i++) {
		aux = nav->dado;
		nav_aux = nav;
		for (j = i; (j > 0) && (aux < nav_aux->ant->dado); j--) {
			nav_aux->dado = nav_aux->ant->dado;
			nav_aux = nav_aux->ant;
		}
		nav_aux->dado = aux;
		nav = nav->prox;
	}
	return l;
}

/*Percorre toda a lista buscando o menor no e guandandoem n_menor, em seguida,
troca de posição com o no guardado em ini que representa os nos ja visitados e
ordenados.*/
Lista* selectionsort(Lista* l) {
	No *ini = l->inicio;
	No *nav = ini->prox;/*Esse no e para que seja possivel percorre toda a lista que não foi ordenada ainda.*/
	No *n_menor;
	int i, j, temp;
	while (ini->prox != NULL) {
		n_menor = ini;
		nav = ini->prox;
		do
		{
			if (n_menor->dado > nav->dado)
				n_menor = nav;
			nav = nav->prox;
		} while (nav != NULL);
		if (n_menor->dado != ini->dado) {
			temp = ini->dado;
			ini->dado = n_menor->dado;
			n_menor->dado = temp;
		}
		ini = ini->prox;
	}
	return l;
}

/*Realiza o particionamento do pivo e realoca com os menores ao lado esquerdo do pivo
e maiores ao lado direito*/
No* particiona(No* ini, No* fim) {
	/*Quando o inicio e igual ao fim, não precisa mais particionar.*/
	if (ini == fim)
		return;
	No* esq = ini;
	No* dir = fim;
	/*Este sera o pivo.*/
	int pivo = ini->dado;
	int temp;
	while (esq != NULL && dir != NULL && esq->id < dir->id) {
		while (esq != NULL && esq->dado <= pivo) {
			esq = esq->prox;
		}
		while (dir != NULL && dir->dado > pivo)
			dir = dir->ant;
		if (esq != NULL && dir != NULL && esq->id < dir->id) {
			temp = esq->dado;
			esq->dado = dir->dado;
			dir->dado = temp;
		}
	}
	if (dir->id > ini->id) {
		ini->dado = dir->dado;
		dir->dado = pivo;
	}
	return dir;
}

void q_sort(No* ini, No* fim) {
	if (ini != NULL && fim != NULL && ini->id < fim->id) {

		No* p = particiona(ini, fim);
		/*Oredeno o lado esquerdo, depois o lado direito.*/
		q_sort(ini, p->ant);
		q_sort(p->prox, fim);
	}
	else
		return;
}

Lista* quicksort(Lista* l) {
	q_sort(l->inicio, l->fim);
	return l;
}

/*
	f-> representa o tamanho da lista.
	i-> representa o indice agual da lista, qual e o no que sera feito o heap
	l-> representa a lista.
*/
void heap(Lista* l, int i, int f) {
	No *n = buscaNo(l, i);
	int aux = n->dado;
	/*representa a posicao do filho a direita.*/
	int j = i * 2 + 1;
	while (j <= f) {
		/*No da posicao j.*/
		No *a = buscaNo(l, j);
		if (j < f) {
			No *b = buscaNo(l, j + 1);
			if (a->dado < b->dado) {
				j++;
			}
		}
		if (aux < a->dado) {
			n->dado = a->dado;
			i = j;
			j = 2 * i + 1;
			n = buscaNo(l, i);
		}
		else
			j = f + 1;
	}
	n = buscaNo(l, i);
	n->dado = aux;
}

Lista* heapsort(Lista* l) {
	int i, aux;
	int N = l->qtd+1;
	for (i = (N - 1) / 2; i >= 0; i--) {
		heap(l, i, N - 1);
	}
	for (i = N - 1; i >= 1; i--) {
		No *n = buscaNo(l, i);
		aux = l->inicio->dado;
		l->inicio->dado = n->dado;
		n->dado = aux;
		heap(l, 0, i - 1);
	}
	return l;
}

No* buscaEsq(No* n, int h) {
	while (n->id > h)
		n = n->ant;
	return n;
}

Lista* shellsort(Lista* l) {
	/*int tmp, i, j, h;
	h = l->qtd / 2;
	while (h > 0) {
		i = h;
		while (i < l->qtd) {
			No *n = buscaNo(l, i);
			tmp = n->dado;
			j = i;
			while (j >= h && tmp < buscaEsq(n, h)->dado) {
				troca(n, buscaEsq(n, h));
				j = j - h;
			}
			n = buscaNo(l, j);
			n->dado = tmp;
			i++;
		}
		h = h / 2;
	}*/
	No *no_ini;
	No *no_salto;
	int p = l->qtd/2;
	no_ini = l->inicio;
	while (p > 0) {
			no_salto = buscaN(no_ini, p, l->qtd);
			while (no_salto != NULL) {
				if (no_ini->dado > no_salto->dado) {
					troca(no_ini, no_salto);
				}
				no_ini = no_ini->prox;
				no_salto = buscaN(no_ini, p, l->qtd);
			}
		p = p / 2;
	}
	return l;
}


