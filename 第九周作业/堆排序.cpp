#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void sift(int arr[],int low,int high)
{
    int i=low,j=2*i;                        //arr[j]��arr [i]������
    int temp=arr[i];
    while (j<=high)
    {
        if (j<high&&arr[j]<arr[j+1])  //���Һ��ӽϴ�,��jָ���Һ���
            j++;                                //��Ϊ2i+1
        if (temp<arr[j])
        {
            arr[i]=arr[j];                          //��arr[j]������˫�׽��λ����
            i=j;                                //�޸�i��jֵ,�Ա��������ɸѡ
            j=2*i;
        }
        else break;                             //ɸѡ����
    }
    arr[i]=temp;                                  //��ɸѡ����ֵ��������λ��
}

//������
void heapsort(int arr[],int len,int d)
{
    int i;
    int temp;
    for (i=len/2; i>=1; i--) //ѭ��������ʼ��
        sift(arr,i,len);
    for (i=len; i>=2; i--) //����len-1��ѭ��,���������
    {
        if(d==0)
            break;
		temp=arr[1];       //arr[1]��ʱΪ���Ԫ�أ��ʷŵ�arr[i]�ϣ��������
        arr[1]=arr[i];
        arr[i]=temp;
        sift(arr,1,i-1);   //ɸѡarr[1]���,�õ�i-1�����Ķ�
        d--;
	}
}

int main()
{
    int a[100];
	char c;
	int m,d,i=0;
	int k=1;
	int num=0;
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
    scanf("%d",&d);
    heapsort(a,num,d-1);   
	for(m=1;m<=num;m++)
        printf("%d,",a[m]);
	return 0;
}
