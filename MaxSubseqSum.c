#include <stdio.h>

int main()
{
	int N, a, i;
	int TempSum, MaxSum;

	TempSum = MaxSum = 0;

	scanf("%d", &N);
	for( i=0; i<N; i++ )
	{
		scanf("%d", &a);
		TempSum += a;
		if(TempSum > MaxSum)
			MaxSum = TempSum;
		else if(TempSum < 0)
			TempSum = 0;
	}
	printf("%d", MaxSum);
	return 0;
}
