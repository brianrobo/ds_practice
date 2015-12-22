#include <stdio.h>

int sa(int* pSArr, int* pArr1, int* pArr2, int n)
{
	int sLength = 0;
	int i;
	int lastFTime = pArr2[0];

	for(i=1; i<n; i++)
	{
		if(pArr1[i] >= lastFTime)
		{
			pSArr[sLength] = i;
			sLength++;

			lastFTime = pArr2[i];
		}		
	}

	return  sLength;
}

PrintAll(int* pArr1, int* pArr2, int n)
{
	int i;

	for(i=0; i<n; i++)
	{
		printf("%d %d\n", pArr1[i], pArr2[i]);
		//printf("%d ", pArr2[i]);
	}
}

Swap(int* pArr1, int* pArr2, int i, int j)
{	
	int temp;

	temp = pArr2[i];
	pArr2[i] = pArr2[j];
	pArr2[j] = temp;

	temp = pArr1[i];
	pArr1[i] = pArr1[j];
	pArr1[j] = temp;
}

void ss(int* pArr1, int* pArr2, int n)
{
	int i, j;
	int smallest_idx;	

	for(i=0; i<n; i++)
	{
		smallest_idx = i;

		for(j=i+1; j<n; j++)
		{
			if( pArr2[smallest_idx] > pArr2[j])                 //(stk) i had a problem again. i need to check the reason later!!
			{
				smallest_idx = j;
			}
		}

		Swap(pArr1, pArr2, i, smallest_idx);
	}


}

int main(void)
{
	int sArr[10];
	int sLength = 0;

	//int start[] = {1, 3, 0, 5, 8, 5};
	//int finish[] = {2, 4, 6, 7, 9, 9};
	int start[] = {5, 3, 5, 0, 8, 1};
	int finish[] = {9, 4, 7, 6, 9, 2};

	//1. sort by finish time
	ss(start, finish, 6);

	//2. process
	sLength = sa(sArr, start, finish, 6);

	return 0;
}







