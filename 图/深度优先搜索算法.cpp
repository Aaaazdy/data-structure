#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 10
typedef struct arcnode{    //结点
	int arcdata;
	struct arcnode*arcnext;
}arcnode;
typedef struct node{      //头结点
	int data;
	arcnode *next;    //不是指向自己的指针，而是指向arcnode
}node;
 
void createg(node*g,int e)//创建邻接表，e为弧的数目
{
	int i;
	for(i=1;i<=NUM;i++)   //头节点数组
	{
		scanf("%d",&g[i].data);
		g[i].next=NULL;	
	}
	int k;
	for(k=1;k<=e;k++)
	{
		int i,j;
		arcnode *p;
		p=(arcnode*)malloc(sizeof(arcnode));
		scanf("%d,%d",&i,&j);
		p->arcdata=j;
		p->arcnext=g[i].next;
		g[i].next=p;


	} 

}

int visited[NUM+1]={0};  //visited存是否被访问，0为未被访问
void dfs(node*g,int i)
{
	printf("%d",g[i].data);
	visited[i]=1;
	arcnode*p;
	p=(arcnode*)malloc(sizeof(arcnode));
	p=g[i].next;
	while(p!=NULL)
	{
		if(visited[p->arcdata]==0)
		    dfs(g,p->arcdata);
		p=p->arcnext;
			
	}
	
	
}
int main()
{
	node g[NUM];
    createg(g,5);
	dfs(g,1);
    return 0;
	
}