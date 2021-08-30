void binsertsort(int A[],int N)
{
    int i,j,low,high,m;
	for(i=2;i<=N;i++)    //数组下标+1
    {
        A[0]=A[i];
        low=1;
        high=i-1;
        while(low<=high)
        {
        	m=(low+high)/2;
        	if(A[0]<A[m])
        	    high=m-1;
        	else 
        	    low=m+1;
		}
		
		
		for(j=i-1;j>=high+1;j--)
        {
            A[j+1]=A[j];
        }
        A[high+1]=A[0];
    }
}


void insertsort(int A[],int len)
{
    int i,j,l,h,m,tmp;
	for(i=1;i<=len-1;i++)
    {
        tmp=A[i];
        l=0;
        h=i-1;
        while(l<=h)
        {
        	m=(l+h)/2;
        	if(tmp<A[m])
        	    h=m-1;
        	else 
        	    l=m+1;
		}
		
		
		for(j=i-1;j>=h+1;j--)
        {
            A[j+1]=A[j];
        }
        A[h+1]=tmp;
    }
}


void insertsort(int A[],int low,int high)
{
    int i,j,l,h,m,tmp;
	for(i=low+1;i<=high;i++)
    {
        tmp=A[i];
        l=low;
        h=i-1;
        while(l<=h)
        {
        	m=(l+h)/2;
        	if(tmp<A[m])
        	    h=m-1;
        	else 
        	    l=m+1;
		}
		
		
		for(j=i-1;j>=h+1;j--)
        {
            A[j+1]=A[j];
        }
        A[h+1]=tmp;
    }
}
