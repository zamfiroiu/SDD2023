//#include<stdlib.h>
//#include<malloc.h>
//#include<stdio.h>
//
//struct Mail
//{
//	int prioritate;
//	char* subiect;
//};
//
//struct Heap
//{
//	struct Mail* mailuri;
//	int dimTotala;
//	int dimNrelemente;
//};
//
//struct Mail initializareMail(int prioritate, const char* subiect)
//{
//	struct Mail m;
//	m.prioritate = prioritate;
//	if (subiect != NULL)
//	{
//		m.subiect = malloc(strlen(subiect) + 1);
//		strcpy_s(m.subiect, strlen(subiect) + 1, subiect);
//	}
//
//	return m;
//}
//
//void afisareMail(struct Mail m)
//{
//	printf("Mail-ul %s are prioritatea %d\n", m.subiect, m.prioritate);
//}
//
//struct Heap initializareHeap(int dimensiune)
//{
//	struct Heap aux;
//	aux.dimTotala = dimensiune;
//	aux.dimNrelemente = 0;
//	aux.mailuri = malloc(sizeof(struct Mail) * aux.dimTotala);
//	return aux;
//}
//void afiseazaHeapUtilizat(struct Heap list)
//{
//	for (int i = 0; i < list.dimNrelemente; i++)
//	{
//		afisareMail(list.mailuri[i]);
//	}
//}
//void afiseazaHeapTotal(struct Heap list)
//{
//	for (int i = 0; i < list.dimTotala; i++)
//	{
//		afisareMail(list.mailuri[i]);
//	}
//}
//
//void FiltrareHeap(struct Heap heap, int index) {
//	int indexMax = index;
//	int indexStang = 2 * index + 1;
//	int indexDreapta = 2 * index + 2;
//
//	if (index < heap.dimNrelemente && indexStang < heap.dimNrelemente && heap.mailuri[indexStang].prioritate>heap.mailuri[indexMax].prioritate) {
//		indexMax = indexStang;
//	}
//
//	if (index < heap.dimNrelemente && indexDreapta < heap.dimNrelemente && heap.mailuri[indexDreapta].prioritate>heap.mailuri[indexMax].prioritate) {
//		indexMax = indexDreapta;
//	}
//
//	if (index != indexMax) {
//
//		struct Mail aux = heap.mailuri[index];
//
//		heap.mailuri[index] = heap.mailuri[indexMax];
//		heap.mailuri[indexMax] = aux;
//
//		if (2 * indexMax + 1 < heap.dimNrelemente) {
//			FiltrareHeap(heap, indexMax);
//		}
//	}
//
//
//
//}
//
//struct Mail extrageMailPrioritateMare(struct Heap *heap) {
//	struct Mail aux = heap->mailuri[0];
//	heap->mailuri[0] = heap->mailuri[heap->dimNrelemente - 1];
//	heap->mailuri[heap->dimNrelemente - 1] = aux;
//	heap->dimNrelemente--;
//	for (int i = (heap->dimNrelemente - 1) / 2; i >= 0; i--)
//	{
//		FiltrareHeap(*heap, i);
//	}
//	return aux;
//}
//
//int main()
//{
//	struct Heap heap;
//	heap = initializareHeap(6);
//	heap.mailuri[0] = initializareMail(4, "Urgent");
//	heap.mailuri[1] = initializareMail(3, "Interes public");
//	heap.mailuri[2] = initializareMail(8, "Glovo");
//	heap.mailuri[3] = initializareMail(7, "Bolt");
//	heap.mailuri[4] = initializareMail(6, "Pizza Hut");
//	heap.mailuri[5] = initializareMail(2, "Taxi");
//	heap.dimNrelemente = 6;
// 
	////pentru determinarea ultimului parinte scadem 2 nu 1
//	for (int i = (heap.dimNrelemente - 2) / 2; i >= 0; i--)
//	{
//		FiltrareHeap(heap, i);
//	}
//	afiseazaHeapTotal(heap);
//
//	struct Mail mail1 = extrageMailPrioritateMare(&heap);
//	struct Mail mail2 = extrageMailPrioritateMare(&heap);
//	extrageMailPrioritateMare(&heap); extrageMailPrioritateMare(&heap); extrageMailPrioritateMare(&heap); extrageMailPrioritateMare(&heap);
//
//	printf("\n\n");
//	afiseazaHeapTotal(heap);
//	
//}