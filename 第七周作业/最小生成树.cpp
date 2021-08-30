#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define num 10
#define INF 1000
typedef struct graph{
	int node[num];
	int arcs[num][num];
}graph;
void shellsort(int *a, int len)
{
    int i, j, k, tmp, gap;  // gap Ϊ����
    for (gap = len / 2; gap > 0; gap /= 2) 
	{  // ������ʼ��Ϊ���鳤�ȵ�һ�룬ÿ�α����󲽳�����,
    	for (i = 0; i < gap; ++i) 
		{ // ���� i Ϊÿ�η���ĵ�һ��Ԫ���±� 
	        for (j = i + gap; j < len; j += gap) 
			{ //�Բ���Ϊgap��Ԫ�ؽ���ֱ�����򣬵�gapΪ1ʱ������ֱ������
	            tmp = a[j];  // ����a[i]��ֵ
	            k = j - gap;  // j��ʼ��Ϊi��ǰһ��Ԫ�أ���i���gap���ȣ�
	            while (k >= 0 && a[k] > tmp) 
				{
	                a[k + gap] = a[k]; // ����a[i]ǰ�ұ�tmp��ֵ���Ԫ������ƶ�һλ
	                k -= gap;
	            }
	            a[k + gap] = tmp; 
	        }
	   
	    }
    
	}

}
void prim(graph*g)
{
	int lowcost[num];
	int prev[num];
	int i,j,min,k=0,l=0;
	int sum[num]={0};
	lowcost[0]=0;
	prev[0]=0;
	for(i=1;i<num;i++)
	{
		lowcost[i]=g->arcs[0][i];
		prev[i]=0;
	}
    for(i=1;i<num;i++)
    {
    	min=INF;
    	for(j=1;j<num;j++)
    	{
    		if(lowcost[j]<min&&lowcost[j]!=0)
    		{
    			min=lowcost[j];
    			k=j;
			}
		}
    	sum[l++]=min;
    	lowcost[k]=0;
    	for(j=1;j<num;j++)
    	{
    		if(g->arcs[k][j]<lowcost[j])
    		{
    			lowcost[j]=g->arcs[k][j];
    			prev[j]=k;
			}
   		
		}
 	
	}
    shellsort(sum,num-1);
    for(i=0;i<num-1;i++)
        printf("%d,",sum[i]);
    
	
}



int main()
{
    char s,t;
	int i,j,k;
	graph* g;
    g = (graph*)malloc(sizeof(graph));
    for (i =0; i <num; i++)
    {
        for (j =0; j <num; j++)
            g->arcs[i][j] = INF;
    }
    
    g->arcs[0][1] =3;
    g->arcs[1][0] =3;
    g->arcs[0][3] =4;
    g->arcs[3][0] =4;          
    g->arcs[0][4] =4;
    g->arcs[4][0] =4;
    g->arcs[1][4] =2;
    g->arcs[4][1] =2;
    g->arcs[1][2] =10;
    g->arcs[2][1] =10;
    g->arcs[1][5] =3;
    g->arcs[5][1] =3;
    g->arcs[5][2] =6;
    g->arcs[2][5] =6;
    g->arcs[2][6] =1;
    g->arcs[6][2] =1;          
    g->arcs[3][4] =5;
    g->arcs[4][3] =5;
    g->arcs[4][5] =11;
    g->arcs[5][4] =11;
    g->arcs[5][6] =2;
    g->arcs[6][5] =2;
    g->arcs[3][7] =6;
    g->arcs[7][3] =6;          
    g->arcs[7][4] =2;
    g->arcs[4][7] =2;
    g->arcs[4][8] =1;
    g->arcs[8][4] =1;
    g->arcs[5][8] =3;
    g->arcs[8][5] =3;
    g->arcs[5][9] =11;
    g->arcs[9][5] =11;
    g->arcs[6][9] =8;
    g->arcs[9][6] =8;         
    g->arcs[9][8] =7;
    g->arcs[8][9] =7;
    g->arcs[7][8] =4;
    g->arcs[8][7] =4;
    for (i =0; i <num; i++)
    {
	    g->node[i] = i+65;
        g->arcs[i][i] = 0;       //�Խ���ӦΪ0
	}   
	scanf("%c,%c,%d",&s,&t,&k);
	g->arcs[s-65][t-65]=k;
	g->arcs[t-65][s-65]=k;
    prim(g);
    return 0;
}