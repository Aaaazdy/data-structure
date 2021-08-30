#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define num 11
typedef struct graph{
	char node[num];
	int arcs[num];
}graph;
typedef struct squeue{
	int front;
	int rear;
	int queue[100];
}squeue;

void dijkstra2(graph*g,squeue*q,int vs)//求最短路径条数
{
	int i,j;
	int dist[num];
	int prev[num];
	int minimum[num];
	for(i=0;i<num;i++)
	{
		prev[i]=0;
		dist[i]=g->arcs[vs][i];
		
	}
    dist[vs]=0;
	q->queue[++q->rear]=vs;
	while(q->front!=q->rear)
	{
		i=q->queue[++q->front];
		for(j=0;j<num;j++)
		{
			if(g->arcs[i][j]>0)
			{
				if((dist[i]+g->arcs[i][j])<dist[j])
				{
					dist[j]=dist[i]+g->arcs[i][j];
					prev[j]=i;
					q->queue[++q->rear]=j;
					minimum[j]=1;
				}
				if((dist[i]+g->arcs[i][j])=dist[j])
				{
					minimum[j]+=1;
				}
				
			}
		
		}

	}
	
}





void dijkstra2(graph*g,squeue*q,int vs)//求最少边
{
	int i,j;
	int dist[num];
	int prev[num];
	int edge[num];
	for(i=0;i<num;i++)
	{
		prev[i]=0;
		dist[i]=g->arcs[vs][i];
		
	}
    dist[vs]=0;
	q->queue[++q->rear]=vs;
	while(q->front!=q->rear)
	{
		i=q->queue[++q->front];
		for(j=0;j<num;j++)
		{
			if(g->arcs[i][j]>0)
			{
				if((dist[i]+g->arcs[i][j])<dist[j])
				{
					dist[j]=dist[i]+g->arcs[i][j];
					prev[j]=i;
					q->queue[++q->rear]=j;
					edge[j]=edge[i]+1;
				}
				if((dist[i]+g->arcs[i][j])=dist[j])
				{
					if((edge[i]+1)<edge[j])
					{
						edge[j]=edge[i]+1;
						prev[j]=i;
						
					}
				
				}
				
			}
		
		}

	}
	
}
