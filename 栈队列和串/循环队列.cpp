#define MAXSIZE 100
#include<stdio.h>                                     
#include<stdlib.h>
#include<math.h>
typedef struct{
    int *data;
	int front;
	int rear;
}seqQueue;


void InitQueue(seqQueue*Q)
{
	Q->data=(int*)malloc(MAXSIZE*sizeof(int));
    if(Q->data)
        exit(OVERFLOW);
    Q->rear=-1;
    Q->front=-1;
}





bool QueueEmpty(seqQueue*Q)
{
	if(Q->rear==Q->front)
	    return true;
	else
	    return false;
}





bool QueueFull(seqQueue*Q)
{
	if((Q->rear+1)%MAXSIZE==Q->front)
	    return true;
	else
	    return false;
}





bool EnQueue(seqQueue*Q,int x)
{
	if(QueueFull(Q))
	    return false;
	Q->rear=(Q->rear+1)%MAXSIZE;
	Q->data[Q->rear]=x;
	return true;
}



bool DeQueue(seqQueue*Q,int *x)
{
	if(QueueEmpty(Q))
	    return false;
	Q->front=(Q->front+1)%MAXSIZE;
	*x=Q->data[Q->front];
    return true;
}



int QueueLength(seqQueue*Q)
{
	return(Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}