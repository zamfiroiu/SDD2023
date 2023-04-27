#include <stdio.h>
#include<malloc.h>
typedef struct Restaurant Restaurant;
typedef struct Nod Nod;
typedef struct HashTable HashTable;

typedef struct Restaurant {
	char* nume;
	int capacitate;
}Restaurant;

typedef struct Nod {
	Restaurant info;
	Nod* next;
}Nod;

typedef struct HashTable {
	Nod** lista;
	int dimensiune;
}HashTable;

int hash(const char* nume, int dimensiune) {
	int suma = 0;
	for (int i = 0; i < strlen(nume); i++) {
		suma += nume[i];
	}
	suma = suma % dimensiune;
	return suma;
}

Restaurant init(const char* nume, int capacitate) {
	Restaurant r;
	r.nume = malloc(strlen(nume) + 1);
	strcpy_s(r.nume, strlen(nume) + 1, nume);
	r.capacitate = capacitate;
	return r;
}

HashTable initializareHashTable(int dimensiune) {
	HashTable hashTable;
	hashTable.dimensiune = dimensiune;
	hashTable.lista = malloc(sizeof(Nod*) * dimensiune);
	for (int i = 0; i < dimensiune; i++) {
		hashTable.lista[i] = NULL;
	}
	return hashTable;
}

void inserareLaFinalLista(Nod** lista, Restaurant r) {
	Nod* nod = malloc(sizeof(Nod));
	nod->info = r;
	nod->next = NULL;
	if ((*lista) == NULL) {
		(*lista) = nod;
	}
	else {
		Nod* aux = (*lista);
		while (aux->next) {
			aux = aux->next;
		}
		aux->next = nod;
	}
}

void inserareRestaurantInTabela(HashTable hashTable, Restaurant r) {
	int hashCode = hash(r.nume, hashTable.dimensiune);
	if (hashTable.lista[hashCode] == NULL) {
		inserareLaFinalLista(&hashTable.lista[hashCode], r);
	}
	else {
		//aici avem coliziune
		inserareLaFinalLista(&hashTable.lista[hashCode], r);
	}
}
//afisare Restaurant
void afisareRestaurant(Restaurant r) {
	printf("\n Restaurantul %s are %d locuri.", r.nume, r.capacitate);
}

//afisare hashTable
void afisareHashTable(HashTable ht) {
	for (int i = 0; i < ht.dimensiune; i++) {
		Nod* aux = ht.lista[i];
		printf("\n\nPozitia %d:", i);
		while (aux)
		{
			afisareRestaurant(aux->info);
			aux = aux->next;
		}
	}
}

Restaurant cautaRestaurantDupaNume(HashTable ht,const char* nume) {
	int hashCode = hash(nume, ht.dimensiune);
	Nod* aux = ht.lista[hashCode];
	while (aux && strcmp(aux->info.nume, nume) != 0) {
		aux = aux->next;
	}
	if (aux == NULL) 
		return init("Not Found", 0);
	return init (aux->info.nume,aux->info.capacitate);
}
void stergeLista(Nod** n) {
	Nod* aux = *n;
	while (aux) {
		free(aux->info.nume);
		Nod* temp = aux->next;
		free(aux);
		aux = temp;
	}
	*n = NULL;
}
void stergeHashTable(HashTable* ht) {
	for (int i = 0; i < ht->dimensiune; i++) {
		stergeLista(&ht->lista[i]);
	}
	free(ht->lista);
	ht->lista = NULL;
	ht->dimensiune = 0;
}
int main() {
	HashTable hashTable = initializareHashTable(5);
	inserareRestaurantInTabela(hashTable, init("La Cocos", 25));
	inserareRestaurantInTabela(hashTable, init("KFC", 125));
	inserareRestaurantInTabela(hashTable, init("MC", 200));
	inserareRestaurantInTabela(hashTable, init("Trattoria", 60));
	inserareRestaurantInTabela(hashTable, init("Pizza Hut", 75));
	inserareRestaurantInTabela(hashTable, init("Casa Dacilor", 29));
	afisareHashTable(hashTable);

	printf("\n");

	Restaurant r = cautaRestaurantDupaNume(hashTable, "Pizza Hut");
	afisareRestaurant(r);

	stergeHashTable(&hashTable);
	printf("%d", hashTable.dimensiune);
	return 0;
}