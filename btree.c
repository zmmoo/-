#include "btree.h"
#include "linkstack.h"

void create_btree(btree_pnode *B)
{
	btree_pnode p;
	datatype value;
	scanf("%c",&value);
	if('#' == value)
	{
		*B = NULL;
		return ;
	}
	p = (btree_pnode)malloc(sizeof(btree_node));
	if(p == NULL)
	{
		puts("malloc failed\n");
		return ;
	}
	(*B) = p;
	(*B)->data = value;
	puts("create lchild\n");
	create_btree(&((*B)->lchild));
	puts("create rchild\n");
	create_btree(&((*B)->rchild));
}



void pre_order(btree_pnode B)
{
	if(B == NULL)
		return ;
	printf("%c", B->data);
	pre_order(B->lchild);
	pre_order(B->rchild);
}

void mid_order(btree_pnode B)
{
	if(B == NULL)
		return ;
	mid_order(B->lchild);
	printf("%c", B->data);
	mid_order(B->rchild);
}
void post_order(btree_pnode B)
{
	if(B == NULL)
		return ;
	post_order(B->lchild);
	post_order(B->rchild);
	printf("%c", B->data);
}
void level_order(btree_pnode B)
{
	linqueue l;
	l = create_queue();
	while(B != NULL)
	{
		printf("%c",B->data);
		if(B->lchild != NULL)
			in_queue(&l, B->lchild);
		if(B->rchild != NULL)
			in_queue(&l, B->rchild);
		if(!is_empty(&l))
			out_queue(&l, &B);
		else
			break;
	}
}
void unpre_order(btree_pnode t)
{
	linkstack_p p;
	p = stack_create();
	while(t != NULL || !linkstack_empty(p))	
		if(t!=NULL)
		{
			printf("%c", t->data);
			if(t->rchild != NULL)
				stack_push(p, t->rchild);
			t = t->lchild;
		}
		else
		{
			t = stack_pop(p);
		}

}
