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
