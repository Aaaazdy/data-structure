#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 10
typedef struct arcnode{   //后续结点
	int arcdata;
	struct arcnode*arcnext;
}arcnode;
typedef struct node{      //头结点
	int data;
	arcnode *next;        //不是指向自己的指针，而是指向arcnode
}node;
node g[NUM];
//给数组赋具体值
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
		scanf("%d,%d",&i,&j);
		p=(arcnode*)malloc(sizeof(arcnode));
		p->arcdata=j;
		p->arcnext=g[i].next;
		g[i].next=p;


	} 

}

//队列操作
#define MAXSIZE 100
typedef struct{
	int queue[MAXSIZE];
	int front;
	int rear;
}squeue;


void inqueue(squeue*q,int x)
{
	q->rear++;
	q->queue[q->rear]=x;
}

void dequeue(squeue*q,int&i)
{
	q->front++;
    i=q->queue[q->front];
}


int visited[NUM+1]={0};
void bfs(node*g,int i)//breadth first search
{
	squeue*q;
	q=(squeue*)malloc(sizeof(squeue));
	q->front=-1;
	q->rear=-1;
	printf("%d",g[i].data);
	visited[i]=1;
	inqueue(q,i);
	while(q->front!=q->rear)
	{
		dequeue(q,i);
		arcnode*p;
		p=(arcnode*)malloc(sizeof(arcnode));
		p=g[i].next;//每次出队列都是取出队列的next
		while(p!=NULL)
		{
			if(visited[p->arcdata]==0)
			{
				printf("%d",g[p->arcdata].data);//原printf("%d",g[i].data);不确定正确性
				visited[p->arcdata]=1;
				inqueue(q,p->arcdata);      //每次入队列都是入已经出过队列并且打印过的元素
			}
			p=p->arcnext;                   //将所有邻结点全部输出
					
		}


	}

	
}