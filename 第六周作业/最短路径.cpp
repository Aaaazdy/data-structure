#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 1000                 //��Ҫ��д�ߴ��ϵĶ���
#define num  7
typedef struct graph {
    int node[num];
    int arcs[num][num];//�ڽӾ��� 
} graph;


void floyd(graph* g)
{
    int P[num][num];    //�洢��ǰ���м�ڵ�
    int D[num][num];    //�洢���·��
    int v, w, k;
    //��ʼ��floyd�㷨���������� 
    for (v = 0; v <num; v++)
    {
        for (w = 0; w <num; w++)
        {
            D[v][w] = g->arcs[v][w];
            P[v][w]=w;
                
                
        }
    }

    //�����Ǹ��������㷨�ĺ��Ĳ��� 
    //kΪ�м�� 
    for (k =0; k <num; k++)
    {
        //vΪ��� 
        for (v =0; v <num; v++)
        {
            //wΪ�յ� 
            for (w = 0; w <num; w++)
            {
                if (D[v][w] > (D[v][k] + D[k][w]))
                {
                    D[v][w] = D[v][k] + D[k][w];//������С·�� 
                    P[v][w] = P[v][k];//������С·���м䶥�� 
                }
            
            
			}
        
        
		}
    
    
	}
    v = 0;
    w = 5;
    k = P[v][w];
    printf("%d,", v+1);//��ӡ���
    while(k != w)
	{
        printf("%d,", k+1);//��ӡ�м��
        k = P[k][w]; 
    }
    printf("%d", w+1);
}

int main()
{
    int i,j,s,t;
    graph* g;
    g = (graph*)malloc(sizeof(graph));
    for (i =0; i <num; i++)
    {
        for (j =0; j <num; j++)
            g->arcs[i][j] = INF;
    }
    
    g->arcs[0][1] = 2;
    g->arcs[0][3] = 1;
    g->arcs[1][3] = 3;
    g->arcs[1][4] = 10;          //����Ҫ��Ӧ
    g->arcs[2][0] = 4;
    g->arcs[2][5] = 5;
    g->arcs[3][2] = 2;
    g->arcs[3][5] = 8;
    g->arcs[3][6] = 4;
    g->arcs[3][4] = 2;
    g->arcs[4][6] = 6;
    g->arcs[6][5] = 1;
    scanf("%d,%d", &s, &t);
    g->arcs[s-1][t-1] = INF;
    for (i =0; i <num; i++)
    {
	    g->node[i] = i;
        g->arcs[i][i] = 0;       //�Խ���ӦΪ0
	}   
	
    floyd(g);
    return 0;
}