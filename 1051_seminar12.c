//#define _CRT_SECURE_NO_WARNINGS
//#include<malloc.h>
//#include<string.h>
//#include<stdlib.h>
//#include<stdio.h>
//
//typedef  struct Adapost {
//	char* tipAnimal;
//	int nrAnimale;
//}Adapost;
//
//Adapost creareAdapost(const char* tipAnimal, int nrAnimale) {
//	Adapost a;
//	a.tipAnimal = (char*)malloc(sizeof(char) * (strlen(tipAnimal) + 1));
//	strcpy(a.tipAnimal, tipAnimal);
//	a.nrAnimale = nrAnimale;
//	return a;
//}
//
//void afisareAdapost(Adapost a) {
//	printf("\nTip animal: %s, nr animale: %d", a.tipAnimal, a.nrAnimale);
//}
//
//typedef struct nod {
//	Adapost info;
//	struct nod* next;
//}nod;
//
//
//void push(nod** Marius, Adapost adapost) {
//	nod* nou = malloc(sizeof(nod));
//	nou->info = adapost;
//	nou->next = *Marius;
//	*Marius = nou;
//}
//
//Adapost pop(nod** nodLista) {
//	if (*nodLista != NULL) {
//		Adapost info = (*nodLista)->info;
//		nod* nodNou = *nodLista;
//		(*nodLista) = (*nodLista)->next;
//		free(nodNou);
//		return info;
//	}
//	else {
//		return creareAdapost("imposibil", -1);
//	}
//
//}
//
//void afisareAdaposturi(nod** stiva) {
//	nod* aux = NULL;
//	while (*stiva != NULL) {
//		Adapost a = pop(stiva);
//		afisareAdapost(a);
//		push(&aux, a);
//	}
//	while (aux) {
//		push(stiva, pop(&aux));
//	}
//}
//
//
//int calculeazaNumarAnimale(nod** stiva) {
//	nod* aux = NULL;
//	int nrAnimale = 0;
//	while (*stiva != NULL) {
//		Adapost a = pop(stiva);
//		nrAnimale += a.nrAnimale;
//		push(&aux, a);
//	}
//	while (aux) {
//		push(stiva, pop(&aux));
//	}
//
//	return nrAnimale;
//}
//
//void main() {
//	Adapost adapostPisici = creareAdapost("Pisici", 30);
//	Adapost adapostCaini = creareAdapost("Caini", 20);
//	Adapost adapostVulturi = creareAdapost("Vulturi", 7);
//
//	nod* cap=NULL;
//
//	push(&cap, adapostPisici);
//	push(&cap, adapostCaini);
//	push(&cap, adapostVulturi);
//
//	afisareAdaposturi(&cap);
//	printf("\n\n");
//	afisareAdaposturi(&cap);
//
//}
