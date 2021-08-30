#include<stdio.h>

void selectsort(int arr[],int len)
{
	int i,j,min,x;
	for(i=0;i<len-1;i++)
	{
		min=i;
		for(j=i+1;j<len;j++)
	    {
	    	if(arr[j]<arr[min])
	    	    min=j;
		}
	    if(min!=i)
	    {
	    	x=arr[min];
	    	arr[min]=arr[i];
	    	arr[i]=x;
		}
	
	}

}