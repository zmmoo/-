#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__
#include <stdio.h>
#include <stdlib.h>
typedef int datatype ;

typedef struct node_t{
	datatype data;
	struct node_t *next;
}linkstack_t, *linkstack_p;


linkstack_p stack_create(void);
int linkstack_empty(const linkstack_p L);
void linkstack_clear(linkstack_p L);

int stack_push(linkstack_p L, datatype value);
datatype stack_pop(linkstack_p L);
datatype stack_top(const linkstack_p L);

#endif
