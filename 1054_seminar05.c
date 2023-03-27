#include<stdio.h>
#include<malloc.h>

typedef struct Frzerie Frizerie;
typedef struct Nod Nod;

typedef struct Frizerie {
	char* nume;
	int nrMediuClienti;
	float costServiciu;
};
typedef struct Nod Nod;
 struct Nod {
	struct Frizerie frizerie;
	struct Nod* next;

};

struct Frizerie initializareFrizerie(char* fnume,int fnrMediuClienti,float fcostServiciu) {
	struct Frizerie f1;
	f1.nume = malloc(sizeof(char) * (strlen(fnume) + 1));
	strcpy_s(f1.nume, strlen(fnume)+1,fnume);
	f1.nrMediuClienti = fnrMediuClienti;
	f1.costServiciu = fcostServiciu;

	return f1;
}
void afisare(struct Frizerie f) {
	printf("%s ", f.nume);
	printf("%d ", f.nrMediuClienti);
	printf("%f ", f.costServiciu);
	printf("\n");
}

void afisareLista(Nod* primNod)
{
	while (primNod != NULL)
	{
		afisare(primNod->frizerie);
		primNod = primNod->next;
	}
}

void pushBack(Nod** head,struct Frizerie f)
{
	Nod* newNod;
	newNod = malloc(sizeof(Nod));
	newNod->frizerie = f;
	newNod->next = NULL;
	if (*head != NULL)
	{

	
		Nod* p=*head;
	
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = newNod;
	}
	else
	{
		*head = newNod;

	}
}

Nod* pushFront(Nod* ptrNod,struct Frizerie f){
	Nod* nod;
	nod = malloc(sizeof(Nod));
	nod->frizerie = f;
	nod->next = ptrNod;
	return nod;
}


void main()
{
	struct Frizerie f1 = initializareFrizerie("One Barbershop", 15, 17.2);
	struct Frizerie f2 = initializareFrizerie("2nd Barbershop", 20, 20.3);
	//afisare(f1);
	Nod* ptr=NULL;
	ptr = pushFront(ptr, f1);
	ptr = pushFront(ptr, f2);
	//afisare(f2);
	pushBack(&ptr, initializareFrizerie("3rd altcevahop", 20, 20.3));
  
	afisareLista(ptr);


	while (ptr != NULL)
	{
		free(ptr->frizerie.nume);
		Nod* p = ptr->next;
		free(ptr);
		ptr = p;
	}

}