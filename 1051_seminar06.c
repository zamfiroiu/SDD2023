//
//#include <stdio.h>
//#include <malloc.h>
//typedef struct cafenea Cafenea;
//typedef struct nod Nod;
//typedef struct nodLdi nodLdi;
//typedef struct listaDubla listaDubla;
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
//struct nodLdi {
//	Cafenea info;
//	nodLdi* next;
//	nodLdi* prev;
//};
//
//struct listaDubla {
//	nodLdi* prim;
//	nodLdi* ultim;
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
//void inserareListDublaSfarsit(listaDubla* listaDubla, Cafenea cafenea) {
//	nodLdi* nod = malloc(sizeof(nodLdi));
//	nod->prev = listaDubla->ultim;
//	nod->next = NULL;
//	nod->info = InitCopiere(cafenea);
//	if (listaDubla->ultim != NULL) {
//		listaDubla->ultim->next = nod;
//	}
//	else
//	{
//		listaDubla->prim = nod;
//	}
//	listaDubla->ultim = nod;
//}
//
//void inserareListaDublaInceput(listaDubla* listaDubla, Cafenea cafenea) {
//	nodLdi* nod = malloc(sizeof(nodLdi));
//	nod->info = InitCopiere(cafenea);
//	nod->prev = NULL;
//	nod->next = listaDubla->prim;
//	if (listaDubla->prim) {
//		listaDubla->prim->prev = nod;
//		listaDubla->prim = nod;
//	}
//	else {
//
//		listaDubla->prim = listaDubla->ultim = nod;
//
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
//void afisareListaDublaDeLaInceput(listaDubla listaCafenele) {
//	nodLdi* p = listaCafenele.prim;
//	while (p) {
//		afisareCafenea(p->info);
//		p = p->next;
//	}
//}
//
//void afisareListaDublaDeLaSfarsit(listaDubla listaCafenele) {
//	nodLdi* p = listaCafenele.ultim;
//	while (p) {
//		afisareCafenea(p->info);
//		p = p->prev;
//	}
//}
//
//void stergereListaDubla(listaDubla* listaCafenele) {
//	nodLdi* p = listaCafenele->prim;
//	while (p) {
//		free(p->info.nume);
//		nodLdi* temp = p->next;
//		free(p);
//		p = temp;		
//	}
//	listaCafenele->prim = NULL;
//	listaCafenele->ultim = NULL;
//}
//
//void interschimba(listaDubla ld, int i1, int i2) {
//	nodLdi* nod1 = ld.prim;
//	nodLdi* nod2 = ld.prim;
//	//int i = 1;
//	//while (i < i1 && nod1->next != NULL) {
//	//	i++;
//	//	nod1 = nod1->next;
//	//}
//
//	for (int i = 1; i < i1 && nod1->next != NULL; i++, nod1 = nod1->next);
//	//for (int i = 1; i < i2, nod2->next != NULL; i++, nod2 = nod2->next);
//	int index = 1;
//	while (index < i2 && nod2->next != NULL) {
//		index++;
//		nod2 = nod2->next;
//	}
//	Cafenea c = nod1->info;
//	nod1->info = nod2->info;
//	nod2->info = c;
//}
//int CalcNrElem(listaDubla ld)
//{
//	int i = 0;
//	while (ld.prim != NULL)
//	{
//		i++;
//		ld.prim = ld.prim->next;
//	}
//	return i;
//}
//char palindrom(listaDubla ld)
//{
//	int i=1;
//	int nrElem = CalcNrElem(ld);
//	while (ld.prim != NULL&&i<nrElem/2)
//	{
//		if (ld.prim->info.nrLocuri != ld.ultim->info.nrLocuri)
//			return '0';
//		ld.prim = ld.prim->next;
//		ld.ultim = ld.ultim->prev;
//		i++;
//	}
//	return '1';
//}
//void main() {
//	listaDubla listaDublaCafenele;
//	listaDublaCafenele.prim = NULL;
//	listaDublaCafenele.ultim = NULL;
//	Cafenea cafenea = Init("Starbucks", 40, 60);
//	Cafenea cafenea2 = Init("Ted", 30, 43);
//	inserareListDublaSfarsit(&listaDublaCafenele,cafenea);
//	inserareListDublaSfarsit(&listaDublaCafenele, cafenea2);
//	afisareListaDublaDeLaInceput(listaDublaCafenele);
//
//	inserareListaDublaInceput(&listaDublaCafenele, cafenea);
//	inserareListaDublaInceput(&listaDublaCafenele, cafenea2);
//	printf("-----------\n");
//	afisareListaDublaDeLaSfarsit(listaDublaCafenele);
//	printf("%c", palindrom(listaDublaCafenele));
//	interschimba(listaDublaCafenele, 2, 4);
//	printf("%c", palindrom(listaDublaCafenele));
//	printf("AFISAREA DUPA INTERSCHIMBARE----------------\n");
//	afisareListaDublaDeLaInceput(listaDublaCafenele);
//
//	stergereListaDubla(&listaDublaCafenele);
//	printf("--------");
//	afisareListaDublaDeLaInceput(listaDublaCafenele);
//
//
//}