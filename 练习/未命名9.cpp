#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 1000                 //不要乱写高大上的定义
#define num  7
typedef struct graph{
	int node[num];
	int arcs[num][num];
}graph;


void floyd(graph*g)
{
	int P[num][num];//存储中间结点
	int D[num][num];//存储最短距离
	int i,j,k,v;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			D[i][j]=g->arcs[i][j];
			P[i][j]=j;
			
		}
	}
	for(k=0;k<num;k++)
	{
		for(j=0;j<num;j++)
		{
			for(i=0;i<num;i++)
			{
				if(D[i][j]>(D[i][k]+D[k][j]))
				{
					D[i][j]=D[i][k]+D[k][j];
					P[i][j]=P[i][k];
				}
			}
		}
	}
	i=0;
	j=5;
	printf("%d,",i+1);
	v=P[i][j];
	while(v!=j)
	{
		printf("%d,",v+1);
		v=P[v][j];
	}
	printf("%d",j+1);

}
int main()
{
	graph*g;
	g=(graph*)malloc(sizeof(graph));
	int i,j,s,t;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		    g->arcs[i][j]=INF;
	}
	 g->arcs[0][1] = 2;
    g->arcs[0][3] = 1;
    g->arcs[1][3] = 3;
    g->arcs[1][4] = 10;          //数据要对应
    g->arcs[2][0] = 4;
    g->arcs[2][5] = 5;
    g->arcs[3][2] = 2;
    g->arcs[3][5] = 8;
    g->arcs[3][6] = 4;
    g->arcs[3][4] = 2;
    g->arcs[4][6] = 6;
    g->arcs[6][5] = 1;
    scanf("%d,%d",&s,&t);
    g->arcs[s-1][t-1]=INF;
	for(i=0;i<num;i++)
	{
		g->node[i]=i;
		g->arcs[i][i]=0;
	}
	floyd(g);
	return 0;
	
}