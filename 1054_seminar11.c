#include<stdio.h>
#include<malloc.h>


struct Festival
{
	int idFestival;
	char* nume;
	int nrParticipanti;
};

typedef struct Nod Nod;
typedef struct Festival Festival;
struct Nod
{
	struct Festival info;
	struct Nod* stanga;
	struct Nod* dreapta;
};

struct Festival initializareFestival(int idF, const char* numeF, int nrP)
{
	struct Festival f;
	f.idFestival = idF;

	f.nume = malloc(sizeof(char) * (strlen(numeF) + 1));
	strcpy(f.nume, numeF);

	f.nrParticipanti = nrP;

	return f;
}

void afisareFestival(struct Festival f)
{
	printf("Id:%d || Nume:%s || NrParticipanti:%d\n", f.idFestival, f.nume, f.nrParticipanti);
}

Nod* inserareFestivalInArbore(Nod* radacina, Festival f)
{
	if (radacina)
	{
		if (radacina->info.idFestival > f.idFestival)
		{
			radacina->stanga = inserareFestivalInArbore(radacina->stanga, f);
		}
		else
		{
			radacina->dreapta = inserareFestivalInArbore(radacina->dreapta, f);
		}
	}
	else
	{
		radacina = malloc(sizeof(Nod));
		radacina->info = f;
		radacina->dreapta = NULL;
		radacina->stanga = NULL;

	}
	return radacina;
}

void afisareInOrdine(Nod* radacina) {

	if (radacina) {
		afisareInOrdine(radacina->stanga);
		afisareFestival(radacina->info);
		afisareInOrdine(radacina->dreapta);
	}

}
void afisarePreOrdine(Nod* radacina) {

	if (radacina) {

		afisareFestival(radacina->info);
		afisarePreOrdine(radacina->stanga);
		afisarePreOrdine(radacina->dreapta);
	}

}

Festival cautareFestivalDupaId(Nod* radacina, int id)
{
	if (radacina)
	{
		if (radacina->info.idFestival > id)
		{
			return cautareFestivalDupaId(radacina->stanga, id);
		}
		else
			if (radacina->info.idFestival < id)
				return cautareFestivalDupaId(radacina->dreapta, id);
			else
			{
				return initializareFestival(radacina->info.idFestival, radacina->info.nume, radacina->info.nrParticipanti);
			}
	}
	else
		return initializareFestival(0, "N/A", 0);
}

int calculNrParticipati(Nod* radacina) {
	if (radacina) {
		return  calculNrParticipati(radacina->stanga)
			+ radacina->info.nrParticipanti
			+ calculNrParticipati(radacina->dreapta);
	}
	else {
		return 0;
	}

}

int calculInaltime(Nod* radacina) {

	if (radacina) {
		int inaltimeS = calculInaltime(radacina->stanga);
		int inaltimeD = calculInaltime(radacina->dreapta);

		return 1 + (inaltimeS < inaltimeD ? inaltimeD : inaltimeS);

	}
	else return 0;
}

int calculGrad(Nod* radacina)
{

	if (radacina)
	{
		return calculInaltime(radacina->stanga) - calculInaltime(radacina->dreapta);
	}
	else return 0;
	
}

void rotireStanga(Nod** radacina)
{
	Nod* aux = (*radacina)->dreapta;
	(*radacina)->dreapta = aux->stanga;
	aux->stanga = *radacina;
	*radacina = aux;
}

void rotireDreapta(Nod** radacina)
{
	Nod* aux = (*radacina)->stanga;
	(*radacina)->stanga = aux->dreapta;
	aux->dreapta = *radacina;
	*radacina = aux;
}




Nod* inserareFestivalInArboreAVL(Nod* radacina, Festival f)
{
	if (radacina)
	{
		if (radacina->info.idFestival > f.idFestival)
		{
			radacina->stanga = inserareFestivalInArboreAVL(radacina->stanga, f);
		}
		else
		{
			radacina->dreapta = inserareFestivalInArboreAVL(radacina->dreapta, f);
		}
		int grad = calculGrad(radacina);
		if (grad == 2)
		{
			if (calculGrad(radacina->stanga) == 1)
			{
				rotireDreapta(&radacina);
			}
			else
			{
				rotireStanga(&(radacina->stanga));
				rotireDreapta(&radacina);
			}
			
		}
		if (grad == -2) {
			if (calculGrad(radacina->dreapta) == 1) {
				rotireDreapta(&(radacina->dreapta));
			}
			rotireStanga(&radacina);

	
		}
	}
	else
	{
		radacina = malloc(sizeof(Nod));
		radacina->info = f;
		radacina->dreapta = NULL;
		radacina->stanga = NULL;

	}
	return radacina;
}
void main()
{
	Nod* radacina = NULL;
	radacina = inserareFestivalInArboreAVL(radacina, initializareFestival(1, "Untold", 2000));
	radacina = inserareFestivalInArboreAVL(radacina, initializareFestival(2, "Neversea", 1500));
	radacina = inserareFestivalInArboreAVL(radacina, initializareFestival(3, "Saga", 1000));
	radacina = inserareFestivalInArboreAVL(radacina, initializareFestival(4, "Beach Please", 10));
	radacina = inserareFestivalInArboreAVL(radacina, initializareFestival(5, "Summer Well", 500));
	radacina = inserareFestivalInArboreAVL(radacina, initializareFestival(6, "Electri Castle", 7000));

	afisarePreOrdine(radacina);
	/*Festival f1 = cautareFestivalDupaId(radacina, 3);
	printf("\n");
	afisareFestival(f1);

	int nrTotalParticipanti = calculNrParticipati(radacina);
	printf("\nNumar total participanti: %d", nrTotalParticipanti);

	int inaltime = calculInaltime(radacina);
	printf(" \n Inaltime: %d", inaltime);*/

	return;
}