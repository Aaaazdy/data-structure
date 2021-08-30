#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXNUM 100

void getnext(char*t,int*next)
{
	int length=strlen(t);
	int j=0;
	int i=-1;
	next[0]=-1;
	while(j<length)
	{
		if(i==-1||t[i]==t[j])
		{
			j++;
			i++;
			next[j]=i;	
		}
		else
		{
			i=next[i];
		}	
    }
}


int kmp(char*s,char*t,int pos)   //pos为数组下标+1
{
	int lengths=strlen(s);
	int lengtht=strlen(t);
	int j=pos-1;
	int i=0;
	int next[lengtht+1];
	getnext(t,next);
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
		return (j-i+1);    //返回匹配的数组下标+1
	else
	    return -1;
	
}


int main()
{
	char s[2000];
	char t[2000];
	scanf("%s",s);
	getchar();
	scanf("%s",t); 
	int n=strlen(t);
	int next[n+1];
	getnext(t,next);
	for(int i=0;i<n;i++)
	{
		printf("%d,",next[i]+1);
	}
	int w=strlen(s);
	int x=0; 
	int m=0;
	int i;
	while(m<w)
	{
	    i=kmp(s,t,m+1);
	    if(i==-1)
        {
		    break;
	    }
		printf("\n%d",i);
	    m=i;
        x++;
	}
    if(x==0)
    printf("\n-1");
    
}