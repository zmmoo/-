#ifndef __LINK_QUEUE_H__
#define __LINK_QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node
{
	datatype data;
	struct node *next;
}linklist;
typedef struct 
{
	linklist *front, *rear;
}linqueue;

void create_queue(linqueue **q);
void in_queue(linqueue *q, datatype value);
void out_queue(linqueue *q, datatype *data);
int is_empty(linqueue *q);

#endif
