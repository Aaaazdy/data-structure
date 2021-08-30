
//使用A[0]作为哨兵，哨兵有两个作用：
//1 暂时存放待插入的元素
//2 防止数组下标越界，将j>0与A[j]>temp结合成只有一次比较A[j]>A[0]，
//  这样for循环只做了一次比较，提高了效率，无哨兵的情况需要比较两次，for循环有两个判断条件
//
void WithSentrySort(ElementType A[],int N)
{
    int i,j;
    for(i=2;i<=N;i++)
    {
        A[0]=A[i];
        for(j=i-1;A[j]>A[0];j--)
        {
            A[j+1]=A[j];
        }
        A[j+1]=A[0];
    }
}