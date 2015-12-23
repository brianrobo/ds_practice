#include <stdio.h>

#define	MAX_Q_SIZE		5

typedef struct _Queue{
	int buffer[MAX_Q_SIZE];
	int count;
} Queue;

void InitQ(Queue* pQueue, int qSize)
{
	int i;
	pQueue->count = 0;

	for(i=0; i<qSize; i++)
	{
		pQueue->buffer[i] = -99;
	}

}

void PrintQ(Queue* pQueue)
{
	int i;
	printf("count: %d\n", pQueue->count);

	for(i=0; i<pQueue->count; i++)
	{
		printf("%d ", pQueue->buffer[i]);
	}
}


void EnQ(Queue* pQueue, int obj)
{
	if(pQueue->count == MAX_Q_SIZE) // stk1) the this statement only true / false, any other status can't be possible? i need to check this for if~else
	{
		//overflow
	}
	else
	{
		if(pQueue->count == 0)
		{
			pQueue->buffer[0] = obj;
		}
		else
		{
			pQueue->buffer[pQueue->count] = obj;
		}
		pQueue->count++;
	}

}

int DeQ(Queue* pQueue)
{
	int popVal;
	int i;

	if(pQueue->count == 0)
	{
		//empty
	}
	else
	{
		popVal = pQueue->buffer[0];
		pQueue->count--;

		for(i=0; i<pQueue->count; i++)
		{
			pQueue->buffer[i] = pQueue->buffer[i+1];
		}

		pQueue->buffer[i] = -99;

		return popVal;
	}
}

int main(void)
{
	int popVal;
	Queue testQueue;


	InitQ(&testQueue, MAX_Q_SIZE);

	EnQ(&testQueue, 1);
	EnQ(&testQueue, 2);
	EnQ(&testQueue, 3);

	PrintQ(&testQueue);

	popVal = DeQ(&testQueue);

	PrintQ(&testQueue);
	




}
