#include <locale.h>
#include <time.h>
#include "ordena.h"

/*
OBS: tempo em milissegundos. E todos os metodos forao testados com geração de numeros aleatorios somente.
A esquerda do ponto são segundos.
ALGORITMO/QTD_ELEMENTOS|	100	 |  	1.000	|	10.000	|	100.000		|	1.000.000 
BubleSort			   |	0	 |		6		|	835		|	12.6110		|		(mais de 2 horas)
InsertionSort		   |	0	 |		1		|	177		|	16.230		|		(+- 1 hora)
SelectionSort		   |	0	 |		2		|	428		|	44.165		|		(não medido)
QuickSort			   |	0	 |		0		|	2		|	42			|		538
HeapSort			   |	0	 |		10		|	1.500	|	17.6587		|		(não medido)
ShellSort			   |	0	 |		2		|	269		|	31.572		|		(não medido)


----------------------------RESULTADO TESTES USANGO NUMEROS EM ORDEM CRESCENTE.
ALGORITMO/QTD_ELEMENTOS|	100	 |  	1.000	|	10.000	|	100.000		|	1.000.000
BubleSort			   |	0	 |		0		|	0		|		2		|		20		(POR CAUSA DA ADAPTAÇÃO DO ALGORITMO, QUE PARA QUANDO A LISTA JA ESTA EM ORDEM)
InsertionSort__________|____0____|______0_______|___0_______|		2		|		25		
SelectionSort		   |	0	 |		3		|	423		|	  53.554	|		-		(TEMPO MUITO GRANDE)
QuickSort			   |	0	 |		3		|	-		|		-		|		-	ESTOURO DA PILHA DE RECURÇÃO.
HeapSort			   |		 |				|			|				|		
ShellSort			   |		 |				|			|				|		

----------------------------RESULTADO TESTES USANGO NUMEROS EM ORDEM DECRESCENTE.
ALGORITMO/QTD_ELEMENTOS|	100	 |  	1.000	|	10.000	|	100.000		|	1.000.000
BubleSort			   |	0	 |		7		|	648		|	126.206		|		-	TEMPO MUITO GRANDE
InsertionSort		   |	0	 |		3		|	386		|	37.310		|		-	TEMPO MUITO GRANDE
SelectionSort		   |	0	 |		2		|	404		|	46.355		|	91:05.427
QuickSort			   |	0	 |		2		|	 -  	|		-		|		-	ESTOURO DA PILHA DE RECURÇÃO
HeapSort			   |	-	 |		-		|	 - 		|				|
ShellSort			   |	-	 |		-		|	 -		|		-		|		-
*/
int main() {
	setlocale(LC_ALL, "Portuguese");
	clock_t t_ini, t_fim;
	Lista *l;
	l = geraListaAleatoria(100, 500);
	//l = geraListaAleatoria(1000, 5000);
	//l = geraListaAleatoria(10000, 50000);
	//l = geraListaAleatoria(100000, 500000);
	//l = geraListaAleatoria(1000000, 5000000);
	
	//l = geraListaCrescente(100);
	//l = geraListaCrescente(1000);
	//l = geraListaCrescente(10000);
	//l = geraListaCrescente(100000);
	//l = geraListaCrescente(1000000);
	
	//l = geraListaDecrescente(100);
	//l = geraListaDecrescente(1000);
	//l = geraListaDecrescente(10000);
	//l = geraListaDecrescente(100000);
	//l = geraListaDecrescente(1000000);

	mostraElementos(l);
	printf("\n");

	/*bubleshooter*
	/*t_ini = clock(); 
	l = bubblesort(l);
	t_fim = clock();*/

	/*insertionsort*
	/*t_ini = clock();
	l = insertionsort(l);
	t_fim = clock();*/

	/*selectionsort*
	/*t_ini = clock();
	l = selectionsort(l);
	t_fim = clock();*/

	/*quick sort*
	/*t_ini = clock();
	l = quicksort(l);
	t_fim = clock();*/

	/*heapsort*/
	t_ini = clock();
	l = heapsort(l);
	t_fim = clock();

	/*shellsort*
	/*t_ini = clock();
	l = shellsort(l);
	t_fim = clock();*/

	mostraElementos(l);
	printf("\n");
	double tempo = difftime(t_fim, t_ini);
	printf("Tempo gasto: %.8f ms.\n", tempo);

	system("pause");
	return 0;
}