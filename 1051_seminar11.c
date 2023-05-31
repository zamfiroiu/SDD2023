//#include<stdio.h>
//#include<malloc.h>
//typedef struct CasaDeDiscuri CasaDeDiscuri;
//typedef struct NodArbore NodArbore;
//
//struct CasaDeDiscuri
//{
//	int id;
//	char* nume;
//	float incasari;
//};
//
//struct NodArbore
//{
//	CasaDeDiscuri info;
//	NodArbore* fiuStanga;
//	NodArbore* fiuDreapta;
//};
//
//CasaDeDiscuri initializareCasa(int id, char* nume, float incasari) {
//	CasaDeDiscuri casa;
//	casa.id = id;
//	casa.nume = malloc(strlen(nume) + 1);
//	strcpy_s(casa.nume, strlen(nume) + 1, nume);
//	casa.incasari = incasari;
//	return casa;
//}
//
//void InserareNodArbore(CasaDeDiscuri casaDeDiscuri, NodArbore** radacina)
//{
//	if (*radacina != NULL)
//	{
//		if (casaDeDiscuri.id > (*radacina)->info.id)
//		{
//			InserareNodArbore(casaDeDiscuri, &(*radacina)->fiuDreapta);
//		}
//		else
//		{
//			InserareNodArbore(casaDeDiscuri, &(*radacina)->fiuStanga);
//		}
//	}
//	else
//	{
//		NodArbore* nou = malloc(sizeof(NodArbore));
//		nou->info = casaDeDiscuri;
//		nou->fiuStanga = NULL;
//		nou->fiuDreapta = NULL;
//		(*radacina) = nou;
//	}
//}
//
//int gradEchilibru(NodArbore* radacina) {
//	int a = inaltimeArbore((*radacina).fiuStanga);
//	int b = inaltimeArbore((*radacina).fiuDreapta);
//	int grEc = a - b;
//
//	return grEc;
//}
//
//NodArbore* rotireDreapta(NodArbore* radacina) {
//	NodArbore* aux = (*radacina).fiuStanga;
//	(*radacina).fiuStanga = (*aux).fiuDreapta;
//	(*aux).fiuDreapta = radacina;
//
//	return aux;
//}
//
//NodArbore* rotireStanga(NodArbore* radacina)
//{
//	NodArbore* aux = radacina->fiuDreapta;
//	radacina->fiuDreapta = aux->fiuStanga;
//	aux->fiuStanga = radacina;
//	return aux;
//}
//
//
//
//
//
//void InserareNodAVL(CasaDeDiscuri casaDeDiscuri, NodArbore** radacina)
//{
//	if (*radacina != NULL)
//	{
//		if (casaDeDiscuri.id > (*radacina)->info.id)
//		{
//			InserareNodAVL(casaDeDiscuri, &(*radacina)->fiuDreapta);
//		}
//		else
//		{
//			InserareNodAVL(casaDeDiscuri, &(*radacina)->fiuStanga);
//		}
//		int grad = gradEchilibru(*radacina);
//		if (grad == -2)
//		{
//			if (gradEchilibru((*radacina)->fiuDreapta )== 1)
//			{
//				(*radacina)->fiuDreapta=rotireDreapta((*radacina)->fiuDreapta);
//				*radacina=rotireStanga(*radacina);
//			}
//			else
//			{
//				*radacina = rotireStanga(*radacina);
//			}
//		}
//		else if (grad == 2) {
//			if (gradEchilibru((*radacina)->fiuStanga) == -1) {
//				(*radacina)->fiuStanga = rotireStanga((*radacina)->fiuStanga);
//			}
//
//			*radacina = rotireDreapta(*radacina);
//		}
//	}
//	else
//	{
//		NodArbore* nou = malloc(sizeof(NodArbore));
//		nou->info = casaDeDiscuri;
//		nou->fiuStanga = NULL;
//		nou->fiuDreapta = NULL;
//		(*radacina) = nou;
//	}
//}
//
//
//
//
//
//
//
//void afisareCasa(CasaDeDiscuri casa) {
//	printf("\nCasa %i - nume: %s - incasari: %.2f\n", casa.id, casa.nume, casa.incasari);
//}
//
//void afisarePreordine(NodArbore* radacina) {
//	if (radacina != NULL) {
//		afisareCasa(radacina->info);
//		afisarePreordine(radacina->fiuStanga);
//		afisarePreordine(radacina->fiuDreapta);
//	}
//}
//
//void afisareInordine(NodArbore* radacina) {
//	if (radacina != NULL) {
//		afisareInordine(radacina->fiuStanga);
//		afisareCasa(radacina->info);
//		afisareInordine(radacina->fiuDreapta);
//	}
//}
//
//CasaDeDiscuri CautareDupaId(NodArbore* radacina, int id) {
//	if (radacina != NULL) {
//		if (radacina->info.id == id) {
//			return initializareCasa(radacina->info.id, radacina->info.nume, radacina->info.incasari);
//		}
//		else
//		{
//			if (radacina->info.id > id)
//				return CautareDupaId(radacina->fiuStanga, id);
//			else
//				return CautareDupaId(radacina->fiuDreapta, id);
//		}
//	}
//	return initializareCasa(0, "Inexistent", 0);
//}
//float sumaIncasari(NodArbore* radacina)
//{
//	if (radacina != NULL)
//	{
//		return radacina->info.incasari +
//			sumaIncasari(radacina->fiuStanga) +
//			sumaIncasari(radacina->fiuDreapta);
//	}
//	return 0;
//}
//
//void stergereArbore(NodArbore** radacina) {
//	if ((*radacina)) {
//		stergereArbore(&(*radacina)->fiuStanga);
//		stergereArbore(&(*radacina)->fiuDreapta);
//		free((*radacina)->info.nume);
//		free((*radacina));
//		(*radacina) = NULL;
//	}
//}
//
//int inaltimeArbore(NodArbore* radacina) {
//	if (radacina) {
//		int inaltimeStanga = inaltimeArbore(radacina->fiuStanga);
//		int inaltimeDreapta = inaltimeArbore(radacina->fiuDreapta);
//		int maxim = inaltimeStanga < inaltimeDreapta ? inaltimeDreapta : inaltimeStanga;
//		return 1 + maxim;
//	}
//	return 0;
//}
//
//void main()
//{
//	NodArbore* radacina = NULL;
//	InserareNodAVL(initializareCasa(1, "casa1", 10000), &radacina);
//	InserareNodAVL(initializareCasa(2, "casa2", 20000), &radacina);
//	InserareNodAVL(initializareCasa(3, "casa3", 30000), &radacina);
//	InserareNodAVL(initializareCasa(4, "casa4", 40000), &radacina);
//	InserareNodAVL(initializareCasa(5, "casa5", 50000), &radacina);
//	InserareNodAVL(initializareCasa(6, "casa6", 60000), &radacina);
//	afisarePreordine(radacina);
//	/*CasaDeDiscuri casa = CautareDupaId(radacina, 4);
//	printf("\n\n");
//	afisareCasa(casa);
//	CasaDeDiscuri casa2 = CautareDupaId(radacina, 10);
//	printf("\n\n");
//	afisareCasa(casa2);
//	printf("\n\n");
//	printf("%.2f\n", sumaIncasari(radacina));
//
//	printf(" Inaltime arbore: \n");
//	printf("%d", inaltimeArbore(radacina));*/
//
//
//	stergereArbore(&radacina);
//	//afisareInordine(radacina);
//	/*free(casa.nume);
//	free(casa2.nume);*/
//
//
//}