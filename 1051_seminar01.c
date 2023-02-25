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
//	free(f.nrFire);
//	free(f.nume);
//	free(f.preturi);
//}