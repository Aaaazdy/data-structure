#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int CountNum(char *arr,int k,int count)//arr为字符数组，k为逗号下标，
{                                      //count为此数字个数
    int result=0;                      //result记录结果数值
    int i=0;                           //i为计数器使所取数组中的数字左移
    if(count==0)                       //count为左移位数
        result=-1;
	while(count>0)
    {
        float ten=pow(10,i);          //依据位数乘以10的次方
        result+=(arr[k-1-i]-48)*ten;  //减48为使用ASCII将字符数转化为整数
        i++;
        count--;
    }
    return result;
}

int ConverToNum(char *arr, int length, int *num)//把输入的字符串中的数字提取
                                                //出来，放在num数组中length是                                                                           
{                                               //arr中的字符个数 
    int m;
	int n=-1;
    int k=0;      
    int count_temp=0;                           //count为逗号间数字个数
    while(k<=length)
    {
        //如果字符是逗号或者结尾，就处理两个逗号之间的字符，转换成数字 
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
    return n;//返回最大数组下标
}