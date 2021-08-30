#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void merge(int arr[],int num, int start, int mid, int end) //start到mid,mid到end为有序才可使用merge函数将两者拼接
{
	int result[num];
	int k = 0;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end) 
	{
		if (arr[i] < arr[j])
		{
			result[k++] = arr[i++];
        }
		else
		{
			result[k++] = arr[j++];
        }
	}
	if (i == mid + 1) 
	{
		while(j <= end)
			result[k++] = arr[j++];
	}
	if (j == end + 1) 
	{
		while (i <= mid)
			result[k++] = arr[i++];
	}
	for (j = 0, i = start ; j < k; i++, j++)
	{
		arr[i] = result[j];
	}
}

int main()
{
    int a1[100],a2[100];
	char c;
	int i=0;
	int k=1;
	int num1=-1;
	do
	{
	    c=getchar();
		if((c==','&&k!=1)||(c=='\n'&&k!=1)||(c==EOF&&k!=1))
		{
			a1[++num1]=i;
			i=0;
			k=1;
		}
		else
		{
			i=c-'0'+i*10;
			k=0;
		}
	}
	while(c!='\n'&&c!=EOF);
	i=0;
    k=1;
	int num2=-1;
	do
	{
	    c=getchar();
		if((c==','&&k!=1)||(c=='\n'&&k!=1)||(c==EOF&&k!=1))
		{
			a2[++num2]=i;
			i=0;
			k=1;
		}
		else
		{
			i=c-'0'+i*10;
			k=0;
		}
	}
	while(c!='\n'&&c!=EOF);
    for(i=0;i<=num2;i++)
    {
    	a1[num1+1+i]=a2[i];
	}
    merge(a1,num1+num2+2,0,num1,num1+num2+1);
    for(i=0;i<=num1+num2+1;i++)
        printf("%d,",a1[i]);
	return 0;
}