#include<stdio.h>
#include<stdlib.h>
void binsertsort(int A[],int N)
{
    int i,j,tmp,low,high,m;
	for(i=2;i<=N;i++)
    {
        tmp=A[i];
        low=1;
        high=i-1;
        while(low<=high)
        {
        	m=(low+high)/2;
        	if(tmp<A[m])
        	    high=m-1;
        	else 
        	    low=m+1;
		}
		
		
		for(j=i-1;j>=high+1;j--)
        {
            A[j+1]=A[j];
        }
        A[high+1]=tmp;
        for(j=1;j<=N;j++)
            printf("%d,",A[j]);
        printf("\n");
	}
}


int main()
{
	int i,N;
	scanf("%d",&N);
	int*a;
	a=(int*)malloc(sizeof(int)*(N+1));
	for(i=1;i<=N;i++)
	    scanf("%d,",&a[i]);
	binsertsort(a,N);
	return 0;
}