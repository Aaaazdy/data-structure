#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void shellsort(int *a, int len)
{
    int i, j, k, tmp, gap;  // gap 为步长
    for (gap = len / 2; gap > 0; gap /= 2) 
	{  // 步长初始化为数组长度的一半，每次遍历后步长减半,
    	for (i = 0; i < gap; ++i) 
		{ // 变量 i 为每次分组的第一个元素下标 
	        for (j = i + gap; j < len; j += gap) 
			{ //对步长为gap的元素进行直插排序，当gap为1时，就是直插排序
	            tmp = a[j];  // 备份a[i]的值
	            k = j - gap;  // j初始化为i的前一个元素（与i相差gap长度）
	            while (k >= 0 && a[k] < tmp) 
				{
	                a[k + gap] = a[k]; // 将在a[i]前且比tmp的值大的元素向后移动一位
	                k -= gap;
	            }
	            a[k + gap] = tmp; 
	        }
	    
		}
    
    for(i=0;i<len;i++)
        printf("%d,",a[i]);
    printf("\n");
    
	}

}



int main()
{
	int N;
	scanf("%d",&N);
	int i;
	int*a;
	a=(int*)malloc(sizeof(int)*N);
	for(i=0;i<N;i++)
	{
		scanf("%d,",&a[i]);
	}
	shellsort(a,N);
	return 0;
}