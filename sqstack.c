#include "sqstack.h"


sqstack *stack_create(int len)
{
	sqstack *s;
	if((s = (sqstack *)malloc(sizeof(sqstack))) == NULL)
	{
		puts("malloc failed\n");
		return NULL;
	}
	if((s->data = (datatype *)malloc(sizeof(datatype)*len)) == NULL)
	{
		puts("malloc failed\n");
		return NULL;
	}
	s->maxlen = len;

	s->top = -1;
	return s;
}


int is_empty(sqstack *s)
{
	return (s->top == -1 ? 1:0);	
}


void stack_clear(sqstack *s)
{
	s->top = -1;	
	free(s->data);
	s->data = NULL;
	free(s);
	s = NULL;
}

int stack_full(sqstack *s)
{
	return (s->top == s->maxlen-1);
}

int stack_push(sqstack *s, datatype value)
{
	if(s == NULL)
	{
		return -1;
	}
	if(stack_full(s))
	{
		puts("stack is full\n");
		return -1;
	}
	s->top++;
	s->data[s->top] = value;
	return 1;
}	

datatype stack_pop(sqstack *s)
{
	s->top--;
	return s->data[s->top+1];
	
}
datatype stack_top(sqstack *s)
{
	return (s->data[s->top]);

}
