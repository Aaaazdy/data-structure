#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct olnode{  //链表每个结点
    int  i, j;          //i行号,j列号   
    int e;        //e值   
    struct olnode *right,*down;  //指针域   
}olnode,*olink;
typedef struct {          // 代表十字链表
    olink *rhead,*chead;  //十字链表头节点存储
    int mu, nu, tu;       // 稀疏矩阵的行数mu,列数nu和元素个数tu    
}crosslist;


int createcorsslist (crosslist *M)  //***传入M前请初始化***
{
	int i,j,m,n,t;
	int k,flag;
	int e;
	M->rhead=NULL;
	M->chead=NULL;
	do{
		flag=1;
		printf("输入行数，列数以及非零元个数");
		scanf("%d%d%d",&m,&n,&t);
		if(m<0||n<0||t<0||t>m*n)
		    flag=0;
	}while(!flag);
	M->mu=m;
	M->nu=n;
	M->tu=t;
	M->rhead=(olink*)malloc(sizeof(olink)*(n+1));
	if(!(M->rhead))
	    return -1;
	M->chead=(olink*)malloc(sizeof(olink)*(m+1));
	if(!(M->chead))
	    return -1;
	for(k=1;k<=n;k++)
	    M->rhead[k]=NULL;
	for(k=1;k<=m;k++)
	    M->chead[k]=NULL;
	return 1;
}
	
int insertcrosslist(crosslist*M,int t)
{
	int k,flag,i,j,e;
	olnode *p,*q;
	for(k=1;k<=t;k++)
	{
		do{
			flag=1;
			printf("输入第%d个结点行号、列号以及值", k);
			scanf("%d%d%d", &i, &j, &e); 
			if (i<=0 || j<=0)  
                flag = 0;  
		}while(!flag);
		p=(olink)malloc(sizeof(olnode));
		if(p==NULL)
		    return -1;
		p->i = i;  
        p->j = j;  
        p->e = e;  
		if(M->chead[i]==NULL||j<M->chead[i]->j)
		{
			p->right=M->chead[i];
			M->chead[i]=p;
		}
		else
		{
			for(q=M->chead[i]; q->right && q->right->j < j;q=q->right)
			;
				p->right=q->right; // 完成行插入    
                q->right=p; 	
		}
		if(M->rhead[j]==NULL||M->rhead[j]->i>i)
		{
			p->down=M->rhead[j];
			M->rhead[j]=p;
		}
		else // 寻查在列表中的插入位置   
        {  
                  //从该列的列链表头开始，直到找到   
            for(q=M->rhead[j]; q->down && q->down->i < i; q=q->down)   
            ;  
            p->down=q->down; // 完成行插入    
            q->down=p;  
 
        }  
   
	}
	return 1;
	
}