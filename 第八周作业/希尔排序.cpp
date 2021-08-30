#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void shellsort(int *a, int len)
{
    int i, j, k, tmp, gap;  // gap Ϊ����
    for (gap = len / 2; gap > 0; gap /= 2) 
	{  // ������ʼ��Ϊ���鳤�ȵ�һ�룬ÿ�α����󲽳�����,
    	for (i = 0; i < gap; ++i) 
		{ // ���� i Ϊÿ�η���ĵ�һ��Ԫ���±� 
	        for (j = i + gap; j < len; j += gap) 
			{ //�Բ���Ϊgap��Ԫ�ؽ���ֱ�����򣬵�gapΪ1ʱ������ֱ������
	            tmp = a[j];  // ����a[i]��ֵ
	            k = j - gap;  // j��ʼ��Ϊi��ǰһ��Ԫ�أ���i���gap���ȣ�
	            while (k >= 0 && a[k] < tmp) 
				{
	                a[k + gap] = a[k]; // ����a[i]ǰ�ұ�tmp��ֵ���Ԫ������ƶ�һλ
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