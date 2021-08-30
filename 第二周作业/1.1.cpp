#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void josp(int n,int m)
{
	int*num=(int*)malloc(n*(sizeof(int)));
	if(!num)
	    printf("error");
	int i;
	for(i=0;i<n;i++)
	{
		num[i]=i+1;
	}
	i=0;
	i=(i+m)%n;
	printf("%d,",num[i]);
	for(int j=i+1;j<n;j++)
		num[j-1]=num[j];
	n--;
	if(i==n)
	    i=0;
	while(n>1)
	{
		i=(i+m)%n;
		printf("%d,",num[i]);
		for(int j=i+1;j<n;j++)
		    num[j-1]=num[j];
		n--;
		if(i==n)
		    i=0;	    //从替换之后的结点开始计数
	}
    printf("%d",num[0]);
}
int main()
{
	int n;
	int m;
	scanf("%d",&n);
	getchar();
	scanf("%d",&m);
    josp(n,m);
	return 0;
}