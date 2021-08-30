#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int r[10];
    int length;
    int flag;
    int a;
}SqList;
void swap(SqList *L, int a, int b)
{
	int p;
	p = L->r[a];
    L->r[a] = L->r[b];
    L->r[b] = p;
}
void InsertionSort (SqList *L, int M, int N) 
{ 
    int j, P; 
    int Tmp; 
    for(P = M; P < M + N; P ++) 
	{ 
	    Tmp = L->r[P];
	    for(j = P; j > 0 && L->r[j - 1] > Tmp; j--) 
	    {
	    	L->r[j] = L->r[j - 1]; 
		}
	    L->r[j] = Tmp;  
	} 
}

int Median3(SqList *L, int Left, int Right) 
{ 
    int Center = (Left + Right) / 2; 
	if(L->r[Left] > L->r[Center]) 
    {
    	swap(L, Left, Center);
	}
	if(L->r[Left] > L->r[Right]) 
    {
    	swap(L, Left, Right);
	}
	if(L->r[Center] > L->r[Right]) 
    {
    	swap(L, Center, Right);
	}
	swap(L, Right, Center);
    return  L->r[Right];
}
void Qsort(SqList *L, int Left, int Right) 
{   int i, j; 
    int Pivot;
    if(Left + 3 <= Right)
	{  
        if(L->flag == 0)
        {
        	Pivot = L->r[L->a];
        	swap(L, L->a, Right);
        	L->flag = 1;
		}else{
			Pivot = Median3(L, Left, Right); 
		}
		i = Left;     
		j = Right - 1;
        for( ; ; ) 
		{ 
	        while ( L->r[i] < Pivot ) 
			{
				i ++;
			} 
	        while ( L->r[j] > Pivot ) 
			{
				j --;
			}  
	        if (i < j) 
	        {
	        	swap(L, i, j); 
			}
	        else{
	        	break;
			}       
        } 
        swap(L, i, Right);
        printf("Qsort(%d,%d):", Left, Right);
		for (int k = 0; k < L->length; k ++)
		{
            printf("%d,", L->r[k]);
        }
        printf("\n");
        Qsort(L, Left, i - 1);     
        Qsort(L, i + 1, Right); 
    } 
    else{
    	InsertionSort(L, Left, Right - Left + 1);
    	printf("insert(%d,%d):", Left, Right - Left + 1);
    	for (int k = 0; k < L->length; k ++)
		{
            printf("%d,", L->r[k]);
        }
        printf("\n");
	    return;
	}
}
void QuickSort(SqList *L)
{
    Qsort(L, 0, L->length - 1);
}
int main() 
{
    int a;
    scanf("%d", &a);
	SqList *L = (SqList*)malloc(sizeof(SqList));
	L->flag = 0;
	L->a = a;
    L->length = 10;
	L->r[0] = 49;
    L->r[1] = 38;
    L->r[2] = 65;
    L->r[3] = 97;
    L->r[4] = 76;
    L->r[5] = 13;
    L->r[6] = 27;
    L->r[7] = 50;
    L->r[8] = 2;
    L->r[9] = 8;
    QuickSort(L);
    return 0;
}