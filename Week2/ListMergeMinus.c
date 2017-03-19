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
void Attach(int a, PtrToNode *pRear);

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

void Attach(int a, PtrToNode *pRear){
	PtrToNode P;

	P = (PtrToNode)malloc(sizeof(struct Node));
	P-> Data = a;
	P-> Next = NULL;
	(*pRear)-> Next = P;
	*pRear = P;
}

List Read() 
{
	int N, a;
	PtrToNode P, Rear, t;

	scanf("%d", &N);
	P = (PtrToNode)malloc(sizeof(struct Node));
	P->Next = NULL;
	Rear = P;
	while(N--){
		scanf("%d", &a);
		Attach(a, &Rear);
	}

	t = P; P = P->Next; free(t);
	return P;
}


List Merge(List L1, List L2)
{
	PtrToNode P, t1, t2, t, Rear;
	t1 = L1; t2 = L2;
	P = (PtrToNode)malloc(sizeof(struct Node));
	P->Next = NULL;
	Rear = P;

	while(t1 && t2){
		if (t1-> Data <= t2-> Data) {
			Attach(t1-> Data, &Rear);
			t1 = t1-> Next;
		}
		else {
			Attach(t2-> Data, &Rear);
			t2 = t2-> Next;			
		}

	}

	while(t1){
		Attach(t1-> Data, &Rear);
		t1 = t1-> Next;
	}

	while(t2){
		Attach(t2-> Data, &Rear);
		t2 = t2-> Next;			
	}

	t = P; P = P->Next; free(t);
	return P;
}

void Print(List L)
{
	while (L != NULL) {
		printf("%d ", L-> Data);
		L = L-> Next;
	}
}



