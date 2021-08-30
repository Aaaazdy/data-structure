#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 10
typedef struct arcnode{   //�������
	int arcdata;
	struct arcnode*arcnext;
}arcnode;
typedef struct node{      //ͷ���
	int data;
	arcnode *next;        //����ָ���Լ���ָ�룬����ָ��arcnode
}node;
node g[NUM];
//�����鸳����ֵ
void createg(node*g,int e)//�����ڽӱ�eΪ������Ŀ
{
	int i;
	for(i=1;i<=NUM;i++)   //ͷ�ڵ�����
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

//���в���
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
		p=g[i].next;//ÿ�γ����ж���ȡ�����е�next
		while(p!=NULL)
		{
			if(visited[p->arcdata]==0)
			{
				printf("%d",g[p->arcdata].data);//ԭprintf("%d",g[i].data);��ȷ����ȷ��
				visited[p->arcdata]=1;
				inqueue(q,p->arcdata);      //ÿ������ж������Ѿ��������в��Ҵ�ӡ����Ԫ��
			}
			p=p->arcnext;                   //�������ڽ��ȫ�����
					
		}


	}

	
}