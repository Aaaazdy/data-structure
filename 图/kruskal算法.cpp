#include <stdio.h>
#define MAXE 100
#define MAXV 100
typedef struct{
	int vex1;                     //�ߵ���ʼ����
	int vex2;                      //�ߵ���ֹ����
	int weight;                    //�ߵ�Ȩֵ
}Edge;
void kruskal(Edge E[],int n,int e)//nΪ��������eΪ����
{ 
	int i,j,m1,m2,sn1,sn2,k,sum=0;
	int vset[n+1];
	for(i=1;i<=n;i++)        //��ʼ���������飬ȷ��ÿһ����������յ�
		vset[i]=i;
	k=1;//��ʾ��ǰ������С�������ĵ�k���ߣ���ֵΪ1
  	j=0;//E�бߵ��±꣬��ֵΪ0
   while(k<e)//���ɵı���С��eʱ����ѭ��
   {
       m1=E[j].vex1;
       m2=E[j].vex2;//ȡһ���ߵ������ڽӵ�
       sn1=vset[m1];  // ��ȡm1��"���е���С������"�е��յ�
       sn2=vset[m2];  // ��ȡm2��"���е���С������"�е��յ�                         
	       //�ֱ�õ��������������ļ��ϱ��
	    if(sn1!=sn2)//����������ڲ�ͬ�ļ��ϣ��ñ�����С��������һ����
	    {//��ֹ���ֱպϻ�· 
			printf("V%d-V%d=%d\n",m1,m2,E[j].weight);
			sum+=E[j].weight;
			k++;                //���ɱ������� 
			if(k>=n)
				break;
			for(i=1;i<=n;i++)    //��������ͳһ���
				if (vset[i]==sn2)  //���ϱ��Ϊsn2�ĸ�Ϊsn1
					vset[i]=sn1;//ʹβ�㼰����������ͳһ�յ�
	    }
    j++;                  //ɨ����һ����
   }
    printf("��СȨֵ֮��=%d\n",sum);
}