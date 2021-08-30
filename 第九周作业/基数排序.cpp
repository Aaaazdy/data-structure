#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void count_sort(int a[], int n, int exp)
{
    int output[n];             // �洢"����������"����ʱ����
    int i, buckets[10] = {0};

    // �����ݳ��ֵĴ����洢��buckets[]��
    for (i = 0; i < n; i++)
        buckets[ (a[i]/exp)%10 ]++;

    // ����buckets[i]��Ŀ�����ø��ĺ��buckets[i]��ֵ���Ǹ�������output[]�е�λ�á�
    for (i = 1; i < 10; i++)
        buckets[i] += buckets[i - 1];

    // �����ݴ洢����ʱ����output[]��
    for (i = n - 1; i >= 0; i--)
    {
        output[buckets[ (a[i]/exp)%10 ] - 1] = a[i];
        buckets[ (a[i]/exp)%10 ]--;
    }

    // ������õ����ݸ�ֵ��a[]
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