#ifndef __DLIST_H__
#define __DLIST_H__
#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node *prior;
	struct node *next;
}dlistnode;

dlistnode * dlist_create();
void show_dlist(dlistnode *L);
void clear_list(dlistnode *L);
dlistnode *get_dlist(dlistnode *L, int pos);
int insert_dlist(dlistnode *L, int value, int pos);
void delete_value(dlistnode *L, int pos);

#endif
