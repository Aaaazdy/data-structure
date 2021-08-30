#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int CountNum(char* arr, int k, int count)//arr为字符数组，k为逗号下标，
{                                      //count为此数字个数
	int result = 0;                      //result记录结果数值
	int i = 0;                           //i为计数器使所取数组中的数字左移,同时代表10的次方
	if (count == 0)                       //count为左移位数
		result = -1;//main函数里初始数组-1，所以赋值-1
	while (count > 0)
	{
		float ten = pow(10, i);          //依据位数乘以10的次方
		result += (arr[k - 1 - i] - 48) * ten;  //减48为使用ASCII将字符数转化为整数
		i++;
		count--;
	}
	return result;
}

void ConverToNum(char* arr, int length, int* num)//把输入的字符串中的数字提取
												//出来，放在num数组中length是                                                                           
{                                               //arr中的字符个数 
	int n = 0;
	int k = 0;
	int count_temp = 0;                           //count为逗号间数字个数
	while (k <= length)
	{
		//如果字符是逗号或者结尾，就处理两个逗号之间的字符，转换成数字 
		if (arr[k] == ',' || arr[k] == '\0')
		{
			num[n] = CountNum(arr, k, count_temp);
			n++;
			count_temp = 0;
		}
		else
		{
			count_temp++;
		}

		k++;
	}

}

typedef struct olnode {  //链表每个结点
	int  i, j;          //i行号,j列号   
	int e;        //e值   
	struct olnode* right, * down;  //指针域   
}olnode, * olink;
typedef struct {          //十字链表头节点存储
	olink* rhead, * chead;
	int mu, nu, tu;       // 稀疏矩阵的行数mu,列数nu和元素个数tu    
}crosslist;


int createcrosslist(crosslist* M, int t)
{
	int i, j, m, n;
	int k, flag;
	int e;
	M->rhead=NULL;
	M->chead=NULL;
	m = n = 5;
	M->mu = 5;
	M->nu = 5;
	M->tu = t;
	M->rhead = (olink*)malloc(sizeof(olink) * (n + 1));
	M->chead = (olink*)malloc(sizeof(olink) * (m + 1));
	if (!(M->chead))
		return -1;
	for (k = 1; k <= n; k++)
		M->rhead[k] = NULL;
	for (k = 1; k <= m; k++)
		M->chead[k] = NULL;
	return 1;
}

int insertcrosslist(crosslist* M, int t, int num[])
{
	int k, flag, i, j, e,b;
	olnode* p, * q;
	for (k = 1; k <= t; k++)
	{
		e = 1;
		i = num[2 * k - 2]+1;
		j = num[2 * k - 1]+1
			;
		p = (olink)malloc(sizeof(olnode));
		if (p == NULL)
			return -1;
		p->i = i;
		p->j = j;
		p->e = e;
		if (M->chead[i] == NULL || j< M->chead[i]->j)
		{
			p->right = M->chead[i];
			M->chead[i] = p;
		}
		else
		{
			for (q = M->chead[i]; q->right && q->right->j < j; q = q->right)
				;
			p->right = q->right; // 完成行插入    
			q->right = p;
		}
		if (M->rhead[j] == NULL || M->rhead[j]->i > i)
		{
			p->down = M->rhead[j];
			M->rhead[j] = p;
		}
		else // 寻查在列表中的插入位置   
		{
			//从该列的列链表头开始，直到找到   
			for (q = M->rhead[j]; q->down && q->down->i < i; q = q->down)
				;
			p->down = q->down; // 完成行插入    
			q->down = p;

		}

	}
	return 1;

}


int main()
{
	int n, i, j, k, l;
	int num[100];
	memset(num, -1, 100 * sizeof(int));
	char s[100];
	gets(s);
	n = strlen(s);
	ConverToNum(s, n, num);
	for (i = 0; num[i] != -1; i++)
		;
	i = i / 2;
	crosslist* M;
	M = (crosslist*)malloc(sizeof(crosslist));
	createcrosslist(M, i);
	insertcrosslist(M, i, num);
	olink p;
	p = (olink)malloc(sizeof(olnode));
	for (j = 1; j <= 5; j++)
	{
		k = 1;
		p = M->chead[j];
		while (p != NULL)
		{
			if (!(k%2))
				p->e = 0;

			p = p->right;
			k++;
		}

	}
	k = 0;
	scanf("%d", &l);
	l = l + 1;
	p = M->rhead[l];
	while (p != NULL)
	{
		if (p->e == 1)
		{
			printf("%d,", p->i-1);
			k++;
		}
		p = p->down;
	}
	if (k == 0)
		printf("-1");

	return 0;
}