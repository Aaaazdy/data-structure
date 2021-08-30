#include<stdio.h>
#define num 20
void printList(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++) 
	{
		printf("%d\t", arr[i]);
	}
}
void merge(int arr[],int num, int start, int mid, int end) //start到mid,mid到end为有序才可使用merge函数将两者拼接
{
	int result[num];
	int k = 0;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end) 
	{
		if (arr[i] < arr[j])
		{
			result[k++] = arr[i++];
        }
		else
		{
			result[k++] = arr[j++];
        }
	}
	if (i == mid + 1) 
	{
		while(j <= end)
			result[k++] = arr[j++];
	}
	if (j == end + 1) 
	{
		while (i <= mid)
			result[k++] = arr[i++];
	}
	for (j = 0, i = start ; j < k; i++, j++)
	{
		arr[i] = result[j];
	}
}
 
void mergesort(int arr[], int start, int end) //使start到end有序
{
	if (start >= end)
		return;
	int mid = ( start + end ) / 2;
	mergesort(arr, start, mid);  //使start到mid有序
	mergesort(arr, mid + 1, end);  //使mid+1到end有序
	merge(arr, start, mid, end);
}
 
int main()
{
	int arr[] = {4, 7, 6, 5, 2, 1, 8, 2, 9, 1};
	mergesort(arr, 0, 9);
	printList(arr, 10);
	return 0;
}