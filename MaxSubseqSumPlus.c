#include <stdio.h>

int main()
{
	int N;
	int TempSum, MaxSum;
	int left, right;

	TempSum = MaxSum = 0;
	left = right = 0;

	scanf("%d", &N);
	int a[N];    // store the whole input number series
	int b[N][3];	// store MaxSum, left, right for every loop

	// read the input number into a number array
	for (int i = 0; i < N; i++)
	{
		scanf("%d", & a[i]);
	}

	// update state in every loop
	for (int i = 0; i < N; i++)
	{

		TempSum += a[i];

		if (TempSum >= MaxSum)
		{
			MaxSum = TempSum;
			right = i;
		}
		else if (TempSum < 0)
		{
			TempSum = 0;
			left = i + 1;
		}
		// store MaxSum, left, right into b 
		b[i][0] = MaxSum;
		b[i][1] = left;
		b[i][2] = right;

	}

	// the case when the whole numbers are negative, e.g. -1,-2,-3
	if ((left == N) & (right == 0))
		printf("%d %d %d\n", 0, a[0], a[N-1]); 
	else
	{
		for (int i = 0; i < N; i++)
		{
			if ( (b[i][0] == MaxSum) & (b[i][2] >= b[i][1]) ) 
			{	
				printf("%d %d %d\n", MaxSum, a[b[i][1]], a[b[i][2]]);
				break;
			}
			else 
				continue;
		}
	}

	return 0;

}