#include<stdio.h>
#include<stdlib.h>//堆排序要求第一位数组下标为1
/*
#define MaxSize 20
typedef int KeyType;    //定义关键字类型
typedef char InfoType[10];
typedef struct          //记录类型
{
    KeyType key;        //关键字项
    InfoType data;      //其他数据项,类型为InfoType
} RecType;              //排序的记录类型定义
*/
//调整堆
void sift(int arr[],int low,int high)
{
    int i=low,j=2*i;                        //arr[j]是arr[i]的左孩子
    int temp=arr[i];
    while (j<=high)
    {
        if (j<high&&arr[j]<arr[j+1])  //若右孩子较大,把j指向右孩子
            j++;                                //变为2i+1
        if (temp<arr[j])
        {
            arr[i]=arr[j];                          //将arr[j]调整到双亲结点位置上
            i=j;                                //修改i和j值,以便继续向下筛选
            j=2*i;
        }
        else break;                             //筛选结束
    }
    arr[i]=temp;                                  //被筛选结点的值放入最终位置
}

//堆排序
void heapsort(int arr[],int len)   //因为是树结构，1对应1，2对应2，是从1到N，此len代表元素个数
{
    int i;
    int temp;
    for (i=len/2; i>=1; i--) //循环建立初始堆
        sift(arr,i,len);
    for (i=len; i>=2; i--) //进行len-1次循环,完成推排序
    {
        temp=arr[1];       //arr[1]此时为最大元素，故放到arr[i]上，完成排序
        arr[1]=arr[i];
        arr[i]=temp;
        sift(arr,1,i-1);   //筛选arr[1]结点,得到i-1个结点的堆
    }
}
