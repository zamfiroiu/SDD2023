//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//struct Farmacie
//{
//	char* denumire;
//	int nr_angajati;
//	float* salarii;
//	int an_infiintare;
//};
//struct Farmacie initializare(const char* denumire,int nr_angajati, float* salarii, int an_infiintare)
//{
//	struct Farmacie f;
//	f.nr_angajati =nr_angajati ;
//	f.an_infiintare = an_infiintare;
//	f.denumire = malloc((strlen(denumire) + 1)*sizeof(char));
//	strcpy(f.denumire, denumire);
//	f.salarii = malloc(sizeof(float) * nr_angajati);
//	for (int i = 0; i < nr_angajati; i++)
//	{
//		 f.salarii[i]=salarii[i];
//	}
//	return f;
//}
//
//void afisareFarmacie(struct Farmacie f)
//{
//	printf("Denumire: %s, infiintata in: %d",f.denumire,f.an_infiintare);
//	printf(", nr. angajati: %d, cu salariile: ", f.nr_angajati);
//	for (int i = 0; i < f.nr_angajati; i++)
//		printf("%5.2f, ", f.salarii[i]);
//	printf("\n");
//}
//struct Farmacie copiere(const struct Farmacie f2)
//{
//	struct Farmacie aux;
//	aux.an_infiintare = f2.an_infiintare;
//	aux.nr_angajati = f2.nr_angajati;
//	aux.denumire = malloc((strlen(f2.denumire) + 1) * sizeof(char));
//	strcpy(aux.denumire, f2.denumire);
//	aux.salarii = malloc(sizeof(float) * f2.nr_angajati);
//	for (int i = 0; i < f2.nr_angajati; i++)
//	{
//		aux.salarii[i] = f2.salarii[i];
//	}
//	return aux;
//}
//
//struct Farmacie* adaugaFarmacieInVector(struct Farmacie* farmacii, struct Farmacie f, int *nr)
//{
//	*nr = *nr + 1;
//	struct Farmacie* aux = malloc(sizeof(struct Farmacie) * (*nr));
//	for (int i = 0; i < *nr - 1; i++)
//		aux[i] = farmacii[i];
//	aux[*nr - 1] = copiere(f);
//	return aux;
//}
//
//int calculNrAngajati(struct Farmacie* farmacii, int nr) {
//	int nrTotalAngajati = 0;
//	for (int i = 0; i < nr; i++) {
//		nrTotalAngajati += farmacii[i].nr_angajati;
//	}
//	return nrTotalAngajati;
//}
//
//void main() {
//	int a = 8;
//	float* v = malloc(sizeof(float)*2);
//	v[0] = 200.4;
//	v[1] = 300.5;
//	float v2[4] = { 200,300, 4000, 200 };
//	struct Farmacie f = initializare("Tei", 2, v, 2001);
//	afisareFarmacie(f);
//	int nr_farmacii=1;
//	struct Farmacie* farmacii;
//	farmacii = malloc(sizeof(f));
//	farmacii[0] = copiere(f);
//	
//	struct Farmacie g = initializare("Catena", 2, v, 1990);
//	farmacii = adaugaFarmacieInVector(farmacii, g, &nr_farmacii);
//	struct Farmacie f3 = initializare("Dr.Max", 4, v2, 2000);
//	farmacii = adaugaFarmacieInVector(farmacii, f3, &nr_farmacii);
//	for (int i = 0; i < nr_farmacii; i++)
//	{
//		afisareFarmacie(*(farmacii+i));
//	}
//
//	int nrTotalAngajati = calculNrAngajati(farmacii, nr_farmacii);
//	printf("Numarul total de angajati este %d",nrTotalAngajati);
//
//	free(v);
//	free(f.denumire);
//	free(f.salarii);
//	for (int j = 0; j < nr_farmacii; j++)
//	{
//		free(farmacii[j].denumire);
//		free(farmacii[j].salarii);
//	}
//	free(farmacii);
//	
//	free(f3.denumire);
//	free(f3.salarii);
//	free(g.denumire);
//	free(g.salarii);
//
//
//
//}