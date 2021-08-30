#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
typedef struct{
	int queue[Maxsize];
	int front;
	int rear;
}sqQueue;


sqQueue *initQueue(void)
{
	sqQueue p;
	sqQueue*q;
	p=*q;
	q->front=-1;
	q->rear=-1;
	return q;
}



bool enqueue(sqQueue*q,int x)
{
	if(q->rear=Maxsize-1)
	    return false;
	q->rear++;
	q->queue[q->rear]=x;
	return true;
}




int dequeue(sqQueue*q)
{
	int x;
	if(q->rear==q->front)
	    return NULL;
	x=q->queue[q->front++];
	return x;
}


int getHead(sqQueue*q)
{
	int x;
	if(q->rear==q->front)
	    return 0;
	x=q->queue[q->front+1];
	return x;
}


bool Empty(sqQueue*q)
{
	if(q->rear==q->front)
	     return true;
	return false;
}



int length(sqQueue*q)
{
	return(q->rear-q->front);
}
