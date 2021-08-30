#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


typedef struct node{
	int data;
	struct node*lch,*rch;
}snode;


int CountNum(char *arr,int k,int count)
{
    int result=0;
    int i=0;
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



snode* insert(snode*t,snode*s)
{
	if(t==NULL)
	    t=s;
	if(s->data<t->data)
	    t->lch=insert(t->lch,s);
	else
	    t->rch=insert(t->rch,s);
	return t;	
}

snode* creat(void)
{
	
	snode*t,*s;
	char m[100];
	int num[100];
	memset(num,0,100*sizeof(int));
	t=NULL;
	gets(m);
	int i=0,b=0;
	int n=strlen(m);
	ConverToNum(m,n,num);
	for(i=0;num[i]!=0;i++)
	{
	    s=(snode*)malloc(sizeof(snode));
	    s->data=num[i];
	    s->lch=NULL;
	    s->rch=NULL;
		t=insert(t,s);
		b++;

	}
	return t;
}





void inorder (snode*p)
{
	if(p!=NULL)
	{
		inorder(p->lch);
		printf("%d,",p->data);
		inorder(p->rch);
	}

	
}

void preorder(snode*p)
{
	if(p!=NULL)
	{
		printf("%d,",p->data);
		preorder(p->lch);
		preorder(p->rch);
	}
}


int main()
{
	snode*t;
	t=creat();
	preorder(t);
	printf("\n");
	inorder(t);
	return 0;
}
	
	
	
	
	





