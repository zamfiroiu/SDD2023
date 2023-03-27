//
//#include <stdio.h>
//#include <malloc.h>
//typedef struct cafenea Cafenea;
//typedef struct nod Nod;
//
//struct cafenea {
//	int nrLocuri;
//	char* nume;
//	float incasari;
//};
//
//struct nod {
//	Cafenea info;
//	Nod* next;
//};
//
//Cafenea Init(char* nume, int nrlocuri, float incasari) {
//	Cafenea c;
//	c.nume = malloc(strlen(nume)+1);
//	strcpy_s(c.nume, strlen(nume) + 1, nume);
//	c.nrLocuri = nrlocuri;
//	c.incasari = incasari;
//	return c;
//}
//
//Cafenea InitCopiere(Cafenea princ) {
//	return Init(princ.nume, princ.nrLocuri, princ.incasari);
//}
//
//void afisareCafenea(Cafenea c) {
//	printf("Cafeneaua %s are %d locuri si are incasari de %5.2f\n", c.nume, 
//		c.nrLocuri, c.incasari);
//}
//
//Nod* adaugareInceput(Nod* cap, Cafenea c) {
//	Nod* n = malloc(sizeof(Nod));
//	n->info = InitCopiere(c);
//	n->next = cap;
//	return n;
//}
//
//void adaugareFinal(Nod** cap, Cafenea c) {
//	Nod* n = malloc(sizeof(Nod));
//	n->info = InitCopiere(c);
//	n->next = NULL;
//	if (*cap != NULL) {
//		Nod* p = *cap;
//		while (p->next) {
//			p = p->next;
//		}
//		p->next = n;
//	}
//	else {
//		*cap = n;
//	}
//}
//
//void afisareLista(Nod* cap) {
//	while (cap) {
//		afisareCafenea(cap->info);
//		cap = cap->next;
//	}
//}
//
//void stergereLista(Nod* *cap) {
//	while (*cap) {
//
//		free((*cap)->info.nume);
//		Nod* aux;
//		aux = (*cap)->next;
//		free((*cap));
//		(*cap) = aux;
//	}
//}
//
//
//
//void main() {
//	Cafenea cafe1;
//	Cafenea cafe2;
//	Nod* cap = NULL;
//	cafe1 = Init("5 to go", 20, 1000);
//	cafe2 = Init("Starbucks", 40, 2500);
//	//afisareCafenea(cafe1);
//	//afisareCafenea(cafe2);
//	
//	cap = adaugareInceput(cap, cafe1);
//	cap = adaugareInceput(cap, cafe2);
//
//	Nod* cap2 = NULL;
//	adaugareFinal(&cap2, cafe1);
//	adaugareFinal(&cap2, cafe2);
//	Cafenea cafe3 = Init("Cafenea Noua", 200, 32452);
//	adaugareFinal(&cap2, cafe3);
//	afisareLista(cap2);
//	
//
//	//afisareLista(cap);
//	stergereLista(&cap);
//	
//	stergereLista(&cap2);
//
//	free(cafe1.nume);
//	free(cafe2.nume);
//	free(cafe3.nume);
//}
