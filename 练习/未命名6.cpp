#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define num 11
typedef struct graph{
	char node[num];
	int arcs[num][num];
}graph;

typedef struct squence{
	int queue[100];
	int front;
	int rear;
	
}squeue;
void creategraph(graph*g)
{
	int i,j;
	for(i=0;i<num-2;i++)
	{
		g->node[i]=i+65;
	}
	g->node[9]='S';
	g->node[10]='T';
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			g->arcs[i][j]=0;
			
		}
	}
	g->arcs[0][1]=1;
    g->arcs[0][4]=1;
    g->arcs[1][2]=1;
    g->arcs[2][10]=1;
    g->arcs[3][0]=1;
    g->arcs[3][4]=1;
    g->arcs[4][2]=1;
    g->arcs[4][5]=1;
    g->arcs[4][8]=1;
    g->arcs[5][2]=1;
    g->arcs[5][10]=1;
    g->arcs[6][3]=1;
    g->arcs[6][4]=1;
    g->arcs[6][7]=1;
    g->arcs[7][4]=1;
    g->arcs[7][8]=1;
    g->arcs[8][5]=1;
    g->arcs[8][10]=1;
    g->arcs[9][0]=1;
    g->arcs[9][3]=1;
    g->arcs[9][6]=1;
	
}
void tuopu(graph*g)
{
	squeue*q;
	q=(squeue*)malloc(sizeof(squeue));
	q->front=q->rear=-1;
	int i,j,k,t,m;
	int n[num]={0};
	printf("S,");
	n[9]=1;
	for(i=0;i<num;i++)
	{
		g->arcs[9][i]=0;
	}
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num;j++)
		{
			if(n[j]==0)
			{
				t=1;
				for(k=0;k<num;k++)
				{
					if(g->arcs[k][j]==1)
				    {
				    	t=0;
				    	break;
					}
				}
		        if(t==1)
		        {
		        	n[j]=1;
		        	q->rear++;
		        	q->queue[q->rear]=j;
				}
		
			}
		}
		q->front++;
		m=q->queue[q->front];
		if(q->front!=q->rear+1)
		{
			printf("%c,",g->node[m]);
			for(k=0;k<num;k++)
		        g->arcs[m][k]=0;
		}
		else
		    break;
	}
	
}
int main()
{
	char s,t;
	graph*g;
	g=(graph*)malloc(sizeof(graph));
	creategraph(g);
	scanf("%c,%c",&s,&t);
	if(s=='S')
	    s='J';
	if(s=='T')
	    s='K';	
	if(t=='S')
	    t='J';
	if(t=='T')
	    t='K';	
	g->arcs[s-65][t-65]=0;
	tuopu(g);
	return 0;

}