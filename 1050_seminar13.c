#include<stdio.h>
#include<malloc.h>

typedef struct Frizerie Frizerie;
typedef struct nodPrincipal NodPrincipal;
typedef struct nodSecundar NodSecundar;
typedef struct nodStiva NodStiva;

struct Frizerie {
	int id;
	char* denumire;
};
struct nodPrincipal {
	Frizerie info;
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

void push(NodStiva** cap, int id) {
	NodStiva* nou = (NodStiva*)malloc(sizeof(NodStiva));
	nou->id = id;
	nou->next = *cap;
	*cap = nou;
}
int pop(NodStiva** cap) {
	int rezultat = (*cap)->id;
	NodStiva* aux = *cap;
	(*cap) = (*cap)->next;
	free(aux);

	return rezultat;
}


void inserareListaPrincipala(NodPrincipal** cap, Frizerie frizerie) {
	NodPrincipal* nou = (NodPrincipal*)malloc(sizeof(NodPrincipal));
	nou->info = frizerie;
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

void afisareFrizerie(Frizerie f) {
	printf("%d. Frizeria %s.\n", f.id, f.denumire);
}
void afisareIDuriListaSecundara(NodSecundar* cap) {
	while (cap) {
		printf("%d\n", cap->adresaNod->info.id);
		cap = cap->next;
	}
}

void afisareListaPrincipala(NodPrincipal* cap) {
	while (cap) {
		afisareFrizerie(cap->info);
		afisareIDuriListaSecundara(cap->vecini);
		cap = cap->next;
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
	nou->next = NULL;
	nou->adresaNod = info;
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

void adaugareArc(NodPrincipal* graf, int idStart, int idStop) {
	NodPrincipal* nodStart = cautaNodDupaID(graf,idStart);
	NodPrincipal* nodStop = cautaNodDupaID(graf,idStop);
	if (nodStart != NULL && nodStop != NULL) {
		inserareListaSecundara(&(nodStart->vecini), nodStop);
		inserareListaSecundara(&nodStop->vecini, nodStart);
	}
}


void parcurgereAdancime(NodPrincipal* graf, int idPlecare, int nrNoduri) {
	/*
	1.creem o stiva
	2. ne luam un vector de vizitate;
	3.marcam nodul de plecare ca fiind vizitat si il punem in stiva
	incepem parcurgerea
	4. extragem nod din stiva
	4.1 Procesam nodul - afisam
	5. luam vecini nevizitati ai nodului ii punem in stiva si ii marcam ca vizitati
	6...ne intoarcem
	*/

	NodStiva* stiva = NULL;
	int* vizitate = (int*)malloc(sizeof(int) * nrNoduri);
	for (int i = 0; i < nrNoduri; i++) {
		vizitate[i] = 0;
	}

	vizitate[idPlecare - 1] = 1;
	push(&stiva, idPlecare);

	while (stiva) {
		int idCurent = pop(&stiva);
		NodPrincipal* nodCurent = cautaNodDupaID(graf, idCurent);
		afisareFrizerie(nodCurent->info);
		NodSecundar* temp = nodCurent->vecini;
		while (temp) {
			if (vizitate[temp->adresaNod->info.id - 1] == 0) {
				vizitate[temp->adresaNod->info.id - 1] = 1;
				push(&stiva, temp->adresaNod->info.id);
			}
			temp = temp->next;
		}
	}
}

void main() {
	NodPrincipal* graf = NULL;

	int nrNoduri = 0;
	printf("Numarul de noduri:");
	scanf("%d", &nrNoduri);
	for (int i = 0; i < nrNoduri; i++) {
		Frizerie f;
		f.id = i+1;
		char buffer[20];
		printf("Numele frizeriei:");
		scanf("%s", &buffer);
		f.denumire = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		strcpy(f.denumire, buffer);
		inserareListaPrincipala(&graf, f);
	}

	int nrArce = 0;

	printf("Numarul de arce:");
	scanf("%d", &nrArce);
	for (int i = 0; i < nrArce; i++) {
		int idStart = 0;
		int idStop = 0;
		printf("Arcul pleaca de la frizeria cu id-ul:");
		scanf("%d", &idStart);
		printf("Arcul se opreste la frizeria cu id-ul:");
		scanf("%d", &idStop);
		adaugareArc(graf, idStart, idStop);
	}
	afisareListaPrincipala(graf);

	parcurgereAdancime(graf, 1, nrNoduri);
}