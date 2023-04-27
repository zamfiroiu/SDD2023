#include<stdio.h>
#include<malloc.h>
typedef struct Librarie Librarie;
typedef struct Nod Nod;
typedef struct HashTable HashTable;

struct Librarie {
	char* denumire;
	int nrCarti;
};

Librarie creareLibrarie(const char* nume, int nrCarti) {
	Librarie l;
	l.denumire = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
	strcpy(l.denumire, nume);
	l.nrCarti = nrCarti;

	return l;
}

struct Nod {
	Librarie info;
	Nod* next;
};

struct HashTable {
	Nod** vector;
	int dim;
};

int functieHash(int dim, const char* denumire) {
	return strlen(denumire) % dim;
}

HashTable creareTabela(int dim) {
	HashTable ht;
	ht.dim = dim;
	ht.vector = (Nod**)malloc(sizeof(Nod*) * dim);
	for (int i = 0; i < dim; i++) {
		ht.vector[i] = NULL;
	}
	return ht;
}

//nu insereaza niciodata primul element
void inserareInLista(Nod* cap, Librarie l) {
	Nod* temp = malloc(sizeof(Nod));
	temp->info = l;
	temp->next = NULL;
	while (cap->next) {
		cap = cap->next;
	}
	cap->next = temp;
}

void inserareLibrarieInTabela(Librarie l, HashTable h) {
	int cod = functieHash(h.dim, l.denumire);
	if (h.vector[cod] == NULL) {
		h.vector[cod] = malloc(sizeof(Nod));
		h.vector[cod]->info = l;
		h.vector[cod]->next = NULL;
	}
	else {
		//avem coliziune
		inserareInLista(h.vector[cod], l);
	}
}

void afisareLibrarie(Librarie l) {
	printf("Libraria %s are %d carti\n", l.denumire, l.nrCarti);
}

void afisareLista(Nod* cap) {
	while (cap) {
		afisareLibrarie(cap->info);
		cap = cap->next;
	}
}

void afisareTabela(HashTable h) {
	for (int i = 0; i < h.dim; i++) {
		printf("\nPozitia %d\n", i);
		afisareLista(h.vector[i]);
	}
}

Librarie cautaLibrarieDupaDenumire(HashTable h, const char* denumire) {
	int poz = functieHash(h.dim, denumire);
	Nod* aux = h.vector[poz];
	while (aux && strcmp(aux->info.denumire, denumire) != 0){
		aux = aux->next;
	}
	if (aux) {
		return creareLibrarie(aux->info.denumire, aux->info.nrCarti);
	}
	else {
		return creareLibrarie("N/A", 0);
	}
}

void main() {
	HashTable ht=creareTabela(5);
	inserareLibrarieInTabela(creareLibrarie("Carturesti", 400), ht);
	inserareLibrarieInTabela(creareLibrarie("Humanitas", 300), ht);
	inserareLibrarieInTabela(creareLibrarie("Delvin", 200), ht);
	inserareLibrarieInTabela(creareLibrarie("Eminescu", 140), ht);
	inserareLibrarieInTabela(creareLibrarie("Sadoveanu", 467), ht);
	inserareLibrarieInTabela(creareLibrarie("Diverta", 734), ht);

	afisareTabela(ht);
	Librarie l = cautaLibrarieDupaDenumire(ht,"Sadov65eanu");
	printf("Libraria cautata: \n");
	afisareLibrarie(l);
}
