#include "link_queue.h"

void create_queue(linqueue **q)
{
	(*q)->front = (*q)->rear = (linklist *)malloc(sizeof(linklist));
	if((*q)->front == NULL)
	{
		puts("malloc failed \n");
		return ;
	}
	(*q)->front->next = NULL;
	(*q)->rear->next = NULL;
}
void in_queue(linqueue *q, datatype value)
{
	linklist *L;
	L = (linklist*)malloc(sizeof(linklist));
	if(L == NULL)	
	{
		puts("malloc failed\n");
		return ;
	}
	L->data = value;
	L->next = q->rear->next;
	q->rear->next = L;
	q->rear = L;
}
void out_queue(linqueue *q, datatype *data)
{
	if(q == NULL)	
	{
		puts("linqueue is a NULL pointer\n");
		return ;
	}
	if(is_empty(q))
	{
		puts("queue is empty\n");
		return ;
	}
	*data = q->front->next->data;
	printf("out: %d \n", *data);
	free(q->front);
	puts("free success\n");
	q->front = q->front->next;
}
int is_empty(linqueue *q)
{
	return (q->front == q->rear);
}
