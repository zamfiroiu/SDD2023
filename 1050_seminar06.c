//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//
//typedef struct Librarie Librarie;
//
//struct Librarie
//{
//	char* nume;
//	int nr_carti;
//	float suprafata;
//
//};
//
//typedef struct Nod Nod;
//struct Nod
//{
//	Librarie info;
//	Nod* next;
//
//};
//
//typedef struct NodLdi NodLdi;
//struct NodLdi
//{
//	Librarie info;
//	NodLdi* prev;
//	NodLdi* next;
//};
//
//struct ListaDubla
//{
//	NodLdi* prim;
//	NodLdi* ultim;
//};
//
//struct ListaDubla inserareInceputLdi(struct ListaDubla lista, Librarie librarie)
//{
//	NodLdi* nou = malloc(sizeof(NodLdi));
//	nou->info = librarie;
//	nou->next = lista.prim;
//	nou->prev = NULL;
//
//	if (lista.prim)
//	{
//		lista.prim->prev = nou;
//	}
//	else
//	{
//		lista.ultim = nou;
//	}
//	lista.prim = nou;
//	return lista;
//}
//
//Nod* inserareInceput(Nod* cap, Librarie l)
//{
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = l;
//	nou->next = cap;
//	return nou;
//}
//
//
//Librarie initializeazaLibrarie(const char* nume, int nr_carti, float suprafata) {
//	Librarie l;
//	l.nr_carti = nr_carti;
//	l.suprafata = suprafata;
//	l.nume = (char*)malloc((strlen(nume) + 1) * sizeof(char));
//	strcpy(l.nume, nume);
//	return l;
//}
//
//void afisareLibrarie(Librarie l) {
//	printf("Libraria %s are %d carti si suprafata de %f mp\n", l.nume, l.nr_carti, l.suprafata);
//}
//void afisareLdi(struct ListaDubla lista) {
//	while (lista.prim) {
//		afisareLibrarie(lista.prim->info);
//		lista.prim = lista.prim->next;
//	}
//}
//
//void afisareDeLaSfarsitLdi(struct ListaDubla lista) {
//	NodLdi* p = lista.ultim;
//	while (p) {
//		afisareLibrarie(p->info);
//		p = p->prev;
//	}
//}
//
//void afisareLista(Nod* cap) {
//	while (cap != NULL) {
//		afisareLibrarie(cap->info);
//		cap = cap->next;
//	}
//}
//
//void inserareFinal(Nod** primNod, Librarie l)
//{
//	if (*primNod != NULL)
//	{
//		Nod* aux = *primNod;
//		while (aux->next != NULL)
//		{
//			aux = aux->next;
//		}
//
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = l;
//		nou->next = NULL;
//		aux->next = nou;
//	}
//	else 
//	{
//		*primNod = malloc(sizeof(Nod));
//		(*primNod)->info = l;
//		(*primNod)->next = NULL;
//	}	
//}
//
//struct ListaDubla inserareSfarsitLdi(struct ListaDubla lista, Librarie librarie) {
//	NodLdi* nou=malloc(sizeof(NodLdi));
//	nou->next = NULL;
//	nou->prev = lista.ultim;
//	nou->info = librarie;
//	if (lista.ultim != NULL) {
//		lista.ultim->next = nou;
//	}
//	else {
//		
//		lista.prim = nou;
//	}
//	lista.ultim = nou;
//
//	return lista;
//	
//}
//
////primim doua pozitii si interschimbam elementele
//typedef struct ListaDubla ListaDubla;
//
//int contorizareLdi(struct ListaDubla lista) {
//	int contor = 0;
//	while (lista.prim) {
//		contor+=1;
//		lista.prim = lista.prim->next;
//	}
//	return contor;
//}
//
////Metoda este gresita
//ListaDubla interschimbareNoduriLdi(int p1, int p2, ListaDubla lista)
//{
//	int dimensiune = contorizareLdi(lista);
//	if (dimensiune >= p1 && dimensiune >= p2 && p1!=p2)
//	{
//		NodLdi* nod1=lista.prim;
//		NodLdi* nod2=lista.prim;
//		while (nod1!=NULL && p1>1)
//		{
//			nod1 = nod1->next;
//			p1 -= 1;
//		}
//		while (nod2 != NULL && p2 > 1)
//		{
//			nod2 = nod2->next;
//			p2 -= 1;
//		}
//		NodLdi* auxnext = nod1->next;
//		NodLdi* auxprev = nod1->prev;
//		if (nod1->next)
//		{
//			nod1->next->prev = nod2;
//		}
//		if (nod1->prev)
//		{
//			nod1->prev->next = nod2;
//		}
//		nod1->next = nod2->next;
//		nod1->prev = nod2->prev;
//		if (nod2->next)
//		{
//			nod2->next->prev = nod1;
//		}
//		if (nod2->prev)
//		{
//			nod2->prev->next = nod1;
//		}
//		nod2->next=auxnext;
//		nod2->prev = auxprev;
//
//	}
//	else
//	{
//		printf("Nu se poate\n");
//	}
//	return lista;
//}
//
//void main() {
//
//	Librarie l1;
//	l1 = initializeazaLibrarie("Carturesti", 25, 150.6);
//	Librarie l2;
//	l2 = initializeazaLibrarie("Diverta", 50, 25.8);
//	struct ListaDubla lista;
//	lista.prim = NULL;
//	lista.ultim = NULL;
//	lista = inserareInceputLdi(lista, l1);
//	lista = inserareInceputLdi(lista, l2);
//	afisareLdi(lista);
//	printf("\n");
//	Librarie l3;
//	l3 = initializeazaLibrarie("Libris", 60, 70.8);
//	lista = inserareInceputLdi(lista, l3);
//	afisareLdi(lista);
//	printf("\n");
//	printf("\nInserare sfarsit\n");
//	Librarie l4;
//	l4 = initializeazaLibrarie("Antic", 50, 20.8);
//	lista = inserareSfarsitLdi(lista, l4);
//	afisareLdi(lista);
//	//printf("De la sfarsit:\n");
//	//afisareDeLaSfarsitLdi(lista);
//
//	//printf("\nInterschimbare noduri\n");
//	//lista=interschimbareNoduriLdi(2, 3, lista);
//	//afisareLdi(lista);
//}