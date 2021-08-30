#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct bitnode{
	char data;
	struct bitnode *lchild, *rchild;
}squeue,bitnode,*bitree;;

int levelorder(bitree bt)
{
	bitree queue[MAXSIZE];
	int front=-1;
	int rear=0;
	if(bt==NULL)
	    return 0;
	queue[rear]=bt;
	while(front!=(rear+1)%MAXSIZE)
	{
		front++;
		printf("%s",queue[front]->data);
		if(queue[front]->lchild!=NULL)
		{
			rear=(rear+1)%MAXSIZE;
			queue[rear]=queue[front]->lchild;
		}
		if(queue[front]->rchild!=NULL)
		{
			rear=(rear+1)%MAXSIZE;
			queue[rear]=queue[front]->rchild;
		}
	
		
	}
	return 1;

}