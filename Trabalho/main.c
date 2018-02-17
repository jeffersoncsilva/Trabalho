#include <locale.h>
#include <time.h>
#include "ordena.h"

/*
OBS: tempo em milissegundos. A esquerda do ponto são segundos.
ALGORITMO/QTD_ELEMENTOS|	100	 |  	1.000	|	10.000	|	100.000		|	1.000.000 
BubleSort			   |	0	 |		6		|	835		|	12.6110		|		(mais de 2 horas)
InsertionSort		   |	0	 |		1		|	177		|	16.230		|		(+- 1 hora)
SelectionSort		   |	0	 |		2		|	428		|	44.165		|		(não medido)
QuickSort			   |	0	 |		0		|	2		|	42			|		538
HeapSort			   |	0	 |		10		|	1.500	|	17.6587		|		(não medido)
ShellSort			   |	0	 |		2		|	269		|	31.572		|		(não medido)
*/



/*#define MAX 100000

void shellSort(int *vetor, int tamanho)
{
	int i = (tamanho - 1) / 2;
	int chave, k, aux;

	while (i != 0)
	{
		do
		{
			chave = 1;
			for (k = 0; k < MAX - i; ++k)
			{
				if (vetor[k] > vetor[k + i])
				{
					aux = vetor[k];
					vetor[k] = vetor[k + i];
					vetor[k + i] = aux;
					chave = 0;
				}
			}
		} while (chave == 0);
		i = i / 2;
	}
}*/

int main() {
	setlocale(LC_ALL, "Portuguese");
	clock_t t_ini, t_fim;


	/*bubleshooter
	Lista *l = geraListaAleatoria(1000000);
	t_ini = clock(); 
	l = bubblesort(l);
	t_fim = clock();
	double tempo = difftime(t_fim, t_ini);
	printf("Tempo gasto: %.8f ms.\n", tempo);*/

	/*insertionsort
	Lista *l = geraListaAleatoria(1000000, 500000);
	mostraElementos(l); 
	printf("\n\n");
	t_ini = clock();
	l = insertionsort(l);
	t_fim = clock();
	double time = difftime(t_fim, t_ini);
	mostraElementos(l);
	printf("\nTime: %.8f ms.\n", time);*/

	/*selectionsort
	Lista *l = geraListaAleatoria(1000000, 500);
	mostraElementos(l); 
	printf("\n\n");
	t_ini = clock();
	l = selectionsort(l);
	t_fim = clock();
	double time = difftime(t_fim, t_ini);
	mostraElementos(l);
	printf("\nTime: %f\n", time);*/

	/*quick sort
	Lista *l = geraListaAleatoria(1000000, 50000000);

	printf("elementos iniciais: \n");
	mostraElementos(l);
	printf("\n");
	t_ini = clock();
	l = quicksort(l);
	t_fim = clock();
	
	mostraElementos(l);
	double time = difftime(t_fim, t_ini);
	printf("\nTime: %f\n", time);*/

	/*heapsort	
	/*Lista * l = geraListaAleatoria(100, 50);
	mostraElementos(l);
	t_ini = clock();
	l = heapsort(l);
	t_fim = clock();
	mostraElementos(l);
	double time = difftime(t_fim, t_ini);
	printf("\ntime: %f\n", time);*/

	Lista *l = geraListaAleatoria(10, 50);
	mostraElementos(l);
	printf("\ninicia shell\n");
	t_ini = clock();
	l = shellsort(l);
	t_fim = clock();
	printf("\nfim shell\n");
	mostraElementos(l);
	double time = difftime(t_fim, t_ini);
	printf("\nTime: %f\n", time);
	

	system("pause");
	return 0;
}