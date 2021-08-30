#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2-1

typedef struct{
	int weight;
	int parent;
	int lchild;
	int rchild;
}huffnodetype;
 void huffmantree(huffnodetype huffnode[])
{
 	int i,j,m1,m2,x1,x2,n;
 	scanf("%d",&n);
 	for(i=0;i<2*n-1;i++)
 	{
 		huffnode[i].weight=0;
 		huffnode[i].parent=-1;
 		huffnode[i].lchild=-1;
 		huffnode[i].rchild=-1;
 		
	}
    for(i=0;i<n;i++)
        scanf("%d",&huffnode[i].weight);
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
    	huffnode[i+n].rchild=x2;
    	
  
	}


}


#define MAXBIT 10
typedef struct{
	int bit[MAXBIT];
	int start;
}huffcodetype;
void huffmancode()
{
	huffnodetype huffnode[MAXNODE];     //存放huffnode数据
	huffcodetype huffcode[MAXLEAF],cd;  //存放每一个叶子节点的huff编码，cd作为临时储存地
	int i,j,c,p,n;
	scanf("%d",&n);
	huffmantree(huffnode);
	for(i=0;i<n;i++)
	{
		cd.start=n-1;                   //start为编码起始位置
		c=i;                            //c为此时所对应的结点
		p=huffnode[c].parent;           //p为此结点的parent
		while(p!=-1)
		{
			if(huffnode[p].lchild==c)
			    cd.bit[cd.start]=0;
			else
			    cd.bit[cd.start]=1;
			cd.start--;                 //转为起始位置的前一位
			c=p;                        //此时c转为p
			p=huffnode[c].parent;       //p变为p的parent
		}
		for(j=cd.start+1;j<n;j++)
			huffcode[i].bit[j]=cd.bit[j];//将cd存储的临时数据传入huffcode里，作为编码
		huffcode[i].start=cd.start+1;    //记录起始位，哈夫曼编码倒置（从结点到根）所以记录起始
	
	}
	for(i=0;i<n;i++)
	{
		for(j=huffcode[i].start;j<n;j++)
		    printf("%ld",huffcode[i].bit[j]);
		printf("\n");
	}

}