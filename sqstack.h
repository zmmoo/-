#ifndef __SQSTACK_H__
#define __SQSTACK_H__
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct{
	datatype *data;
	int maxlen;
	int top;
}sqstack;
sqstack *stack_create(int len);
int is_empty(sqstack *s);
void stack_clear(sqstack *s);
int stack_full(sqstack *s);
int stack_push(sqstack *s, datatype value); 
datatype stack_pop(sqstack *s);
datatype stack_top(sqstack *s);

#endif

