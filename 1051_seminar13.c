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
	NodPrincipal* adresaNodPrincipal;
	NodSecundar* next;
};

struct nodStiva {
	int id;
	NodStiva* next;
};

void afisareOras(Oras o) {
	printf("%d. NUmele orasului este: %s\n", o.id, o.nume);
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
		NodStiva* aux = *cap;
		*cap = (*cap)->next;
		free(aux);
		return rezultat;
	}
	else return -1;
}

void inserareListaPrincipala(NodPrincipal** cap, Oras o) {
	NodPrincipal* nou = (NodPrincipal*)malloc(sizeof(NodPrincipal));
	nou->info = o;
	nou->vecini = NULL;
	nou->next = NULL;
	if (*cap) {
		NodPrincipal* aux = *cap;
		while (aux->next) {
			aux = aux->next;
		}
		aux->next = nou;
	}
	else {
		*cap = nou;
	}
}

void inserareListaSecundara(NodSecundar** cap, NodPrincipal* vecin) {
	NodSecundar* nou = (NodSecundar*)malloc(sizeof(NodSecundar));
	nou->adresaNodPrincipal = vecin;
	nou->next=NULL;
	if (*cap) {
		NodSecundar* temp = *cap;
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

void inserareArc(NodPrincipal* graf, int idStart, int idStop) {
	NodPrincipal* nodStart = cautaNodDupaID(graf,idStart);
	NodPrincipal* nodStop = cautaNodDupaID(graf, idStop);
	if (nodStart != NULL && nodStop != NULL) {
		inserareListaSecundara(&nodStart->vecini, nodStop);
		inserareListaSecundara(&nodStop->vecini, nodStart);
	}
}

void parcurgereAdancime(NodPrincipal* graf, int idPlecare, int nrNoduri) {
	/*
	1.luam o stiva si un vector de vizitate initializat cu 0 pe toate pozitiile
	2. inseram nodul de plecare in stiva si il marcam ca vizitat
	//incepem parcurgerea
	3. scoatem un nod din stiva,
	4. afisam nod extras
	5. cautam vecinii nevizitati, ii inseram in stiva si ii marcam ca vizitati
	6. ne intoarcem la pasul 3 pana cand stiva este goala

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
		NodSecundar* temp = nodCurent->vecini;
		while (temp) {
			if (vizitate[temp->adresaNodPrincipal->info.id - 1] == 0) {
				push(&stiva, temp->adresaNodPrincipal->info.id);
				vizitate[temp->adresaNodPrincipal->info.id - 1] = 1;
			}
			temp = temp->next;
		}

	}

}

void main() {
	NodPrincipal* graf = NULL;
	int nrNoduri = 0;
	printf("Cate orase avem:");
	scanf("%d", &nrNoduri);
	for (int i = 0; i < nrNoduri; i++) {
		printf("Numele orasului %d:", (i + 1));
		char buffer[20];
		scanf("%s", buffer);
		Oras o;
		o.id = i + 1;
		o.nume = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		strcpy(o.nume, buffer);
		inserareListaPrincipala(&graf, o);
	}
	int nrArce = 0;

	printf("Cate arce avem:");
	scanf("%d", &nrArce);
	for (int i = 0; i < nrArce; i++) {
		int idStart = 0;
		int idStop = 0;
		printf("De la ce nod pleaca arcul:");
		scanf("%d", &idStart);
		printf("Pana ce nod merge arcul:");
		scanf("%d", &idStop);
		inserareArc(graf, idStart, idStop);
	}

	parcurgereAdancime(graf, 1, nrNoduri);

}