#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct avlnode
{
    int val;
    struct avlnode *left,*right;
    int height;//AVL���ĸ߶�
}avlnode;


int max(int a,int b)
{
	return a>=b?a:b;
}


int  getheight(avlnode*r)
{
	return r?r->height:-1;
}

avlnode* lrotation(avlnode*r)//l˳ʱ����ת
{
	avlnode*p=r->left;
	r->left=p->right;
	p->right=r;
	r->height=max(getheight(r->left),getheight(r->right))+1;
	p->height=max(getheight(p->left),getheight(p->right))+1;
	return p;
}


avlnode* rrotation(avlnode*r)//r��ʱ����ת
{
	avlnode*p=r->right;
	r->right=p->left;
	p->left=r;
	r->height=max(getheight(r->left),getheight(r->right))+1;
	p->height=max(getheight(p->left),getheight(p->right))+1;
	return p;
}

avlnode*lrrotation(avlnode*r)
{
	r->left=rrotation(r->left);
	return lrotation(r);
}

avlnode*rlrotation(avlnode*r)
{
	r->right=lrotation(r->right);
	return rrotation(r);
}


avlnode*avlinsert(avlnode*r,int e)
{
	if(r==NULL)
	{
		
		r=(avlnode*)malloc(sizeof(avlnode));
		r->val=e;
		r->left=r->right=NULL;
		r->height=0;
		return r;
	}
	if(r->val<e)//���������в�����
	{
		r->right=avlinsert(r->right,e);
		if(getheight(r->right)-getheight(r->left)>=2)//�ҽ����ܲ�ƽ��
		{
			r=(getheight(r->right->left)>getheight(r->right->right))?rlrotation(r):rrotation(r);
		}	
	}
	else if(r->val>e)
	{
		r->left=avlinsert(r->left,e);
		if(getheight(r->left)-getheight(r->right)>=2)//������ܲ�ƽ��
		{
			r=(getheight(r->left->left)>getheight(r->left->right))?lrotation(r):lrrotation(r);
		}	
	
	}
	r->height=max(getheight(r->left),getheight(r->right))+1;
	return r;
}



avlnode*avlremove(avlnode*r,int e)	
{
	if(r==NULL)
	    return r;
	if(r->val<e)
	{
		r->right=avlremove(r->right,e);
	}
	else if(r->val>e)
	{
		r->left=avlremove(r->left,e);
	}
	else
	{
		if(r->left&&r->right)//���Ҷ���Ϊ��
		{
			avlnode*p=r->right;
			while(p->left)//�ұ���������Сֵ
			    p=p->left;
			r->val=p->val;
			r->right=avlremove(r->right,p->val);
			
		}
		else
		{
			avlnode*p=(r->left)?r->left:r->right;
			free(r);
			return p;
		}
	}
	if(getheight(r->left)-getheight(r->right)>=2)
	    r=(getheight(r->left->left)>getheight(r->left->right))?lrotation(r):lrrotation(r);
	else if(getheight(r->right)-getheight(r->left)>=2)
	    r=(getheight(r->right->left)>getheight(r->right->right))?rlrotation(r):rrotation(r);
	r->height=max(getheight(r->left),getheight(r->right))+1;
	return r;
}
void inorder(avlnode*p)
{
	if(p==NULL)
	    return;
	inorder(p->left);
	printf("%d",p->val);
	inorder(p->right);
}

int main()
{
	avlnode*r=NULL;
	r=avlinsert(r,3);//һ��ʼֻ�ǲ���û���õ�����ֵ����ַû�и��£�avl��error;
    r=avlinsert(r,1);
    r=avlinsert(r,4);
    r=avlinsert(r,6);
    r=avlinsert(r,9);
    r=avlinsert(r,2);
    r=avlinsert(r,5);
    r=avlinsert(r,7);
	inorder(r);
	return 0;

}	