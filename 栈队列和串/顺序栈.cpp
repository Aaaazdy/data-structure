#define Maxsize 100
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int elem[Maxsize];
	int top;
}SqStack;
SqStack * Init_SqStack(void)
{
	SqStack* S;
	S=(SqStack*)malloc(sizeof(SqStack));
	if(S)
	{
		S->top=-1;
		printf("ÖÃ¿ÕÕ»³É¹¦£¡\n");
	}
    return 	S;
}



int Empty_SqStack(SqStack*S)
{
	if(S->top==-1)
	    return 1;
	else
	    return 0;
}



int Push_SqStack(SqStack*S)
{
	if(S->top==Maxsize-1)
	    return 0;
	else
    {
    	int x;
		scanf("%d",&x);
    	S->top++;
    	S->elem[S->top]=x;
    	return 1;
	}
}



int Pop_SqStack(SqStack*S,int*x)
{
	if(Empty_SqStack(S))
	    return 0;
	else
	{
		*x=S->elem[S->top];
		S->top--;
		return 1;
	}
}



int GetTop_SqStack(SqStack*S,int *x)
{
	if(Empty_SqStack(S))
	    return 0;
	else
	{
		*x=S->elem[S->top];
		return 1;
		
	}
}