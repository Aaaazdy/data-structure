#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2-1
typedef struct huffnode{
	int weight;
	int lchild;
	int rchild;
	int parent;
}huffnodetype;


void huffmantree(huffnodetype huffnode[])
{
	int i,j,m1,m2,x1,x2,n;
	n=8;
	for(i=0;i<2*n-1;i++)
	{
		huffnode[i].weight=0;
		huffnode[i].parent=-1;
		huffnode[i].lchild=-1;
		huffnode[i].rchild=-1;
	}
	huffnode[0].weight=7;
    huffnode[1].weight=19;
    huffnode[2].weight=2;
    huffnode[3].weight=6;
    huffnode[4].weight=32;
    huffnode[5].weight=3;
    huffnode[6].weight=21;
    huffnode[7].weight=10;
    for(i=0;i<n-1;i++)
    {
    	m1=m2=MAXVALUE;
    	x1=x2=0;
    	for(j=0;j<n+i;j++)
    	{
    		if(huffnode[j].weight<m1&&huffnode[j].parent==-1)
    		{
    			m2=m1;
    			x2=x1;
    			m1=huffnode[j].weight;
    			x1=j;
			}
		    else if(huffnode[j].weight<m2&&huffnode[j].parent==-1)
		    {
		    	m2=huffnode[j].weight;
		    	x2=j;
			}
	
		}
        huffnode[x1].parent=n+i;
        huffnode[x2].parent=n+i;
        huffnode[n+i].weight=huffnode[x1].weight+huffnode[x2].weight;
        huffnode[n+i].lchild=x1;
        huffnode[n+i].rchild=x2;

	}
	
	
}