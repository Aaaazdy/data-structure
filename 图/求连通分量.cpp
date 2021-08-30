#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 10
typedef struct arcnode{
	int arcdata;
	struct arcnode*arcnext;
}arcnode;
typedef struct node{
	int data;
	arcnode *next;    //不是指向自己的指针，而是指向arcnode
}node;
node agraph[NUM];


int visited[NUM+1]={0};
void dfs(node*g,int i)
{
	printf("%d",g[i]);
	visited[i]=1;
	arcnode*p;
	p=g[i].next;
	while(p!=NULL)
	{
		if(visited[p->arcdata]==0)
		    dfs(g,p->arcdata);
		p=p->arcnext;

	}

}

void con(node*g,int i)
{
	int count=0;
	for(i=1;i<NUM;i++)
	{
		if(!visited[i])
		{
			count++;
			dfs(g,i);
		}
	}
	printf("\n总共有%d个连通分量",count);
	
	
	
}




