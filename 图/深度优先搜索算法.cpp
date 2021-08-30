#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 10
typedef struct arcnode{    //���
	int arcdata;
	struct arcnode*arcnext;
}arcnode;
typedef struct node{      //ͷ���
	int data;
	arcnode *next;    //����ָ���Լ���ָ�룬����ָ��arcnode
}node;
 
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
		p=(arcnode*)malloc(sizeof(arcnode));
		scanf("%d,%d",&i,&j);
		p->arcdata=j;
		p->arcnext=g[i].next;
		g[i].next=p;


	} 

}

int visited[NUM+1]={0};  //visited���Ƿ񱻷��ʣ�0Ϊδ������
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