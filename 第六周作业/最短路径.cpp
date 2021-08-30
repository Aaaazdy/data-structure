#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 1000                 //不要乱写高大上的定义
#define num  7
typedef struct graph {
    int node[num];
    int arcs[num][num];//邻接矩阵 
} graph;


void floyd(graph* g)
{
    int P[num][num];    //存储靠前的中间节点
    int D[num][num];    //存储最短路径
    int v, w, k;
    //初始化floyd算法的两个矩阵 
    for (v = 0; v <num; v++)
    {
        for (w = 0; w <num; w++)
        {
            D[v][w] = g->arcs[v][w];
            P[v][w]=w;
                
                
        }
    }

    //这里是弗洛伊德算法的核心部分 
    //k为中间点 
    for (k =0; k <num; k++)
    {
        //v为起点 
        for (v =0; v <num; v++)
        {
            //w为终点 
            for (w = 0; w <num; w++)
            {
                if (D[v][w] > (D[v][k] + D[k][w]))
                {
                    D[v][w] = D[v][k] + D[k][w];//更新最小路径 
                    P[v][w] = P[v][k];//更新最小路径中间顶点 
                }
            
            
			}
        
        
		}
    
    
	}
    v = 0;
    w = 5;
    k = P[v][w];
    printf("%d,", v+1);//打印起点
    while(k != w)
	{
        printf("%d,", k+1);//打印中间点
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
    g->arcs[1][4] = 10;          //数据要对应
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
        g->arcs[i][i] = 0;       //对角线应为0
	}   
	
    floyd(g);
    return 0;
}