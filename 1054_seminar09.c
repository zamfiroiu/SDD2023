#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>


struct Pacient
{
	char* nume;
	int gravitate;

};

struct Heap {
	int dimensiune;
	int numarElemente;
	struct Pacient* vector;
};

struct Pacient initializarePacient(char* numeP, int gravitateP)
{
	struct Pacient p;
	p.nume = malloc(sizeof(char) * (strlen(numeP) + 1));
	strcpy(p.nume, numeP);

	p.gravitate = gravitateP;

	return p;
}

struct Heap initializareHeap(int dimensiune) {
	struct Heap h;
	h.dimensiune = dimensiune;
	h.numarElemente = 0;
	h.vector = malloc(sizeof(struct Pacient) * dimensiune);
	return h;
}


void afisarePacient(struct Pacient p)
{
	printf("Nume:%s Gravitate:%d \n",p.nume,p.gravitate);
}

void afisareHeap(struct Heap h) {
	for (int i = 0; i < h.numarElemente; i++) {
		afisarePacient(h.vector[i]);
	}
}

void filtrare(struct Heap h, int poz)
{

	int pozS = 2 * poz + 1;
	int pozD = 2 * poz + 2;
	int pozMax = poz;

	if (pozS < h.numarElemente &&  h.vector[pozMax].gravitate < h.vector[pozS].gravitate)
	{
		pozMax = pozS;
	}

	if (pozD < h.numarElemente && h.vector[pozMax].gravitate < h.vector[pozD].gravitate)
	{
		pozMax = pozD;
	}

	if (pozMax != poz)
	{
		struct Pacient aux;

		aux = h.vector[pozMax];
		h.vector[pozMax] = h.vector[poz];
		h.vector[poz] = aux;

		if (2 * pozMax + 1 < h.numarElemente)
			filtrare(h, pozMax);

	}




}

struct Pacient extragePacientGrav(struct Heap *heap) {
	struct Pacient aux = heap->vector[0];
	heap->vector[0] = heap->vector[heap->numarElemente - 1];
	heap->vector[heap->numarElemente - 1] = aux;
	heap->numarElemente--;
	for (int i = (heap->numarElemente - 1) / 2; i >= 0; i--) {
		filtrare(*heap, i);
	}
	return aux;
}


void main()
{
	struct Heap h = initializareHeap(6);
	h.vector[0] = initializarePacient("Ion", 3);
	h.vector[1] = initializarePacient("Mihai", 4);
	h.vector[2] = initializarePacient("Vlad", 7);
	h.vector[3] = initializarePacient("Cristi", 9);
	h.vector[4] = initializarePacient("Sorin", 6);
	h.vector[5] = initializarePacient("Marcel", 2);
	h.numarElemente = 6;

	//pentru determinarea ultimului parinte scadem 2 nu 1
	for (int i = (h.numarElemente - 2) / 2; i >= 0; i--) {
		filtrare(h, i);
	}

	afisareHeap(h);

	struct Pacient p = extragePacientGrav(&h);
	
	printf("\n");
	afisareHeap(h);
	extragePacientGrav(&h); extragePacientGrav(&h); extragePacientGrav(&h); extragePacientGrav(&h); extragePacientGrav(&h);

	printf("Nr elemente: %d\n",h.numarElemente);
	afisareHeap(h);
	printf("Vector sortat:\n");
	for (int i = 0; i < h.dimensiune; i++) {
		afisarePacient(h.vector[i]);
	}
	return;
}