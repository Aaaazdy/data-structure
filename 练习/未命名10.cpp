#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define num 7
#define INF 1000
typedef struct graph{
	int node[num];
	int arcs[num][num];
}graph;
void floyd(graph*g)
{
	int i,j,k,v;
	int P[num][num];
	int D[num][num];
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
    	for(i=0;i<num;i++)
    	{
    		for(j=0;j<num;j++)
    		{
    			if(D[i][j]>D[i][k]+D[k][j])
    			{
    				D[i][j]=D[i][k]+D[k][j];
    				P[i][j]=P[i][k];
				}
			}
		}
	}
    i=0;
    j=5;
    v=P[i][j];
	printf("%d,",i+1);
    while(v!=j)
    {
    	printf("%d,",v+1);
    	v=P[v][j];
	}
    printf("%d",j+1);

}

int main()
{
	int i,j,s,t;
	graph*g;
	g=(graph*)malloc(sizeof(graph));
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			g->arcs[i][j]=INF;
		}
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