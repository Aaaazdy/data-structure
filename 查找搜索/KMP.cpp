#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXNUM 100
typedef struct {
	char*ch;
	int length;
	int strsize;
}string;
void getnext(string*t,int next[])
{
	int j=0,i=-1;
	next[0]=-1;
	while(j<t->length)
	{
		if(i==-1||t->ch[i]==t->ch[j])
		{
			j++;
			i++;
		    next[j]=i;
		}
        else
            i=next[i];

	}

}



int KMPindex(string*s,string*t,int pos)
{
	int i,j;
	int next[t->length+1];
	getnext(t,next);
	i=pos-1;
	j=0;
	while(i<s->length&&j<t->length)
	{
		if(j==-1||s->ch[i]==t->ch[j])
		{
			i++;
			j++;
		}
		else
		    j=next[j];
		
	}
	if(j>=t->length)
	    return(i-t->length+1);
	else
	    return 0;
			
}