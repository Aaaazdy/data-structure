#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 50


typedef struct stack {         //定义栈，采用数组存储，top为栈顶元素的数组下标，-1表示栈空
	char elem[MAXSIZE];
	int top;
}stack;
stack* initstack(void)          //栈的初始化
{
	stack*s;
	s = (stack*)malloc(sizeof(stack));
	if (s)
	{
		s->top = -1;
	}
	return s;

}

int stackempty(stack*s)       //判断栈是否为空，即栈顶top是否为-1
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

int push(stack*s, char n)        //压栈
{
	if (s->top == MAXSIZE - 1)
		return 0;
	else
	{
		s->top++;
		s->elem[s->top] = n;
		return 1;
	}
}

int pop(stack*s, char*e)          //弹栈
{
	if (s->top == -1)
		return 0;
	else
	{
		*e = s->elem[s->top];
		s->top--;
		return 1;
	}
}
void check(int*a) //传入数组a的指针，a[0]的数值表示‘（’是否正确匹配，a[0]=0表示正确匹配
{                 //a[0]=1表示匹配错误，a[1]和a[2]分别对应‘【’和‘{’的匹配是否正确
	stack*s;
	s = initstack();   //初始化s
	char ch[50], ch_e[50], *p, *e;
	gets(ch);         //输入要检查的字符串
	p = ch; 
	e = ch_e;
	while (*p)            //当p指向的内容不为空时
	{
		switch (*p)                //选择情况
		{
		case'(':
		case'[':
		case'{':
			push(s, *p);
			p++;
			break;        //左括号的情况下压栈
		case')':
		case']':
		case'}':
		if (s->top != -1)     //右括号的情况下先判断此前栈是否为空，若为空则说明直接发生了错误
		{
			pop(s, e);      //将栈顶元素弹出进行处理
			
			if (*p == ')'&&*e == '[')    //根据情况改变数组a的值，记录未匹配的具体情况
				a[0] = a[1] = 1;
			else if (*p == ')'&&*e == '{')
				a[0] = a[2] = 1;
			else if (*p == ']'&&*e == '(')
				a[0] = a[1] = 1;
			else if (*p == ']'&&*e == '{')
				a[1] = a[2] = 1;
			else if (*p == '}'&&*e == '(')
				a[0] = a[2] = 1;
			else if (*p == '}'&&*e == '[')
				a[1] = a[2] = 1;
			
		}
	    else                           //此前栈为空的情况下 ，根据情况改变数组a的值，记录未匹配的具体情况
		{
			if (*p == ')')
				a[0] = 1;
			else if (*p == ']')
				a[1] = 1;
			else if (*p == '}')
				a[2] = 1;
		}
		default:
			p++;
			break;

		}
	}
	while (s->top != -1)            //当循环结束时，若栈里还有元素，则必定为左括号，根据左括号的类型判断未匹配的情况
	{
		pop(s, e);
		if (*e == '(')
			a[0] = 1;
		else if (*e == '[')
			a[1] = 1;
		else if (*e == '{')
			a[2] = 1;
	}




}

int main()
{
    
	int a[3] = {0, 0, 0};             //创建a数组，并赋初值为0
	check(a);
	if (a[0] == 0 && a[1] == 0 && a[2] == 0)     //若都为0，则说明匹配成功，输出1
		printf("0");
	for (int i = 0; i < 3; i++)               //若有非0项，则输出对应的匹配错误的情况
	{
		if (a[i] != 0)
			printf("%d,", i + 1);
	}
	return 0;
}

