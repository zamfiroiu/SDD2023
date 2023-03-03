//#include<stdio.h>
//#include<malloc.h>
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
//void main() {
//	struct Florarie f;
//	float preturi[] = { 1.5, 2.5 };
//	int cantitati[] = { 10, 15 };// e pe stack
//	int* v; //avem v pe stiva si memoria pentru v e in heap
//	f = createFlorarie("Tei", 2, preturi, cantitati);
//	afisareFlorarie(f);
//	editNume(&f, "Flora");
//	afisareFlorarie(f);
//
//
//
//	struct Florarie* florarii;
//	int nrFlorarii = 1;
//	florarii = malloc(sizeof(struct Florarie));
//	florarii[0] = deepCopy(f);
//
//	struct Florarie f1;
//	f1 = createFlorarie("Tei2", 2, preturi, cantitati);
//	float preturi2[] = { 1.5,2.5,3.5 };
//	int cantitati2[] = { 15,20,30 };
//
//	struct Florarie f2;
//	f2 = createFlorarie("Tei3", 3, preturi2, cantitati2);
//	
//	florarii=adaugareFlorarie(f1, florarii, &nrFlorarii);
//	florarii = adaugareFlorarie(f2, florarii, &nrFlorarii);
//	for (int i = 0; i < nrFlorarii; i++)
//	{
//		afisareFlorarie(florarii[i]);
//	}
//	afisareFlorarie(florarii[0]);
//	printf("\n%.2f", totalProfit(florarii, nrFlorarii));
//
//	for (int i = 0; i < nrFlorarii; i++) {
//		free(florarii[i].nrFire);
//		free(florarii[i].nume);
//		free(florarii[i].preturi);
//	}
//	free(florarii);
//
//
//	free(f.nrFire);
//	free(f.nume);
//	free(f.preturi);
//}