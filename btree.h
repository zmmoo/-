#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "link_queue.h"


void create_btree(btree_pnode *B);
void pre_order(btree_pnode B);
void mid_order(btree_pnode B);
void post_order(btree_pnode B);
void level_order(btree_pnode B);
void unpre_order(btree_pnode t);
void travel(char *str, void (*p)(btree_pnode), btree_pnode t);

#endif

