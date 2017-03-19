#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode List;

List Read();
void Print(List L);

List Merge(List L1, List L2);

int main()
{

	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;

}


List Read() 
{
	int N;
	List P, Rear;

	scanf("%d", &N);
	P = (List)malloc(sizeof(struct Node));
	P->Next = NULL;
	Rear = P;
	while(N--){
		List Pt;
		Pt = (List)malloc(sizeof(struct Node));
		scanf("%d", &(Pt-> Data));
		Pt-> Next = NULL;
		Rear-> Next = Pt;
		Rear = Pt;
	}

	return P;
}


List Merge(List L1, List L2)
{
	List P, Rear, t1, t2;
	P = (List)malloc(sizeof(struct Node));
	P->Next = NULL;
	Rear = P;

	t1 = L1-> Next;
	t2 = L2-> Next;

	while(t1 && t2){
		if (t1-> Data < t2-> Data) {
			Rear-> Next = t1;
			t1 = t1-> Next;
			Rear = Rear-> Next;
		}
		else {
			Rear-> Next = t2;
			t2 = t2-> Next;
			Rear = Rear-> Next;			
		}

	}

	while(t1 != NULL){
		Rear-> Next = t1;
		t1 = t1-> Next;
		Rear = Rear-> Next;
	}

	while(t2 != NULL){
		Rear-> Next = t2;
		t2 = t2-> Next;
		Rear = Rear-> Next;			
	}

	L1-> Next = NULL;
	L2-> Next = NULL;
	Rear-> Next = NULL;

	return P;
}


void Print(List L)
{
	List P = L-> Next;
	if (P != NULL) {
		List Rear;
		Rear = L;
		while (Rear-> Next) {
			Rear = Rear-> Next;
			printf("%d ", Rear-> Data);
		}
	}
	else{
		printf("NULL");
	}
	printf("\n");
	
}



