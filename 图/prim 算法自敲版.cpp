#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define num 7
#define INF 1000
typedef struct graph{
	int node[num];
	int arcs[num][num];
}graph;
void prim(graph*g)
{
	int lowcost[num];
	int prev[num];
	int i,j,min,k,sum=0;
	lowcost[1]=0;
	prev[1]=0;
	for(i=2;i<=num;i++)
	{
		lowcost[i]=g->arcs[1][i];//lowcost��Ŷ���1�ɴ���·������
		prev[i]=1;//��ʼ����1λ��ʼ�� 
	}
    for(i=2;i<=num;i++)
    {
    	min=INF;
    	for(j=2;j<=num;j++)
    	{
    		if(lowcost[j]<min&&lowcost[j]!=0)
    		{
    			min=lowcost[j];
    			k=j;
			}
		}
    	sum+=min;
    	lowcost[k]=0;//�ô����·����Ϊ0 
    	for(j=2;j<=num;j++)
    	{
    		if(g->arcs[k][j]<lowcost[j])
    		{
    			lowcost[j]=g->arcs[k][j];
    			prev[j]=k;
			}
   		
		}
 	
	}

    printf("��СȨֵ֮��Ϊ%d\n",sum);
	
}