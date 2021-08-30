#include<stdio.h>
int minisum(int a[],int n)
{
	int i;
	int sum=0;
    int mini=0;
	for(i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum<mini)
		{
			mini=sum;
	    }
	    if(sum>0)
	    {
	    	sum=0;
		}
	}
	return mini;
}
int main()
{
	int i,n,m;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    m=minisum(a,n);
    printf("%d",m);
    return 0;

}