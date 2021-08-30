#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define num 11
typedef struct graph{
	char node[num];
	int arcs[num][num];
}graph;
typedef struct squeue{
	int queue[100];
	int front;
	int rear;
}squeue;
void creategraph(graph *g)
{
	int i,j;
	for(i=0;i<num-2;i++)
	    g->node[i]=i+65;
	g->node[9]='S';
	g->node[10]='T';
    for(i=0;i<num;i++)
    {
		for(j=0;j<num;j++)
            g->arcs[i][j]=0;
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


void tuopu(graph *g)
{
    squeue*q;
    q=(squeue*)malloc(sizeof(squeue));
    q->rear=q->front=-1;
	
	
	//int row[num]={0};//按照列来设置标志，为1表示已经输出（不再考虑），为0表示未输出。
	//int v=1;//标志符，1表示已经输出（不再考虑），为0表示未输出，赋给row数组
	int i,j,k,t,m;
	int n[num]={0};
	printf("S,");
	n[9]=1;
	for(i=0;i<num;i++)
		g->arcs[9][i]=0;//将已经输出的活动所到达的下个活动的入度置为0
	//v++;
	for(k=0;k<num-1;k++)
	{
		
		for(j=0;j<num;j++)
		{
			if(n[j]==0)//活动j还未输出
			{
				t=1;//标识符
				for(i=0;i<num;i++)
					if(g->arcs[i][j]==1)//当前活动有入度（活动i必须在活动j之前）
					{
						t=0;
						break;
					}
				if(t==1)//活动j没有入度
				{
					m=j;
					n[j]=1;
					q->rear++;
		            q->queue[q->rear]=m;
				}
			}
		}
		q->front++;
		m=q->queue[q->front];
		if(q->front!=q->rear+1)
		{
			//row[m]=1;//v;
			printf("%c,",g->node[m]);
			for(i=0;i<num;i++)
				g->arcs[m][i]=0;//将已经输出的活动所到达的下个活动的入度置为0
			//v++;
		}
		else 
			break;
	
	
	}
	//if(v-1<num)//当row中不是所有的元素都被赋予新值v时，说明有环存在
	//	printf("\n该有向图有环存在！");
	
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