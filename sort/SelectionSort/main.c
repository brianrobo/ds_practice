/*
(1) 정렬안된 전체가 round가 반본될수록 갯수가 한개씩 줄어듬.
	이를 배열에서 반복으로 표현해보면?

	int arr[5]

	   [0][1][2][3][4]
	   [ ][ ][ ][ ][ ]

	  처음엔 확인할게 5개,
	  다음round엔 4개
	  그다음엔 3개

	  int i,j;

	  int min_idx;

	  for(i=0; i<5-1; i++)   <--- 실제 맨앞부분에 넣을 위치에 대한 반복.  전체개수 마지막 전까지만 넣으면 됨, 남은거 어차피 최대값이니~
	  {

		min_idx = i; <-- 일단 각 round별 들어가기 전에 최소값은 맨처음 값으로.
		for(j=i+1; j<5; j++) <--- 실제 각 round별로 최소값을 찾기위한 반복.
		{
		   if( arr[min_idx] > arr[j] )
		   {
			  min_idx = j;
		   }
		}
		swap(arr, i, min_idx);
	  }

	  //Inspection

			  [0][1][2][3][4]
			  [4][2][3][1][5]

			  (1round)    start
			  i        :    0
			  j        :    1
			  min_idx  :    0

	  : => Inspection 실제로 여기에 표현하기 어려우니 Note에 해볼것.

*/


#include <stdio.h>

void SelectionSort(int* pArr, int n);
void Swap(int* pArr, int idxA, int idxB);
void PrintArr(int* pArr, int n);

int main(void)
{
	int myArr[5] = { 4, 2, 3, 1, 5 };

	printf("Initial Arr\n");
	PrintArr(myArr, 5);

	SelectionSort(myArr, 5);
	printf("After Sorting Arr\n");
	PrintArr(myArr, 5);

	return 0;
}


void SelectionSort(int* pArr, int n)
{
	int i, j;
	int minIdx;


	for (i = 0; i < n - 1; i++)
	{
		minIdx = i;

		for (j = i + 1; j < n; j++)
		{
			if (pArr[minIdx] > pArr[j])
			{
				minIdx = j;
			}
		}

		Swap(pArr, i, minIdx);
	}
}

void Swap(int* pArr, int idxA, int idxB)
{
	int temp;

	temp = pArr[idxA];

	pArr[idxA] = pArr[idxB];
	pArr[idxB] = temp;
}

void PrintArr(int* pArr, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", pArr[i]);
	}
	printf("\n");
}


