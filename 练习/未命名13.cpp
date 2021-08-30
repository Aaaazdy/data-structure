#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INF 1000
#define num 7
typedef struct graph{
    char node[num];       // 顶点集合         
    int arcs[num][num]; // 邻接矩阵
}graph;
void dijkstra(graph*g,int vs,int count[])
{
	int i,j,k,min,tmp,m,l;
	int prev[num];
	int flag[num];
	int dist[num];
	for(i=0;i<num;i++)
	{
		flag[i]=0;
		prev[i]=0;
		dist[i]=g->arcs[vs][i];
		
	}
    flag[vs]=1;
    dist[vs]=0;
    for(i=0;i<num;i++)
    {
    	min=INF;
    	for(j=0;j<num;j++)
    	{
    		if(flag[j]==0&&(dist[j]<min))
    		{
    			min=dist[j];
    			k=j;
			}
		}
    	flag[k]=1;
    	for(j=0;j<num;j++)
    	{
    		tmp=(g->arcs[k][j]==INF)?INF:(min+g->arcs[k][j]);
    		if(flag[j]==0&&(tmp<dist[j]))
    		{
    			dist[j]=tmp;
    			prev[j]=k;
			}
			
		}
		
	}
    k=prev[5];
    l=0;
    i=0;
    j=5;
	while(k!=0)
	{
		count[i]=k;
		i++;
		k=prev[k];
	}
	
	printf("%d,",l+1);
	for(m=i-1;m>=0;m--)
    {
	   printf("%d,",count[m]+1);	
	}
    printf("%d",j+1);

}


int main()
{
    int i,j,s,t;
    int count[20]={-1};
	graph* g;
    g = (graph*)malloc(sizeof(graph));
    for (i =0; i <num; i++)
    {
        for (j =0; j <num; j++)
            g->arcs[i][j] = INF;
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
    scanf("%d,%d", &s, &t);
    g->arcs[s-1][t-1] = INF;
    for (i =0; i <num; i++)
    {
	    g->node[i] = i;
        g->arcs[i][i] = 0;       //对角线应为0
	}   
	
    dijkstra(g,0,count);
    return 0;
}