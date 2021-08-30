#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s1[100];
	char s2[50];
	char s3[50];
	char k;
	gets(s1);
	gets(s2);
	scanf("%c",&k);
	int n=strlen(s1);
	int s=-1;
	for(int i=0;i<n;i++)
	{
		if(s1[i]==k)
		{
		    s=i;
			break;
	    }
	
	}
	if(s==-1)
	{
		strcat(s1,s2);
	    puts(s1);
		return 0;
	}
	for(int i=s;i<n;i++)
	{
		s3[i-s]=s1[i];
	    
	}   
	s1[s]='\0';
	s3[n-s]='\0';
	strcat(s1,s2);
	strcat(s1,s3);
	puts(s1);
    return 0;	
}