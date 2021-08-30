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
void create_agraph(node*g,int e)
{
	int i,j;
	for(int i=1;i<=NUM;i++)
	{
		scanf("%d",&g[i].data);
		g[i].next=NULL;
	}
	for(int k=1;k<=e;k++)
	{
		arcnode *p;
		scanf("%d %d",&i,&j);
		p=(arcnode*)malloc(sizeof(arcnode));
		p->arcdata=j;
		p->arcnext=g[i].next;
		g[i].next=p;
		
	}
	
	
}