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
    v=0;
    for(w=0;w<num;w++)
   	{
   		k = P[v][w];
        printf("%c,", g->node[v]);//打印起点
        while(k != w)
        {
	        printf("%c,", g->node[k]);//打印中间点
            k = P[k][w]; 
        }
        printf("%c", g->node[w]);
		printf("且最短路径值为%d\n",D[v][w]);
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
    g->arcs[1][4] = 3;          //数据要对应
    g->arcs[1][6] = 1;
    g->arcs[2][3] = 7;
    g->arcs[2][4] = 7;
    g->arcs[3][0] = 2;
    g->arcs[3][5] = 6;
    g->arcs[4][5] = 1;
    for (i =0; i <num; i++)
    {
	    g->node[i] = i+65;
        g->arcs[i][i] = 0;       //对角线应为0
	}   
	
    floyd(g);
    return 0;
}