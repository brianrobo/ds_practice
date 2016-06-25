/*
(1) ���ľȵ� ��ü�� round�� �ݺ��ɼ��� ������ �Ѱ��� �پ��.
	�̸� �迭���� �ݺ����� ǥ���غ���?

	int arr[5]

	   [0][1][2][3][4]
	   [ ][ ][ ][ ][ ]

	  ó���� Ȯ���Ұ� 5��,
	  ����round�� 4��
	  �״����� 3��

	  int i,j;

	  int min_idx;

	  for(i=0; i<5-1; i++)   <--- ���� �Ǿպκп� ���� ��ġ�� ���� �ݺ�.  ��ü���� ������ �������� ������ ��, ������ ������ �ִ밪�̴�~
	  {

		min_idx = i; <-- �ϴ� �� round�� ���� ���� �ּҰ��� ��ó�� ������.
		for(j=i+1; j<5; j++) <--- ���� �� round���� �ּҰ��� ã������ �ݺ�.
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

	  : => Inspection ������ ���⿡ ǥ���ϱ� ������ Note�� �غ���.

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


