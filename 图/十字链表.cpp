#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct olnode{  //����ÿ�����
    int  i, j;          //i�к�,j�к�   
    int e;        //eֵ   
    struct olnode *right,*down;  //ָ����   
}olnode,*olink;
typedef struct {          // ����ʮ������
    olink *rhead,*chead;  //ʮ������ͷ�ڵ�洢
    int mu, nu, tu;       // ϡ����������mu,����nu��Ԫ�ظ���tu    
}crosslist;


int createcorsslist (crosslist *M)  //***����Mǰ���ʼ��***
{
	int i,j,m,n,t;
	int k,flag;
	int e;
	M->rhead=NULL;
	M->chead=NULL;
	do{
		flag=1;
		printf("���������������Լ�����Ԫ����");
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
			printf("�����%d������кš��к��Լ�ֵ", k);
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
				p->right=q->right; // ����в���    
                q->right=p; 	
		}
		if(M->rhead[j]==NULL||M->rhead[j]->i>i)
		{
			p->down=M->rhead[j];
			M->rhead[j]=p;
		}
		else // Ѱ�����б��еĲ���λ��   
        {  
                  //�Ӹ��е�������ͷ��ʼ��ֱ���ҵ�   
            for(q=M->rhead[j]; q->down && q->down->i < i; q=q->down)   
            ;  
            p->down=q->down; // ����в���    
            q->down=p;  
 
        }  
   
	}
	return 1;
	
}