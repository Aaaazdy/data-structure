#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node*next;
}StackNode,*LinkStack;


LinkStack Init_LinkStack()
{
	return NULL;
}


int Empty_LinkStack(LinkStack 	top)
{
	if(top=NULL)
	    return 1;
	else
	    return 0;
}



LinkStack Push_LinkStack(LinkStack top,int x)
{
	LinkStack s;
	s=(LinkStack)malloc(sizeof(StackNode));
	s->data=x;
	s->next=top;
	top=s;
	return top;
}



LinkStack Push_LinkStack(LinkStack top, int* x)
{
	LinkStack p;
	if(top==NULL)
	    return NULL;
	else
	{
		*x=top->data;
		p=top;
		top=top->next;
		free(p);
		return top;
	}
}