#include<stdio.h>
#include<malloc.h>

struct Restaurant {
	int cod;
	char *nume;
	unsigned int nrAngajati;
	float *salarii;
	float suprafata;
};

struct Restaurant initializare (int cod, const char* nume, unsigned int nrAngajati, const float* salarii, float suprafata) {
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

}

void main() {
	float salarii[] = { 2000, 1650, 4000 };
	struct Restaurant r = initializare(23, "KFC", 3, salarii, 120);
	afisare(r);

	free(r.nume);
	free(r.salarii);
}