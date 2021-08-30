#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int top[2],end[2];
	int*elem;
	int m;
}DblStack;



void initstack (DblStack*s,int n)
{
	s->elem=(int*)malloc(sizeof(int)*n);
	if(s->elem==NULL)
	    printf("assign failure");
	s->m=n;
	s->top[0]=s->end[0]=-1;
	s->top[1]=s->end[1]=n;
}



bool stackempty(DblStack*s,int i)//判断栈i是否为空
{
	if(s->top[i]==s->end[i])
	    return true;
	else
	    return false;
		
}



bool stackfull(DblStack*s)    //判断栈是否为满
{
	if(s->top[0]+1==s->top[1])
	    return true;
	else
	    return false;
	
}



int push(DblStack*s,int x,int i)   //将x进i栈
{
	if(stackfull(s))
	    return 0;
	if(i==0)
	    s->elem[++s->top[0]]=x;
	else
	    s->elem[--s->top[1]]=x;
	return 1;	
	
}



int pop(DblStack*s,int*x,int i)     //弹出栈i，通过指针x返回值
{
	if(stackempty(s,i))
	    return 0;
	if(i==0)
		*x=s->elem[s->top[0]--];
	else
	    *x=s->elem[s->top[1]++];
	return 1;	
	
}




int gettop(DblStack*s,int*x,int i)   //取栈顶元素并通过指针x返回值
{
	if(stackempty(s,i))
	    return 0;
	*x=s->elem[s->top[i]];
	return 1;
	
}



void makeempty(DblStack*s,int i)
{
	if(i==0)
	    s->top[0]=s->end[0]=-1;
	else
	    s->top[1]=s->end[1]=s->m;
}

