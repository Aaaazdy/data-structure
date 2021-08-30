#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node{
	struct node*next;
	int data;
}Qlist;
typedef struct{
	Qlist*front;
	Qlist*rear;
}LinkQueue;


LinkQueue* InitQueue(void)
{
	LinkQueue*q;
	q->front=q->rear=(Qlist*)malloc(sizeof(Qlist));
	if(!q->front)
	    exit(OVERFLOW);
	q->front->next=NULL;
	return q;
}


void EnQueue(LinkQueue*q,int e)
{
	Qlist*p;
	p=(Qlist*)malloc(sizeof(Qlist));
	p->data=e;
	p->next=NULL;
	if(q->rear==NULL)
	    q->front=q->rear=p;
	else
	{
		q->rear->next=p;
		q->rear=p;
	}	
}



bool DeQueue(LinkQueue*q,int *e)
{
	Qlist*p;
	if(q->front==q->rear)
	    return false;
    p=q->front->next;
    *e=p->data;
    q->front->next=p->next;
    if(q->rear==p)
        q->rear=q->front;
    else
        free(p);
    return true;


}



bool DestroyQueue(LinkQueue*q)
{
	while(q->front)
	{
		q->rear=q->front->next;
		free(q->front);
		q->front=q->rear;
	}
    return true;
}