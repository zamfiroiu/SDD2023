//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//
//typedef struct Farmacie Farmacie;
//
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
//
//void afisareVectorFarmacie(struct Farmacie* f,int nr_farmacii) {
//	printf("Numarul de farmacii: %d",nr_farmacii);
//	for (int i = 0; i < nr_farmacii; i++) {
//		afisareFarmacie(f[i]);
//	}
//}
//
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
//struct Farmacie citireFisier(FILE *f)
//{
//	struct Farmacie aux;
//	char buffer[30];
//	fscanf(f, "%s", buffer);
//	aux.denumire = malloc(strlen(buffer) + 1);
//	strcpy(aux.denumire, buffer);
//	fscanf(f, "%d", &aux.nr_angajati);
//	aux.salarii = malloc(sizeof(float) * aux.nr_angajati);
//	for (int i = 0; i < aux.nr_angajati; i++) {
//		fscanf(f, "%f", &aux.salarii[i]);
//	}
//	fscanf(f, "%d", &aux.an_infiintare);
//	return aux;
//}
//struct Farmacie* citireVectorFisier(const char* nume_fisier,int* nr_farmacii)
//{
//	FILE* file=fopen(nume_fisier,"r");
//	struct Farmacie* farmacii;
//	fscanf(file, "%d", nr_farmacii);
//	farmacii = malloc(sizeof(struct Farmacie) * (*nr_farmacii));
//	for (int i = 0; i < (*nr_farmacii); i++)
//	{
//		farmacii[i]=citireFisier(file);	
//	}
//	return farmacii;
//
//}
//Farmacie** creeazaMatrice(Farmacie* farmacii, int** dimensiuni, int numarStructuri, int* numarCateg) {
//	Farmacie** matrice;
//	//aici ar fi trebuit sa stabilim numarul de categorii
//	//a fost gasit numarul 3
//	*numarCateg = 3;
//	matrice = malloc(sizeof(Farmacie*) * (*numarCateg));
//	*dimensiuni = malloc(sizeof(int) * (*numarCateg));
//	for (int i = 0; i < *numarCateg; i++) {
//		(*dimensiuni)[i] = 0;
//		matrice[i] = NULL;
//	}
//	for (int i = 0; i < numarStructuri; i++) {
//		int index = farmacii[i].an_infiintare - 2021;
//		matrice[index] = adaugaFarmacieInVector(matrice[index], farmacii[i], &((*dimensiuni)[index]));
//	}
//
//	return matrice;
//}
//
//void afisareMatrice(Farmacie** matriceFarm,int *dimensiuni,int nrLinii)
//{
//	for (int i = 0; i < nrLinii; i++) {
//		afisareVectorFarmacie(matriceFarm[i], dimensiuni[i]);
//		printf("\n\n");
//	}
//}
//
//void main() {
//	
//	int nr_farm;
//	struct Farmacie* farm=citireVectorFisier("farmacie.txt", &nr_farm);
//	//afisareVectorFarmacie(farm,nr_farm);
//	
//	Farmacie** matriceFarm;
//	int* dimensiuni;
//	int numarCateg;
//	matriceFarm = creeazaMatrice(farm, &dimensiuni, nr_farm, &numarCateg);
//	afisareMatrice(matriceFarm, dimensiuni, numarCateg);
//}