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
//void main() {
//	Librarie l, l2;
//	l = initializeazaLibrarie("Carturesti", 500, 200);
//	l2 = initializeazaLibrarie("Humanitas", 820, 350);
//
//	Nod* cap = NULL;
//	
//	inserareInceput(cap, l);
//	cap = inserareInceput(cap, l2);
//
//
//	afisareLista(cap);
//
//	Librarie l3 = initializeazaLibrarie("Anticariat", 3500, 67.5f);
//	cap = inserareInceput(cap, l3);
//	printf("\n\n");
//
//	afisareLista(cap);
//	Nod* cap2 = NULL;
//	inserareFinal(&cap2, initializeazaLibrarie("Librarie23", 343, 70.4));
//	inserareFinal(&cap2, initializeazaLibrarie("Lib3", 354, 79.4));
//	afisareLista(cap2);
//
//	while (cap) {
//		Nod* p = cap->next;
//		free(cap->info.nume);
//		free(cap);
//		cap = p;
//	}
//
//	while (cap2) {
//		Nod* p = cap2;
//		cap2 = cap2->next;
//		free(p->info.nume);
//		free(p);
//	}
//
//}
//
//
//
