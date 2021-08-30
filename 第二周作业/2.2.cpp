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




//把输入的字符串中的数字提取出来，放在num数组中
//length是arr中的字符个数 
int ConverToNum(char *arr, int length, int *num)
{
    int n=0;
    int k=0;
    int count_temp=0;
    while(k<=length)
    {
        //如果字符是逗号或者结尾，就处理两个逗号之间的字符，转换成数字 
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



snode* insert(snode*t,int x)
{
	if(t==NULL)
	{
	    t=(snode*)malloc(sizeof(snode));
	    if(t==NULL)
	        printf("error");
        else 
        {
        	t->data=x;
        	t->lch=t->rch=NULL;
		}
	
	}
	else
	{
		if(x<t->data)
		    t->lch=insert(t->lch,x);
		else if(x>t->data)
		    t->rch=insert(t->rch,x);
	}
    return t;
}

snode* creat(void)
{
	
	snode*t,*s;
	char m[100];
	int num[100];
	memset(num,-1,100*sizeof(int));
	t=NULL;
	gets(m);
	int i=0,b=0;
	int n=strlen(m);
	ConverToNum(m,n,num);
	for(i=0;num[i]!=0;i++)
	{
	    t=insert(t,num[i]);
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

void posorder(snode*p)
{
	if(p!=NULL)
	{
		
		posorder(p->lch);
		posorder(p->rch);
		printf("%d,",p->data);
	}
}


int main()
{
	snode*t;
	t=creat();
	posorder(t);
	printf("\n");
	inorder(t);
	return 0;
}
	
	
	
	
	
