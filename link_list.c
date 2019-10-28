#include "link_list.h"

linklist create_list(void)
{
	linklist L;
	L = (linklist)malloc(sizeof(listnode));
	if(L == NULL)
	{
		puts("create list malloc failed\n");
		return NULL;
	}
	L->data = 0;
	L->next = NULL;
	return L;
}
void delete_list(linklist L)
{
	linklist l = L;
	if(L == NULL)
	{
		puts("link list is null\n");
		return ;
	}

	while(L->next)
	{
		L = L->next;
		free(L);
	}
	free(l);
	puts("free memory\n");
}
int insert_list(linklist L, datatype data, int pos)
{
	linklist p;
	if(L == NULL)
	{
		puts("link list is null\n");
		return -1;
	}
	p = (linklist)malloc(sizeof(listnode));
	if(p == NULL)
	{
		puts("link list is null\n");
		return -1;
	}
	while(L->next)
		L = L->next;
	p->data = data;
	p->next = L->next;
	L->next = p;
	return 0;
}
int chenge_list(linklist L, datatype data, int pos)
{
	if(L == NULL)
	{
		puts("is a NULL pointer\n");
		return -1;
	}
	while(L->next)
	{
		if(L->next->data == data)
		{
			L->next->data = pos;
			return 0;
		}
		L = L->next;
	}

}
int search_list(linklist L, datatype data)
{
	if(L == NULL)
	{
		puts("is a NULL pointer\n");
		return -1;
	}
	while(L->next)
	{
		if(L->next->data == data)
		{
			printf("find data %d\n", data);
			return 0;
		}
		L = L->next;
	}
	puts("not find data\n");
	return -1;
}
void show_list(linklist L)
{
	if(L == NULL)
	{
		puts("link list is null\n");
		return ;
	}
	
	while(L->next)
	{
		printf("%d\n",L->next->data);
		L = L->next;
	}

}
void reverse(linklist L)
{
	linklist p, q;
	p = L->next;
	L->next = NULL;
	while(p != NULL)
	{
		q = p;
		p = p->next;

		q->next = L->next;
		L->next = q;
	}
}
int insert_order_list(linklist L, datatype data)
{
	linklist p, q;
	if((p = (linklist)malloc(sizeof(listnode))) == NULL)
	{
		puts("insert order list malloc failed\n");
		return -1;
	}
	p->data = data;
	q = L;
	while(q->next && (data > q->next->data))
		q = q->next;
	p->next = q->next;
	q->next = p;
	return 0;
}
void sort_list(linklist L)
{
	linklist p,q,r;
	p = L->next;
	while(p)
	{
		q = p;
		p = p->next;
		r = L;
		while(r->next && r->next->data < q->data)
			r = r->next;
		q->next = r->next;
		r->next = q;
	}
}
