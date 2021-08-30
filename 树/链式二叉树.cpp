#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct bitnode{
	char data;
	struct bitnode *lchild,*rchild;
}BiTNode,*BiTree;


int initiate(BiTree bt)
{
	if((bt=(BiTree)malloc(sizeof(BiTNode)))==NULL)
	    return 0;
	bt->lchild=bt->rchild=NULL;
	return 1;
}


BiTree create(char x,BiTree lbt,BiTree rbt)
{
	BiTree p;
	if((p=(BiTree)malloc(sizeof(BiTNode)))==NULL)
	    return NULL;
	p->data=x;
	p->lchild=lbt;
	p->rchild=rbt;
	return p;
	
		
}



BiTree InsertL(BiTree bt,BiTree parent,char x)
{
	BiTree p;
	if(parent==NULL)
	{
		printf("²åÈë´íÎó\n");
		return NULL;
	}
	if((p=(BiTree)malloc(sizeof(BiTNode)))==NULL)
	    return NULL;
	p->data=x;
	p->lchild=p->rchild=NULL;
	if(parent->lchild==NULL)
	    parent->lchild=p;
	else
	{
		p->lchild=parent->lchild;
		parent->lchild=p;
		
	}
	return bt;
	
}



BiTree InsertR(BiTree bt,BiTree parent,char x)
{
	BiTree p;
	if(parent==NULL)
	{
		printf("²åÈë´íÎó\n");
		return NULL;
	}
	if((p=(BiTree)malloc(sizeof(BiTNode)))==NULL)
	    return NULL;
	p->data=x;
	p->lchild=p->rchild=NULL;
	if(parent->rchild==NULL)
	    parent->rchild=p;
	else
	{
		p->rchild=parent->rchild;
		parent->rchild=p;
		
	}
	return bt;
	
}




BiTree DeleteL(BiTree bt,BiTree parent)
{
	BiTree p;
	if(parent==NULL||parent->lchild==NULL)
	    printf("É¾³ý³ö´í");
	p=parent->lchild;
	parent->lchild=NULL;
	free(p);
	return bt;
}




