//#include <stdio.h>
//#include <malloc.h>
//
//typedef struct Piata Piata;
//typedef struct HashTable HashTable;
//typedef struct nodLs Nod;
//
//struct Piata {
//	char* nume;
//	int nrTarabe;
//};
//
//struct HashTable {
//	int dim;
//	Nod**lista;
//};
//
//int functieHash(char* nume,int dimensiuneTabela) {
//	int suma = 0;
//	for (int i = 0; i < strlen(nume); i++) {
//		suma += nume[i];
//	}
//	return suma%dimensiuneTabela;
//}
//
//
//struct nodLs {
//	Piata informatie;
//	Nod* next;
//};
//
//HashTable initHashTable(int dim) {
//	HashTable tabela;
//	tabela.dim = dim;
//	tabela.lista = malloc(sizeof(Nod*) * dim);
//	for (int i = 0; i < dim; i++) {
//		tabela.lista[i] = NULL;
//	}
//	return tabela;
//}
//
//Piata initializarePiata(const char* nume, int nrTarabe) {
//	Piata p;
//	p.nume = malloc(sizeof(char) * (strlen(nume) + 1));
//	strcpy(p.nume, nume);
//	p.nrTarabe = nrTarabe;
//	return p;
//}
//
//void inserareLista(Nod** cap, Piata p) {
//	Nod* nou = malloc(sizeof(Nod));
//	nou->informatie = p;
//	nou->next = NULL;
//	if ((*cap) == NULL) {
//		(*cap) = nou;
//	}
//	else {
//		Nod* copie = (*cap);
//		while (copie->next != NULL) {
//			copie = copie->next;
//		}
//		copie->next = nou;
//	}
//}
//
//void inserarePiataInHashTable(HashTable hash,Piata p) {
//	int poz;
//	poz = functieHash(p.nume, hash.dim);
//	if (hash.lista[poz] != NULL) {
//		//avem coliziune
//		inserareLista(&hash.lista[poz], p);
//	}
//	else {
//		inserareLista(&hash.lista[poz], p);
//	}
//}
//
//void afisareHashTable(HashTable tabela) {
//	for (int i = 0; i < tabela.dim; i++) {
//		printf("\nPozitia %d.\n", i);
//		for (Nod* pas = tabela.lista[i]; pas != NULL; pas=pas->next) {
//			printf("Piata %s are %d tarabe.\n", pas->informatie.nume, pas->informatie.nrTarabe);
//		}
//	}
//}
//
//Piata cautarePiataDupaNume(HashTable tabela, const char* nume)
//{
//	int pozitie;
//	pozitie = functieHash(nume, tabela.dim);
//	
//	
//		Nod* aux=tabela.lista[pozitie];
//		while (aux && strcmp(aux->informatie.nume,nume)!=0)
//		{
//			aux = aux->next;
//		}
//		if (aux)
//			return initializarePiata(aux->informatie.nume, aux->informatie.nrTarabe);
//		else
//			return initializarePiata("NA", 0);
//
//}
//
//int main() {
//	Piata p0;
//	HashTable tabela;
//	tabela = initHashTable(5);
//	inserarePiataInHashTable(tabela, initializarePiata("Matache", 20));
//	inserarePiataInHashTable(tabela, initializarePiata("Obor", 15));
//	inserarePiataInHashTable(tabela, initializarePiata("Unirii", 12));
//	inserarePiataInHashTable(tabela, initializarePiata("Amzei", 13));
//	inserarePiataInHashTable(tabela, initializarePiata("Romana", 25));
//	inserarePiataInHashTable(tabela, initializarePiata("Drumul Taberei", 30));
//	afisareHashTable(tabela);
//
//	p0 = cautarePiataDupaNume(tabela, "Romana");
//	printf("Piata cautata se numeste %s si are %d tarabe", p0.nume, p0.nrTarabe);
//}