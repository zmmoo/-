#include "dlist.h"

dlistnode * dlist_create()
{
	dlistnode *L, *p, *r;
	int n;
	L = (dlistnode*)malloc(sizeof(dlistnode));
	if(L == NULL)
	{
		puts("malloc failed\n");
		return NULL;
	}
	L->prior = L;
	L->next = L;
	r = L;
	while(1)
	{
		printf("please input:");
		scanf("%d",&n);
		if(n == -1)
			break;
		p = (dlistnode*)malloc(sizeof(dlistnode));
		if(p == NULL)
		{
			puts("malloc failed\n");
			return NULL;
		}
		p->data = n;
		
		p->prior = r;
		p->next = r->next;
		r->next = p;
		L->prior = p;
		r = p;
	}
		return L;

}
void show_dlist(dlistnode *L)
{
	dlistnode *p;
	p = L->next;
	while(p != L)
	{
		printf("%d ",p->data);
		p = p->next;
	}

}
void clear_list(dlistnode *L)
{
	dlistnode *p;
	p = L->next;
	while(p != L)
	{
		p = p->next;
		free(p);
	}
	free(L->next);
	free(L);
	puts("free memory success\n");
}

dlistnode *get_dlist(dlistnode *L, int pos)
{
	int i = -1;
	dlistnode *p = L;
	if(pos < 0)
	{
		puts("pos < 0,invaild\n");
		return NULL;
	}
	while(i<pos)
	{
		p = p->next;
		i++;
		if(p == L)
		{
			printf("pos is invaild\n");
			return NULL;
		}
	}
	return p;
}

int insert_dlist(dlistnode *L, int value, int pos)
{
	dlistnode *p, *q;
	p = get_dlist(L, pos);
	if(p == NULL)
	{
		return -1;
	}
	if((q = (dlistnode*)malloc(sizeof(dlistnode))) == NULL)
	{
		puts("mallco failed\n");
		return -1;
	}
	q->data = value;
	q->prior = p->prior;
	(p->prior)->next = q;
	q->next = p;
	p->prior = q;
}
void delete_value(dlistnode *L, int pos)
{
	dlistnode *p;
	p = get_dlist(L, pos);
	if(p == NULL)
	{
		return ;
	}
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	p = NULL;
}
