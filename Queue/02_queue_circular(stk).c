#include <stdio.h>

#define	MAX_Q_SIZE		5

typedef struct _Queue{
	int buffer[MAX_Q_SIZE];
	int front_idx; // 0 base
	int rear_idx;  // 0 base	
} Queue;

void PrintQ(Queue* pQueue, int qSize)
{
	int front_idx;
	int rear_idx;
	int i;

	front_idx = pQueue->front_idx;
	rear_idx = pQueue->rear_idx;

	if(front_idx == rear_idx)
	{
		//empty
		return;
	}
	//
	for(i=0; i<qSize; i++)
	{
		if(i == front_idx)
		{
			printf("SS ");
		}
		else if(i == rear_idx)
		{
			printf("EE ");
		}
		else
		{
			printf("###");
		}
	}
	printf("\n");
	//

	if(front_idx < rear_idx)
	{
		for(i=front_idx; i<=rear_idx; i++)
		{
			printf("%2d ", pQueue->buffer[i]);
		}
	}
	else if(rear_idx < front_idx)
	{
		for(i=front_idx; i<qSize; i++)
		{
			printf("%2d ", pQueue->buffer[i]);
		}

		for(i=0; i<=rear_idx; i++)
		{
			printf("%2d ", pQueue->buffer[i]);
		}
	}
}

int IsOverFlow(Queue* pQueue, int qSize)
{
	int front_idx;
	int rear_idx;

	front_idx = pQueue->front_idx;
	rear_idx = pQueue->rear_idx;

	if(front_idx < rear_idx)
	{
		if( (front_idx+1) == rear_idx )
			return 1;
	}
	else if(rear_idx < front_idx)
	{
		if( (rear_idx+1) == front_idx )
			return 1;
	}

	return 0;
}

void EnQ(Queue* pQueue, int qSize, int obj)
{
	int front_idx;
	int rear_idx;

	if(IsOverFlow(pQueue, qSize))
	{
		//overflow
		printf("overflow!\n");
	}
	else // <-- here is only can be false haha. i found good example of statement of logic. (This mean it isn't overflow)
	{
		front_idx = pQueue->front_idx;
		rear_idx = pQueue->rear_idx;

		if(front_idx == -1 && rear_idx == -1) // if queue is first empty status
		{
			front_idx = (front_idx++) % qSize;
			pQueue->front_idx = front_idx;

			rear_idx = (rear_idx++) % qSize;
			pQueue->buffer[rear_idx] = obj;
			pQueue->rear_idx = rear_idx;
		}
		else
		{
			//rear_idx = (rear_idx + 1) % qSize;
			rear_idx = (rear_idx++) % qSize;
			pQueue->buffer[rear_idx] = obj;
			pQueue->rear_idx = rear_idx;
		}
	}	
}

int DeQ(Queue* pQueue, int qSize)
{
	int front_idx;
	int rear_idx;
	int popVal;

	if(IsOverFlow(pQueue, qSize))
	{
		//overflow
		printf("overflow!\n");
		return -99;

	}
	else
	{
		front_idx = pQueue->front_idx;
		rear_idx = pQueue->rear_idx;

		popVal = pQueue->buffer	[front_idx];
		front_idx = (front_idx++) % qSize;
		pQueue->front_idx = front_idx;

		return popVal;
	}
	
}



void InitQ(Queue* pQueue, int qSize)
{
	int i;

	pQueue->front_idx = -1;
	pQueue->rear_idx = -1;	

	for(i=0; i<qSize; i++)
	{
		pQueue->buffer[i] = -99;
	}
}


int main(void)
{
	Queue testQueue;
	int qSize = MAX_Q_SIZE;

	InitQ(&testQueue, qSize);

	EnQ(&testQueue, qSize, 10);
	EnQ(&testQueue, qSize, 22);
	EnQ(&testQueue, qSize, 33);
	EnQ(&testQueue, qSize, 44);
	EnQ(&testQueue, qSize, 55);

	PrintQ(&testQueue, qSize);


	return 0;
}

/*
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

*/
