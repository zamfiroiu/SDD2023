//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct task Task;
//typedef struct heap Heap;
//
//struct task {
//	int prioritate;
//	char* denumire;
//};
//
//struct heap {
//	Task* vector;
//	int dimensiune;
//};
//
//Task Initializare(int prioritate, char* denumire) {
//	Task t;
//	t.prioritate = prioritate;
//	t.denumire = malloc(strlen(denumire) + 1);
//	strcpy_s(t.denumire, strlen(denumire) + 1, denumire);
//	return t;
//}
//
//void afisareTask(Task t) {
//	printf("Taskul %s are prioritatea %d.\n", t.denumire, t.prioritate);
//
//}
//
//Heap initHeap(int dim)
//{
//	Heap h;
//	h.dimensiune = dim;
//	h.vector = malloc(sizeof(Task)*dim);
//	return h;
//}
//
//void afisareHeap(Heap h) {
//	for (int i = 0;i< h.dimensiune; i++) {
//		afisareTask(h.vector[i]);
//	}
//}
//
//void filtrareHeap(int pozitieRadacina, Heap h) {
//	int pozitieFiuDreapta = 2 * pozitieRadacina + 2;
//	int pozitieFiuStanga = 2 * pozitieRadacina + 1;
//
//	int indexMaxim = pozitieRadacina;
//
//	
//	if ( pozitieFiuDreapta < h.dimensiune && 
//		h.vector[indexMaxim].prioritate
//		< h.vector[pozitieFiuDreapta].prioritate) {
//		indexMaxim = pozitieFiuDreapta;
//	}
//
//	if (pozitieFiuStanga < h.dimensiune &&
//		h.vector[indexMaxim].prioritate < h.vector[pozitieFiuStanga].prioritate) {
//		indexMaxim = pozitieFiuStanga;
//	}
//
//	if (pozitieRadacina != indexMaxim) {
//		Task taskDeMutat = h.vector[indexMaxim];
//		h.vector[indexMaxim] = h.vector[pozitieRadacina];
//		h.vector[pozitieRadacina] = taskDeMutat;
//		if (2*indexMaxim+1<h.dimensiune) {
//			filtrareHeap(indexMaxim, h);
//		}
//	}
//
//}
//
//void InserareTask(Task t, Heap* h) {
//	Task* vectorTemp = malloc(sizeof(Task)*(h->dimensiune +1));
//	for (int i = 0; i < h->dimensiune; i++) {
//		vectorTemp[i] = h->vector[i];
//	}
//	vectorTemp[h->dimensiune] = t;
//	h->dimensiune++;
//	free(h->vector);
//	h->vector = vectorTemp;
//	for (int i = ((*h).dimensiune - 1) / 2; i >= 0; i--) {
//		filtrareHeap(i, (*h));
//	}
//
//}
//
//
//
//void main()
//{
//	Heap h;
//	h = initHeap(6);
//	h.vector[0] = Initializare(3,"Structuri de date");
//	h.vector[1] = Initializare(7, "PL SQL");
//	h.vector[2] = Initializare(9, "PWA");
//	h.vector[3] = Initializare(4, "PEAG");
//	h.vector[4] = Initializare(2, "POO");
//	h.vector[5] = Initializare(5, "SQL");
//	afisareHeap(h);
// 
	////pentru determinarea ultimului parinte scadem 2 nu 1
//	for (int i = (h.dimensiune - 2) / 2; i >= 0; i--) {
//		filtrareHeap(i, h);
//	}
//	printf("\n");
//	afisareHeap(h);
//
//	InserareTask(Initializare(14, "fotbal"),&h);
//	afisareHeap(h);
//
//}