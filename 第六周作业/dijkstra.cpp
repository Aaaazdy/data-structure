#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MAX 100                 // �����������
#define INF 1000//(~(0x1<<31))        // ���ֵ(��0X7FFFFFFF)
#define num 10
// �ڽӾ���
typedef struct graph{
    char node[num];       // ���㼯��         
    int arcs[num][num]; // �ڽӾ���
}graph;
/* Dijkstra���·����
 * ����ͳ��ͼ(G)��"����vs"������������������·����
 *
 * ����˵����
 *        G -- ͼ
 *       vs -- ��ʼ����(start vertex)��������"����vs"��������������·����
 *     prev -- ǰ���������顣����prev[i]��ֵ��"����vs"��"����i"�����·����������ȫ�������У�λ��"����i"֮ǰ���Ǹ����㡣
 *     dist -- �������顣����dist[i]��"����vs"��"����i"�����·���ĳ��ȡ�
 */
void dijkstra(graph*g,int vs)
{
    int prev[num];
    int dist[num];
	int i,j,k;
    int min;
    int tmp;
    int flag[num];      // flag[i]=1��ʾ"����vs"��"����i"�����·���ѳɹ���ȡ��

    // ��ʼ��
    for (i=0;i<num;i++)
    {
        flag[i] = 0;              // ����i�����·����û��ȡ����
        prev[i] = 0;              // ����i��ǰ������Ϊ0��
        dist[i] = g->arcs[vs][i];// ����i�����·��Ϊ"����vs"��"����i"��Ȩ��ȨΪһȷ����ֵ�������
    }

    // ��"����vs"������г�ʼ��
    flag[vs] = 1;
    dist[vs] = 0;

    // ����G.vexnum-1�Σ�ÿ���ҳ�һ����������·����
    for (i=0;i<num-1;i++)
    {
        // Ѱ�ҵ�ǰ��С��·����
        // ������δ��ȡ���·���Ķ����У��ҵ���vs����Ķ���(k)��
        min = INF;
        for (j=0;j<num;j++)
        {
            if (flag[j]==0 && dist[j]<min)
            {
                min = dist[j];
                k = j;
            }
        }
        
        // ���"����k"Ϊ�Ѿ���ȡ�����·��
        flag[k] = 1;
        // ������ǰ���·����ǰ������
        // �������Ѿ�"����k�����·��"֮�󣬸���"δ��ȡ���·���Ķ�������·����ǰ������"��
        for (j=0;j<num;j++)
        {
            tmp = (g->arcs[k][j]==INF?INF:(min+g->arcs[k][j])); // ��ֹ���
            if (flag[j]==0 && (tmp<dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    // ��ӡdijkstra���·���Ľ��
    printf("dijkstra(%c): \n", g->node[vs]);
    for (i=0;i<num;i++)
        printf("  shortest(%c, %c)=%d\n",g->node[vs],g->node[i], dist[i]);
}