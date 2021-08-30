#include<stdio.h>
#include<string.h>
int getmax(int a[],int n)
{
	int i,max;
	max=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
    return max;
}
void sort(int a[],int n,int exp)
{
	int i;
	int output[n];
	int bucket[10];
	memset(bucket,0,sizeof(bucket));
	for(i=0;i<n;i++)
	{
		bucket[(a[i]/exp)%10]++;
	}
	for(i=1;i<10;i++)
	{
		bucket[i]+=bucket[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		output[bucket[(a[i]/exp)%10]-1]=a[i];
		bucket[(a[i]/exp)%10]--;
	}
	for(i=0;i<n;i++)
	{
		a[i]=output[i];
	}	
}


int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    int exp;
    int max=getmax(a,n);
    for(exp=1;max/exp!=0;exp*=10)
    {
    	sort(a,n,exp);	
	}
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;

}