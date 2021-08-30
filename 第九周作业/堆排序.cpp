#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void sift(int arr[],int low,int high)
{
    int i=low,j=2*i;                        //arr[j]是arr [i]的左孩子
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
void heapsort(int arr[],int len,int d)
{
    int i;
    int temp;
    for (i=len/2; i>=1; i--) //循环建立初始堆
        sift(arr,i,len);
    for (i=len; i>=2; i--) //进行len-1次循环,完成推排序
    {
        if(d==0)
            break;
		temp=arr[1];       //arr[1]此时为最大元素，故放到arr[i]上，完成排序
        arr[1]=arr[i];
        arr[i]=temp;
        sift(arr,1,i-1);   //筛选arr[1]结点,得到i-1个结点的堆
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
