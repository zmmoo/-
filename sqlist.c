#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>


sqlist_t *create_sqlist(void)
{
	sqlist_t *L = NULL;
	L = (sqlist_t*)malloc(sizeof(sqlist_t));
	if(L == NULL)
	{
		puts("no memory");
		return NULL;
	}
	L->last = -1;
	return L;
}
void clear_sqlist(sqlist_t *L)
{
	if(L == NULL)
	{
		puts("sqlist is NULL");
		return ;
	}
	free(L);
	return ;
}

int is_empty_sqlist(sqlist_t *L)
{
	if(L == NULL)
	{
		puts("sqlist* is NULL");
		return -1;
	}
	return (L->last == -1);
}
int is_full_sqlist(sqlist_t *L)
{
	if(L == NULL)
	{
		puts("sqlist* is NULL");
		return -1;
	}
	return (L->last == MAXSIZE-1);
}
void set_empty_sqlist(sqlist_t *L)
{
	if(L == NULL)
	{
		puts("sqlist* is NULL");
		return ;
	}
	L->last = -1;
	return ;
}
int get_length_sqlist(sqlist_t *L)
{
	if(L == NULL)
	{
		puts("sqlist* is NULL");
		return -1;
	}
	return L->last + 1;

}
void show_sqlist(sqlist_t *L)
{
	int i=0;
	if(L == NULL)
	{
		puts("sqlist * is NULL");
		return ;
	}
	for(i=0; i<= L->last; i++)
	{
		printf("L->data[%d]=%d\n", i, L->data[i]);
	}
	return ;
}

int insert_sqlist(sqlist_t *L, data_t x, int pos)
{
	int i = 0;
	if((is_full_sqlist(L))||(pos<0)||(pos>L->last+1))
	{
		puts("intput argv is invalid");
		return -1;
	}
	for(i=L->last; i>=pos; i--)
	{
		L->data[i+1] = L->data[i];
	}	
	L->data[pos] = x;
	L->last++;
	return 0;
}
int delete_sqlist(sqlist_t *L, int pos)
{
	int i = 0;
	if((pos<0)||(pos>L->last+1))
	{
		puts("intput argv is invalid");
		return -1;
	}
	for(i=pos; i<get_length_sqlist(L); i++)
		L->data[i] = L->data[i+1];
	L->last--;
	return 0;
}
int change_sqlist(sqlist_t *L, data_t x, int pos)
{
	if((pos<0)||(pos>L->last+1))
	{
		puts("intput argv is invalid");
		return -1;
	}
	L->data[pos] = x;
	return 0;

}
int search_sqlist(sqlist_t *L, data_t x)
{
	int i = 0;
	if(L == NULL)
	{
		puts("sqlist * is NULL");
		return -1;
	}
	for(i=0; i<=L->last; i++)
		if(L->data[i] == x)
			return i;
	printf("not find it");
	return -1;
}

