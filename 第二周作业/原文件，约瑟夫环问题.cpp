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
        printf( "************************welcome*************************\n**  ��Ϸ�������⼸����Χ��һȦ���ӵ�һ���˿�ʼ����  **\n**  ��1,2,3��4....�������涨�����ֵ��˳��֣�Ȼ����    **\n**  һ���˴�1��ʼ����������ֱ�����һ����Ϊʤ���ߡ�   **\n********************************************************\n\n���������������������:" );
        scanf( "%d", & number );
        printf( "\n�����뱨�����ֵ��������:" );
        scanf( "%d", & point );
        winner=josep(number,point);
        printf( "\n\n���%d������ʤ���ߣ�\n\n",winner );
        flag=3;
        while (3==flag)//�ж��Ƿ�������������
        {
            printf( "\n\n�Ƿ������������֣�1Ϊ�ǣ�2Ϊ�񣩣�\n�����룺" );
            scanf( "%d", & flag );
            if (1==flag)
                flag=1;
            else if (2==flag)
                flag=0;
            else 
            {
                flag=3;
                printf( "\n�������ִ���\n" );
            }
        }

    }
    return 0;
}

int josep( int n , int m )
{
    int i,j,winner;
    int *num = ( int * )malloc( n * sizeof(int) );//�����������
    if ( num == NULL )
    printf( "�ڴ�����������������" );
    for ( i=0 ; i<n ; i++)//��ʼ��������飬�ֱ��š�
    {
        num[i]=i+1; 
    }
    printf( "\n��ұ�����");
    i=0;
    while ( n > 1 )
    {
        i=( i + m - 1 ) % n;//�����㷨����������ˡ�
        printf( "\n���%d��",num[i] );
        delay();
        for ( j=i+1;j<n;j++)//�ƶ���λ
            num[j-1]=num[j];
        n--;//������һ
        if (i==n)
            i=0;
    }
    winner=num[0];
    free (num);
    return winner;  
}

/**��ʱ����**/
int delay()
{
    int i,j;
    for (i=0;i<5000;i++)
        for(j=0;j<5000;j++);
    return 0;
}