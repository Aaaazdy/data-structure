#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void getnext(char*t,int *next)
{
	int length=strlen(t);
	int j=0;
	int i=-1;
	next[0]=-1;
	while(j<length)
	{
		if(i==-1||t[i]==t[j])
		{
			i++;
			j++;
			next[j]=i;
		}
		else
		    i=next[i];
		
    }
}

int kmp(char*s,char*t,int pos,int *next)
{
	int lengtht=strlen(t);
	int lengths=strlen(s);
	int j=pos-1;
	int i=0;
	while(j<lengths&&i<lengtht)
	{
		if(i==-1||s[j]==t[i])
		{
			i++;
			j++;
		}
		else
		    i=next[i];
	}
	if(i==lengtht)
	    return j-i+1;
	else 
	    return -1;
		
}
int main()
{
	
	char s[100];
	char t[100];
	gets(s);
	gets(t);
	int lengtht=strlen(t);
	int lengths=strlen(s);
	
	int next[lengtht+1];
	getnext(t,next);
	for(int i=0;i<lengtht;i++)
	    printf("%d,",next[i]);
	int m=0;
	int x=0;
	int i;
	while(m<lengths)
	{
		i=kmp(s,t,m+1,next);
		if(i==-1)
		    break;
		printf("\n%d",i);
		m=i;
		x++;
	}
	if(x==0)
    	printf("-1");	
    system("pause");
}