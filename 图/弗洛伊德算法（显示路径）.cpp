#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF         1000//(~(0x1<<31)) 
#define max 10
typedef struct graph{
    char node[max];
    int vexnum;//������ 
    int edgnum;//���� 
    int arcs[max][max];//�ڽӾ��� 
} graph;



void floyd(graph*g, int P[max][max], int D[max][max], int num)
{
    int v, w, k;
    //��ʼ��floyd�㷨���������� 
    for(v = 0; v < num; v++)
	{
        for(w = 0; w < num; w++)
		{
            D[v][w] = g->arcs[v][w];
            P[v][w] = w;
        }
    }

    //�����Ǹ��������㷨�ĺ��Ĳ��� 
    //kΪ�м�� 
    for(k = 0; k < num; k++)
	{
        //vΪ��� 
        for(v = 0 ; v < num; v++)
		{
            //wΪ�յ� 
            for(w =0; w < num; w++)
			{
                if(D[v][w] > (D[v][k] + D[k][w]))
				{
                    D[v][w] = D[v][k] + D[k][w];//������С·�� 
                    P[v][w] = P[v][k];//������С·���м䶥�� 
                }
            }
        }
    }

    printf("\n��ʼ����D����\n");
    for(v = 0; v < num; v++)
	{
        for(w = 0; w < num; w++)
		{
            printf("%d ", D[v][w]);
        }
        printf("\n");
    }

    printf("\n��ʼ����P����\n");
    for(v = 0; v < num; v++)
	{
        for(w = 0; w < num; w++)
		{
            printf("%d", P[v][w]);
        }
        printf("\n");
    }

    v = 0;
    w = 3;
    //�� 0 �� 3����С·��
    printf("\n%d -> %d ����С·��Ϊ��%d\n", v, w, D[v][w]);
    k = P[v][w];
    printf("path: %d", v);//��ӡ���
    while(k != w)
	{
        printf("-> %d", k);//��ӡ�м��
        k = P[k][w]; 
    }
    printf("-> %d\n", w);
}

int main()
{
    int v, w, num;
    graph*g;
    g = (graph*)malloc(sizeof(graph));
	printf("�����붥����:\n");
    scanf("%d", &num);
    printf("�������ʼ����ֵ��\n");
    for(v = 0; v <num; v++)
	{
        for(w = 0; w <num; w++)
		{
            scanf("%d", &g->arcs[v][w]);
        }
    }
    printf("\n����ľ���ֵ��\n");
    for(v = 0; v < num; v++)
	{
        for(w = 0; w < num; w++)
		{
            printf("%d ", g->arcs[v][w]);
        }
        printf("\n");
    }
    int P[max][max];//��¼��Ӧ�����С·����ǰ���㣬����p(1,3) = 2 ˵������1������3����С·��Ҫ����2 
    int D[max][max];//��¼��������С·��ֵ
	floyd(g,P,D, num);
}