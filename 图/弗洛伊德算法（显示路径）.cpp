#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF         1000//(~(0x1<<31)) 
#define max 10
typedef struct graph{
    char node[max];
    int vexnum;//顶点数 
    int edgnum;//边数 
    int arcs[max][max];//邻接矩阵 
} graph;



void floyd(graph*g, int P[max][max], int D[max][max], int num)
{
    int v, w, k;
    //初始化floyd算法的两个矩阵 
    for(v = 0; v < num; v++)
	{
        for(w = 0; w < num; w++)
		{
            D[v][w] = g->arcs[v][w];
            P[v][w] = w;
        }
    }

    //这里是弗洛伊德算法的核心部分 
    //k为中间点 
    for(k = 0; k < num; k++)
	{
        //v为起点 
        for(v = 0 ; v < num; v++)
		{
            //w为终点 
            for(w =0; w < num; w++)
			{
                if(D[v][w] > (D[v][k] + D[k][w]))
				{
                    D[v][w] = D[v][k] + D[k][w];//更新最小路径 
                    P[v][w] = P[v][k];//更新最小路径中间顶点 
                }
            }
        }
    }

    printf("\n初始化的D矩阵\n");
    for(v = 0; v < num; v++)
	{
        for(w = 0; w < num; w++)
		{
            printf("%d ", D[v][w]);
        }
        printf("\n");
    }

    printf("\n初始化的P矩阵\n");
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
    //求 0 到 3的最小路径
    printf("\n%d -> %d 的最小路径为：%d\n", v, w, D[v][w]);
    k = P[v][w];
    printf("path: %d", v);//打印起点
    while(k != w)
	{
        printf("-> %d", k);//打印中间点
        k = P[k][w]; 
    }
    printf("-> %d\n", w);
}

int main()
{
    int v, w, num;
    graph*g;
    g = (graph*)malloc(sizeof(graph));
	printf("请输入顶点数:\n");
    scanf("%d", &num);
    printf("请输入初始矩阵值：\n");
    for(v = 0; v <num; v++)
	{
        for(w = 0; w <num; w++)
		{
            scanf("%d", &g->arcs[v][w]);
        }
    }
    printf("\n输入的矩阵值：\n");
    for(v = 0; v < num; v++)
	{
        for(w = 0; w < num; w++)
		{
            printf("%d ", g->arcs[v][w]);
        }
        printf("\n");
    }
    int P[max][max];//记录对应点的最小路径的前驱点，例如p(1,3) = 2 说明顶点1到顶点3的最小路径要经过2 
    int D[max][max];//记录顶点间的最小路径值
	floyd(g,P,D, num);
}