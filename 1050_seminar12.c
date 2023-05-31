//#include <stdio.h>
//#include <malloc.h>
//typedef struct Shaormerie Shaormerie;
//struct Shaormerie {
//	char* nume;
//	int nr_angajat;
//};
//typedef struct Nod Nod;
//struct Nod {
//	struct Shaormerie info;
//	struct Nod* next;
//};
//
//struct Shaormerie initializareShaormerie(const char* nume, int nr_angajat) {
//	struct Shaormerie aux;
//	aux.nume = malloc(sizeof(char) * (strlen(nume) + 1));
//	strcpy(aux.nume, nume);
//	aux.nr_angajat = nr_angajat;
//	return aux;
//}
//
//struct Nod* push(struct Nod* cap, Shaormerie s) {
//	Nod* nou = malloc(sizeof(Nod));
//	nou->info = s;
//	nou->next = cap;
//	return nou;
//}
//Shaormerie pop(Nod** cap) {
//	if (*cap != NULL) {
//		Shaormerie aux = (*cap)->info;
//		Nod* auxNod = *cap;
//		(*cap) = (*cap)->next;
//		free(auxNod);
//		return aux;
//	}
//	else {
//		Shaormerie aux2 = initializareShaormerie("empty", 0);
//		return aux2;
//	}
//}
//void afisareShaormerie(Shaormerie s) {
//	printf("shaormeria %s are %d angajati \n", s.nume, s.nr_angajat);
//}
//
//
//void afisareStiva(Nod** cap) {
//	Nod* aux = NULL;
//	while (*cap != NULL) {
//		Shaormerie s = pop(cap);
//		afisareShaormerie(s);
//		aux = push(aux, s);
//	}
//	while (aux) {
//		*cap = push(*cap, pop(&aux));
//	}
//}
//
//
//int calculeazaNumarAngajati(Nod** cap) {
//	Nod* aux = NULL;
//	int numarTotal = 0;
//	while (*cap != NULL) {
//		Shaormerie s = pop(cap);
//		numarTotal += s.nr_angajat;
//		aux = push(aux, s);
//	}
//	while (aux) {
//		*cap = push(*cap, pop(&aux));
//	}
//	return numarTotal;
//}
//
//int main() {
//
//	struct Shaormerie s1;
//	struct Shaormerie s2;
//	struct Shaormerie s3;
//	s1 = initializareShaormerie("Baneasa", 5);
//	s2 = initializareShaormerie("La Micutu", 10);
//	s3 = initializareShaormerie("Socului", 7);
//	Nod* cap = NULL;
//	Shaormerie s4 = pop(&cap);
//	afisareShaormerie(s4);
//	cap = push(cap, s1);
//	cap = push(cap, s2);
//	cap = push(cap, s3);
//	afisareStiva(&cap);
//	printf("\n\n");
//	afisareStiva(&cap);
//
//	return 0;
//
//}