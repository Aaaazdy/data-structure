#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXNUM 100
typedef struct {
	char*ch;
	int length;
	int strsize;
}string;
  string createnewstring(void)
{
	string s;
	s.ch=(char*)malloc(MAXNUM*sizeof(char));
	s.length=0;
	s.strsize=MAXNUM;
	return s;
}
   
   
   
int isempty(string s)                                       //判断是否为空
{
	if(s.length==0)
	    return 1;
	else
	    return 0;
}



void stringassign(string*s1,char s2[])                       //串常量赋值串变量
{
	int i=0;
	while(s2[i]!='\0')
	    i++;
	if(s1->strsize<i)
	{
		s1->ch=(char*)realloc(s1->ch,i*sizeof(char));
		s1->strsize=i;
	}
	s1->length=i;
	for(i=0;i<s1->length;i++)
	    s1->ch[i]=s2[i];
	    
}


void assign(string*s1,string*s2)                     //串变量赋值串变量
{
	if(s1->strsize<s2->length)
	{
		s1->ch=(char*)realloc(s1->ch,s2->length*sizeof(char));
		s1->strsize=s2->length;
	}
    s1->length=s2->length;
    for(int i=0;i<s2->length;i++)
        s1->ch[i]=s2->ch[i];
        
}



int len(string s)                                   //求串长
{
	return s.length;
}



void concat(string*s,string s1,string s2)           //串连接
{
	if(s->strsize<s1.length+s2.length)
	{
		s->ch=(char*)realloc(s->ch,(s1.length+s2.length)*sizeof(char));
		s->strsize=s1.length+s2.length;
	}
    s->length=s1.length+s2.length;
    for(int i=0;i<s1.length;i++)
    {
    	s->ch[i]=s1.ch[i];
	}

    for(int i;i<s->length;i++)
    {
    	s->ch[i]=s2.ch[i-s1.length];
	}

}



int substr(string s,int i,int j,string*t)           //取子串
{
	if(i<=0||i>s.length||j<0||j+i>s.length)
	    return 0;
	if(t->length<j)
	{
		t->ch=(char*)realloc(t->ch,j*sizeof(char));
		t->strsize=j;
	}
	for(int k=0;k<j;k++)
	{
		t->ch[k]=s.ch[i-1+k];
	}
    t->length=j;
    return 1;

}





int insert(string*s,int i,string t)
{
	if(i<=0||i>s->length)
	    return 0;
    if(s->strsize<s->length+t.length)
    {
    	s->ch=(char*)realloc(s->ch,(s->length+t.length)*sizeof(char));
    	s->strsize=s->length+t.length;
	}
	for(int j=s->length-1;j>i-1;j--)
	    s->ch[j+t.length]=s->ch[j];
	for(int j=0;j<t.length;j++)
	    s->ch[i+j-1]=t.ch[j];
	s->length=s->length+t.length;
	return 1;
	
	
	
 }