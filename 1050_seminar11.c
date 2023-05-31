//#include <stdio.h>
//#include <malloc.h>
//
//struct Brutarie {
//
//	char* nume;
//	int id;
//	int nrAngajati;
//};
//
//typedef struct Brutarie Brutarie;
//
//Brutarie initializareBrutarie(const char* nume, int id, int nrAngajati) {
//	Brutarie b;
//	b.nume = malloc(sizeof(char) * (strlen(nume) + 1));
//	strcpy(b.nume, nume);
//	b.id = id;
//	b.nrAngajati = nrAngajati;
//
//	return b;
//
//
//}
//
//typedef struct Nod Nod;
//struct Nod {
//
//	Brutarie info;
//	Nod* st;
//	Nod* dr;
//};
//
//
//void inserareNod(Brutarie b, Nod** radacina) {
//	if (*radacina) {
//		if ((*radacina)->info.id > b.id) {
//			inserareNod(b, &(*radacina)->st);
//		}
//		else {
//			inserareNod(b, &(*radacina)->dr);
//		}
//	}
//	else {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = b;
//		nou->st = NULL;
//		nou->dr = NULL;
//		*radacina = nou;
//	}
//}
//
//void afisareBrutarie(Brutarie b) {
//	printf("%d %s %d\n", b.id, b.nume, b.nrAngajati);
//}
//
//void afisarePreordine(Nod* radacina) {
//	if (radacina) {
//		afisareBrutarie(radacina->info);
//		afisarePreordine(radacina->st);
//		afisarePreordine(radacina->dr);
//	}
//}
//
//void afisareInordine(Nod* radacina) {
//	if (radacina) {
//		afisareInordine(radacina->st);
//		afisareBrutarie(radacina->info);
//		afisareInordine(radacina->dr);
//	}
//}
//
//Brutarie cautaBrutarie(Nod* rad, int id)
//{
//	if (rad) {
//		if (id < rad->info.id) {
//			return cautaBrutarie(rad->st, id);
//		}
//		else {
//			if (id > rad->info.id) {
//				return cautaBrutarie(rad->dr, id);
//			}
//			else {
//				return initializareBrutarie(rad->info.nume, rad->info.id, rad->info.nrAngajati);
//			}
//		}
//	}
//	else {
//		return initializareBrutarie("", 0, 0);
//	}
//
//}
//
//int calcNrTotalAngajati(Nod* radacina) {
//	if (radacina) {
//		return radacina->info.nrAngajati 
//			+ calcNrTotalAngajati(radacina->st) 
//			+ calcNrTotalAngajati(radacina->dr);
//	}
//	else {
//		return 0;
//	}
//}
//
//int determinareInaltime(Nod* radacina) {
//	if (radacina) {
//		int stH = determinareInaltime(radacina->st);
//		int drH = determinareInaltime(radacina->dr);
//		return 1 + (stH > drH ? stH : drH);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//void stergereArbore(Nod** radacina) {
//	if (*radacina) {
//		stergereArbore(&(*radacina)->st);
//		stergereArbore(&(*radacina)->dr);
//		free((*radacina)->info.nume);
//		free(*radacina);
//		*radacina = NULL;
//	}
//}
//
//void rotireStanga(Nod** radacina) {
//	Nod* aux = (*radacina)->dr;
//	(*radacina)->dr = aux->st;
//	aux->st = (*radacina);
//	*radacina = aux;
//}
//
//void rotireDreapta(Nod** radacina) {
//	Nod* aux = (*radacina)->st;
//	(*radacina)->st = aux->dr;
//	aux->dr = (*radacina);
//	*radacina = aux;
//}
//
//int gradEchilibru(Nod* radacina) {
//
//	if (radacina) {
//		int hStanga = determinareInaltime(radacina->st);
//		int hDreapta = determinareInaltime(radacina->dr);
//		return hStanga - hDreapta;
//	}
//
//	return 0;
//}
//
//void inserareNodAVL(Brutarie b, Nod** radacina) {
//	if (*radacina) {
//		if ((*radacina)->info.id > b.id) {
//			inserareNodAVL(b, &(*radacina)->st);
//		}
//		else {
//			inserareNodAVL(b, &(*radacina)->dr);
//		}
//
//		int grad = gradEchilibru(*radacina);
//		if (grad == 2) {
//			if (gradEchilibru((*radacina)->st) == 1) {
//				rotireDreapta(radacina);
//			}
//			else {
//				rotireStanga(&(*radacina)->st);
//				rotireDreapta(radacina);
//			}
//		}
//
//		if (grad == -2) {
//			if (gradEchilibru((*radacina)->dr) == 1) {
//				rotireDreapta(&(*radacina)->dr);
//			}
//			rotireStanga(radacina);
//		}
//
//	}
//	else {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = b;
//		nou->st = NULL;
//		nou->dr = NULL;
//		*radacina = nou;
//	}
//}
//
//int calcNrTotalAngajatiDupaIdMare(Nod* radacina,int id) {
//	if (radacina) {
//		if ((*radacina).info.id > id) {
//			return radacina->info.nrAngajati
//				+ calcNrTotalAngajatiDupaIdMare(radacina->st,id)
//				+ calcNrTotalAngajatiDupaIdMare(radacina->dr,id);
//		}
//		else {
//
//			//era gresit deoarece apela si pentru radacinele 
//			//care au valoare mai mica decat id-ul primit
//			//in aceasta situatie terbuie sa apelam doar functia...
//			//...fara adunarea infroatiei din radacina
//			return calcNrTotalAngajatiDupaIdMare(radacina->dr, id);
//		}
//	}
//	else {
//		return 0;
//	}
//}
//
//void main() {
//
//	Nod* rad = NULL;
//
//	inserareNodAVL(initializareBrutarie("LaCostel", 1, 15), &rad);
//	inserareNodAVL(initializareBrutarie("LaMarcel", 2, 4), &rad);
//	inserareNodAVL(initializareBrutarie("LaFlorica", 3, 3), &rad);
//	inserareNodAVL(initializareBrutarie("LaAlex", 4, 9), &rad);
//	inserareNodAVL(initializareBrutarie("LaSilviu", 5, 7), &rad);
//	inserareNodAVL(initializareBrutarie("LaMaria", 6, 12), &rad);
//
//	afisarePreordine(rad);
//
//	
//
//	/*Brutarie search = cautaBrutarie(rad, 4);
//	printf("\n");
//	afisareBrutarie(search);
//
//	int sumTotalAngajati = calcNrTotalAngajati(rad);
//
//	printf("\n %d", sumTotalAngajati);
//
//	printf("\nInaltime: %d\n", determinareInaltime(rad));
//	*/
//
//	/*free(search.nume);*/
//
//
//	printf("Numarul de angajati pt cele cu id mai mare de 4: %d", calcNrTotalAngajatiDupaIdMare(rad, 4));
//	printf("Numarul de angajati : %d", calcNrTotalAngajati(rad));
//		stergereArbore(&rad);
//}