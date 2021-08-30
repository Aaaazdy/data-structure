#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM 10 


typedef struct mgraph{
	int vexs[NUM];
	int arcs[NUM][NUM];
}mgraph;


void create_mgraph(mgraph*g,int e)
{
	int i,j;
	for(i=0;i<NUM;i++)
	    g->vexs[i]=i;
	for(i=0;i<NUM;i++)
	{
		for(int j=0;j<NUM;j++)
		    g->arcs[i][j]=0;
	}
	for(int k=0;k<e;k++)
	{
		scanf("%d,%d",&i,&j);
		g->arcs[i][j]=1;
		g->arcs[j][i]=1;
		}    
	    
	    
	    
}