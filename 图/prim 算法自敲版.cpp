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
		lowcost[i]=g->arcs[1][i];//lowcost存放顶点1可达点的路径长度
		prev[i]=1;//初始化以1位起始点 
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
    	lowcost[k]=0;//该处最短路径置为0 
    	for(j=2;j<=num;j++)
    	{
    		if(g->arcs[k][j]<lowcost[j])
    		{
    			lowcost[j]=g->arcs[k][j];
    			prev[j]=k;
			}
   		
		}
 	
	}

    printf("最小权值之和为%d\n",sum);
	
}