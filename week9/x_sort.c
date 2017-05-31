#include <stdio.h>

typedef int ElementType;

void Swap(ElementType *a, ElementType *b) 
{
	ElementType temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

void Bubble_Sort(ElementType A[], int N)
{
	for (int P = N-1; P >= 0; P--)
	{
		int flag = 0;
		for (int i = 0; i < P; i++)
		{
			if (A[i] > A[i+1])
			{
				Swap(&A[i], &A[i+1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}


void Merge1( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd ) {  
    //将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列  
    int LeftEnd, NumElements, Tmp;  
    int i;  
    LeftEnd = R - 1;    //左边终点位置  
    Tmp = L;    //有序序列的起始位置  
    NumElements = RightEnd - L + 1;     //元素总个数  
    while( L <= LeftEnd && R <= RightEnd ) {  
        if( A[L] <= A[R] )  
            TmpA[Tmp++] = A[L++];   //将左边元素复制到TmpA  
        else  
            TmpA[Tmp++] = A[R++];   //将右边元素复制到TmpA  
    }  
    while( L <= LeftEnd )  
        TmpA[Tmp++] = A[L++];   //直接复制左边剩下的  
    while( R <= RightEnd )  
        TmpA[Tmp++] = A[R++];   //直接复制右边剩下的  
}  

void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length ) {  
    //两两归并相邻有序子列  
    int i, j;  
    for( i = 0; i <= N - 2 * length; i += 2 * length )  
        Merge1( A, TmpA, i, i + length, i + 2 * length - 1 );  
    if( i + length < N ) //归并最后2个子列  
        Merge1( A, TmpA, i, i + length, N - 1 );  
    else  //最后只剩1个子列  
        for( j = i; j < N; j++ )  
            TmpA[j] = A[j];  
}  

void Merge_Sort_Loop( ElementType A[], int N ) {  
    int length;  
    ElementType *TmpA;  
    length = 1;     //初始化子序列长度  
    TmpA = (ElementType *)malloc(N * sizeof(ElementType));  
    if ( TmpA != NULL ) {  
        while( length < N ) {  
            Merge_pass( A, TmpA, N, length );  
            length *= 2;  
            Merge_pass( TmpA, A, N, length );  
            length *= 2;  
        }  
        free( TmpA );  
    }  
    else printf("空间不足");  
}  


int main()
{
	int N;

	scanf("%d", &N);

	int A[N];

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	// Bubble_Sort(A, N);
	Merge_Sort_Loop(A, N);

	for (int i = 0; i < N; i++)
	{
		if (i == 0)
			printf("%d", A[i]);
		else
			printf(" %d", A[i]);
	}

}