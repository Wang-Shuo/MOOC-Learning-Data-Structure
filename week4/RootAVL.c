#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode *AVLTree;
typedef struct AVLNode *Position;
struct AVLNode {
	int Data;
	int Height;
	AVLTree Left;
	AVLTree Right;
};


AVLTree Insert(int X, AVLTree T);
int GetHeight(Position T);
int Max(int a, int b);
Position Rotation_LL(Position K);
Position Rotation_RR(Position K);
Position Rotation_LR(Position K);
Position Rotation_RL(Position K);


int main() {
	AVLTree T = NULL;
	int n;
	scanf("%d", &n);
	while(n--){
		int x;
		scanf("%d", &x);
		T = Insert(x, T);
	}
	if(T)
		printf("%d", T->Data);

	return 0;
}


AVLTree Insert(int X, AVLTree T) {
	if (T == NULL) {
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	}
	else if (X < T->Data) {
		T->Left = Insert(X, T->Left);
		if(GetHeight(T->Left) - GetHeight(T->Right) == 2) {
			if (X < T->Left->Data)
				T = Rotation_LL(T);
			else
				T = Rotation_LR(T);
		}
	}
	else if (X > T->Data) {
		T->Right = Insert(X, T->Right);
		if (GetHeight(T->Right) - GetHeight(T->Left) == 2) {
			if (X > T->Right->Data)
				T = Rotation_RR(T);
			else
				T = Rotation_RL(T);
		}
	}
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	return T;

}


int GetHeight(Position T) {
	if (!T) 
		return -1;
	else 
		return T->Height;
}


int Max(int a, int b) {
	return (a > b)? a : b;
}

Position Rotation_LL(Position K) {
	Position Tmp;  
    Tmp = K;  
    K = K->Left;  
    Tmp->Left = K->Right;  
    K->Right = Tmp;  
    Tmp->Height = Max(GetHeight(Tmp->Left), GetHeight(Tmp->Right)) + 1;  
    K->Height = Max(GetHeight(K->Left), GetHeight(K->Right)) + 1;  
    return K;  
}


Position Rotation_RR(Position K) {
	Position Tmp;  
    Tmp = K;  
    K = K->Right;  
    Tmp->Right = K->Left;  
    K->Left = Tmp;  
    Tmp->Height = Max(GetHeight(Tmp->Left), GetHeight(Tmp->Right)) + 1;  
    K->Height = Max(GetHeight(K->Left), GetHeight(K->Right)) + 1;  
    return K; 
}

Position Rotation_LR(Position K) {
	K->Left = Rotation_RR(K->Left);
	return Rotation_LL(K);
}

Position Rotation_RL(Position K) {
	K->Right = Rotation_LL(K->Right);
	return Rotation_RR(K);
}