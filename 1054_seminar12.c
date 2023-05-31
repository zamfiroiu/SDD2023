#include <stdio.h>
#include <malloc.h>
#include <string.h>


typedef struct Nod Nod;
typedef struct Tren Tren;

typedef struct Tren {
	int nrVagoane;
	char* culoare;
} Tren;

typedef struct Nod {
	Tren tren;
	Nod* next;
}Nod;

Tren creeazaTren(int nrVagoane, char* culoare) {
	Tren tren;
	tren.nrVagoane = nrVagoane;
	tren.culoare = (char*)malloc(strlen(culoare) + 1);
	strcpy_s(tren.culoare,strlen(culoare )+1, culoare);
	return tren;
}

void enqueue(Nod** lista, Tren tren) {
	Nod* temp = (Nod*)malloc(sizeof(Nod));
	temp->tren = tren;
	temp->next = NULL;
	if (*lista == NULL) {
		*lista = temp;
		return;
	}
	Nod* iterator = *lista;
	while (iterator->next != NULL) {
		iterator = iterator->next;
	}
	iterator->next = temp;
}


Tren dequeue(Nod** lista) {
	if (*lista != NULL) {
		Tren t1 = (*lista)->tren;
		Nod* a = *lista;
		(*lista)=(*lista)->next;
		free (a);
		return t1;
	}
	else {
		return creeazaTren(0,"N");
	}

}

void afisareTren(Tren t)
{
	printf("\nTrenul cu %d vagoane are culoarea %s", t.nrVagoane, t.culoare);
}

void afisareCoada(Nod** lista)
{
	Nod* temp = NULL;
	while (*lista)
	{
		Tren t = dequeue(lista);
		afisareTren(t);

		enqueue(&temp, t);

	}
	*lista = temp;
}

int calculeazaNumarVagoane(Nod** lista)
{
	Nod* temp = NULL;
	int suma = 0;
	while (*lista)
	{
		Tren t = dequeue(lista);
		suma += t.nrVagoane;

		enqueue(&temp, t);

	}
	*lista = temp;
	return suma;
}

int main() {

	Nod* lista = NULL;

	enqueue(&lista, creeazaTren(5, "Alb"));
	enqueue(&lista, creeazaTren(7, "Rosu"));
	enqueue(&lista, creeazaTren(3, "Verde"));

	afisareCoada(&lista);
	printf("\n--------------------------");
	afisareCoada(&lista);

	printf("Numar vagoane: %d", calculeazaNumarVagoane(&lista));




}