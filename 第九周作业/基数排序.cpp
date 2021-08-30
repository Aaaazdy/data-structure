#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void count_sort(int a[], int n, int exp)
{
    int output[n];             // 存储"被排序数据"的临时数组
    int i, buckets[10] = {0};

    // 将数据出现的次数存储在buckets[]中
    for (i = 0; i < n; i++)
        buckets[ (a[i]/exp)%10 ]++;

    // 更改buckets[i]。目的是让更改后的buckets[i]的值，是该数据在output[]中的位置。
    for (i = 1; i < 10; i++)
        buckets[i] += buckets[i - 1];

    // 将数据存储到临时数组output[]中
    for (i = n - 1; i >= 0; i--)
    {
        output[buckets[ (a[i]/exp)%10 ] - 1] = a[i];
        buckets[ (a[i]/exp)%10 ]--;
    }

    // 将排序好的数据赋值给a[]
    for (i = 0; i < n; i++)
        a[i] = output[i];
}


int main()
{
    int a[100];
	char c;
	int i=0;
	int k=1;
	int num=-1;
	do
	{
	    c=getchar();
		if((c==','&&k!=1)||(c=='\n'&&k!=1)||(c==EOF&&k!=1))
		{
			a[++num]=i;
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
    int d;
    scanf("%d",&d);
	int exp;
    for(exp=1,i=1;i<=d;i++,exp*=10)
    {
		count_sort(a,num+1,exp);	
	}
    for(i=0;i<=num;i++)
        printf("%d,",a[i]);
	return 0;
}