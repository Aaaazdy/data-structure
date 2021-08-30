#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 50
typedef struct stack{
    char elem[MAXSIZE];
    int top;
}stack;
 stack* initstack(void)
 {
    stack*s;
    s=(stack*)malloc(sizeof(stack));
    if(s)
        s->top=-1;
    return s;
 }
 
 
 int push(stack*s,char n)
 {
    if(s->top==MAXSIZE-1)
        return 0;
    s->top++;
    s->elem[s->top]=n;
    return 1;
 }

 int pop(stack*s)
 {
    if(s->top==-1)
        return 0;
    s->top--;
    return 1;
 }


void judge(int*a)
{
    stack*s;
    s=initstack();
    char ch[50],ch_e[50],*p,e;
    gets(ch);
    p=ch;
    
    while(*p)
    {
        switch (*p)
        {
        case'(':
        case'[':
        case'{':
            push(s,*p);
            p++;
            break;
        case')':
        case']':
        case'}':
            if(s->top!=-1)
            {
                e=s->elem[s->top];
                pop(s);
                if(e=='('&&*p==']')
                    a[0]=a[1]=1;
                else if(e=='('&&*p=='}')
                    a[0]=a[2]=1;
                else if(e=='['&&*p==')')
                    a[0]=a[1]=1;
                else if(e=='['&&*p=='}')
                    a[1]=a[2]=1;
                else if(e=='{'&&*p==')')
                    a[0]=a[2]=1;
                else if(e=='{'&&*p==']')
                    a[1]=a[2]=1;
            }
            else
            {
                if(*p==')')
                    a[0]=1;
                else if(*p==']')
                    a[1]=1;
                else if(*p=='}')
                    a[2]=1;
            }
        
        
        
        default:
            p++;
            break;
        }



    }
    while(s->top!=-1)
    {
        e=s->elem[s->top];
        pop(s);
        if(e=='(')
            a[0]=1;
        else if(e=='[')
            a[1]=1;
        else if(e=='{')
            a[2]=1;

    }


}

int main()
{
    int a[3]={ 0,0,0 };
    judge(a);
    if(a[0]==0&&a[1]==0&&a[2]==0)
        printf("0");
    for(int i=0;i<3;i++)
    {
        if(a[i]>0)
            printf("%d,",i+1);
    }
    return 0;
    system("pause");
}
