#include <stdio.h>
#define MAXE 100
#define MAXV 100
typedef struct{
	int vex1;                     //边的起始顶点
	int vex2;                      //边的终止顶点
	int weight;                    //边的权值
}Edge;
void kruskal(Edge E[],int n,int e)//n为顶点数，e为边数
{ 
	int i,j,m1,m2,sn1,sn2,k,sum=0;
	int vset[n+1];
	for(i=1;i<=n;i++)        //初始化辅助数组，确定每一个顶点的最终点
		vset[i]=i;
	k=1;//表示当前构造最小生成树的第k条边，初值为1
  	j=0;//E中边的下标，初值为0
   while(k<e)//生成的边数小于e时继续循环
   {
       m1=E[j].vex1;
       m2=E[j].vex2;//取一条边的两个邻接点
       sn1=vset[m1];  // 获取m1在"已有的最小生成树"中的终点
       sn2=vset[m2];  // 获取m2在"已有的最小生成树"中的终点                         
	       //分别得到两个顶点所属的集合编号
	    if(sn1!=sn2)//两顶点分属于不同的集合，该边是最小生成树的一条边
	    {//防止出现闭合回路 
			printf("V%d-V%d=%d\n",m1,m2,E[j].weight);
			sum+=E[j].weight;
			k++;                //生成边数增加 
			if(k>=n)
				break;
			for(i=1;i<=n;i++)    //两个集合统一编号
				if (vset[i]==sn2)  //集合编号为sn2的改为sn1
					vset[i]=sn1;//使尾点及后续结点归于统一终点
	    }
    j++;                  //扫描下一条边
   }
    printf("最小权值之和=%d\n",sum);
}