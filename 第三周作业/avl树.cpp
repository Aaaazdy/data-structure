#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int CountNum(char *arr,int k,int count)
{
    int result=0;
    int i=0;
    if(count==0)
        result=-1;
	while(count>0)
    {
        float ten=pow(10,i);
        result+=(arr[k-1-i]-48)*ten;
        i++;
        count--;
    }
    return result;
}




//��������ַ����е�������ȡ����������num������
//length��arr�е��ַ����� 
int ConverToNum(char *arr, int length, int *num)
{
    int n=0;
    int k=0;
    int count_temp=0;
    while(k<=length)
    {
        //����ַ��Ƕ��Ż��߽�β���ʹ�����������֮����ַ���ת�������� 
        if(arr[k]==','||arr[k]=='\0')
        {
            num[n]=CountNum(arr,k,count_temp);
            n++;
            count_temp=0;
        }
        else
        {
            count_temp++;
        }

        k++;
    }

    return n;
}



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
void preorder(avlnode*p)
{
	if(p==NULL)
	    return;
	printf("%d,",p->val);
	preorder(p->left);
    preorder(p->right);
}


int main()
{
	char m[100];
	int num[100];
	memset(num,-1,100*sizeof(int));
	gets(m);
	int n=strlen(m);
	ConverToNum(m, n, num);
	avlnode*r=NULL;
	int i;
    for(i=0;num[i]!=-1;i++)
	    r=avlinsert(r,num[i]);
	preorder(r);
	return 0;
	
	
	
}	

