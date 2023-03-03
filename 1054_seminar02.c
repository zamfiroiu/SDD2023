#include<stdio.h>
#include<malloc.h>

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

void main() {
	float salarii[] = { 2000, 1650, 4000 };
	struct Restaurant r = initializare(23, "KFC", 3, salarii, 120);
	afisare(r);
	struct Restaurant* restaurante;

	restaurante = malloc(sizeof(struct Restaurant));
	int nrRestaurante = 1;
	salarii[1] = 3000;
	restaurante[0] = copiereRestaurant(r);

	float salarii2[] = { 2400, 2500 };
	struct Restaurant r2 = initializare(42, "MC", 2, salarii2, 150);
	struct Restaurant r3 = initializare(24, "Burget King", 2, salarii2, 200);

	//adaugam un restaurant la vector
	push_restaurant(r2, &restaurante, &nrRestaurante);
	push_restaurant(r3, &restaurante, &nrRestaurante);

	for (int i = 0; i < nrRestaurante; i++) {
		afisare(restaurante[i]);
	}

	printf("Numarul de angajati de la toate restaurantele: %d",
		numarAngajati(restaurante, nrRestaurante));

	for (int i = 0; i < nrRestaurante; i++)
	{
		free(restaurante[i].nume);
		free(restaurante[i].salarii);
	}
	free(restaurante);
	free(r.nume);
	free(r.salarii);
}