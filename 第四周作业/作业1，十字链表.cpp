#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int CountNum(char* arr, int k, int count)//arrΪ�ַ����飬kΪ�����±꣬
{                                      //countΪ�����ָ���
	int result = 0;                      //result��¼�����ֵ
	int i = 0;                           //iΪ������ʹ��ȡ�����е���������,ͬʱ����10�Ĵη�
	if (count == 0)                       //countΪ����λ��
		result = -1;//main�������ʼ����-1�����Ը�ֵ-1
	while (count > 0)
	{
		float ten = pow(10, i);          //����λ������10�Ĵη�
		result += (arr[k - 1 - i] - 48) * ten;  //��48Ϊʹ��ASCII���ַ���ת��Ϊ����
		i++;
		count--;
	}
	return result;
}

void ConverToNum(char* arr, int length, int* num)//��������ַ����е�������ȡ
												//����������num������length��                                                                           
{                                               //arr�е��ַ����� 
	int n = 0;
	int k = 0;
	int count_temp = 0;                           //countΪ���ż����ָ���
	while (k <= length)
	{
		//����ַ��Ƕ��Ż��߽�β���ʹ�����������֮����ַ���ת�������� 
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

typedef struct olnode {  //����ÿ�����
	int  i, j;          //i�к�,j�к�   
	int e;        //eֵ   
	struct olnode* right, * down;  //ָ����   
}olnode, * olink;
typedef struct {          //ʮ������ͷ�ڵ�洢
	olink* rhead, * chead;
	int mu, nu, tu;       // ϡ����������mu,����nu��Ԫ�ظ���tu    
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
			p->right = q->right; // ����в���    
			q->right = p;
		}
		if (M->rhead[j] == NULL || M->rhead[j]->i > i)
		{
			p->down = M->rhead[j];
			M->rhead[j] = p;
		}
		else // Ѱ�����б��еĲ���λ��   
		{
			//�Ӹ��е�������ͷ��ʼ��ֱ���ҵ�   
			for (q = M->rhead[j]; q->down && q->down->i < i; q = q->down)
				;
			p->down = q->down; // ����в���    
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