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
//void main() {
//	int a = 8;
//	float* v = malloc(sizeof(float)*2);
//	v[0] = 200.4;
//	v[1] = 300.5;
//	struct Farmacie f = initializare("Tei", 2, v, 2001);
//	afisareFarmacie(f);
//	free(v);
//	free(f.denumire);
//	free(f.salarii);
//
//
//
//}