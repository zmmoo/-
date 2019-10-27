#ifndef __SQLIST_H__
#define __SQLIST_H__
#include <stdio.h>

#define MAXSIZE 100
typedef int data_t;
typedef struct{
	data_t data[MAXSIZE];
	int last;
}sqlist_t;

sqlist_t *create_sqlist(void);
void clear_sqlist(sqlist_t *L);

int is_empty_sqlist(sqlist_t *L);
int is_full_sqlist(sqlist_t *L);
void set_empty_sqlist(sqlist_t *L);
int get_length_sqlist(sqlist_t *L);
void show_sqlist(sqlist_t *L);

int insert_sqlist(sqlist_t *L, data_t x, int pos);
int delete_sqlist(sqlist_t *L, int pos);
int change_sqlist(sqlist_t *L, data_t x, int pos);
int search_sqlist(sqlist_t *L, data_t x);

#endif
