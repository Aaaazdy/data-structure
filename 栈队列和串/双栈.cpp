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



bool stackempty(DblStack*s,int i)//�ж�ջi�Ƿ�Ϊ��
{
	if(s->top[i]==s->end[i])
	    return true;
	else
	    return false;
		
}



bool stackfull(DblStack*s)    //�ж�ջ�Ƿ�Ϊ��
{
	if(s->top[0]+1==s->top[1])
	    return true;
	else
	    return false;
	
}



int push(DblStack*s,int x,int i)   //��x��iջ
{
	if(stackfull(s))
	    return 0;
	if(i==0)
	    s->elem[++s->top[0]]=x;
	else
	    s->elem[--s->top[1]]=x;
	return 1;	
	
}



int pop(DblStack*s,int*x,int i)     //����ջi��ͨ��ָ��x����ֵ
{
	if(stackempty(s,i))
	    return 0;
	if(i==0)
		*x=s->elem[s->top[0]--];
	else
	    *x=s->elem[s->top[1]++];
	return 1;	
	
}




int gettop(DblStack*s,int*x,int i)   //ȡջ��Ԫ�ز�ͨ��ָ��x����ֵ
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

