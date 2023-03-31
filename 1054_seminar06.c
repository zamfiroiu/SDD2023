#include<stdio.h>
#include<malloc.h>

typedef struct Frizerie Frizerie;
typedef struct Nod Nod;
typedef struct NodLdi NodLdi;
typedef struct ListaDubla ListaDubla;

typedef struct Frizerie {
	char* nume;
	int nrMediuClienti;
	float costServiciu;
};
typedef struct Nod Nod;
struct Nod {
	struct Frizerie frizerie;
	struct Nod* next;

};

struct NodLdi {
	struct Frizerie info;
	NodLdi* prev;
	NodLdi* next;
};

struct ListaDubla {
	NodLdi* prim;
	NodLdi* ultim;
};


void afisare(struct Frizerie f) {
	printf("%s ", f.nume);
	printf("%d ", f.nrMediuClienti);
	printf("%f ", f.costServiciu);
	printf("\n");
}

void inserareLaInceputLdi(ListaDubla *lista,Frizerie f)
{
	NodLdi* nod;
	nod = malloc(sizeof(NodLdi));
	nod->info = f;
	nod->prev = NULL;
	nod->next = lista->prim;
	//nod->next->prev = nod;
	if (lista->prim)
	{
		lista->prim->prev = nod;
		lista->prim = nod;
	}
	else
	{
		lista->prim = nod;
		lista->ultim = nod;
	}
}

void afisareListaDublaDeLaInceput(ListaDubla lista)
{
	NodLdi *aux=lista.prim;
	while (aux != NULL)
	{
		afisare(aux->info);
		aux = aux->next;
	}
}


void afisareListaDublaDeLaFinal(ListaDubla lista) {
	while (lista.ultim != NULL)
	{
		afisare(lista.ultim->info);
		lista.ultim = lista.ultim->prev;
	}
}

void inserareLaSfarsitLDI(ListaDubla* lista, Frizerie f)
{
	NodLdi* nod;
	nod = malloc(sizeof(NodLdi));
	nod->next = NULL;
	nod->info = f;
	nod->prev = lista->ultim;
	if (lista->ultim != NULL)
	{
		lista->ultim->next = nod;
		lista->ultim = nod;
	}
	else
	{
		lista->prim = nod;
		lista->ultim = nod;
	}
}

struct Frizerie initializareFrizerie(char* fnume, int fnrMediuClienti, float fcostServiciu) {
	struct Frizerie f1;
	f1.nume = malloc(sizeof(char) * (strlen(fnume) + 1));
	strcpy_s(f1.nume, strlen(fnume) + 1, fnume);
	f1.nrMediuClienti = fnrMediuClienti;
	f1.costServiciu = fcostServiciu;

	return f1;
}

void afisareLista(Nod* primNod)
{
	while (primNod != NULL)
	{
		afisare(primNod->frizerie);
		primNod = primNod->next;
	}
}

void pushBack(Nod** head, struct Frizerie f)
{
	Nod* newNod;
	newNod = malloc(sizeof(Nod));
	newNod->frizerie = f;
	newNod->next = NULL;
	if (*head != NULL)
	{


		Nod* p = *head;

		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = newNod;
	}
	else
	{
		*head = newNod;

	}
}

Nod* pushFront(Nod* ptrNod, struct Frizerie f) {
	Nod* nod;
	nod = malloc(sizeof(Nod));
	nod->frizerie = f;
	nod->next = ptrNod;
	return nod;
}

void stergereLista(ListaDubla* lista) {

	NodLdi* temp = lista->prim;

	while (temp != NULL) {
		free(temp->info.nume);
		temp = temp->next;
		if (temp != NULL) {
			free(temp->prev);
		}
		
	}

	free(lista->ultim);

	lista->prim = NULL;
	lista->ultim = NULL;

}

//functie care sterge o frizerie dupa un anumit numar de clienti
void stergereNod(ListaDubla* list, int nrMediuClienti) {

	NodLdi* current = list->prim;
	
	while (current != NULL && current->info.nrMediuClienti != nrMediuClienti) {
		current = current->next;
	}

	if (current != NULL) {
		if (current->prev != NULL) {
			current->prev->next = current->next;
		}
		else {
			list->prim = current->next;
		}

		if (current->next != NULL) {
			current->next->prev = current->prev;
		}
		else {
			list->ultim = current->prev;
		}

	}
}






void main()
{
	Frizerie f1 = initializareFrizerie("Frizerie 1", 6, 19.3);
	Frizerie f2 = initializareFrizerie("Frizerie 2", 7, 20.5);
	ListaDubla lista;
	lista.prim = NULL;
	lista.ultim = NULL;
	inserareLaInceputLdi(&lista, f1);
	inserareLaInceputLdi(&lista, f2);

	afisareListaDublaDeLaInceput(lista);
	Frizerie f3 = initializareFrizerie("Frizerie 3", 3, 30.5);
	Frizerie f4 = initializareFrizerie("Frizerie 4", 4, 40.5);


	inserareLaSfarsitLDI(&lista, f3);
	inserareLaSfarsitLDI(&lista, f4);
	printf("afisare dupa inserare:\n");

	afisareListaDublaDeLaInceput(lista);

	printf("\n\nafisare de la sfarsit\n");
	afisareListaDublaDeLaFinal(lista);

	stergereNod(&lista, 7);
	stergereNod(&lista, 4);
	printf("\n\nAfisare dupa stergere nod: \n");
	afisareListaDublaDeLaInceput(lista);


	stergereLista(&lista);
	printf("\n\nAfisare dupa stergere: \n");
	afisareListaDublaDeLaFinal(lista);

	

}