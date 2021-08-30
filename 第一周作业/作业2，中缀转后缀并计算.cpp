#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100




typedef struct stack {                   //定义顺序栈
	int top;                             //top指向栈顶数组下标
	char elem[MAXSIZE];
}stack;
typedef struct stack2{                   //定义顺序栈
	int top;                             //top指向栈顶数组下标
	float elem[MAXSIZE];
}stack2;

stack* initstack(void)                    //初始化栈
{
	stack*s;
	s = (stack*)malloc(sizeof(stack));
	s->top = -1;                            //top初始化为-1
	return s;

}


int pop(stack*s)                           //弹栈，即top-1
{
	if (s->top == -1)
		return 0;

	s->elem[s->top] = '\0';
	s->top--;
	return 1;

}
int push(stack*s, char n)                    //压栈，即top+1，并将n设置为栈顶元素
{
	if (s->top == MAXSIZE - 1)
		return 0;
	s->top++;
	s->elem[s->top] = n;
	return 1;
}




void judge(char*exp,char*e)        //judge函数将字符数组exp（中置表达式）转换为后缀表达式
{
	stack*s;                 //栈用来记录运算符号+-*/（），如果栈顶符号优先级大于等于即将入栈的符号，则出栈并输入e中，否则进栈
	s = initstack();       //e数组用来盛放后置表达式
	int i = 0;
	int j = 0;
	while (exp[i] != '\0')             //当exp数组不为空时，即把输入的exp数组全部转换为后缀表达式
	{
		if (exp[i] >= '0' && exp[i] <= '9')  //若为数字则直接输入e中，数字不进入栈中，只有符号需要进栈
		{
			e[j++] = exp[i];
		}
		else if (exp[i] == '(')  //若为左括号，则直接进栈
		{
			push(s, exp[i]);
		}
		else if (exp[i] == ')')   //若为右括号，则将e中左括号与此右括号之间的所有符号输出到e中并将他们全部弹栈
		{
			while (s->top != -1)
			{
				if (s->elem[s->top] == '(')
				{
					pop(s);
					break;
				}
				else
				{
					e[j++] = s->elem[s->top];
					pop(s);
				}
			}



		}
		else if (exp[i] == '+' || exp[i] == '-')//若为+-，因为他们优先级最低，所以只要栈顶元素不是（，其他符号全部输入e中并弹栈
		{
			while (s->top != -1)
			{
				char c = s->elem[s->top];
				if (c == '+' || c == '-' || c == '*' || c == '/')
				{
					e[j++] = c;
					pop(s);

				}
				else
					break;
			}
			push(s, exp[i]);   //此时优先级大于等于+-的符号皆已经弹栈，那么此符号进栈
		}
		else if (exp[i] == '*' || exp[i] == '/') //同理*/和+-类似
		{
			while (s->top != -1)
			{
				char c = s->elem[s->top];
				if (c == '*' || c == '/')
				{
					e[j++] = c;
					pop(s);
				}
				else
					break;
			}
			push(s, exp[i]);

		}
		i++;
	}
	while (s->top != -1)         //当表达式已经全部传递完时，将栈里剩余的符号全部弹栈进入e中
	{
		e[j++] = s->elem[s->top];
		pop(s);
	}
	e[j] = '\0';                //最后在字符串e最后一位添加元素\0
}




float count(char*exp)       
{
	stack2*s;                      //创建stack2类型栈，定义栈里元素为float类型
	s=(stack2*)malloc(sizeof(stack2));
	s->top=-1;
	int i = 0;
	float m;
	float n;
	while (exp[i] != '\0')
	{
		char c = exp[i];
		if (c >='0'&&c <= '9')
		{
			s->top++;
			m =(float)atof(&c);     //转换为float类型
			s->elem[s->top]=m;    
		}
		else if (c == '+')         
		{
			m =s->elem[s->top];
			s->top--;
			n =s->elem[s->top];
			s->elem[s->top]=n+m;

		}
		else if (c == '-')         //同理
		{
			m =s->elem[s->top];
			s->top--;
			n =s->elem[s->top];
			s->elem[s->top]=n-m;

		}
		else if (c == '*')
		{
			m =s->elem[s->top];
			s->top--;
			n =s->elem[s->top];
			s->elem[s->top]=n*m;

		}
		else if (c == '/')
		{
			m =s->elem[s->top];
			s->top--;
			n =s->elem[s->top];
			s->elem[s->top]=n/m;

		}
		i++;
	}

	return s->elem[s->top];	 //若后缀表达式正确，栈里应该只剩运算结果，输出结果
}
int main()
{
	static char e[1000];
	char exp[100];     
	scanf("%s", exp);      
	judge(exp,e);
	float n = count(e);  
	printf("%.2f\n", n);  
	printf("%s", e);    
	return 0;
}