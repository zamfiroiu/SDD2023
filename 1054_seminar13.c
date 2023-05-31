#include<stdio.h>
#include<malloc.h>

typedef struct Oras Oras;
typedef struct nodPrincipal NodPrincipal;
typedef struct nodSecundar NodSecundar;
typedef struct nodStiva NodStiva;

struct Oras {
	int id;
	char* nume;
};

struct nodPrincipal {
	Oras info;
	NodSecundar* vecini;
	NodPrincipal* next;
};

struct nodSecundar {
	NodPrincipal* adresaNod;
	NodSecundar* next;
};

struct nodStiva {
	int id;
	NodStiva* next;
};

void afisareOras(Oras oras) {
	printf("%d. Orasul %s.\n", oras.id, oras.nume);
}

void push(NodStiva** cap, int id) {
	NodStiva* nou = (NodStiva*)malloc(sizeof(NodStiva));
	nou->id = id;
	nou->next = *cap;
	*cap = nou;
}

int pop(NodStiva** cap) {
	if (*cap) {
		int rezultat = (*cap)->id;
		NodStiva* temp = *cap;
		*cap = (*cap)->next;
		free(temp);
		return rezultat;
	}
	else {
		return -1;
	}
}

void inserareListaPrincipala(NodPrincipal** cap, Oras oras) {
	NodPrincipal* nou = (NodPrincipal*)malloc(sizeof(NodPrincipal));
	nou->info = oras;
	nou->vecini = NULL;
	nou->next = NULL;
	if (*cap) {
		NodPrincipal* temp = *cap;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = nou;
	}
	else {
		*cap = nou;
	}
}

NodPrincipal* cautaNodDupaID(NodPrincipal* graf, int id) {
	while (graf && graf->info.id != id) {
		graf = graf->next;
	}
	return graf;
}

void inserareListaSecundara(NodSecundar* *cap, NodPrincipal* info) {
	NodSecundar* nou = (NodSecundar*)malloc(sizeof(NodSecundar));
	nou->adresaNod = info;
	nou->next = NULL;
	if (*cap) {
		NodSecundar* aux = *cap;
		while (aux->next) {
			aux = aux->next;
		}
		aux->next = nou;
	} else {
		*cap = nou;
	}
}

void adaugaArc(NodPrincipal* graf, int idStart, int idStop) {
	NodPrincipal* nodStart = cautaNodDupaID(graf, idStart);
	NodPrincipal* nodStop = cautaNodDupaID(graf, idStop);
	if (nodStart != NULL && nodStop != NULL) {
		inserareListaSecundara(&nodStart->vecini, nodStop);
		inserareListaSecundara(&nodStop->vecini, nodStart);
	}
}

void parcurgereInAdancime(NodPrincipal* graf, int idPlecare, int nrNoduri) {
	/*
	1. ne luam o stiva si un vector de vizitate initializat cu 0 pe toate pozitiile
	2. adaugam in stiva nodul de plecare si il marcam ca vizitat;
	//incepem procesul de parcurgere si realizam acest loop cat timp avem stiva
	3. extragem un nod din stiva;
	4. procesam nodul curent // afisare
	5. cautam nodurile vecine nevizitate....le introducem in stiva si le marcam ca vizitate
	6. ne intoracem la 3
	*/

	NodStiva* stiva = NULL;
	int* vizitate = (int*)malloc(sizeof(int) * nrNoduri);
	for (int i = 0; i < nrNoduri; i++) {
		vizitate[i] = 0;
	}
	push(&stiva, idPlecare);
	vizitate[idPlecare - 1] = 1;
	while (stiva) {
		int idCurent = pop(&stiva);
		NodPrincipal* nodCurent = cautaNodDupaID(graf, idCurent);
		afisareOras(nodCurent->info);
		NodSecundar* aux = nodCurent->vecini;
		while (aux) {
			if (vizitate[aux->adresaNod->info.id - 1] == 0) {
				push(&stiva, aux->adresaNod->info.id);
				vizitate[aux->adresaNod->info.id - 1] = 1;
			}
			aux = aux->next;
		}
	}


}

void main() {
	NodPrincipal* graf = NULL;
	int nrNoduri = 0;
	printf("Cate noduri avem:");
	scanf("%d", &nrNoduri);
	for (int i = 0; i < nrNoduri; i++) {
		Oras oras;
		oras.id = i + 1;
		printf("Numele orasului %d:", i + 1);
		char buffer[50];
		scanf("%s", buffer);
		oras.nume = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		strcpy(oras.nume, buffer);
		inserareListaPrincipala(&graf, oras);
	}

	int nrArce = 0;
	printf("Cate arce avem:");
	scanf("%d", &nrArce);
	for (int i = 0; i < nrArce; i++) {
		int idStart;
		printf("De la ce nod pleaca arcul:");
		scanf("%d", &idStart);

		int idStop;
		printf("La ce nod se opreste arcul:");
		scanf("%d", &idStop);
		adaugaArc(graf, idStart, idStop);

	}

	parcurgereInAdancime(graf, 1, nrNoduri);
}