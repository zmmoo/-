#include "squeue.h"

void create_queue(squeue_p *q)
{
	if((*q=(squeue_p)malloc(sizeof(squeue))) == NULL)
	{
		puts("malloc failed\n");
		return ;
	}
	(*q)->front = MAX - 1;
	(*q)->rear = MAX - 1;
}

void in_queue(squeue_p q, datatype value)
{
	if(is_full(q))
	{
		puts("queue is full\n");
		return ;
	}
	q->rear = (q->rear+1) % MAX;
	q->data[q->rear] = value;
	
}

int is_full(squeue_p q)
{
	return ((q->rear+1)%MAX == q->front) ;
}

void out_queue(squeue_p q, datatype *dat)
{
	if(is_empty(q))
	{
		puts("queue is empty\n");
		return ;
	}
	q->front = (q->front+1)%MAX;
	*dat = q->data[q->front];
}

int is_empty(const squeue_p q)
{
	return (q->rear == q->front);
}
void show_queue(squeue_p q)
{
	int i;
	if(is_empty(q))
		return ;
	for(i=(q->front+1)%MAX; i != (q->rear+1)%MAX; i=(i+1)%MAX)	
	{
		printf("%d ",q->data[i]);	
	}
		
}
