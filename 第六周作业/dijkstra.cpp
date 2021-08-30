#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MAX 100                 // 矩阵最大容量
#define INF 1000//(~(0x1<<31))        // 最大值(即0X7FFFFFFF)
#define num 10
// 邻接矩阵
typedef struct graph{
    char node[num];       // 顶点集合         
    int arcs[num][num]; // 邻接矩阵
}graph;
/* Dijkstra最短路径。
 * 即，统计图(G)中"顶点vs"到其它各个顶点的最短路径。
 *
 * 参数说明：
 *        G -- 图
 *       vs -- 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。
 *     prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
 *     dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
 */
void dijkstra(graph*g,int vs)
{
    int prev[num];
    int dist[num];
	int i,j,k;
    int min;
    int tmp;
    int flag[num];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。

    // 初始化
    for (i=0;i<num;i++)
    {
        flag[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = 0;              // 顶点i的前驱顶点为0。
        dist[i] = g->arcs[vs][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。权为一确定数值或无穷大
    }

    // 对"顶点vs"自身进行初始化
    flag[vs] = 1;
    dist[vs] = 0;

    // 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
    for (i=0;i<num-1;i++)
    {
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
        min = INF;
        for (j=0;j<num;j++)
        {
            if (flag[j]==0 && dist[j]<min)
            {
                min = dist[j];
                k = j;
            }
        }
        
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;
        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j=0;j<num;j++)
        {
            tmp = (g->arcs[k][j]==INF?INF:(min+g->arcs[k][j])); // 防止溢出
            if (flag[j]==0 && (tmp<dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    // 打印dijkstra最短路径的结果
    printf("dijkstra(%c): \n", g->node[vs]);
    for (i=0;i<num;i++)
        printf("  shortest(%c, %c)=%d\n",g->node[vs],g->node[i], dist[i]);
}