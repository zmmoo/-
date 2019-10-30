#include "linkstack.h"
linkstack_p stack_create(void)
{
	linkstack_p L;
	L = (linkstack_p)malloc(sizeof(linkstack_t));
	if(L == NULL)
	{
		puts("malloc failed \n");
		return NULL;
	}
	L->next = NULL;
	return L;
}

int linkstack_empty(const linkstack_p L)
{
	return (L->next == NULL);
		
}
void linkstack_clear(linkstack_p L)
{
	linkstack_p p = L－>next;
	while(p != NULL)
	{
		printf("clear:%d\n ", p->data);
		free(p);
		p = p->next;
	}
	free(L);
	L->next = NULL;

}

int stack_push(linkstack_p L, datatype value)
{
	linkstack_p p;
	p = (linkstack_p)malloc(sizeof(linkstack_t));
	if(p == NULL)
	{
		puts("malloc failed \n");
		return -1;
	}
	p->data = value;
	p->next = L->next;
	L->next = p;
	return 0;
}
datatype stack_pop(linkstack_p L)
{
	datatype data;
	linkstack_p p = L->next;	
	data = p->data;
	L->next = p->next;
	free(p);
	return data;

}
datatype stack_top(const linkstack_p L)
{
	return L->next->data;
}
