#include<stdio.h>
#include<stdlib.h>
void swap(int a[],int i,int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}


int median(int a[],int low,int high)
{
	int center=(low+high)/2;
	if(a[low]>a[high])
	    swap(a,low,high);
	if(a[low]>a[center])
	    swap(a,low,center);
	if(a[center]>a[high])
	    swap(a,center,high);
	swap(a,center,high-1);
	return a[high-1];
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



void Qsort(int a[],int low,int high,int k,int l)
{
	int i,j,pivot,m;
	if(low+3<=high)
	{
		if(k==0)
		{
			pivot=a[l]; 
			swap(a,l,high);
		 	k++;
		 	i=low-1;
		 	j=high;
		}
		else
		{
	        pivot=median(a,low,high);
		    i=low;
		    j=high-1;
	    }
		for(;;)
		{
			while(a[++i]<pivot)
			{}
			while(a[--j]>pivot)
			{}
			if(i<j)
			    swap(a,i,j);
			else
			    break;	
		}
		if(k==1)
		{
		    swap(a,i,high);
			k++;	
		}
		else
		    swap(a,i,high-1);
		printf("Qsort(%d,%d):",low,high);
	    for(m=0;m<10;m++)
            printf("%d,",a[m]);
        printf("\n");
		Qsort(a,low,i-1,k,l);
		Qsort(a,i+1,high,k,l);
	}
	else
	{
	    insertsort(a,low,high);
        printf("insert(%d,%d):",low,high-low+1);
        for(m=0;m<10;m++)
            printf("%d,",a[m]);
        printf("\n");
    }
}

int main()
{
    int i,j=0;
	int a[10]={49,38,65,97,76,13,27,50,2,8};
    scanf("%d",&i);
	Qsort(a,0,9,j,i);
    return 0;
}