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
    v=0;
    for(w=0;w<num;w++)
   	{
   		k = P[v][w];
        printf("%c,", g->node[v]);//��ӡ���
        while(k != w)
        {
	        printf("%c,", g->node[k]);//��ӡ�м��
            k = P[k][w]; 
        }
        printf("%c", g->node[w]);
		printf("�����·��ֵΪ%d\n",D[v][w]);
		}
    
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
    
    g->arcs[0][1] = 5;
    g->arcs[0][2] = 3;
    g->arcs[1][2] = 2;
    g->arcs[1][4] = 3;          //����Ҫ��Ӧ
    g->arcs[1][6] = 1;
    g->arcs[2][3] = 7;
    g->arcs[2][4] = 7;
    g->arcs[3][0] = 2;
    g->arcs[3][5] = 6;
    g->arcs[4][5] = 1;
    for (i =0; i <num; i++)
    {
	    g->node[i] = i+65;
        g->arcs[i][i] = 0;       //�Խ���ӦΪ0
	}   
	
    floyd(g);
    return 0;
}