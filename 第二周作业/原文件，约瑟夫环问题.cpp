#include<stdio.h>
#include<stdlib.h>
int josep( int , int );
int delay();
int main()
{
    int flag=1;
    while(flag)
    {
        int number,point,winner;
        printf( "************************welcome*************************\n**  游戏规则：任意几个人围坐一圈，从第一个人开始报数  **\n**  “1,2,3，4....，数到规定的数字的人出局，然后下    **\n**  一个人从1开始继续，这样直到最后一个人为胜利者。   **\n********************************************************\n\n请输入玩家人数（整数）:" );
        scanf( "%d", & number );
        printf( "\n请输入报数最大值（整数）:" );
        scanf( "%d", & point );
        winner=josep(number,point);
        printf( "\n\n玩家%d是最终胜利者！\n\n",winner );
        flag=3;
        while (3==flag)//判断是否重新输入数字
        {
            printf( "\n\n是否重新输入数字（1为是，2为否）？\n请输入：" );
            scanf( "%d", & flag );
            if (1==flag)
                flag=1;
            else if (2==flag)
                flag=0;
            else 
            {
                flag=3;
                printf( "\n输入数字错误！\n" );
            }
        }

    }
    return 0;
}

int josep( int n , int m )
{
    int i,j,winner;
    int *num = ( int * )malloc( n * sizeof(int) );//创建玩家数组
    if ( num == NULL )
    printf( "内存分配错误，请重启程序" );
    for ( i=0 ; i<n ; i++)//初始化玩家数组，分别编号。
    {
        num[i]=i+1; 
    }
    printf( "\n玩家编号完成");
    i=0;
    while ( n > 1 )
    {
        i=( i + m - 1 ) % n;//核心算法，计算出局人。
        printf( "\n玩家%d，",num[i] );
        delay();
        for ( j=i+1;j<n;j++)//移动座位
            num[j-1]=num[j];
        n--;//人数减一
        if (i==n)
            i=0;
    }
    winner=num[0];
    free (num);
    return winner;  
}

/**延时函数**/
int delay()
{
    int i,j;
    for (i=0;i<5000;i++)
        for(j=0;j<5000;j++);
    return 0;
}