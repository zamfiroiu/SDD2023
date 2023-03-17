#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<malloc.h>
typedef struct Restaurant Restaurant;

struct Restaurant {
	int cod;
	char* nume;
	unsigned int nrAngajati;
	float* salarii;
	float suprafata;
};

struct Restaurant initializare(int cod, const char* nume, unsigned int nrAngajati, const float* salarii, float suprafata) {
	struct Restaurant r;
	r.cod = cod;
	r.nrAngajati = nrAngajati;
	r.suprafata = suprafata;
	r.nume = malloc((strlen(nume) + 1) * sizeof(char));
	strcpy(r.nume, nume);
	r.salarii = malloc(sizeof(float) * nrAngajati);
	for (int i = 0; i < nrAngajati; i++)
	{
		r.salarii[i] = salarii[i];
	}
	return r;
}

void afisare(struct Restaurant r) {
	printf("Cod: %d. Suprafata: %5.2f. Nume: %s\n", r.cod, r.suprafata, r.nume);
	printf("Salarii: ");
	for (int i = 0; i < r.nrAngajati; i++) {
		printf("%5.2f; ", r.salarii[i]);
	}
	printf("\n");

}

struct Restaurant copiereRestaurant(struct Restaurant r)
{
	struct Restaurant ra;
	ra.cod = r.cod;
	ra.nrAngajati = r.nrAngajati;
	ra.suprafata = r.suprafata;
	ra.nume = malloc((strlen(r.nume) + 1) * sizeof(char));
	strcpy(ra.nume, r.nume);
	ra.salarii = malloc(sizeof(float) * r.nrAngajati);
	for (int i = 0; i < ra.nrAngajati; i++)
	{
		ra.salarii[i] = r.salarii[i];
	}
	return ra;
}

void push_restaurant(struct Restaurant r, struct Restaurant** restaurante, int* nrRestaurante) {
	(*nrRestaurante)++; //dereferientiem pointerul

	//alocam memorie
	struct Restaurant* copieRestaurante = malloc((*nrRestaurante) * sizeof(struct Restaurant));

	//copiem fiecare restaurant
	for (int i = 0; i < (*nrRestaurante) - 1; i++) {
		copieRestaurante[i] = (*restaurante)[i]; //facem shallow copy
	}

	//adaugam noul restaurant
	copieRestaurante[(*nrRestaurante) - 1] = copiereRestaurant(r);

	//dezalocam pointerul catre vectorul initial
	free(*restaurante);

	//schimbam pointerul pentru a pointa spre vectorul modificat
	(*restaurante) = copieRestaurante;




}

int numarAngajati(struct Restaurant* vectorRestaurante, int nrRestaurante)
{
	int nrAngajati = 0;

	for (int i = 0; i < nrRestaurante; i++)
	{
		nrAngajati += vectorRestaurante[i].nrAngajati;
	}

	return nrAngajati;
}

struct Restaurant citireRestaurantDinFisier(FILE* fisier)
{
	struct Restaurant r;
	fscanf(fisier, "%d", &r.cod);
	char aux[50];
	fscanf(fisier, "%s", aux);
	r.nume = malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy(r.nume, aux);
	fscanf(fisier, "%d", &r.nrAngajati);
	r.salarii = malloc(sizeof(float) * r.nrAngajati);
	for (int i = 0; i < r.nrAngajati; i++)
	{
		fscanf(fisier, "%f", &r.salarii[i]);
	}
	fscanf(fisier, "%f", &r.suprafata);

	return r;
}

void CitireRestauranteDinFisier(const char* denumire, struct Restaurant** Vector, int* nrElemente)
{
	FILE* file = fopen(denumire, "r");
	fscanf(file, "%d", nrElemente);
	*Vector = malloc(sizeof(struct Restaurant) * (*nrElemente));
	for (int i = 0; i < (*nrElemente); i++) {
		(*Vector)[i] = citireRestaurantDinFisier(file);
	}
}

void afisareVectorRestaurante(struct Restaurant* vector, int nrRestaurante) {
	for (int i = 0; i < nrRestaurante; i++) {
		afisare(vector[i]);
	}
}
Restaurant** construieste_matrice(Restaurant* restaurante, int dimensiune, int* nrLinii, int pragSuprafata, int** nrColoane)
{
	*nrLinii = 2;
	*nrColoane = malloc(sizeof(int) * (*nrLinii));
	Restaurant** matrice = malloc(sizeof(Restaurant*) * (*nrLinii));
	for (int i = 0; i < (*nrLinii); i++)
	{
		(*nrColoane)[i] = 0;
		matrice[i] = NULL;
	}
	for (int i = 0; i < dimensiune; i++)
	{
		if (restaurante[i].suprafata < pragSuprafata)
		{
			push_restaurant(restaurante[i], &(matrice[0]), &((*nrColoane)[0]));
		}
		else
		{
			push_restaurant(restaurante[i], &(matrice[1]), &((*nrColoane)[1]));
		}
	}
	return matrice;
}
void afiseazaMatrice(Restaurant** matrice, int nrLinii, int* nrColoane)
{
	for (int i = 0; i < nrLinii; i++)
	{
		afisareVectorRestaurante(matrice[i], nrColoane[i]);
			printf("\n\n");
	}
}
void main() {

	int nrLinii=0;
	int* vectornrColoane=NULL;
	struct Restaurant* restaurante = NULL;
	int nrRestaurante = 0;
	CitireRestauranteDinFisier("restaurant.txt", &restaurante, &nrRestaurante);
	//afisareVectorRestaurante(restaurante, nrRestaurante);
	struct Restaurant** matrice = construieste_matrice(restaurante, nrRestaurante, &nrLinii, 50, &vectornrColoane);
	afiseazaMatrice(matrice, nrLinii, vectornrColoane);
}