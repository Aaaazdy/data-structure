#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int CountNum(char *arr,int k,int count)//arrΪ�ַ����飬kΪ�����±꣬
{                                      //countΪ�����ָ���
    int result=0;                      //result��¼�����ֵ
    int i=0;                           //iΪ������ʹ��ȡ�����е���������
    if(count==0)                       //countΪ����λ��
        result=-1;
	while(count>0)
    {
        float ten=pow(10,i);          //����λ������10�Ĵη�
        result+=(arr[k-1-i]-48)*ten;  //��48Ϊʹ��ASCII���ַ���ת��Ϊ����
        i++;
        count--;
    }
    return result;
}

int ConverToNum(char *arr, int length, int *num)//��������ַ����е�������ȡ
                                                //����������num������length��                                                                           
{                                               //arr�е��ַ����� 
    int m;
	int n=-1;
    int k=0;      
    int count_temp=0;                           //countΪ���ż����ָ���
    while(k<=length)
    {
        //����ַ��Ƕ��Ż��߽�β���ʹ�����������֮����ַ���ת�������� 
        if(arr[k]==','||arr[k]=='\0')
        {
            m=CountNum(arr,k,count_temp);
            if(m!=-1)
            {
			    num[++n]=m;
            }
			count_temp=0;
        }
        else
        {
            count_temp++;
        }

        k++;
    }
    return n;//������������±�
}