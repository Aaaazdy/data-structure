
#include<stdio.h>
#include<stdlib.h>
#define N 7//�������
 
typedef struct 
{
	char vexs[N];//��������
	int arcs[N][N];//�ڽӾ���
}graph;
 
void TopoSort_matrix(graph g)
{
	int row[N]={0};//�����������ñ�־��Ϊ1��ʾ�Ѿ���������ٿ��ǣ���Ϊ0��ʾδ�����
	int v=1;//��־����1��ʾ�Ѿ���������ٿ��ǣ���Ϊ0��ʾδ���������row����
	int i,j,k,t,m;
	for(k=0;k<N;k++)
	{
		for(j=0;j<N;j++)
		{
			if(row[j]==0)//�j��δ���
			{
				t=1;//��ʶ��
				for(i=0;i<N;i++)
					if(g.arcs[i][j]==1)//��ǰ�����ȣ��i�����ڻj֮ǰ��
					{
						t=0;
						break;
					}
				if(t==1)//�jû�����
				{
					m=j;
					break;
				}
			}
		}
		if(j!=N)
		{
			row[m]=v;
			printf("%c",g.vexs[m]);
			for(i=0;i<N;i++)
				g.arcs[m][i]=0;//���Ѿ�����Ļ��������¸���������Ϊ0
			v++;
		}
		else 
			break;
		}
		if(v-1<N)//��row�в������е�Ԫ�ض���������ֵvʱ��˵���л�����
			printf("\n������ͼ�л����ڣ�");
	
}
 
