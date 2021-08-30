#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF         1000//(~(0x1<<31)) 

int main()  
{  
    int map[10][10],n,m,t1,t2,t3;  
    scanf("%d%d",&n,&m);//n��ʾ���������m��ʾ�ߵ�����  
    //��ʼ��  
    for(int i=0; i<n; i++)  
        for(int j=0; j<n; j++)  
            if(i==j)  
                map[i][j]=0;  
            else  
                map[i][j]=INF;  
    //�����  
    for(int i=0; i<m; i++)  
    {  
        scanf("%d%d%d",&t1,&t2,&t3);  
        map[t1][t2]=t3;  
    }  
    //��������(Floyd)�������  
    for(int k=0; k<n; k++)  
        for(int i=0; i<n; i++)  
            for(int j=0; j<n; j++)  
                if(map[i][k]+map[k][j]<map[i][j])  
                    map[i][j]=map[i][k]+map[k][j];  
    for(int i=0; i<n; i++)  
    {  
        for(int j=0; j<n; j++)  
            printf("%10d",map[i][j]);  
        printf("\n");  
    }  
    return 0;  
}  
