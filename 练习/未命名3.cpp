#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int countnum(char arr[],int k,int count)
{
	int result=0;
	int i=0;
	if(count==0)
	    result=-1;
	while(count>0)
	{
		int ten=pow(10,i);
		result+=(arr[k-1-i]-48)*ten;
		count--;
		i++;
		

	}
    return result;


}
void covertonum(char arr[],int length,int num[])
{
	int n=0;
	int k=0;
	int counttemp=0;
	while(k<=length)
	{
		if(arr[k]==','||arr[k]=='\0')
		{
			num[n]=countnum(arr,k,counttemp);
			n++;
			counttemp=0;
		}
	    else 
	        counttemp++;
	
	    k++;
	
	}

}