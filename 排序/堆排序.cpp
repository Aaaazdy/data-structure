#include<stdio.h>
#include<stdlib.h>//������Ҫ���һλ�����±�Ϊ1
/*
#define MaxSize 20
typedef int KeyType;    //����ؼ�������
typedef char InfoType[10];
typedef struct          //��¼����
{
    KeyType key;        //�ؼ�����
    InfoType data;      //����������,����ΪInfoType
} RecType;              //����ļ�¼���Ͷ���
*/
//������
void sift(int arr[],int low,int high)
{
    int i=low,j=2*i;                        //arr[j]��arr[i]������
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
void heapsort(int arr[],int len)   //��Ϊ�����ṹ��1��Ӧ1��2��Ӧ2���Ǵ�1��N����len����Ԫ�ظ���
{
    int i;
    int temp;
    for (i=len/2; i>=1; i--) //ѭ��������ʼ��
        sift(arr,i,len);
    for (i=len; i>=2; i--) //����len-1��ѭ��,���������
    {
        temp=arr[1];       //arr[1]��ʱΪ���Ԫ�أ��ʷŵ�arr[i]�ϣ��������
        arr[1]=arr[i];
        arr[i]=temp;
        sift(arr,1,i-1);   //ɸѡarr[1]���,�õ�i-1�����Ķ�
    }
}
