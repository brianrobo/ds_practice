#include <stdio.h>

void is(int* pArr, int n)
{
	int i, j;
	int curVal;

	for(i=1; i<n; i++) // 0 base
	{
		curVal = pArr[i];

		j = i-1;

		while( j>=0 && pArr[j] > curVal)
		{
			pArr[j+1] = pArr[j];
			j = j -1;
		}
		//pArr[j] = curVal; <--- (me) intuitively assign curVal to j idx which originally i-1, but due to "j = j -1".. need to be add 1 in the index.
		pArr[j+1] = curVal;
	}
}

void printArr(int* pArr, int n)
{
	int i;

	for(i=0; i<n; i++)
	{
		printf("%d ", pArr[i]);
	}
}

int main(void)
{
	int arr[] = {5, 1, 7, 3, 9};


	printArr(arr, 5);
	printf("\n");


	is(arr, 5);
	printArr(arr, 5);
	printf("\n");


	return 0;
}
