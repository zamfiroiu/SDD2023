//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//typedef struct Florarie Florarie;
//
//struct Florarie {
//	char *nume;
//	int nrTipuriFlori;
//	float* preturi;
//	int* nrFire;
//};
//
//struct Florarie createFlorarie(char*nume, int nrTpuriFlori, float*preturi, int*nrFire) {
//	struct Florarie f;
//	f.nume = malloc(strlen(nume)+1);//size de char 1
//	strcpy(f.nume, nume);
//	f.nrTipuriFlori = nrTpuriFlori;
//	f.preturi = malloc(f.nrTipuriFlori * sizeof(float));
//	f.nrFire = malloc(f.nrTipuriFlori * sizeof(int));
//	for (int i = 0; i < f.nrTipuriFlori; i++) {
//		f.nrFire[i] = nrFire[i];
//		f.preturi[i] = preturi[i];
//	}
//	return f;
//}
//
//void afisareFlorarie(struct Florarie f)
//{
//	printf("\nNumele florariei este: %s", f.nume);
//	printf("\nNumarul tipurilor de flori este: %d", f.nrTipuriFlori);
//	printf("\nStocul si pretul:");
//	for (int i = 0; i < f.nrTipuriFlori; i++)
//	{
//		printf("\n%d | %5.2f", f.nrFire[i], f.preturi[i]);
//	}
//}
//void editNume(struct Florarie *f, char* nume)
//{
//	free((*f).nume);
//	(*f).nume = malloc(strlen(nume) + 1);
//	strcpy((*f).nume, nume);
//
//}
//struct Florarie deepCopy(struct Florarie f) {
//	struct Florarie copie;
//	copie.nume = malloc(strlen(f.nume) + 1);//size de char 1
//	strcpy(copie.nume, f.nume);
//	copie.nrTipuriFlori = f.nrTipuriFlori;
//	copie.preturi = malloc(copie.nrTipuriFlori * sizeof(float));
//	copie.nrFire = malloc(copie.nrTipuriFlori * sizeof(int));
//	for (int i = 0; i < copie.nrTipuriFlori; i++) {
//		copie.nrFire[i] = f.nrFire[i];
//		copie.preturi[i] = f.preturi[i];
//	}
//	return copie;
//}
//
//struct Florarie* adaugareFlorarie(struct Florarie f, struct Florarie* florarii, int *nrFlorarii)
//{
//	struct Florarie* nou = malloc(sizeof(struct Florarie) * ((*nrFlorarii) + 1));
//	for (int i = 0; i < (*nrFlorarii); i++)
//	{
//		nou[i] = florarii[i];
//	}
//	nou[(*nrFlorarii)] = f;
//	(*nrFlorarii)++;
//	return nou;
//}
//float totalProfit(struct Florarie* f, int nrFlorarii) {
//	float suma = 0;
//	for (int i = 0; i < nrFlorarii; ++i) {
//		for (int j = 0; j < f[i].nrTipuriFlori; ++j) {
//			suma += f[i].preturi[j] * f[i].nrFire[j];
//		} 
//	}
//	return suma;
//}
//
//struct Florarie citireFlorarieDinFisier(FILE* f) {
//	char buffer[50];
//	fscanf(f, "%s", buffer);
//	struct Florarie florarie;
//	florarie.nume = malloc(strlen(buffer) + 1);
//	strcpy_s(florarie.nume, (strlen(buffer)+1),buffer);
//	fscanf(f, "%d", &florarie.nrTipuriFlori);
//	florarie.preturi = malloc(florarie.nrTipuriFlori * sizeof(float));
//	florarie.nrFire = malloc(florarie.nrTipuriFlori * sizeof(int));
//	for (int i = 0; i < florarie.nrTipuriFlori; i++)
//	{
//		fscanf(f, "%f", &florarie.preturi[i]);
//	}
//	for (int i = 0; i < florarie.nrTipuriFlori; i++)
//	{
//		fscanf(f, "%d", &florarie.nrFire[i]);
//	}
//	return florarie;
//
//}
//
//struct Florarie* citireFlorariiDinFisier(const char* fileName,int *nr)
//{
//	FILE* f;
//
//	f = fopen(fileName, "r");
//	fscanf(f, "%d", nr);
//	struct Florarie* florarii = malloc(sizeof(struct Florarie) * (*nr));
//	for (int i = 0; i < *nr; i++)
//	{
//		florarii[i] = citireFlorarieDinFisier(f);
//	}
//	return florarii;
//
//
//}
//
//void afisareFlorarii(struct Florarie* florarii, int nr ) {
//	for (int i = 0; i < nr; i++) {
//		afisareFlorarie(florarii[i]);
//	}
//
//}
//
//struct Florarie** generareMatrice(Florarie* florarii, int lungimeFlorarii, int** dimensiuni, int* nrCategorii)
//{
//	//trebuie sa contorizam nr. de categorii 
//	//in urma calcului, a reiesit 3
//	*nrCategorii = 3;
//	*dimensiuni = malloc(sizeof(int)  * (*nrCategorii));
//	Florarie** matriceFlorarie = malloc(sizeof(Florarie*) * (*nrCategorii));
//
//	for (int i = 0; i < *nrCategorii; i++)
//	{
//		(*dimensiuni)[i] = 0;
//		matriceFlorarie[i] = NULL;
//	}
//
//	for (int i = 0; i < lungimeFlorarii; i++) {
//		int pozitie = florarii[i].nrTipuriFlori -2;
//		matriceFlorarie[pozitie] = adaugareFlorarie(florarii[i], matriceFlorarie[pozitie], &(*dimensiuni)[pozitie]);
//		
//	}
//	return matriceFlorarie;
//}
//
////tudor sorin 
//
//void afisareMatrice(Florarie** matrice, int* dimensiuni, int numarCategorii) {
//
//	for (int i = 0; i < numarCategorii; i++) {
//		afisareFlorarii(matrice[i], dimensiuni[i]);
//		printf("\n\n");
//	}
//
//}
//
//void main() {
//
//	struct Florarie* florarii;
//	int nr=0;
//	florarii=citireFlorariiDinFisier("florarie.txt",&nr);
//	afisareFlorarii(florarii, nr);
//	int nrCategorii;
//	int* dimensiuni;
//	Florarie** matrice;
//	matrice = generareMatrice(florarii, nr, &dimensiuni, &nrCategorii);
//	afisareMatrice(matrice, dimensiuni, nrCategorii);
//	
//}