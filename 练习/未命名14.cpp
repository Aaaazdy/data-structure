#include<stdio.h>
int main()
{
	int i=1;
	i+=(i++)+(++i);
	printf("%d",i);
	return 0;
}