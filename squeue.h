#ifndef __SQUEUE_H__
#define __SQUEUE_H__


#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef int datatype;

typedef struct
{
	datatype data[MAX];
	int front,rear;

}squeue, *squeue_p;

void create_queue(squeue_p *q);
void in_queue(squeue_p q, datatype value);
void out_queue(squeue_p q, datatype *dat);
int is_empty(const squeue_p q);
int is_full(squeue_p q);
void show_queue(squeue_p q);


#endif

